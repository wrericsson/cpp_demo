#ifndef __DEMO_H
#define __DEMO_H

#ifdef __cplusplus
#define EXTERN_C     extern "C"
#else
#define EXTERN_C     extern
#endif

#include "stdio.h"
#include "math.h"
#include "string.h"
#include <time.h>


#include "OpenCV\inc\cv.h"
#include "OpenCV\inc\cxcore.h"
#include "OpenCV\inc\highgui.h"

#pragma  comment(lib,"OpenCV\\lib\\cv.lib")
#pragma  comment(lib,"OpenCV\\lib\\cxcore.lib")
#pragma  comment(lib,"OpenCV\\lib\\highgui.lib")


typedef unsigned char  Byte1;   //定义1个字节长度
typedef unsigned short Byte2;   //定义2个字节长度

#define SCALE_VALUE              4096   

#define  IMG_SIZE        WIDTH*HEIGHT        //柯达800万相机分辨率
#define  WIDTH           4224
#define  HEIGHT          3136
#define  GET2BYTE(p,i)   (*((Byte2 *)((Byte1*)(p)+(i))))      /// 从BYTE类型变换成unsigned short类型

typedef unsigned char BYTE;

#define CLIP8(a)                 (((a) & 0xFFFFFF00) ? (((a) < 0) ? 0 : 255 ) : (a))   /// 判断8位数据范围
#define CLIP10(a)                (((a) & 0xFFFFFC00) ? (((a) < 0) ? 0 : 1023) : (a))   /// 判断10位数据范围
#define CLIP12(a)                (((a) & 0xFFFFF000) ? (((a) < 0) ? 0 : 4095) : (a))   /// 判断12位数据范围
#define MAX(b,c)                 (((b)>(c))?(b):(c))                                   /// 求最大值
#define MIN(b,c)                 (((b)>(c))?(c):(b))                                   /// 求最小值

void RawBGWhiteBalance(unsigned short* pRaw, int nWidth, int nHeight);
void ImpulseFilter(int *pSrc, int nWidth, int nHeight, int radius);

//定义Bayer色彩格式
typedef enum BAYER_TYPE
{
	BAYER_GB = 0,
	BAYER_GR = 1,
	BAYER_BG = 2,
	BAYER_RG = 3
}BAYER_TYPE;

#endif