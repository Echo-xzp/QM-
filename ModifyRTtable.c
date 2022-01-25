/*
 * @Description: 这是一个修改质蕴表的函数，修改包括去除劣势行，合并同类行
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-13 16:54:06
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 20:32:58
 */

#include  <string.h>

#include  "ResultTB.h"

/*  
 * @name: ModifyRTtable
 * @description: 修正质蕴表,包括合并相同行，删去劣势行
 * @param {ResulTB} *table    质蕴表
 * @param {QMminterms} *phead    索引
 * @return {*} 1 / 0 
 */
status  ModifyRTtable(ResultTB *ptable , QMminterms *index)
{
    ResultTB *ptr = ptable , *p = NULL ;
    QMminterms *pterms = NULL ;
    int flag1 = 0 , flag2 = 0 ;

    if (!index->next || !ptable->next)
    {
        return 1 ;          // 索引与质蕴表都已经为空，无需再修改
    }

    while(ptr && ptr->next)
    {   
        p = ptr->next ;
        while(p && p->next)
        {
            pterms = index->next ;
            while(pterms)
            {   
                // 上行为优势行
                if (ptr->next->pTBvalue[pterms->data.value] > p->next->pTBvalue[pterms->data.value])
                {
                    flag1 = 1 ;
                }
                // 下行为优势行
                else if(ptr->next->pTBvalue[pterms->data.value] < p->next->pTBvalue[pterms->data.value])
                {
                    flag2 = 1 ;
                }
                
                // 标记值同为1，两行不相等
                if ((flag1 + flag2) == 2)
                {
                    break ;
                }     

                pterms = pterms->next ;            
            }

             // 相同，执行空语句 
            if ((flag1 + flag2) == 2)
            {
                ;
            }   
            // 删除劣势行 ：下
            else if (flag1 == 1)
            {
                DeleteRTtable(p) ;
            }
            // 删除劣势行 ：上
            else if (flag2 == 1)
            {
                DeleteRTtable(ptr) ;
                p = ptr->next ;         // ptr的下一个节点被重置，p需重新指向
            }
            // 相同，拷贝内容，并删除其中一行
            else
            {   strcat(ptr->next->result,"(") ;
                strcat(ptr->next->result,p->next->result) ;
                strcat(ptr->next->result,")") ;
                DeleteRTtable(p) ;
            }
            
            flag1 = flag2 = 0 ;         // 重置标记值
            p =  p->next ;
        }

        ptr = ptr->next ;
    }

    return 0 ;
}
