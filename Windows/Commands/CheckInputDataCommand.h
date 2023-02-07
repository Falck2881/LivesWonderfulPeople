#ifndef CHECKINPUTDATACOMMAND_H
#define CHECKINPUTDATACOMMAND_H

#include "WorkingWithDataLinker.h"
#include <QLineEdit>
#include <QVector>

class CheckInputDataCommand: public WorkingWithDataLinker
{
    Q_OBJECT
    public:
        CheckInputDataCommand(QLineEdit* const lineEdit);
        CheckInputDataCommand(QVector<QLineEdit*> arrayLineEdit);
    private slots:
        virtual bool executeImplementationPart() final;
    private:
        bool checkArrayLineEdit();
        bool checkLineEdit();
        QVector<QLineEdit*> arrayLineEdit;
        QLineEdit* const lineEdit;
};

#endif // CHECKINPUTDATACOMMAND_H
