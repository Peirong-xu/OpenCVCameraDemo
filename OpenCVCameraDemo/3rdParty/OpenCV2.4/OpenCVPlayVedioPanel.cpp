#include "OpenCVPlayVedioPanel.h"
#include <QPaintEvent>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QDebug>
#include <QFile>
#include <QBuffer>
//#include "database/config/ConfigOption.h"
//
#define  PALY_VIDEO_TIME_LEN 40

//
OpenCVPlayVedioPanel::OpenCVPlayVedioPanel(QWidget *parent) :QLabel(parent)
{
	this->setObjectName("PlayVedioPanel");
    //
    m_RotateNum = 0;
    initVideoConfig();
    //
    setupCustomUI();
    updateCustomUI();
    //
    m_showTimer.setInterval(PALY_VIDEO_TIME_LEN);
    connect(&m_showTimer, SIGNAL(timeout()), this,SLOT(showVideoToPanel()));
}
//
OpenCVPlayVedioPanel::~OpenCVPlayVedioPanel()
{
    unInitVideoConfig();
}
/**
*功能:监听窗口大小改变事件，实现背景图片拉伸功能
*/
void OpenCVPlayVedioPanel::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    updateCustomUI();
}
//
void OpenCVPlayVedioPanel::setupCustomUI()
{
    //
    m_box_x = 0;
    m_box_y = 0;
    m_box_width = 0;
    m_box_height = 0;
	//
	m_pBoxBase = new QWidget(this);
	m_pBoxBase->setObjectName("BoxBase");
	m_pBoxBase->hide();
	//
	m_pBoxLine = new QLabel(m_pBoxBase);
	m_pBoxLeft = new QLabel(m_pBoxBase);
	m_pBoxRight = new QLabel(m_pBoxBase);
	m_pBoxUp = new QLabel(m_pBoxBase);
	m_pBoxDown = new QLabel(m_pBoxBase);

	m_pBoxLeft->setObjectName("BoxBack");
	m_pBoxRight->setObjectName("BoxBack");
	m_pBoxUp->setObjectName("BoxBack");
	m_pBoxDown->setObjectName("BoxBack");
	//
	pWgScanBase = new QWidget(m_pBoxLine);
	pWgScanBase->setObjectName("ScanBase");
	pLbScanBack = new QLabel(pWgScanBase);
	pLbScanBack->setObjectName("ScanBack");
	pMoveScanAnimation = new QPropertyAnimation(pWgScanBase, "geometry", this);
	pMoveScanAnimation->setLoopCount(-1);
	pMoveScanAnimation->setDuration(4*1000);
}
//
void OpenCVPlayVedioPanel::updateCustomUI()
{
	m_pBoxBase->resize(this->width(), this->height());
	m_pBoxLine->setGeometry(m_box_x,m_box_y,m_box_width,m_box_height);

	m_pBoxLeft->resize(m_box_x, m_pBoxBase->height());
	m_pBoxRight->resize(m_pBoxBase->width()-(m_box_x+m_box_width), m_pBoxLeft->height());
	m_pBoxUp->resize(m_box_width, m_box_y);
	m_pBoxDown->resize(m_pBoxUp->width(), m_pBoxBase->height()-(m_box_y+m_box_height));

	m_pBoxLeft->move(0, 0);
	m_pBoxRight->move(m_box_x+m_box_width, 0);
	m_pBoxUp->move(m_box_x, 0);
	m_pBoxDown->move(m_box_x, m_box_y+m_box_height);

	pWgScanBase->resize(m_pBoxLine->size());
	pLbScanBack->resize(pWgScanBase->width(), pWgScanBase->height());
	//
	pMoveScanAnimation->setStartValue(QRect(0, -pWgScanBase->height(), pWgScanBase->width(), pWgScanBase->height()));
	pMoveScanAnimation->setEndValue(QRect(0, 0, pWgScanBase->width(), pWgScanBase->height()));
	pMoveScanAnimation->setKeyValueAt(0.9, QRect(0, 0, pWgScanBase->width(), pWgScanBase->height()));
}
//
void OpenCVPlayVedioPanel::initVideoConfig()
{

	//if(ConfigOption::getConfigPunchCardViewMode() == -1)
	//{
	//	setRotate(-90);
	//}
	m_pCapture = NULL;
	m_pFrame = NULL;
}
//
void OpenCVPlayVedioPanel::unInitVideoConfig()
{
    closeVedioInfo();
}
//关闭视频
void OpenCVPlayVedioPanel::closeVedioInfo()
{
    m_showTimer.stop();
	if(m_pCapture != NULL)
	{
		cvReleaseCapture(&m_pCapture);  
	}
}
//播放视频
void  OpenCVPlayVedioPanel::playVedioInfo()
{
    closeVedioInfo();
	m_pCapture = cvCreateCameraCapture(0);//0为要索引的摄像头  
	if(m_pCapture != NULL){
		m_showTimer.start();
	}
}
//
bool OpenCVPlayVedioPanel::catchPicture(QString& fileName)
{
    if(!m_showImage.isNull())
    {
        QImage tmpImage = QImage(m_showImage);
        rotateImage(tmpImage);
        return tmpImage.save(fileName,"JPG");
    }
    return false;
}
//
bool OpenCVPlayVedioPanel::catchPicture(QImage& tmpImage)
{
    if(!m_showImage.isNull())
    {

        tmpImage = QImage(m_showImage);
        rotateImage(tmpImage);
        return true;
    }
    return false;
}
//
void OpenCVPlayVedioPanel::showVideoToPanel(){

    m_showMutex.lock();
    QImage faceImg = rgbDataToQImage();
    rotateImage(faceImg);
    showImageToWnd(faceImg);
    m_showMutex.unlock();
}
//
QImage OpenCVPlayVedioPanel::rgbDataToQImage()
{
	m_pFrame = cvQueryFrame(m_pCapture);//从摄像头抓取一帧图像  
	if(m_pFrame != NULL){
		QImage faceImg((unsigned char*)m_pFrame->imageData, m_pFrame->width, m_pFrame->height, QImage::Format_RGB888);
		m_showImage =faceImg.rgbSwapped();
	}
    return m_showImage;
}
//
void OpenCVPlayVedioPanel::showImageToWnd(QImage &tmpImage){
    if(!tmpImage.isNull()){
        this->setPixmap(QPixmap::fromImage(tmpImage.scaled(this->size(), Qt::IgnoreAspectRatio)));
    }
}
//
void OpenCVPlayVedioPanel::rotateImage(QImage &tmpImage){
    if(m_RotateNum == 0) return;
    QMatrix leftmatrix;
    leftmatrix.rotate(m_RotateNum);
    tmpImage =tmpImage.transformed(leftmatrix,Qt::SmoothTransformation);
}
//
void OpenCVPlayVedioPanel::setRotate(int iRotate){
    if(iRotate <-360 || iRotate > 360) return;
    m_RotateNum = iRotate;
}
//
void  OpenCVPlayVedioPanel::updateBoxLineGeometry(int ix, int iy, int iwidth, int iheight){
    if(iwidth > 0 && iheight > 0){
        //
        if(ix > this->width() || ix < 0){
            ix = 0;
        }
        //
        if(iy > this->height() || iy < 0){
            iy = 0;
        }
        //
        if(ix+iwidth > this->width()){
            iwidth = this->width() - ix;
        }
        //
        if(iy+iheight > this->height()){
            iheight =  this->height() - iy;
        }
        //
        if(iwidth > 0 && iheight > 0){
            //
            m_box_x = ix;
            m_box_y = iy;
            m_box_width = iwidth;
            m_box_height = iheight;
            updateCustomUI();
			//
			pMoveScanAnimation->start();
			m_pBoxBase->show();
			//
            return;
        }
    }
	m_pBoxBase->hide();
	pMoveScanAnimation->stop();
}
//
void OpenCVPlayVedioPanel::updateBoxScanTime(int sec)
{
	pMoveScanAnimation->setDuration(sec*1000);
}
//
QImage OpenCVPlayVedioPanel::cutImageToServerImage(const QImage& rawImage){

    if(m_pBoxBase->isVisible())
    {
        int realTop =  rawImage.height()*m_box_y/ this->height();
        int realLeft = rawImage.width()*m_box_x/ this->width();
        int leftWidth =  rawImage.width()*m_box_width/this->width();
        int topHeight =  rawImage.height()*m_box_height/ this->height();
        return rawImage.copy(realLeft,realTop,leftWidth,topHeight);
    }
    return rawImage;
}
//
QImage  OpenCVPlayVedioPanel::cutImageToServerImage(){
    if(m_pBoxBase->isVisible() && !m_showImage.isNull())
    {
                int realTop =  m_showImage.height()*m_box_y/ this->height();
                int realLeft = m_showImage.width()*m_box_x/ this->width();
        int leftWidth =  m_showImage.width()*m_box_width/this->width();
        int topHeight =  m_showImage.height()*m_box_height/ this->height();
        return m_showImage.copy(realLeft,realTop,leftWidth,topHeight);
    }
    return m_showImage;
}
//
QByteArray OpenCVPlayVedioPanel::cutImageToServerData(const QImage& rawImage)
{
    if(m_pBoxBase->isVisible())
    {
                int realTop =  rawImage.height()*m_box_y/ this->height();
                int realLeft = rawImage.width()*m_box_x/ this->width();
        int leftWidth =  rawImage.width()*m_box_width/this->width();
        int topHeight =  rawImage.height()*m_box_height/ this->height();
        QImage useImage =rawImage.copy(realLeft,realTop,leftWidth,topHeight);
        QByteArray photoImgBytes;
        QBuffer photoImgBuffer(&photoImgBytes);
        photoImgBuffer.open(QIODevice::WriteOnly);
        useImage.save(&photoImgBuffer, "JPG");
        photoImgBuffer.close();
        return photoImgBytes.toBase64();
    }
    return QByteArray();
}
//
QByteArray OpenCVPlayVedioPanel::cutImageToServerData()
{
    if(m_pBoxBase->isVisible() && !m_showImage.isNull())
    {
                int realTop =  m_showImage.height()*m_box_y/ this->height();
                int realLeft = m_showImage.width()*m_box_x/ this->width();
        int leftWidth =  m_showImage.width()*m_box_width/this->width();
        int topHeight =  m_showImage.height()*m_box_height/ this->height();
        QImage useImage =m_showImage.copy(realLeft,realTop,leftWidth,topHeight);
        QByteArray photoImgBytes;
        QBuffer photoImgBuffer(&photoImgBytes);
        photoImgBuffer.open(QIODevice::WriteOnly);
        useImage.save(&photoImgBuffer, "JPG");
        photoImgBuffer.close();
        return photoImgBytes.toBase64();
    }
    return QByteArray();
}