#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Commands/HideWinCommand.h"
#include "Commands/OpenWinCommand.h"
#include "InputDataWindow.h"

MainWindow::MainWindow():
    Window(this),
    linkerSearchPublisherWin{std::make_unique<ManagerLinkerCommand>()},
    linkerInputDataWin{std::make_unique<ManagerLinkerCommand>()},
    searchPublisherWin{std::make_unique<SearchPublisherWindow>(this)},
    inputDataWin{std::make_unique<InputDataWindow>(this)},
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(650,350);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    addCommandsInLinkerSearchPublisherWin();
    addCommandsInLinkerInputDataWin();
    setConnection();
}

void MainWindow::addCommandsInLinkerSearchPublisherWin()
{
    auto hideCurrentWin{std::make_unique<HideWinCommand>(this)};
    linkerSearchPublisherWin->append(std::move(hideCurrentWin));
    auto openSearchPublisherWin{std::make_unique<OpenWinCommand>(searchPublisherWin.get())};
    linkerSearchPublisherWin->append(std::move(openSearchPublisherWin));
}

void MainWindow::addCommandsInLinkerInputDataWin()
{
    auto hideCurrentWin{std::make_unique<HideWinCommand>(this)};
    linkerInputDataWin->append(std::move(hideCurrentWin));
    auto openInputDataWin{std::make_unique<OpenWinCommand>(inputDataWin.get())};
    linkerInputDataWin->append(std::move(openInputDataWin));
}

void MainWindow::setConnection()
{
    QObject::connect(ui->searchPublisherButton, &QPushButton::clicked,
                     linkerSearchPublisherWin.get(), &ManagerLinkerCommand::execute);
    QObject::connect(ui->addWorkAuthorButton, &QPushButton::clicked,
                     linkerInputDataWin.get(),  &ManagerLinkerCommand::execute);
}

void MainWindow::updateDataInApplication(BufferData buffer)
{
    searchPublisherWin->updateData(buffer);
    inputDataWin->close();
    this->open();
}

MainWindow::~MainWindow()
{
    delete ui;
}
