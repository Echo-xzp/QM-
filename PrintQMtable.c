/*
 * @Descripttion: 这是一个打印QM表中数据的函数的接口
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-17 20:13:36
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 19:42:27
 */

#include  "PrintQMtable.h"

/**
 * @name: PrintQMtable
 * @description: 打印QM表中数据
 * @param {QMtable} *ptable   QM表头
 * @param {int}   size   变量数目
 * @return {*}  status  状态值
 */
status  PrintQMtable(QMtable *ptable , int size) 
{
    QMgroup *pgroup = NULL ;
    QMminterms *p = NULL ;
    int i = 0 , j = 0 ;

    if (!ptable->next)
    {
        printf("ERROR! The table is null!\n") ;
        return ERROR ;
    }
    
    printf("--------------QM--------------\n\n") ;
    
    while (ptable->next)
    {
        ptable = ptable->next ;
        pgroup = ptable->group ;

        printf("%-3d",ptable->couts) ;

        while (pgroup)
        {
           p = pgroup->line->pterms ;
           while (p)
           {
               printf("%d ",p->data.value) ;
               p = p->next ;
           }
           
            for ( i = 0; i < size ; ++i)
            {
                printf("%3d",*(pgroup->line->variables + i)) ;
            }
            printf("\n") ;
            printf("   ") ;

            pgroup = pgroup->next ;
        }

        printf("\n") ;

    }
    
    return OK ;

}