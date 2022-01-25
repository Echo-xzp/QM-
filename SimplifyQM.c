/*
 * @Descripttion: 这是一个简化QM表的函数的接口
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-30 20:00:39
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-16 19:42:36
 */

#include  "SimplifyQM.h"

/**
 * @name: SimplifyQM
 * @description: 合并QM组，出现PI时将其储存在表头指针的组数链表中；成功简化返回1，已经不能简化返回0
 * @param {QMtable} *ptable
 * @param {int} size
 * @return {*} 简化的次数
 */
int  SimplifyQM(QMtable *ptable , int size)
{
    QMtable *ptr_table = ptable->next , *ptmp_table = NULL ;
    QMgroup *ptr_group = NULL , *ptmp_group = NULL , *pfree_group = NULL ;
    QMtableline *ptr_line = NULL ;
    int pos = 0 , count = 0 ;             
    
    while (ptr_table->next)
    {
        ptmp_table = ptr_table->next ;
        ptr_group = ptr_table->group ;
        while (ptr_group)
        {   
            ptmp_group = ptmp_table->group ;
            while (ptmp_group)
            {   
                // 检查变量值是否只有一处不同
                if (isVarOneDiff(ptr_group->line->variables,ptmp_group->line->variables,size,&pos))
                {   
                   // 拷贝该行数据
                   CopyLine(&ptr_line,ptr_group->line,size) ;
                   
                   // 修改拷贝行数据
                   ModifyLine(ptr_line,ptmp_group->line->pterms,pos) ;

                   // 将拷贝行最小项组链表排序
                   SortMinterms(ptr_line->pterms) ;

                   // 检查是否之前已经存在与拷贝行一样的行
                   if (CheckLineSame(ptr_table->group,ptr_group, ptr_line ,size))
                   {    
                       ptr_group->line->flag = 1 ;                  // 更改标记，说明该项已被使用，不会是PI
                       ptmp_group->line->flag = 1 ;

                       FreeLine(&ptr_line) ;                         // 该拷贝行无用，直接释放
                   }
                   else
                   {   
                       TablePushFront(ptr_table,ptr_line) ;          // 拷贝行有效，使用头插法插入该组 

                       ptr_group->line->flag = 1 ;                  // 更改标记，说明该项已被使用，不会是PI
                       ptmp_group->line->flag = 1 ;

                       ++ count ;                                  // 记录合并的次数
                   }
                }
                ptmp_group = ptmp_group->next ;
            }
            
            pfree_group = ptr_group ;   
            ptr_group = ptr_group->next ;

            // 根据标记值确定该项是否为 PI，不是删除该节点，否则将该节点从链表中取出，存在表头组中
            if ( 1 == pfree_group->line->flag || isRandom(pfree_group->line))
            {
                DeleteLine(ptr_table,pfree_group,Delete) ;      //删除
                                    
            }
            else
            {   
                DeleteLine(ptr_table,pfree_group,NoDelete) ;    // 提取
                TablePushFront(ptable,pfree_group->line) ;      // 头插法
                free(pfree_group) ;                             // 释放
            }
            
        }

        ptr_table = ptr_table->next ;
          
    }
    
    // 单独处理QM表最后一行，处理与上类似
    ptr_group = ptr_table->group ;
    while (ptr_group)
    {   
        pfree_group = ptr_group ;
        ptr_group = ptr_group->next ;
        // 根据标记值确定该项是否为 PI，不是删除该节点，否则将该节点从链表中取出，存在表头组中
        if ( 1 == pfree_group->line->flag || isRandom(pfree_group->line))
        {
            DeleteLine(ptr_table,pfree_group,Delete) ;                    
        }
        else
        {   
            DeleteLine(ptr_table,pfree_group,NoDelete) ;
            TablePushFront(ptable,pfree_group->line) ;
            free(pfree_group) ;
        }    
    }
    
    DeleteTable(&ptable) ;      //  删除QM表中的空数据节点

    return count ;              // 返回化简次数，最简时返回0(FALSE)

}