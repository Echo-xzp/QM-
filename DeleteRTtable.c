/*
 * @Description: 这是一个删除质蕴表中目标节点之后的节点的函数
 * @Author: Xiao ZhiPeng
 * @Version: 1.0
 * @InterFace: 
 * @Date: 2021-11-13 17:26:10
 * @LastEditors: Xiao ZhiPeng
 * @LastEditTime: 2021-11-13 17:39:28
 */

#include  "ResultTB.h"

status  DeleteRTtable(ResultTB *pos) 
{
    ResultTB *ptemp = pos->next ;
    
    pos->next = ptemp->next ;

    FreeMinterms(&(ptemp->pminterms)) ;
    free(ptemp->pTBvalue) ;
    free(ptemp->result) ;
    free(ptemp) ;

    return 0 ;

}