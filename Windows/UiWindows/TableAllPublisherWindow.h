#ifndef TABLEALLPUBLISHERWINDOW_H
#define TABLEALLPUBLISHERWINDOW_H

#include <memory>
#include <QTableWidget>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QWidget>
#include <QVector>
#include "Stream/Publisher.h"

namespace Ui {
    class TableAllPublisherWindow;
}

class TableAllPublisherWindow : public QWidget
{
    Q_OBJECT

    public:
        TableAllPublisherWindow();
        void updateWholeTable(const BufferData& buffer);
    private:
        void createTable();
        void setProperties();
        void setMaxRowCount();
        void openArchiveForRead();
        void readAllRecordsByPublishersFromFile();
        void readAllRecordsByPublishersFromFile(QDomElement childElement);
        void addRecordsAboutPublisher(const BufferData& buffer);
        void placeAllRecordsAboutPublishers();
        void placeDataAboutPublisherInColumn(Publisher dataPublisher);
        QVector<Publisher> dataPublishers;
        QDomElement parentElement;
        QDomDocument document;
        BufferData buffer;
        std::unique_ptr<QTableWidget> tableAllPublisher;
        qint64 currentRow;
        Ui::TableAllPublisherWindow* ui;
};

#endif // TABLEALLPUBLISHERWINDOW_H
