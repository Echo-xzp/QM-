/*
 * @Descripttion:检查该行是否为随意项 
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-11-06 12:17:12
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-06 13:40:33
 */

#include  "QM.h"

bool  isRandom(QMtableline *pline) 
{
    QMminterms  *pterms = pline->pterms ;

    while (pterms)
    {
        if (pterms->data.flag == 0)
        {
            return 0 ;
        }
        pterms = pterms->next ;
    }
    
    return 1 ; 

}