#include  "QM.h"

/**
 * @name: CopyLine
 * @description: 拷贝QM表中一行
 * @param {QMtableline} *pcoy  [NUll] 拷贝生成副本
 * @param {QMtableline} *copied [行地址]      被拷贝的源QM行
 * @return {*} [函数状态值] 1 / 0
 */
status CopyLine(QMtableline **pcopy, QMtableline *pcopied, int size) //添加了一个形参 size ,为获取变量的个数
{   
    int i = 0 , *pVar = NULL ;
    QMminterms *ptr = NULL, *temp = NULL, *phead = NULL ;
    QMminterms *pterms = pcopied->pterms ;
    //*phead 为 QMminterms 链表的表头，之后会删除
    phead = (QMminterms *)calloc(1, sizeof(QMminterms));
    if (!phead)
    {
        printf("OVERFOLW!！！\n");
        exit(-1);
    }

    temp = phead;

    //此循环为复制 *copied 里的 QMminterms 链表的数据
    while (pterms)
    {   
        ptr = (QMminterms *)calloc(1, sizeof(QMminterms));
        if (!ptr)
        {
            printf("OVERFOLW!！！\n");
            exit(-1);
        }

        ptr->data.value = pterms->data.value;
        ptr->data.flag = pterms->data.flag;
        ptr->next = NULL; //将该链表表尾 next 置空

        temp->next = ptr; //这里可能出现BUG，因为 temp->next 为空
        temp = ptr;

        pterms = pterms->next;
    }

    temp = phead ;
    phead = phead->next;
    free(temp); //删除表头 *phead

    pVar = (int*)calloc(size,sizeof(int)) ;
    for (i = 0; i < size; ++i)
    {
        pVar[i] = pcopied->variables[i];
    }

    *pcopy = (QMtableline *)calloc(1, sizeof(QMtableline));
    if (!*pcopy)
    {
        printf("OVERFOLW!！！\n");
        exit(-1);
    }

    (*pcopy)->flag = 0 ;
    (*pcopy)->variables = pVar ;
    (*pcopy)->pterms = phead;
    (*pcopy)->couts = pcopied->couts;

    return 0;
}