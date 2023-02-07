#ifndef WORKINGWITHDATALINKER_H
#define WORKINGWITHDATALINKER_H

#include <QObject>
#include <QList>
#include <memory>

class WorkingWithDataLinker: public QObject
{
    Q_OBJECT
    public:
        WorkingWithDataLinker(){};
        virtual ~WorkingWithDataLinker(){}
        void append(std::unique_ptr<WorkingWithDataLinker> command);
        void append(WorkingWithDataLinker* command);
    public slots:
        void execute();
    protected slots:
        virtual bool executeImplementationPart(){return true;};
    private:
        QList<std::shared_ptr<WorkingWithDataLinker>> listCommand;
};

#endif // WORKINGWITHDATALINKER_H
