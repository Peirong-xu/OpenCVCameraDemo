#include "3rdParty/OpenCV2.4/CameraWidget.h"
#include "OpenCVCameraDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	OpenCVCameraDemo w;
    w.show();

    return a.exec();
}
