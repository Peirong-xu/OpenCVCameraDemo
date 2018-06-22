#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QCamera>
#include "ui_OpenCVCameraDemo.h"
#include "3rdParty/OpenCV2.4/Cvv_AllInclude.h"

#define PALY_VIDEO_TIME_LEN 30
#define CAMERA_WINDOW_WIDGET 480	//视频窗口宽
#define CAMERA_WINDOW_HEIGET 600	//视频窗口高（图像的最小像素高）

class CameraWidget : public QWidget
{
	Q_OBJECT

public:
	CameraWidget(QWidget *parent = Q_NULLPTR, int w = CAMERA_WINDOW_WIDGET, int h = CAMERA_WINDOW_HEIGET);
	~CameraWidget();
	//播放
	void playVideo();
	//停止播放
	void stopVideo();
	//获取当前图像（截图）
	void getCurrentPixmap(QPixmap &iPixmap);
protected:
	void paintEvent(QPaintEvent *event);
	QImage rgbDataToQImage();
private:
	//设置窗口大小
	void setSize(int iWidth, int iHeight);
public slots:
	void slotGetFrame();
private:
	int m_nWidth;			//视频窗口宽
	int m_nHeight;			//视频窗口高
	//视频播放相关
	IplImage* m_pFrame;		//获取图片对象  
	CvCapture* m_pCapture;	//获取摄像头    
	//
	QTimer m_showTimer;		//定时获取帧
	QImage m_showImage;		//当前帧图像
	QPixmap m_pixmap;		//当前图片
	QMutex m_showMutex;		//锁
};
