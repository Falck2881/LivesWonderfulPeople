#include "InputDataWindow.h"
#include "ui_InputDataWindow.h"
#include "HideWinCommand.h"
#include "OpenWinCommand.h"
#include "CheckInputDataCommand.h"
#include "AddWorkAuthorCommand.h"
#include "MainWindow.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QLineEdit>

InputDataWindow::InputDataWindow(Window* mainWin):Window(this),mainWin(mainWin),
                      backMainWin{std::make_unique<ManagerLinkerCommand>()},
                      managerUpdateData{std::make_unique<WorkingWithDataLinker>()},
                      ui(new Ui::InputDataWindow)
{
    ui->setupUi(this);
    move(500,250);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setValidatorForInput();
    addCommandsInLinkers();
    setConnection();

}

void InputDataWindow::setValidatorForInput()
{
    QVector<QLineEdit*> arrayLineEdit{ui->lineFioAuthor,ui->lineNameEssay,ui->lineNamePublisher,
                                     ui->lineYearPublication,ui->lineCountPage};
    QVector<QString> arrayPattren{"[^!-~]{1,12}","[^!-~]{1,32}","[^!-~]{1,16}",
                                  "[^ -/:-я]{1,4}","[^ -/:-я]{1,4}"};
    QRegularExpression regExpInputString;
    QVector<QRegularExpressionValidator*> arrayRegValInputString;
    for(uint8_t i = 0; i < arrayPattren.size(); ++i)
    {
        regExpInputString.setPattern(arrayPattren.at(i));
        arrayRegValInputString.push_back(new QRegularExpressionValidator(regExpInputString,arrayLineEdit.at(i)));
        arrayLineEdit[i]->setValidator(arrayRegValInputString.at(i));
    }
}

void InputDataWindow::addCommandsInLinkers()
{
    addCommandsInBackWinLinker();
    addCommandsInManagerUpdateDataLinker();
}

void InputDataWindow::addCommandsInBackWinLinker()
{
    auto hideCurrentWin{std::make_unique<HideWinCommand>(this)};
    backMainWin->append(std::move(hideCurrentWin));
    auto openMainWin(std::make_unique<OpenWinCommand>(mainWin));
    backMainWin->append(std::move(openMainWin));
}

void InputDataWindow::addCommandsInManagerUpdateDataLinker()
{
    QVector<QLineEdit*> arrayLineEdit{ui->lineFioAuthor,ui->lineNameEssay,
                                     ui->lineNamePublisher,ui->lineYearPublication,
                                     ui->lineCountPage};
    auto checkInputData{std::make_unique<CheckInputDataCommand>(arrayLineEdit)};
    managerUpdateData->append(std::move(checkInputData));
    auto addWorkAuthor{std::make_unique<AddWorkAuthorCommand>(arrayLineEdit,dynamic_cast<MainWindow*>(mainWin))};
    managerUpdateData->append(std::move(addWorkAuthor));
}

void InputDataWindow::setConnection()
{
    QObject::connect(ui->backButton, &QPushButton::clicked,
                     backMainWin.get(), &ManagerLinkerCommand::execute);
    QObject::connect(ui->addWorkButton, &QPushButton::clicked,
                     this, &InputDataWindow::updateDataInProgram);
}

void InputDataWindow::updateDataInProgram()
{
    managerUpdateData->execute();
    clearArrayLineEdit();
}

void InputDataWindow::clearArrayLineEdit()
{
    QVector<QLineEdit*> arrLineEdit{ui->lineFioAuthor,ui->lineNameEssay,ui->lineNamePublisher,
                                    ui->lineYearPublication, ui->lineCountPage};

    foreach(auto lineEdit, arrLineEdit)
        lineEdit->setText("");
}

InputDataWindow::~InputDataWindow()
{
    delete ui;
}
