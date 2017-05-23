
#include "demo.h"

typedef struct RGB16TRIPLE
{
	unsigned short   RgbBlue;
	unsigned short   RgbGreen;
	unsigned short   RgbRed;
} RGB16TRIPLE;

/// 插值成全分辨率的G分量
void InterpolateG(int *pDest,short *pSrc,int nWidth,int nHei,BAYER_TYPE Bayer_type);

/// 获得dBayer
void GetdBayer(int *pDest, short *pSrc, int *pFullG,int nWidth, int nHeight);

/// dBayer 滤波
void dBayerFilter(int *pDest, int *pSrc, short *pBayer,int nWidth, int nHeight);
void IterativeSigmaFilter(int *pArray, int *pRefArray, int nWidth,int nHei,int radius,unsigned short *pThArray);
void ColorBuildGammaNoiseThreshold(short *plBayer, int nlWidth, int nlHei,float scale,float slope,float intercept,unsigned short *pThArray);

/// dBayer进行脉冲滤波
void ImpulseFilter_dBayer(int *pSrc, int nWidth, int nHeight, int radius);

///  RB分量进行插值
void RBInterprate(int* pSrc, int nWidth, int nHeight,int *pldRed,int *pldGreen,int *pldBlue,BAYER_TYPE Bayer_type);

void InterpolationGreenofXG16Bit(unsigned short *pSrce, unsigned short* pDest, int nWid, int nHei);
void InterGreen16Bit(unsigned short *pRaw, int nWid, unsigned short &uchGreen);
void RawBGWhiteBalance(short* pRaw, int nWidth, int nHeight);

void Gamma8RGBImg(BYTE *pRGBImg, int nWidth, int nHei, int *phPan_mean, int *phdRed, int *phdGreen, int *phdBlue, int *pG);

void ColorCorrection(BYTE *pRGBImg, int nWidth, int nHei);

void Convolve1D(int *pArray, int nWidth, int nHeight, float *pKernel, int nkernelsize, bool edirection);
void WhiteBalance(short *pSrc, int nWidth, int nHeight, float fRatioR, float fRatioB, BAYER_TYPE Bayer_type);
