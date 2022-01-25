/*
 * @Descripttion: 
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-11-02 21:21:17
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-02 21:25:52
 */

#include  "QM.h"

status  DeleteGroup(QMgroup **ppgroup)
{
    QMgroup *ptr = *ppgroup , *ptmp = NULL ;

    while (ptr)
    {
        ptmp = ptr ;
        ptr = ptr->next ;
        FreeLine(&(ptmp->line)) ;
        free(ptmp) ;
    }
    (*ppgroup) = NULL ;

    return 0 ;

}