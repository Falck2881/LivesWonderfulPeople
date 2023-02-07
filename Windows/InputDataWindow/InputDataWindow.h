#ifndef INPUTDATAWINDOW_H
#define INPUTDATAWINDOW_H

#include "Window.h"
#include "ManagerLinkerCommand.h"
#include "WorkingWithDataLinker.h"
#include <memory>

namespace Ui {
class InputDataWindow;
}

class InputDataWindow: public Window
{
    Q_OBJECT

    public:
        InputDataWindow(Window* mainWin);
        ~InputDataWindow();
    private slots:
        void updateDataInProgram();
    private:
        void addCommandsInLinkers();
        void addCommandsInBackWinLinker();
        void addCommandsInManagerUpdateDataLinker();
        void setValidatorForInput();
        virtual void setConnection() final;
        void clearArrayLineEdit();
        Window* mainWin;
        std::unique_ptr<ManagerLinkerCommand> backMainWin;
        std::unique_ptr<WorkingWithDataLinker> managerUpdateData;
        Ui::InputDataWindow* ui;
};

#endif // INPUTDATAWINDOW_H
