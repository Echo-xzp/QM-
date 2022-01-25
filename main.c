/*
 * @Descripttion: 这是一个实现逻辑运算中QM法化简的程序
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Date: 2021-10-09 18:50:27
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-30 10:56:03
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <windows.h>

#include  "QM.h"
#include  "ResultTB.h"
#include  "Input.h"
#include  "PrintQMtable.h"
#include   "SimplifyQM.h"
#include   "FindResult.h"
#include   "Pause.h"

#define    ARR_MAX_SIZE     100         // 数组最大长度

int main(int argc, char const *argv[])
{
    int size = 0 , i = 0 ;
    QMminterms  *phead = NULL ;                     // 用户输入最小项组与任意性组
    QMtable table = { -1 , NULL , NULL } ;          // QM表头
    ResultTB RTtable = {NULL,NULL,NULL,NULL} ;      // 质蕴表表头
    char result[100] = {'\0'} ;                     // 结果字符串

    printf("This is a program that uses the Quine-McClusky to simplify the logical variables \n\n") ;

    /* 让用户输入数据，进行初始化 */
    Input(&size , &phead) ;
    Pause() ;
    
    /* 初始化QM表  */
    InitTable(&table,size, phead) ;
    
    /* 打印QM表，再合并QM表，直到QM表最简 */
    do
    {   
        PrintQMtable(&table,size) ;
        Pause() ;

    } while (SimplifyQM(&table,size)) ;
    
    /* 由QM表生成质蕴表 */
    InitResultTB(&RTtable,table.group,size) ;

    /* 根据质蕴表找出答案 */
    FindResult(result,&RTtable , phead,size) ;
    
    /* 打印答案 */
    printf("-----------------------------\n") ;
    printf("The result is \n\t") ;
    printf("%s\n\n",result) ;
 
    free(phead) ;       // 释放最小项组空表头
    system("pause") ;
    return 0;
    
}
