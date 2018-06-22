#include "OpenCVCameraWidget.h"

#define PALY_VIDEO_TIME_LEN 40

VideoCapture m_Capture(0);
QImage cvMat2QImage(const cv::Mat& mat);

OpenCVCameraWidget::OpenCVCameraWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	resize(600, 480);
	m_showTimer.setInterval(PALY_VIDEO_TIME_LEN);
	connect(&m_showTimer, SIGNAL(timeout()), this, SLOT(slotGetFrame()));
	this->playVideo();
}

OpenCVCameraWidget::~OpenCVCameraWidget()
{
	stopVideo();
}

void OpenCVCameraWidget::playVideo()
{
	stopVideo();
	m_showTimer.start();
}

void OpenCVCameraWidget::stopVideo()
{
	m_showTimer.stop();
}

QImage OpenCVCameraWidget::rgbDataToQImage()
{
	//m_pFrame = cvQueryFrame(m_pCapture);//´ÓÉãÏñÍ·×¥È¡Ò»Ö¡Í¼Ïñ  
	//if (m_pFrame != NULL)
	//{
	//	QImage faceImg((unsigned char*)m_pFrame->imageData, m_pFrame->width, m_pFrame->height, QImage::Format_RGB888);
	//	m_showImage = faceImg.rgbSwapped();
	//	QImage tempImage = m_showImage.mirrored(true, false);//¾µÏñ·­×ª
	//	m_pixmap = QPixmap::fromImage(tempImage);
	//}
	if (m_Capture.isOpened())
	{
		m_Capture >> m_MatFrame;
	}
	m_showImage = cvMat2QImage(m_MatFrame);
	QImage tempImage = m_showImage.mirrored(true, false);//¾µÏñ·­×ª
	tempImage = tempImage.copy(0, 0, 600, 480);
	m_pixmap = QPixmap::fromImage(tempImage);

	return m_showImage;
}

void OpenCVCameraWidget::slotGetFrame()
{
	m_showMutex.lock();
	rgbDataToQImage();
	m_showMutex.unlock();
	update();
}

void OpenCVCameraWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_pixmap.width(), m_pixmap.height(), m_pixmap);
}


QImage cvMat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1  
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)  
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat  
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3  
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}