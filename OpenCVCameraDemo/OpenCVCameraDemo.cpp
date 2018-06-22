#include "OpenCVCameraDemo.h"

#define PALY_VIDEO_TIME_LEN 30
#define CAMERA_WINDOW_WIDGET 480	//视频窗口宽
#define CAMERA_WINDOW_HEIGET 600	//视频窗口高（图像的最小像素高）

OpenCVCameraDemo::OpenCVCameraDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}

OpenCVCameraDemo::~OpenCVCameraDemo()
{
	m_ThreadCamera.quit();
	m_ThreadCamera.wait();
}

void OpenCVCameraDemo::initUI()
{
	this->setFixedSize(600, 800);
	m_pCameraWidget = new CameraWidget(this,600);
	ui.VideoFrame->layout()->addWidget(m_pCameraWidget);
	connect(ui.btnCapture, SIGNAL(clicked()), this, SLOT(slotBtnCapture()));
	connect(ui.btnClear, SIGNAL(clicked()), this, SLOT(slotBtnClear()));
	m_pCameraWidget->moveToThread(&m_ThreadCamera);
	m_ThreadCamera.start();
}

void OpenCVCameraDemo::slotBtnCapture()
{
	QPixmap iPixmap;
	m_pCameraWidget->getCurrentPixmap(iPixmap);
	iPixmap = iPixmap.scaled(ui.labelCapture->size(), Qt::KeepAspectRatio);
	ui.labelCapture->setPixmap(iPixmap);
}

void OpenCVCameraDemo::slotBtnClear()
{
	ui.labelCapture->setPixmap(QPixmap());
}
