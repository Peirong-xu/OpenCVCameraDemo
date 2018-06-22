/********************************************************************************
** Form generated from reading UI file 'OpenCVCameraWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCVCAMERAWIDGET_H
#define UI_OPENCVCAMERAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenCVCameraWidget
{
public:

    void setupUi(QWidget *OpenCVCameraWidget)
    {
        if (OpenCVCameraWidget->objectName().isEmpty())
            OpenCVCameraWidget->setObjectName(QStringLiteral("OpenCVCameraWidget"));
        OpenCVCameraWidget->resize(400, 300);

        retranslateUi(OpenCVCameraWidget);

        QMetaObject::connectSlotsByName(OpenCVCameraWidget);
    } // setupUi

    void retranslateUi(QWidget *OpenCVCameraWidget)
    {
        OpenCVCameraWidget->setWindowTitle(QApplication::translate("OpenCVCameraWidget", "OpenCVCameraWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenCVCameraWidget: public Ui_OpenCVCameraWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCVCAMERAWIDGET_H
