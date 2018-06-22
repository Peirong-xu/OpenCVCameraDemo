/********************************************************************************
** Form generated from reading UI file 'OpenCVCameraDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCVCAMERADEMO_H
#define UI_OPENCVCAMERADEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenCVCameraDemoClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFrame *VideoFrame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *ContorlFrame;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QFrame *btnFrame;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnCapture;
    QPushButton *btnClear;
    QVBoxLayout *verticalLayout_4;
    QFrame *labelFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelCapture;
    QVBoxLayout *verticalLayout_3;
    QFrame *datetimeFrame;
    QVBoxLayout *ba;

    void setupUi(QWidget *OpenCVCameraDemoClass)
    {
        if (OpenCVCameraDemoClass->objectName().isEmpty())
            OpenCVCameraDemoClass->setObjectName(QStringLiteral("OpenCVCameraDemoClass"));
        OpenCVCameraDemoClass->resize(482, 802);
        verticalLayout_2 = new QVBoxLayout(OpenCVCameraDemoClass);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        VideoFrame = new QFrame(OpenCVCameraDemoClass);
        VideoFrame->setObjectName(QStringLiteral("VideoFrame"));
        VideoFrame->setMinimumSize(QSize(480, 600));
        horizontalLayout_2 = new QHBoxLayout(VideoFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addWidget(VideoFrame);

        ContorlFrame = new QFrame(OpenCVCameraDemoClass);
        ContorlFrame->setObjectName(QStringLiteral("ContorlFrame"));
        ContorlFrame->setMinimumSize(QSize(480, 200));
        horizontalLayout = new QHBoxLayout(ContorlFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        btnFrame = new QFrame(ContorlFrame);
        btnFrame->setObjectName(QStringLiteral("btnFrame"));
        btnFrame->setMinimumSize(QSize(160, 200));
        verticalLayout_6 = new QVBoxLayout(btnFrame);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnCapture = new QPushButton(btnFrame);
        btnCapture->setObjectName(QStringLiteral("btnCapture"));
        btnCapture->setMinimumSize(QSize(150, 30));
        btnCapture->setMaximumSize(QSize(150, 30));

        verticalLayout_6->addWidget(btnCapture);

        btnClear = new QPushButton(btnFrame);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setMinimumSize(QSize(150, 30));
        btnClear->setMaximumSize(QSize(150, 30));

        verticalLayout_6->addWidget(btnClear);


        verticalLayout_5->addWidget(btnFrame);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelFrame = new QFrame(ContorlFrame);
        labelFrame->setObjectName(QStringLiteral("labelFrame"));
        labelFrame->setMinimumSize(QSize(160, 200));
        horizontalLayout_3 = new QHBoxLayout(labelFrame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelCapture = new QLabel(labelFrame);
        labelCapture->setObjectName(QStringLiteral("labelCapture"));
        labelCapture->setMinimumSize(QSize(144, 180));
        labelCapture->setMaximumSize(QSize(144, 180));

        horizontalLayout_3->addWidget(labelCapture);


        verticalLayout_4->addWidget(labelFrame);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        datetimeFrame = new QFrame(ContorlFrame);
        datetimeFrame->setObjectName(QStringLiteral("datetimeFrame"));
        datetimeFrame->setMinimumSize(QSize(160, 200));
        ba = new QVBoxLayout(datetimeFrame);
        ba->setSpacing(0);
        ba->setContentsMargins(0, 0, 0, 0);
        ba->setObjectName(QStringLiteral("ba"));

        verticalLayout_3->addWidget(datetimeFrame);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addWidget(ContorlFrame);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(OpenCVCameraDemoClass);

        QMetaObject::connectSlotsByName(OpenCVCameraDemoClass);
    } // setupUi

    void retranslateUi(QWidget *OpenCVCameraDemoClass)
    {
        OpenCVCameraDemoClass->setWindowTitle(QApplication::translate("OpenCVCameraDemoClass", "OpenCVCameraDemo", 0));
        btnCapture->setText(QApplication::translate("OpenCVCameraDemoClass", "\346\210\252\345\233\276", 0));
        btnClear->setText(QApplication::translate("OpenCVCameraDemoClass", "\346\270\205\351\231\244\346\210\252\345\233\276", 0));
        labelCapture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenCVCameraDemoClass: public Ui_OpenCVCameraDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCVCAMERADEMO_H
