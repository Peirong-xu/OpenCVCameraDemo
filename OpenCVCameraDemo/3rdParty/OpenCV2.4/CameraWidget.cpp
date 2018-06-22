#include "CameraWidget.h"

CameraWidget::CameraWidget(QWidget *parent,int w, int h)
	: QWidget(parent)
{
	m_pFrame = NULL;
	m_pCapture = NULL;
	setSize(w, h);
	m_showTimer.setInterval(PALY_VIDEO_TIME_LEN);
	connect(&m_showTimer, SIGNAL(timeout()), this, SLOT(slotGetFrame()));
	this->playVideo();
	this->resize(m_nWidth, m_nHeight);
}

CameraWidget::~CameraWidget()
{
	stopVideo();
}


void CameraWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_pixmap.width(), m_pixmap.height(), m_pixmap);
}

void CameraWidget::playVideo()
{
	stopVideo();
	m_pCapture = cvCreateCameraCapture(0);//0为要索引的摄像头

	cvSetCaptureProperty(m_pCapture, CV_CAP_PROP_FRAME_WIDTH, m_nHeight*1.5);
	cvSetCaptureProperty(m_pCapture, CV_CAP_PROP_FRAME_HEIGHT, m_nHeight);

	if (m_pCapture != NULL)
	{
		m_showTimer.start();
	}
}

void CameraWidget::stopVideo()
{
	m_showTimer.stop();
	if (m_pCapture != NULL)
	{
		cvReleaseCapture(&m_pCapture);
	}
}

void CameraWidget::slotGetFrame()
{
	m_showMutex.lock();
	rgbDataToQImage();
	m_showMutex.unlock();
	update();
}

QImage CameraWidget::rgbDataToQImage()
{
	m_pFrame = cvQueryFrame(m_pCapture);//从摄像头抓取一帧图像  
	if (m_pFrame != NULL)
	{
		QImage faceImg((unsigned char*)m_pFrame->imageData, m_pFrame->width, m_pFrame->height, QImage::Format_RGB888);
		m_showImage = faceImg.rgbSwapped();
		QImage tempImage = m_showImage.mirrored(true, false);//镜像翻转
		tempImage = tempImage.copy((m_nHeight*1.5 - m_nWidth)*0.5, 0, m_nWidth, m_nHeight);//裁剪图片
		//tempImage = tempImage.scaled(QSize(480, 600), Qt::KeepAspectRatioByExpanding);
		m_pixmap = QPixmap::fromImage(tempImage);
	}
	return m_showImage;
}

void CameraWidget::setSize(int iWidth, int iHeight)
{
	m_nWidth = iWidth;
	m_nHeight = iHeight;
}

void CameraWidget::getCurrentPixmap(QPixmap &iPixmap)
{
	iPixmap = m_pixmap;
}

