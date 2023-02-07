#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include "Window.h"
#include "SearchPublisherWindow.h"
#include "InputDataWindow/InputDataWindow.h"
#include "Commands/ManagerLinkerCommand.h"
#include "Stream/BufferData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public Window
{
    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();
        void updateDataInApplication(BufferData buffer);

    private:
        void addCommandsInLinkerSearchPublisherWin();
        void addCommandsInLinkerInputDataWin();
        virtual void setConnection() final;
        std::unique_ptr<ManagerLinkerCommand> linkerSearchPublisherWin;
        std::unique_ptr<ManagerLinkerCommand> linkerInputDataWin;
        std::unique_ptr<SearchPublisherWindow> searchPublisherWin;
        std::unique_ptr<InputDataWindow> inputDataWin;
        Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
