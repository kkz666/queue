#include"AQueue.h"
#include<stdio.h>
void InitAQueue(AQueue* Q)
{
    int i;
    Q->length = MAXQUEUE;
    for (i = 0; i < MAXQUEUE; i++)
        //��֪���û��������������ʹ�С�����Ը���20
        Q->data[i] = (void*)malloc(21);
    Q->front = Q->rear = 0;
}
void DestoryAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
    return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}
Status GetHeadAQueue(AQueue* Q, void* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ�û�ж�ͷ��\n");
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
        printf("�������ˣ�����������ˣ�\n");
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
        printf("�����ǿյģ������˶ӣ�\n");
        return FALSE;
    }
    Q->front = (Q->front + 1) % Q->length;
    return TRUE;
}

void ClearAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("�����Ѿ��ǿյ��ˣ�\n");
        return;
    }
    Q->front = Q->rear = 0;
}
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q, int typeData))
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("��������ʲô��û��!\n");
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
Status inputCheck(int* val)  //�������
{
    char n[50] = { 0 };
    int i = 0, flag = 0, minus = 0;
    // �û���ʼ����
    scanf("%s", n);
    getchar();
    for (int j = 0; n[j] != '\0'; j++)
    {
        // ����Ƿ���ȷ�������λ
        if (j == 0 && (n[j] == '-' || n[j] == '+'))
        {
            continue;
        }
        if (n[j] < '0' || n[j] > '9')
            flag = 1;
    }
    if (flag == 1)
    {
        // flag==1 ��˵���û������뷢���˴���
        return FALSE;
    }
    int temp = 0, simple = 1;
    for (int j = 0; n[j] != '\0'; j++)
    {
        if (n[j] == '-')
        {
            // simple���ڼ���û��Ƿ������˸���
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

