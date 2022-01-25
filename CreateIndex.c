/*
 * @Description: 这是一个根据最小项组生成索引的函数
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-10 20:50:19
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 20:13:41
 */

#include  "ResultTB.h"

/**
 * @name: CreateIndex
 * @description: 删除任意性并将链表排序，构成索引
 * @param {QMminterms} *head   QM源最小项组表头
 * @return {*} 1 / 0
 */
status  CreateIndex(QMminterms *head) 
{   
    QMminterms *ptr = head ;
    while (ptr->next && !ptr->next->data.flag)
    {
        ptr = ptr->next ;
    }
    if (ptr->next)
    {
        FreeMinterms(&ptr->next) ;
        ptr->next = NULL ;
    }
    

    SortMinterms(head->next) ;

    return 0 ;

}