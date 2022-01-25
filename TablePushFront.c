/*
 * @Descripttion: 这是一个使用头插法向QM表头的Group组中插入节点的函数实现
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-11-01 19:30:43
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-02 21:06:39
 */

#include  "QM.h"

status TablePushFront(QMtable *ptable,QMtableline *pline)
{
    QMgroup *ptmp =  ptable->group ;
    
    QMgroup *pgroup = (QMgroup *)malloc(sizeof(QMgroup)) ;
    if (!pgroup)
    {
        printf("OVERFLOW!!\n") ;
        exit(-1) ;
    }
    pgroup->line = pline ;
    pgroup->next = ptmp ;

    ptable->group = pgroup ;

    return 0 ;

}