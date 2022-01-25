/*
 * @Descripttion: 这是一个释放行内存的函数实现
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-30 21:26:08
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-05 21:07:51
 */

#include  "QM.h"

status  FreeLine(QMtableline **ppline)
{
    QMtableline *pline = *ppline ;
    
    free(pline->variables) ;
    pline->variables = NULL ;
    FreeMinterms(&(pline->pterms)) ;
    pline->pterms = NULL ;
    free(pline) ;
    pline = NULL ;

    (*ppline) = NULL ;
    
    return 0 ;

}