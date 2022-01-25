/*
 * @Description: 这是一个暂停程序数秒回后清屏的函数
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-15 21:03:05
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 21:19:45
 */
#include  <stdio.h>
#include  <stdlib.h>
#include  <windows.h>

#include  "Pause.h" 

#define   PAUSE_COUNT    5
#define   SLEEP_TIME    1000

void  Pause() 
{
    int i = 0 ;
    
    printf("Waiting") ;
    for(i = 0 ; i < PAUSE_COUNT ; ++i )
    {
        printf("   >>") ;
        Sleep(SLEEP_TIME) ;
    }
    
    system("cls") ;

}