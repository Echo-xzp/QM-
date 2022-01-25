/*
 * @Descripttion: 这是一个实现 QM 化简表储存的数据结构接口
 * @Author: Xiao ZhiPeng
 * @version: 1.0 
 * @Date: 2021-10-10 16:25:16
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-16 19:03:15
 */

#ifndef __QM_H__
#define __QM_H__

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define status int
#define bool int

// 定义最小项
typedef struct QMMINTERM
{
    int value; // 最小项值
    int flag;  // 标记值，任意项为 1 ，标准项为 0

} QMminterm;

// 定义最小项组
typedef struct QMMINTERMS
{
    QMminterm data; // 使用链表储存
    struct QMMINTERMS *next;

} QMminterms;

// 定义组中的每一行
typedef struct QMTABLELINE
{
    QMminterms *pterms; // 最小项组
    int *variables;     // 变量值
    int couts;          // 组数，即 “1” 的数目
    int flag;           // 标记该组是否参与合并

} QMtableline;

// 定义每一组
typedef struct QMGROUP
{
    QMtableline *line; // 使用链表将每一行连接在一起，构成一组
    struct QMGROUP *next;

} QMgroup;

// 定义 QM 表，使用邻接表储存
typedef struct QMTABLE
{
    int couts;            // 组数，即 “1” 的数目
    QMgroup *group;       //指向组数链表
    struct QMTABLE *next; //下一个节点

} QMtable;

/*****************************************************************/

status InitLine(QMtableline **ppline, int size, QMminterm mintern);             // 初始化QM表中的一行数据

status InitTable(QMtable *ptable, int size, const QMminterms *phead);           // 初始化整个QM表

status TablePushFront(QMtable *ptable, QMtableline *pline);                     // 从QM头添加节点

status SortMinterms(QMminterms *pterms) ;                                       // 对最小项组进行排序

status DeleteTable(QMtable **pptable);                                          // 清空表头中的数据

status FreeMinterms(QMminterms **ppminters);                                     // 释放最小项组链表

status DeleteGroup(QMgroup **ppgroup);                                          // 释放行组链表

status FreeLine(QMtableline **ppline);                                          // 释放行内存

status DeleteLine(QMtable *head, QMgroup *pos, status (*pfunc)(QMgroup *));     // 删除QM组链表中的目标节点
status NoDelete(QMgroup *pgroup) ;
status Delete(QMgroup *pgrpup) ;


status CopyLine(QMtableline **pcopy, QMtableline *copied, int size);            // 拷贝QM的一行

bool isVarOneDiff(int *pcompare, int *pcompared, int size, int *pos);           // 判断变量数组中值是否只有一处不同

status ModifyLine(QMtableline *pline, QMminterms *head, int pos);               // 修改QM表行数据，包括最小项插入，变量值划杠

bool CheckLineSame(QMgroup *begin, QMgroup *end, QMtableline *pline, int size); // 检查QM组中从头到被比较节点是否存在相同的行

status GroupInsert(QMgroup *ppos, QMgroup *pinsert);                            // 在QM组链表中的节点的后面插入目标节点

bool isRandom(QMtableline *plinie);                                             // 检查该行是否为随意项

#endif
