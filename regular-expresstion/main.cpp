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
    //const char* url = "<sip:tom@172.18.1.133>";  
    //char uri[10] = {0};  
    //sscanf(url, "%*[^:]:%[^@]", uri);  
    //cout << uri << endl;  
 
    const char* url = "https://www.baidu.com/";  
    char uri_0[30] = {0};  
    char uri_1[30] = {0};  
    char uri_2[30] = {0};  
    char uri_3[30] = {0};  
    sscanf(url, "%[^://]://%[^.].%[^.].%[^/]/", uri_0,uri_1,uri_2,uri_3);  
    cout << uri_0 << endl;  
    cout << uri_1 << endl;  
    cout << uri_2 << endl;  
    cout << uri_3<< endl;  
  


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

