/*
 * @Description: 这是一个打印质蕴表中数据的函数
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @Date: 2021-11-15 20:35:07
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-30 10:55:59
 */

#include  "ResultTB.h"
#include  "Pause.h"

status  PrintRTtable(ResultTB *RTtable , QMminterms *index) 
{
    QMminterms *pterms = NULL ;
    ResultTB *ptable = RTtable->next ;
    
    if (!RTtable->next || !index->next)
    {
        return 1 ;
    }

    printf("------------RESULT-------------\n\n") ;
    pterms = index->next ;
    while (pterms)
    {
        printf("%-3d",pterms->data.value) ;
        pterms = pterms->next ;
    }
    printf("\n\n") ;

    while (ptable)
    {
        pterms = index->next ;
        while (pterms)
        {   
            printf("%-3d",ptable->pTBvalue[pterms->data.value]) ;
            pterms = pterms->next ;
        }
        printf("\t%s\n",ptable->result) ;

        ptable = ptable->next ;
    }
    
    printf("\n\n") ;

    Pause() ;

    return 0 ;   

}