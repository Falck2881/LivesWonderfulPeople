#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QString>
#include <memory>

class Archive: public QObject
{
    public:
        Archive();
        QString fileName() const;
    private:
        void setConnectWithServer();
        bool isNoError() const;
        void showMassageError() const;
    private slots:
        void receiveAnswerFromServer();
        void errorFromConnect(QNetworkReply::NetworkError error);

    private:
        QUrl pathToArchive;
        QNetworkReply* replay;
        std::unique_ptr<QNetworkAccessManager> manager;
};

#endif // ARCHIVE_H
