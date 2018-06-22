#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QCamera>
#include "ui_OpenCVCameraDemo.h"
#include "3rdParty/OpenCV2.4/Cvv_AllInclude.h"

#define PALY_VIDEO_TIME_LEN 30
#define CAMERA_WINDOW_WIDGET 480	//��Ƶ���ڿ�
#define CAMERA_WINDOW_HEIGET 600	//��Ƶ���ڸߣ�ͼ�����С���ظߣ�

class CameraWidget : public QWidget
{
	Q_OBJECT

public:
	CameraWidget(QWidget *parent = Q_NULLPTR, int w = CAMERA_WINDOW_WIDGET, int h = CAMERA_WINDOW_HEIGET);
	~CameraWidget();
	//����
	void playVideo();
	//ֹͣ����
	void stopVideo();
	//��ȡ��ǰͼ�񣨽�ͼ��
	void getCurrentPixmap(QPixmap &iPixmap);
protected:
	void paintEvent(QPaintEvent *event);
	QImage rgbDataToQImage();
private:
	//���ô��ڴ�С
	void setSize(int iWidth, int iHeight);
public slots:
	void slotGetFrame();
private:
	int m_nWidth;			//��Ƶ���ڿ�
	int m_nHeight;			//��Ƶ���ڸ�
	//��Ƶ�������
	IplImage* m_pFrame;		//��ȡͼƬ����  
	CvCapture* m_pCapture;	//��ȡ����ͷ    
	//
	QTimer m_showTimer;		//��ʱ��ȡ֡
	QImage m_showImage;		//��ǰ֡ͼ��
	QPixmap m_pixmap;		//��ǰͼƬ
	QMutex m_showMutex;		//��
};
