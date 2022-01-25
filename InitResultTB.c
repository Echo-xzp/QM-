/*
 * @Description: 这是初始化QM法质蕴表的函数实现
 * @Version: 1.0
 * @InterFace: ResultTB.h
 * @Author: Xiao ZhiPeng
 * @Date: 2021-11-08 19:34:22
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 20:08:03
 */

#include  <math.h>
#include  <string.h>

#include  "ResultTB.h"

#define   INIT_MAX_SIZE     50

/**
 * @name: toString
 * @description: 根据QM组变量值生成字符串
 * @param {int} arr[]    QM变量组
 * @param {int} *head   变量数
 * @return {*} 转换生成的字符串
 */
char* toString(int arr[] , int size) 
{   
    int i = 0 ;
    char *result = NULL , temp[3] = {'\0'} , a[50] = {'\0'}  ;     

    result = (char*)calloc(INIT_MAX_SIZE,sizeof(char)) ;
    

    for ( i = 0 ; i < size ; i++)
    {
        switch (arr[i])
        {
        case 0 :
            temp[0] = 65 + i ;
            temp[1] = '\'' ; 
            strcat(result,temp) ;   
            break ;
        case 1 :
            temp[0] = 65 + i ;
            temp[1] = '\0' ;
            strcat(result,temp) ;   
            break ;
        default:
            break ;
        }
    }

    return result ;
}

/**
 * @name: InitResultTB
 * @description:由QM表生成质蕴表
 * @param {ResultTB} *TBhead    质蕴表表头
 * @param {QMgroup} *pgroup     QM组(PI)
 * @return {*} 1 / 0
 */
status InitResultTB(ResultTB *TBhead , QMgroup *pgroup , int size) 
{   
    TBNode ptr = NULL , ptemp = NULL ;
    QMminterms  *pterms = NULL ;

    ptr = TBhead ;

    while (pgroup)
    {   
        pterms = pgroup->line->pterms ;

        ptemp = (TBNode)malloc(sizeof(ResultTB)) ;
        if(!ptemp)  exit(-1) ;

        ptemp->pminterms = pterms ;
        ptemp->next = NULL ;

        ptemp->pTBvalue = (int *)calloc(pow(2,size),sizeof(int)) ;
        while (pterms)
        {
            ptemp->pTBvalue[pterms->data.value] = 1 ;
            pterms = pterms->next ;
        }
        
        ptemp->result = toString(pgroup->line->variables,size) ;

        ptr->next = ptemp ;
        ptr = ptr->next ;

        pgroup = pgroup->next ;

    }
    
    return 0 ;
}