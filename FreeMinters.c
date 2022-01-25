/*
 * @Descripttion: 这是一个释放最小项组链表的函数实现
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-30 21:30:37
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-10-30 21:39:46
 */

#include  "QM.h"

status  FreeMinters(QMminterms **ppminters)
{
    QMminterms *pminters = *ppminters , *ptemp = NULL ;

    if (!pminters)
    {
        printf("Memery Error!\n") ;
        exit(-1) ;
    }
    
    while (pminters)
    {
        ptemp = pminters ;
        pminters = pminters->next ;    
        free(ptemp) ;
    }

    pminters = NULL ;
    
    return 0 ;

}
