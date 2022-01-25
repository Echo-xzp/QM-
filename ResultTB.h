/*
 * @Description: 这是一个关于QM法质蕴表的数据结构的接口
 * @Version: 1.0
 * @InterFace: 
 * @Author: Xiao ZhiPeng
 * @Date: 2021-11-08 19:34:22
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-15 21:11:07
 */

#ifndef __RESULTTB_H__
#define __RESULTTB_H__

#include "QM.h"


typedef struct RESULTTB
{
        char *result ;
        QMminterms *pminterms ;
        int  *pTBvalue ;  
        struct RESULTTB *next;
} ResultTB , *TBNode ;

status  InitResultTB(ResultTB *presultTB , QMgroup *pgroup , int size) ;

status  CreateIndex(QMminterms *head) ;

status  ModifyIndex(QMminterms *Index , QMminterms *pterms) ;

status  ModifyRTtable(ResultTB *ptable , QMminterms *index) ;

status  FindEpi(char *result ,ResultTB *ptable , QMminterms *index , int size ) ;

status  DeleteRTtable(ResultTB *pos) ;

status  PrintRTtable(ResultTB *RTtable , QMminterms *index) ;

#endif