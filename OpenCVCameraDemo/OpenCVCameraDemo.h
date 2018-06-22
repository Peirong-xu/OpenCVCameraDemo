#pragma once

#include <QtWidgets/QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QCamera>
#include <QThread>
#include "ui_OpenCVCameraDemo.h"
#include "3rdParty/OpenCV2.4/CameraWidget.h"

class OpenCVCameraDemo : public QWidget
{
    Q_OBJECT

public:
    OpenCVCameraDemo(QWidget *parent = Q_NULLPTR);
	~OpenCVCameraDemo();

protected:
	void initUI();
public slots:
	void slotBtnCapture();
	void slotBtnClear();
private:
    Ui::OpenCVCameraDemoClass ui;
	CameraWidget *m_pCameraWidget;
	QThread m_ThreadCamera;
};
