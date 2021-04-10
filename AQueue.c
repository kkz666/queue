#include"AQueue.h"
#include<stdio.h>
void InitAQueue(AQueue* Q)
{
    int i;
    Q->length = MAXQUEUE;
    for (i = 0; i < MAXQUEUE; i++)
        //不知道用户想放入的数据类型大小，所以给个20
        Q->data[i] = (void*)malloc(21);
    Q->front = Q->rear = 0;
}
void DestoryAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
    for (int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
    Q->data[0] = NULL;
}
Status IsFullAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
        return FALSE;
    if (LengthAQueue(Q) == MAXQUEUE - 1)
    {
        return TRUE;
    }
    else
        return FALSE;
}
Status IsEmptyAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}
Status GetHeadAQueue(AQueue* Q, void* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！没有队头！\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 20);
    return TRUE;
}
int LengthAQueue(AQueue* Q)
{
    return (Q->rear - Q->front + Q->length) % Q->length;
}

Status EnAQueue(AQueue* Q, void* data)
{
    if (IsFullAQueue(Q))
    {
        printf("队列满了！不能再入队了！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        memcpy(Q->data[Q->front], data, 20);
        Q->rear = (Q->rear + 1) % Q->length;
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 20);
    Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}
Status DeAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列是空的！出不了队！\n");
        return FALSE;
    }
    Q->front = (Q->front + 1) % Q->length;
    return TRUE;
}

void ClearAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列已经是空的了！\n");
        return;
    }
    Q->front = Q->rear = 0;
}
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q, int typeData))
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("队列里面什么都没有!\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->data[Q->front + i], Q->type[Q->front + i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

void APrint(void* q, int typeData)
{
    if (typeData == 3)
        printf("--> %.2lf", *(double*)q);
    if (typeData == 2)
        printf("--> %c", *(char*)q);
    if (typeData == 1)
        printf("--> %d ", *(int*)q);
    if (typeData == 4)
        printf("--> %s ", (char*)q);
}
Status inputCheck(int* val)  //检查输入
{
    char n[50] = { 0 };
    int i = 0, flag = 0, minus = 0;
    // 用户开始输入
    scanf("%s", n);
    getchar();
    for (int j = 0; n[j] != '\0'; j++)
    {
        // 检测是否正确输入符号位
        if (j == 0 && (n[j] == '-' || n[j] == '+'))
        {
            continue;
        }
        if (n[j] < '0' || n[j] > '9')
            flag = 1;
    }
    if (flag == 1)
    {
        // flag==1 则说明用户的输入发生了错误
        return FALSE;
    }
    int temp = 0, simple = 1;
    for (int j = 0; n[j] != '\0'; j++)
    {
        if (n[j] == '-')
        {
            // simple用于检测用户是否输入了负数
            simple = -1;
            continue;
        }
        else if (n[j] == '+')
        {
            continue;
        }
        temp = temp * 10 + (n[j] - 48);
    }

    *val = temp * simple;
    return TRUE;
}

