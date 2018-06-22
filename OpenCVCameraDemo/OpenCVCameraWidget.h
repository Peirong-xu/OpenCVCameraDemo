#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include "ui_OpenCVCameraWidget.h"
#include<opencv2/opencv.hpp>   
#include<cv.h>  

using namespace cv;
using namespace std;

class OpenCVCameraWidget : public QWidget
{
	Q_OBJECT

public:
	OpenCVCameraWidget(QWidget *parent = Q_NULLPTR);
	~OpenCVCameraWidget();
	void playVideo();
	void stopVideo();
protected:
	void paintEvent(QPaintEvent *event);
	QImage rgbDataToQImage();
public slots:
	void slotGetFrame();
private:
	Ui::OpenCVCameraWidget ui;
	Mat m_MatFrame;
	QTimer m_showTimer;		//��ʱ��ȡ֡
	QImage m_showImage;		//��ǰ֡ͼ��
	QMutex m_showMutex;		//
	QPixmap m_pixmap;		//
};
