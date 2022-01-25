/*
 * @Descripttion: 
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-22 21:07:09
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-02 13:16:34
 */
#include "QM.h"

/**
 * @name: ModifyLine
 * @description: 修改QM表行数据 : 将函数接受最小项组链表数据拷贝，生成新节点，再将这些新节点
 *                               连接至目标行的最小项组链表(head前后不能被修改！) ； 修改
 *                               QM行变量组中pos的值为-1(相当于QM法中的划线) 
 * @param {QMtableline} *pline     被修改的行
 * @param {QMminterms} *head     被拷贝的最小项组链表   
 * @param {int} pos                     需要修改的变量位置
 * @return {*}  0
 */
status ModifyLine(QMtableline *pline, QMminterms *head, int pos)
{   
    int i = 0;
    QMminterms *ptr = NULL, *temp = NULL, *phead = NULL ,
                 *pterms = pline->pterms ;

    //*phead 为 QMminterms 链表的表头，之后会删除
    phead = (QMminterms *)calloc(1, sizeof(QMminterms));
    if (!phead)
    {
        printf("OVERFOLW!！！\n");
        exit(-1);
    }
    ptr = phead;

    //此循环为复制 *copied 里的 QMminterms 链表的数据
    while (head)
    {   
        temp = (QMminterms *)calloc(1, sizeof(QMminterms));
        if (!temp)
        {
            printf("OVERFOLW!！！\n");
            exit(-1);
        }

        temp->data.value = head->data.value ;
        temp->data.flag = head->data.flag ;
        temp->next = NULL ;

        ptr->next = temp ;  
        ptr = ptr->next ;
        
        head = head->next;
    }

    ptr = phead->next;
    free(phead); //删除表头 *phead

    //此循环为了找到最小项组链表的表尾
    while (pterms->next)
    {
        pterms = pterms->next ;
    }
    
    pterms->next = ptr;  //将复制的最小项组链表数据接到表尾
    pline->variables[pos] = -1 ;

    return 0;
}
