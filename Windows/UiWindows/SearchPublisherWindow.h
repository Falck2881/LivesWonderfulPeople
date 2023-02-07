#ifndef SEARCHPUBLISHERWINDOW_H
#define SEARCHPUBLISHERWINDOW_H

#include "Window.h"
#include "Commands/ManagerLinkerCommand.h"
#include "WhatInputWindow.h"
#include "TableAllPublisherWindow.h"
#include "StructureData/TreeBuilder.h"
#include "Commands/WorkingWithDataLinker.h"
#include "HistorySearch.h"
#include "TableAboutAuthor.h"
#include "Stream/BufferData.h"
#include "Commands/SearchInputDataCommand.h"

namespace Ui {
class SearchPublisherWindow;
}

class SearchPublisherWindow : public Window
{
    Q_OBJECT

    public:
        explicit SearchPublisherWindow(Window* mainWindow);
        ~SearchPublisherWindow();
        void updateData(const BufferData& buffer);

    private:
        void setPropertyInput();
        void initializeObservers();
        void addCommandsInLinkers();
        void addCommandsInLinkerBackWin();
        void addCommandsInLinkerSearchData();
        void buildTrees();
        virtual void setConnection() final;
        Window* mainWin;
        std::unique_ptr<ManagerLinkerCommand> linkerBackWin;
        std::unique_ptr<WorkingWithDataLinker> searchDataLinker;
        SearchInputDataCommand* searchInputDataCommand;
        std::unique_ptr<WhatInputWindow> whatInputWin;
        std::unique_ptr<TableAllPublisherWindow> tableAllPublisherWin;
        std::unique_ptr<TreeBuilder> avlBuilder;
        std::unique_ptr<TableAboutAuthor> tableAboutAuthor;
        std::unique_ptr<HistorySearch> historySearch;
        Ui::SearchPublisherWindow* ui;
};

#endif // SEARCHPUBLISHERWINDOW_H
