/*
 * @Description: 这是一个删除链表中子链节点的函数
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-12 20:17:44
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-12 21:27:22
 */

#include  "ResultTB.h"

status  ModifyIndex(QMminterms *index , QMminterms *pterms)
{
    QMminterms *p = index , *ptr = pterms , *ptemp = NULL ;

    while(ptr)
    {   
        if (ptr->data.flag == 1)
        {
            ptr = ptr->next ;
            continue ;
        }

        if (ptr->data.value > p->next->data.value )
        {
            p = p->next ;
            
        }
        else if (ptr->data.value < p->next->data.value)
        {
            ptr = ptr->next ;
        }
        else
        {
            ptemp = p->next ;
            p->next = ptemp->next ;
            free(ptemp) ;
            ptr = ptr->next ;
        }  
            
        if (!p->next)    break ;

    }

    return 0 ;

}
