/*
 * @Descripttion: 这是一个初始化QM表组中每一行的函数的定义
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface:  InitTable.c
 * @Date: 2021-10-15 19:51:07
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-10-30 20:38:42
 */

#include  "QM.h"

status  InitLine(QMtableline **ppline , int size , QMminterm mintern) 
{
    int *p = NULL , temp = mintern.value , couts = 0  , i = 0 ;
    QMminterms *pterms = NULL ;

    // 构造最小项组链表
    pterms = (QMminterms*) malloc(sizeof(QMminterms)) ;
    if (!pterms)
    {
        printf("OVERFOLW!！\n")  ;
        exit(-1) ;
    }
    pterms->data = mintern ;
    pterms->next = NULL ;

    // 初始化表行的指针
    (*ppline) = (QMtableline*) malloc(sizeof(QMtableline)) ;
    if (!(*ppline))
    {
        printf("OVERFOLW!\n") ;
        exit(-1) ;
    }
    
    (*ppline)->pterms = pterms ;        // 将构造好的最小项组链表接入

    // 分配内存储存二进制化的最小项值
    p = (int*) calloc(size,sizeof(int)) ;       // calloc 默认给内存数据初始化为 0
    if (!p)
    {
        printf("OVERFOLW!！！\n") ;
        exit(-1) ;
    }
    (*ppline)->variables = p ;      // 将分配好的内存接入
    
    // 最小项转二进制并保存其每一位
    for ( i = size ; i > 0  ; --i)
    {
        *(p+i-1) = temp % 2 ;
        temp /= 2 ;

        // 检查 1 的数量
        if (1 == *(p+i-1))
        {
            ++couts ;
        }

    }

    (*ppline)->couts = couts ;   // 初始化其组数
    (*ppline)->flag = 0 ;        // 初始化其标记值

    return OK ;

}