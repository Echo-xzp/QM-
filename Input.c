/*
 * @Descripttion:这是一个让用户输入关于QM法相关数据的函数的接口
 * @Author: Xiao ZhiPeng
 * @version: 1.0
 * @Interface: 
 * @Date: 2021-10-14 21:24:41
 * @LastEditors: xiao zhipeng
 * @LastEditTime: 2021-11-21 12:50:30
 */

#include  <math.h>

#include  "Input.h"

/**
 * @name: Input
 * @description: 让用户输入数据，确定变量数目，构建最小项组链表 ，
 * @param {int} *psize   指向变量数的指针
 * @param {QMgminterms} **pphead   指向最小项组表头的指针地址
 * @return {*} 1 / 0
 */
int Input(int *psize , QMminterms **pphead)
{
    int temp = 0 ;
    char ch = '\0' ;
    QMminterms *ptr = NULL ;

    // 初始化最小项组链表的表头
    *pphead = (QMminterms*)malloc(sizeof(QMminterms)) ;
    if (!pphead)
    {
        printf("OVERFLOW!\n") ;
        return ERROR ;
    }
    ptr = (*pphead) ;
    ptr->data.value = -1 ;
    ptr->data.flag = -1 ;
    ptr->next = NULL ;

    // 输入变量数目
    printf("Please input the couts about the variables :\n") ;
    scanf("%d",psize) ;
    fflush(stdin) ;     //清空缓冲区，避免错误输入影响后续输入
    
    // 输入标准最小项
    printf("Please input the Minumn terms :\n") ;
    while(scanf("%d",&temp))
    {   
        if (temp >= pow(2,*psize))
        {
            printf("The numbers you inputed are bigger than the expected!\n") ;
            system("pause") ;
            exit(1) ;
        }
        
        // 将输入保存到链表中
        ptr->next = (QMminterms*) malloc(sizeof(QMminterms)) ;
        ptr = ptr->next ; 
        ptr->data.value = temp ;
        ptr->data.flag = 0 ;

        // 检查数字后面是否为换行，结束输入
        if(getchar() == '\n')
        {
            break ;
        }
    }
    fflush(stdin) ;

    // 输入任意项
    printf("Have Random items to input(YES : y / NO : n) ? \n") ;
    ch = getchar() ;

    if(ch == 'y' || ch == 'Y')
    {
        printf("Please input the Anyitems :\n") ;
        while(scanf("%d",&temp))
        {   
            ptr->next = (QMminterms*) malloc(sizeof(QMminterms)) ;
            ptr = ptr->next ;
            ptr->data.value = temp ;
            ptr->data.flag = 1 ;

            if (getchar() == '\n')
            {
                break ;
            }
            
        }
        ptr->next = NULL ;
        return 1 ;

    } 

    else if (ch == 'n' || ch == 'N')
    {   
        ptr->next = NULL ;
        return 0 ;
    }
    
    else
    {
        printf("ERRO INPUT！！ENDING THE PROGRAM!\n") ;
        system("pause") ;
        exit(1) ;
    }

}
