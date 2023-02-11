#include "Archive.h"
#include <QMessageBox>
#include <QApplication>

Archive::Archive():
    pathToArchive(QString("https://drive.google.com/file/d/1jBqUmR3NJNTQyCH5GEMRciDf-BG2AjpL/view?usp=share_link")),
    replay(nullptr),
    manager(std::make_unique<QNetworkAccessManager>(this))
{

    setConnectWithServer();
}

void Archive::setConnectWithServer()
{
    QNetworkRequest request(pathToArchive);

    if(replay == nullptr)
        replay = manager->get(request);

    QObject::connect(replay, &QNetworkReply::finished,
                     this, &Archive::receiveAnswerFromServer);

    QObject::connect(replay, &QNetworkReply::errorOccurred,
                     this, &Archive::errorFromConnect);
}


void Archive::receiveAnswerFromServer()
{
    if(replay != nullptr)
    {
        while(replay->isRunning())
        {
            if(replay->isFinished())
            {
                if(isNoError())
                    pathToArchive = replay->url();
            }
        }
    }
}

bool Archive::isNoError() const
{
    return replay != nullptr && replay->error() == QNetworkReply::NoError ? true:false;
}

void Archive::showMassageError() const
{
    QMessageBox* message = new QMessageBox(QMessageBox::Critical, "The Error connect",
                                           "An error occurred when connecting "
                                           "to Google drive. ", QMessageBox::Ok);

    quint32 value = message->exec();

    if(value == QMessageBox::Ok)
        QApplication::quit();
}


void Archive::errorFromConnect(QNetworkReply::NetworkError error)
{
    if(error != QNetworkReply::NoError)
        showMassageError();
}


QString Archive::fileName() const
{
    QString name = pathToArchive.fileName();
    return name;
}
