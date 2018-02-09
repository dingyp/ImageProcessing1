#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

bool ROI_AddImage()  
{  
   
       //【1】读入图像  
       Mat srcImage1= imread("timg.jpg");  
       Mat logoImage= imread("mying.jpg");  
       if(!srcImage1.data ) { printf("你妹，读取srcImage1错误~！ \n"); return false; }  
       if(!logoImage.data ) { printf("你妹，读取logoImage错误~！ \n"); return false; }  
   
       //【2】定义一个Mat类型并给其设定ROI区域  
       Mat imageROI= srcImage1(Rect(100,100,logoImage.cols,logoImage.rows));  
   
       //【3】加载掩模（必须是灰度图）  
       Mat mask= imread("mying.jpg",0);  
   
       //【4】将掩膜拷贝到ROI  
       logoImage.copyTo(imageROI,mask);  
   
       //【5】显示结果  
       namedWindow("<1>利用ROI实现图像叠加示例窗口");  
       imshow("<1>利用ROI实现图像叠加示例窗口",srcImage1);  
   
       return true;  
}  

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    //namedWindow("Display Image", WINDOW_AUTOSIZE );
    //imshow("Display Image", image);

    ROI_AddImage();
    waitKey(10000);

    return 0;
}