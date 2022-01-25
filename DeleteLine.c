/*
 * @Descripttion: 
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-22 21:38:24
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-16 19:04:09
 */
/*
* File name :DeleteLine .c
* Author :Li Zhaofeng
* Date :2021/10/30
*/

#include  "QM.h"

/**
 * @name: Delete
 * @description: 释放节点
 * @param {QMgroup} *pgrpup
 * @return {*}
 */
status Delete(QMgroup *pgrpup)
{
    FreeLine(&(pgrpup->line)) ;
    free(pgrpup) ;
    return 0 ;
}

/**
 * @name: NoDelete
 * @description: 不删除，只是把节点从链表中取出
 * @param {QMgroup} *pgroup
 * @return {*}
 */
status NoDelete(QMgroup *pgroup)
{
    return 0 ;
}

/*
* input parameter : two poiners
* out parameter : 0
* Modification record :nothing
* Description : Deleting a target node.
* others : nothing
*/ 
status  DeleteLine(QMtable *head , QMgroup *pos , status (*pfunc)(QMgroup*))
{
	QMgroup *ptr = head->group ;
	QMgroup *new_head = NULL ;

	new_head = (QMgroup *)malloc(sizeof(QMgroup)) ;
	if (!new_head)
	{
		printf("OVERFOLW!！！\n");
        exit(-1);
	}
	new_head->line = NULL ;
	new_head->next = ptr ;
	ptr = new_head ;
	 
	while(ptr -> next != pos)
	{
		ptr = ptr->next ;
	}
	
	ptr->next = pos->next ;

	pfunc(pos) ;

	head->group = new_head->next ;
	free(new_head) ;

	return 0 ;

}
