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


typedef unsigned char  Byte1;   //����1���ֽڳ���
typedef unsigned short Byte2;   //����2���ֽڳ���

#define SCALE_VALUE              4096   

#define  IMG_SIZE        WIDTH*HEIGHT        //�´�800������ֱ���
#define  WIDTH           4224
#define  HEIGHT          3136
#define  GET2BYTE(p,i)   (*((Byte2 *)((Byte1*)(p)+(i))))      /// ��BYTE���ͱ任��unsigned short����

typedef unsigned char BYTE;

#define CLIP8(a)                 (((a) & 0xFFFFFF00) ? (((a) < 0) ? 0 : 255 ) : (a))   /// �ж�8λ���ݷ�Χ
#define CLIP10(a)                (((a) & 0xFFFFFC00) ? (((a) < 0) ? 0 : 1023) : (a))   /// �ж�10λ���ݷ�Χ
#define CLIP12(a)                (((a) & 0xFFFFF000) ? (((a) < 0) ? 0 : 4095) : (a))   /// �ж�12λ���ݷ�Χ
#define MAX(b,c)                 (((b)>(c))?(b):(c))                                   /// �����ֵ
#define MIN(b,c)                 (((b)>(c))?(c):(b))                                   /// ����Сֵ

void RawBGWhiteBalance(unsigned short* pRaw, int nWidth, int nHeight);
void ImpulseFilter(int *pSrc, int nWidth, int nHeight, int radius);

//����Bayerɫ�ʸ�ʽ
typedef enum BAYER_TYPE
{
	BAYER_GB = 0,
	BAYER_GR = 1,
	BAYER_BG = 2,
	BAYER_RG = 3
}BAYER_TYPE;

#endif