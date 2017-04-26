/*
 **************************************************************************************
 *       Filename:  main.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-04-26 10:27:19
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
  
int main()  
{  
    //例1：从<sip:tom@172.18.1.133>中提取tom  
    const char* url = "<sip:tom@172.18.1.133>";  
    char uri[10] = {0};  
    sscanf(url, "%*[^:]:%[^@]", uri);  
    cout << uri << endl;  
  
    //例2：从iios/12DDWDFF@122中提取 12DDWDFF  
    const char* s = "iios/12DDWDFF@122";  
    char buf[20];  
    sscanf(s, "%*[^/]/%[^@]", buf);  
    cout << buf << endl;  
  
    int k;  
    sscanf( "AAA123BBB456" , "%*[^0-9]%i" , &k) ;  
    printf("%d\n",k);  
    return 0;  
}  




/********************************** END **********************************************/

