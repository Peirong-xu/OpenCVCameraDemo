#ifndef OPENCVPLAYVEDIOPANEL_H
#define OPENCVPLAYVEDIOPANEL_H
#include "3rdParty/OpenCV2.4/Cvv_AllInclude.h"
#include <QLabel>
#include <QTimer>
#include <QMutex>
#include <QPropertyAnimation>
class OpenCVPlayVedioPanel : public QLabel
{
    Q_OBJECT
public:
    explicit OpenCVPlayVedioPanel(QWidget *parent = 0);
    ~OpenCVPlayVedioPanel();
    //
    void initVideoConfig();
    void unInitVideoConfig();
    //
    void updateBoxLineGeometry(int ix, int iy, int iwidth, int iheight);
	void updateBoxScanTime(int sec);
    QImage cutImageToServerImage(const QImage& rawImage);
    QImage cutImageToServerImage();
    QByteArray cutImageToServerData(const QImage& rawImage);
    QByteArray cutImageToServerData();
    //
    void closeVedioInfo();
    void playVedioInfo();
    bool catchPicture(QString& fileName);
    bool catchPicture(QImage& tmpImage);
    void setRotate(int iRotate);
    //
    void updateVideoSize(int iWidth, int iHeight);
    QImage rgbDataToQImage();
    void rotateImage(QImage &tmpImage);
    void  showImageToWnd(QImage &tmpImage);
    //

signals:

public slots:

    void showVideoToPanel();
protected:
    void resizeEvent(QResizeEvent *event);
    void setupCustomUI();
    void updateCustomUI();
private:
	//
    //视频播放相关
	IplImage* m_pFrame;//获取图片对象  
	//获取摄像头    
	CvCapture* m_pCapture;
	//
    QTimer m_showTimer;
    QImage m_showImage;
    //
    int m_Width;
    int m_Height;
    int m_RotateNum;
    QString m_sRtspUrl;
    QMutex m_showMutex;

	//显示边框
	QWidget *m_pBoxBase;
	QLabel *m_pBoxLeft;
	QLabel *m_pBoxRight;
	QLabel *m_pBoxUp;
	QLabel *m_pBoxDown;
	QLabel *m_pBoxLine;
	int m_box_x;
	int m_box_y;
	int m_box_width;
	int m_box_height;
	//
	QPropertyAnimation *pMoveScanAnimation;
	QWidget *pWgScanBase;
	QLabel *pLbScanBack;
};

#endif // PLAYVEDIOPANEL_H
