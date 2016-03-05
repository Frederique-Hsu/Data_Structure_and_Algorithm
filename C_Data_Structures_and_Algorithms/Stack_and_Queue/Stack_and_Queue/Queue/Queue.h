/*****************************************************************************************************
 * File name        : Queue.h
 * Description      : Define the Queue structure and declare the operation functions prototype.
 * Creator          : Frederick Hsu
 * Creation date    : Sat.  April 18, 2015
 * Copyright(C)     2015    All rights reserved.
 *
 *****************************************************************************************************/


#ifndef QUEUE_H
#define QUEUE_H

    #include "../general.h"

    /*----------------隊列的順序存儲表示-------------------*/
    typedef int QueueElemType;

    typedef struct Queue
    {
        QueueElemType *front;
        QueueElemType *rear;
        int queue_actual_len;
        int queue_total_size;
    }
    Queue,  *PtrQueue;


    /*----------------单链队列 ： 隊列的链式存储结构-------------------*/
    typedef int QElemType;

    typedef struct QNode
    {
        QElemType data;
        struct QNode *next;
    }
    QNode,  *QueuePtr;

    typedef struct LinkQueue
    {
        QueuePtr front;     // 队列头指针
        QueuePtr rear;      // 队列尾指针
    }
    LinkQueue,  *PtrLinkQueue;

    Status InitQueue(LinkQueue *Q);
    Status CreateQueue(LinkQueue *Q, int len);
    Status DestroyQueue(LinkQueue *Q);
    void DisplayQueue(LinkQueue Q);
    Status ClearQueue(LinkQueue *Q);
    Status IsQueueEmpty(LinkQueue Q);
    int QueueLength(LinkQueue Q);
    Status GetQueueHead(LinkQueue Q, QElemType *e);
    Status GetQueueTail(LinkQueue Q, QElemType *e);
    Status EnQueue(LinkQueue *Q, QElemType e);
    Status DeQueue(LinkQueue *Q, QElemType *e);
    Status QueueTraverse(LinkQueue Q, Status (*visit)(QElemType e));


    /*----------------循环队列 ： 隊列的顺序存储结构-------------------*/
    #define MAXQSIZE    100     // 循环队列的最大队列长度

    typedef struct SqQueue
    {
        QElemType *base;    // 初始化的动态分配存储空间
        int front;          // 头指针，若队列不为空，指向队列头元素
        int rear;           // 尾指针，若队列不为空，指向队列尾元素的下一个位置
    }
    SqQueue,    *PtrSqQueue;

    Status InitSqQueue(SqQueue *Q);
    Status DestroySqQueue(SqQueue *Q);
    int SqQueueLength(SqQueue Q);
    Status EnSqQueue(SqQueue *Q);
    Status DeSqQueue(SqQueue *Q);
    void DisplaySqQueue(SqQueue Q);


#endif  /*  QUEUE_H  */