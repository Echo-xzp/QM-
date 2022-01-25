/*
 * @Descripttion: 
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-11-02 21:11:25
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-06 19:48:39
 */

#include  "QM.h"

status  DeleteTable(QMtable **pptable)
{
    QMtable *ptable = (*pptable) , *ptmp = NULL ;
    
    if (!ptable->next)
    {
      return 0 ;
    }

    while ( ptable)
    { 
      if (ptable->next && !ptable->next->group)
      {
          ptmp = ptable->next ;
          ptable->next = ptmp->next ;
          free(ptmp) ;
      }
      else
         ptable = ptable->next ;
    }

    return 0 ;

}