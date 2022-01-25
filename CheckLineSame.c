/*
 * @Description: 
 * @Author: Xiao ZhiPeng
 * @Interface: 
 * @Date: 2021-10-22 22:28:10
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-06 11:49:25
 */

#include "QM.h"

/**
 * @name: CheckLineSame
 * @description:检查QM组中从头[head]到被比较节点[pos]是否存在相同的行,相同返回1，不同返回0
 * @param {QMgroup} *head   当前QM组的首节点
 * @param {QMgroup} *pos    被检查的节点
 * @return {*} 1 / 0
 */
bool CheckLineSame(QMgroup *begin, QMgroup *end, QMtableline *pline , int size) //添加了一个形参 size ,为获取变量的个数
{
    int i = 0 , count = 0 ;

    if ( begin == end ) //判断两行的组数是否相同
    {
        return 0 ;
    }
    else
    { 
        if (begin->line->couts == end->line->couts)
        {
            while (begin != end)
            {
                for (i = 0; i < size; ++i) //psize为变量个数
                {
                    if (begin->line->variables[i] == pline->variables[i]) //判断两行的变量值variables是否不同，若不同，则返回0
                    {
                        ++ count ;
                    }
                }
                if (count == size )
                {
                    return 1 ;
                }
                
                begin = begin->next;
                count = 0 ;
            }
            return 0; //两行变量值中没有不同，返回1

        }

        else //两行组数不同，输出“这两个组数不同”，返回0
        {
            return 0;
        }
    }
}