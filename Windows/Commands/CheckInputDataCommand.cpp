#include "CheckInputDataCommand.h"
#include "Warning.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

CheckInputDataCommand::CheckInputDataCommand(QLineEdit* const lineEdit):lineEdit{lineEdit}
{
}

CheckInputDataCommand::CheckInputDataCommand(QVector<QLineEdit*> arrayLineEdit):arrayLineEdit(arrayLineEdit),
                                                                                lineEdit(nullptr)
{

}

bool CheckInputDataCommand::executeImplementationPart()
{
    bool value = false;

    if(lineEdit != nullptr)
        value = checkLineEdit();
    else if(!arrayLineEdit.empty())
        value = checkArrayLineEdit();

    return value;
}

bool CheckInputDataCommand::checkLineEdit()
{
    bool value;

    try{
        if(lineEdit->text() != "")
            value = true;
        else{
            throw new Warning("Пожалуйста - введите правельно \
                               фамилию автора");
        }
    }catch(Warning* warning){
        warning->show();
        value = false;
    }
    return value;
}

bool CheckInputDataCommand::checkArrayLineEdit()
{
    bool value = false;

    foreach(auto& lineEdit, arrayLineEdit)
    {
        try{
            if(lineEdit->text() != "")
                value = true;
            else{
                throw new Warning("Пожалуйста - введите правельно \
                                   фамилию автора");
            }
        }catch(Warning* warning){
            warning->show();
            value = false;
        }
    }
    return value;
}
