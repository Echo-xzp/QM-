/*
 * @Description: 
 * @Author: Peng Jun
 * @Interface: 
 * @Date: 2021-10-22 22:28:10
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-06 11:19:00
 */
#include "QM.h"

/**
 * @name: isVarOneDiff
 * @description: 判断变量数组中值是否只有一处不同  ，一处不同修改pos保存不同处的位置，
 *               同时返回1 ；多处不同返回0，不修改pos ; 不存在相同的情况
 * @param {int} *pcompare   比较者
 * @param {int} *pcompared  被比较者
 * @param {int} size        内存长度/数组大小
 * @param {int} *pos        数组不同的位置        
 * @return {*} [bool]  1 / 0
 */
bool isVarOneDiff(int *pcompare, int *pcompared, int size, int *pos)
{
    int i = 0, counters = 0, record = 0;
    int sum = 0 ;

    for (i = 0; i < size; ++i)
    {   
        if (pcompare[i] != pcompared[i] )
        {
            ++counters;
            record = i;
        }
    }
    sum = pcompare[record] + pcompared[record] ;
    if (counters == 1 && sum == 1)
    {
        *pos = record;
        return 1;
    }
    else
    {
        return 0;
    }
}
