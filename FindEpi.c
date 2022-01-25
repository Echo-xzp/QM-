/*
 * @Description: 这是一个找到质蕴表中Epi的函数实现
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-10 20:57:03
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 20:24:08
 */

#include  <string.h>

#include  "ResultTB.h"

/**
 * @name: FindEpi
 * @description: 根据索引寻找质蕴表中的EPI
 * @param {char} *result   指向结果字符串的指针
 * @param {ResulTB} *RTtable    质蕴表
 * @param {QMminterms} *index    索引
 * @param {int}  size      变量数
 * @return {*} 1 / 0
 */
status  FindEpi(char *result ,ResultTB *ptable , QMminterms *index , int size ) 
{   
    ResultTB *ptr_tb = NULL , *ptmp_tb = NULL  , *pfree_tb = NULL ;
    QMminterms *pterms = index ;
    int counter = 0 ;

    while (pterms->next)
    {   
        ptr_tb = ptable ;
        while(ptr_tb->next)
        {
            if (1 == ptr_tb->next->pTBvalue[pterms->next->data.value])
            {
                ++counter ;
                if (counter > 1)   break ; 
                ptmp_tb = ptr_tb ;
            } 
            
            ptr_tb = ptr_tb->next ;
        }

        if (1 == counter)        // 找到EPI
        {      
               pfree_tb = ptmp_tb->next ;

               strcat(result,"+") ;                  // 拷贝结果
               strcat(result,pfree_tb->result) ;

               /* 修正索引，即将出现的EPI从索引中删除 */
               ModifyIndex(index,pfree_tb->pminterms) ;     

               /* 删除EPI的节点 */
               DeleteRTtable(ptmp_tb) ;
            
               pterms = index ;
        }
        else        // 未找到，寻找下一个节点
        {
            pterms = pterms->next ;
        }

        counter = 0 ;       // 计数器清零

    }
    
    return 0 ;

}