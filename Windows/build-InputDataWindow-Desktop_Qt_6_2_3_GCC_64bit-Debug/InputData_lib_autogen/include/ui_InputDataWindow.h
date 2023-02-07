/********************************************************************************
** Form generated from reading UI file 'InputDataWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDATAWINDOW_H
#define UI_INPUTDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDataWindow
{
public:
    QFrame *frame;
    QFrame *line;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLabel *label_2;
    QLineEdit *lineFioAuthor;
    QLabel *label_8;
    QLabel *label_3;
    QLineEdit *lineNameEssay;
    QLabel *label_9;
    QLabel *label_4;
    QLineEdit *lineNamePublisher;
    QLabel *label_10;
    QLabel *label_5;
    QLineEdit *lineYearPublication;
    QLabel *label_11;
    QLabel *label_6;
    QLineEdit *lineCountPage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backButton;
    QPushButton *addWorkButton;

    void setupUi(QWidget *InputDataWindow)
    {
        if (InputDataWindow->objectName().isEmpty())
            InputDataWindow->setObjectName(QString::fromUtf8("InputDataWindow"));
        InputDataWindow->setWindowModality(Qt::WindowModal);
        InputDataWindow->resize(531, 331);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InputDataWindow->sizePolicy().hasHeightForWidth());
        InputDataWindow->setSizePolicy(sizePolicy);
        InputDataWindow->setMaximumSize(QSize(531, 331));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyIcons/AddRecords.png"), QSize(), QIcon::Normal, QIcon::Off);
        InputDataWindow->setWindowIcon(icon);
        frame = new QFrame(InputDataWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 531, 331));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(4);
        frame->setMidLineWidth(0);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 20, 491, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 10, 261, 20));
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 491, 231));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_7);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineFioAuthor = new QLineEdit(formLayoutWidget);
        lineFioAuthor->setObjectName(QString::fromUtf8("lineFioAuthor"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineFioAuthor);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_8);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        lineNameEssay = new QLineEdit(formLayoutWidget);
        lineNameEssay->setObjectName(QString::fromUtf8("lineNameEssay"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineNameEssay);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_9);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        lineNamePublisher = new QLineEdit(formLayoutWidget);
        lineNamePublisher->setObjectName(QString::fromUtf8("lineNamePublisher"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineNamePublisher);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_10);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        lineYearPublication = new QLineEdit(formLayoutWidget);
        lineYearPublication->setObjectName(QString::fromUtf8("lineYearPublication"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lineYearPublication);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(8, QFormLayout::FieldRole, label_11);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_6);

        lineCountPage = new QLineEdit(formLayoutWidget);
        lineCountPage->setObjectName(QString::fromUtf8("lineCountPage"));

        formLayout->setWidget(9, QFormLayout::FieldRole, lineCountPage);

        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(230, 290, 288, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(horizontalLayoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(0, 0));
        backButton->setMaximumSize(QSize(120, 21));

        horizontalLayout_2->addWidget(backButton);

        addWorkButton = new QPushButton(horizontalLayoutWidget);
        addWorkButton->setObjectName(QString::fromUtf8("addWorkButton"));

        horizontalLayout_2->addWidget(addWorkButton);


        retranslateUi(InputDataWindow);

        QMetaObject::connectSlotsByName(InputDataWindow);
    } // setupUi

    void retranslateUi(QWidget *InputDataWindow)
    {
        InputDataWindow->setWindowTitle(QCoreApplication::translate("InputDataWindow", "Add Records", nullptr));
        label->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#2555b5;\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\320\261\321\211\321\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 </span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\244\320\230\320\236 \320\220\320\262\321\202\320\276\321\200\320\260 \320\262\320\262\320\276\320\264 \321\201\321\202\321\200\320\276\320\263\320\276 \320\277\320\276 \320\277\321\200\320\270\320\274\320\265\321\200\321\203: </span><span style=\" color:#ff0000;\">\320\257\320\275\320\276\320\262 \320\222 \320\227</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\244\320\230\320\236 \320\220\320\262\321\202\320\276\321\200\320\260</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270 \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\261\321\213\320\273\320\276 \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\276 \321\201\320\276\321\207\320\270\320\275\320\265\320\275\320\270\320\265.</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\276\321\207\320\270\320\275\320\265\320\275\320\270\321\217</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\230\320\274\321\217 \320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\260 \320\262 \320\272\320\276\321\202\320\276\321\200\320\276\320\274 \320\261\321\213\320\273\320\276 \320\276\320\277\321\203\320\261\320\273\320\270\320\272\320\276\320\262\320\260\320\275\320\276 \321\201\320\276\321\207\320\270\320\275\320\265\320\275\320\270\320\265.</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\230\320\274\321\217 \320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\260</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\223\320\276\320\264 \320\272\320\276\320\263\320\264\320\260 \320\261\321\213\320\273\320\276 \320\276\320\277\321\203\320\261\320\273\320\270\320\272\320\276\320\262\320\260\320\275\320\276 \321\201\320\276\321\207\320\270\320\275\320\265\320\275\320\270\320\265</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\244\320\260\320\272\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\272\320\276\320\273\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200. \320\262 \321\201\320\276\321\207\320\270\320\275\320\265\320\275\320\270\320\270 </span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("InputDataWindow", "<html><head/><body><p><span style=\" color:#2555b5;\">\320\232\320\276\320\273\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206</span></p></body></html>", nullptr));
        backButton->setText(QCoreApplication::translate("InputDataWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        addWorkButton->setText(QCoreApplication::translate("InputDataWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\220\321\200\321\205\320\270\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputDataWindow: public Ui_InputDataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDATAWINDOW_H
