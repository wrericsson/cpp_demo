#include "Tk1ClientNode.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define SERVER_IP "10.60.99.127"
#define SERVER_PORT 55555

using namespace std;


//double getAvg(cv::Mat img)
//{
    //cv::Mat gray;
    //cvtColor(img,gray,CV_RGB2GRAY);
    //cv::Scalar scalar = mean(gray);
    //return scalar.val[0];
//}

int main(int argc, char **argv)
{

    concreteBuilding cb("兵营");
    cb.production();
    cb.injured();
    cb.repair();
    cb.show();
    return 0;

	return 0;
}
