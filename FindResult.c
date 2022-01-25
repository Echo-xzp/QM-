/*
 * @Description: 这是一个从质蕴表中找出Epi与Pi构成答案的函数接口
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @Date: 2021-11-13 18:04:48
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 21:10:40
 */

#include  "FindResult.h"

/**
 * @name: FindResult
 * @description:检查QM组中从头[head]到被比较节点[pos]是否存在相同的行,相同返回1，不同返回0
 * @param {char} *result   指向结果字符串的指针
 * @param {ResulTB} *RTtable    质蕴表
 * @param {QMminterms} *phead    索引
 * @param {int}  size      变量数
 * @return {*} 1 / 0
 */
status  FindResult(char *result , ResultTB *RTtable , QMminterms *phead , int size) 
{
    /* 根据最小项组生成索引 */
    CreateIndex(phead) ;

    PrintRTtable(RTtable,phead) ;

    /* 寻找EPI */
    FindEpi(result,RTtable,phead,size) ;
    
    PrintRTtable(RTtable,phead) ;

    /* 修正质蕴表 */
    ModifyRTtable(RTtable,phead) ;
    
    PrintRTtable(RTtable,phead) ;

    /* 寻找PI */
    FindEpi(result,RTtable,phead,size) ;

    result[0] = ' ' ;     // 结果字符串的首字符为“+”，修改为空格

    return 0 ;
    
}