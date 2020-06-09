
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    
    string le("/Users/beonghyunkang/Downloads/멀미/tsukuba/scene1.row3.col2.png");
    string ri("/Users/beonghyunkang/Downloads/멀미/tsukuba/scene1.row3.col3.png");
    string di("/Users/beonghyunkang/Downloads/멀미/tsukuba/truedisp.row3.col3.png");
    
    Mat left,right,disparitymap,output;
    
    left=imread(le.c_str());
    right=imread(ri.c_str());
    cvtColor(left, left, COLOR_BGR2GRAY);
    cvtColor(right, right, COLOR_BGR2GRAY);
    disparitymap=imread(di.c_str());
    
    output = Mat::zeros(left.size(),CV_8U);
    
    int kernel=3;
    int margin = kernel / 2;
    
    for (int r = margin; r < left.rows-margin; r++) {
        for (int c = margin; c < left.cols - margin; c++) {
            
            int best_disp=0;
            float mincost=INT_MAX;
            
            for(int d=0;d<=16;++d){
                float sum = 0;
                
                if(c-d-margin<0)break;
                for (int rr = 0; rr < kernel; rr++) {
                    for (int cc = 0; cc < kernel; cc++) {
                        sum += pow(left.at<uchar>(r + rr - margin, c+ cc - margin)-right.at<uchar>(r + rr - margin, c-d + cc - margin),2);
                    }
                }
                if(sum<mincost){
                    best_disp=d;
                    mincost=sum;
                }
            }
            output.at<uchar>(r,c)=best_disp;
        }
    }
   
    output=output*10;
    
    namedWindow("left",1);
    namedWindow("right",1);
    namedWindow("map",1);
    namedWindow("output",1);
    
    imshow("left", left);
    imshow("right", right);
    imshow("map", disparitymap);
    imshow("output", output);
    
    
    waitKey(0);
    return 0;
    
}





