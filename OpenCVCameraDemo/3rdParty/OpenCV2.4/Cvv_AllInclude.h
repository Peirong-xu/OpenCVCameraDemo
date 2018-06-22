#pragma once

#include "cv.h"
#include "highgui.h"
#define OPENCVPATH "./3rdParty/OpenCV2.4/lib/"
#ifdef _DEBUG
#pragma comment(lib,OPENCVPATH"opencv_core249.lib")
#pragma comment(lib,OPENCVPATH"opencv_highgui249.lib")
#pragma comment(lib,OPENCVPATH"opencv_imgproc249.lib")
#else
#pragma comment(lib,OPENCVPATH"opencv_core249.lib")
#pragma comment(lib,OPENCVPATH"opencv_highgui249.lib")
#pragma comment(lib,OPENCVPATH"opencv_imgproc249.lib")
#endif