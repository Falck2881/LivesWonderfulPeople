#include "SearchPublisherWindow.h"
#include "ui_searchpublisherwindow.h"
#include "HideWinCommand.h"
#include "OpenWinCommand.h"
#include "AvlBuilder.h"
#include "CheckInputDataCommand.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "ArchiveAuthor.h"

SearchPublisherWindow::SearchPublisherWindow
(Window* mainWindow):Window(this),
                     mainWin{mainWindow},
                     linkerBackWin{std::make_unique<ManagerLinkerCommand>()},
                     searchDataLinker{std::make_unique<WorkingWithDataLinker>()},
                     whatInputWin{std::make_unique<WhatInputWindow>()},
                     tableAllPublisherWin{std::make_unique<TableAllPublisherWindow>()},
                     avlBuilder{std::make_unique<AvlBuilder>()},
                     ui(new Ui::SearchPublisherWindow)
{
    ui->setupUi(this);
    avlBuilder->initialize();
    move(400,200);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    initializeObservers();
    setPropertyInput();
    addCommandsInLinkers();
    setConnection();
}

void SearchPublisherWindow::initializeObservers()
{
    tableAboutAuthor = std::make_unique<TableAboutAuthor>(ui->tableAboutAuthor,avlBuilder->getReadyTree());
    historySearch = std::make_unique<HistorySearch>(avlBuilder->getReadyTree());
}

void SearchPublisherWindow::addCommandsInLinkers()
{
    addCommandsInLinkerBackWin();
    addCommandsInLinkerSearchData();
}

void SearchPublisherWindow::addCommandsInLinkerBackWin()
{
    auto hideCurrentWin{std::make_unique<HideWinCommand>(this)};
    linkerBackWin->append(std::move(hideCurrentWin));
    auto openWin{std::make_unique<OpenWinCommand>(mainWin)};
    linkerBackWin->append(std::move(openWin));
}

void SearchPublisherWindow::addCommandsInLinkerSearchData()
{
    auto checkInputCommand{new CheckInputDataCommand(ui->lineEditFioAuthor)};
    searchDataLinker->append(checkInputCommand);
    searchInputDataCommand = new SearchInputDataCommand(ui->lineEditFioAuthor,
                                                        avlBuilder->getReadyTree());
    searchDataLinker->append(searchInputDataCommand);
}

void SearchPublisherWindow::setPropertyInput()
{
    QRegularExpression regExp{"[^!-~]{1,12}"};
    QRegularExpressionValidator* regVal = new QRegularExpressionValidator(regExp,ui->lineEditFioAuthor);
    ui->lineEditFioAuthor->setValidator(regVal);
}

void SearchPublisherWindow::setConnection()
{
    QObject::connect(ui->searchBestPublisherButton, &QPushButton::clicked,
                     searchDataLinker.get(), &WorkingWithDataLinker::execute);
    QObject::connect(ui->backMainWindow, &QPushButton::clicked,
                     linkerBackWin.get(), &ManagerLinkerCommand::execute);
    QObject::connect(ui->whatInputButton, &QPushButton::clicked,
                     whatInputWin.get(), &WhatInputWindow::show);
    QObject::connect(ui->showAllPublisherButton, &QPushButton::clicked,
                     tableAllPublisherWin.get(), &TableAllPublisherWindow::show);
    QObject::connect(ui->historySearchButton, &QPushButton::clicked,
                     historySearch.get(), &HistorySearch::show);
}

void SearchPublisherWindow::updateData(const BufferData& buffer)
{
    avlBuilder->insert(buffer);
    searchInputDataCommand->updataTree(avlBuilder->getReadyTree());
    tableAllPublisherWin->updateWholeTable(buffer);
}

SearchPublisherWindow::~SearchPublisherWindow()
{
    delete ui;
}
