/*
 * @Description: 这是一个对最小项组进行排序的函数
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-10 19:54:35
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-16 19:47:14
 */

#include  "QM.h"

status SortMinterms(QMminterms *pterms)
{
    QMminterms *ptr = NULL , *p= NULL ;
    QMminterm tmp = {0,0} ;

    for (ptr = pterms ; ptr != NULL ; ptr = ptr->next)
    {
        for(p = ptr->next ; p != NULL ; p = p->next)
        {
            if (p->data.value < ptr->data.value )
            {   
                tmp = ptr->data ;
                ptr->data = p->data ;
                p->data = tmp ;
            }
            
        }
    }

    return 0 ;

}