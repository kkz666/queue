#include"LQueue.h"
void InitAQueue(LQueue* Q)
{
    int i;
    Q = (LQueue*)malloc(sizeof(LQueue));
    Q->length = 0;
    Q->front = Q->rear = 0;
}
Status EnLQueue(LQueue* Q, void* data) 
{
    Node* p;
    if (p = (Node*)malloc(sizeof(Node))) {
        p->data = data;
        p->next = 0;
        if (Q->front == 0 && Q->rear == 0) {
            Q->front = p;
            Q->rear = p;
        }
        else {
            Q->front = p;
        }
        Q->length++;
        return TRUE;
    }
    else return FALSE;
}
void DestoryLQueue(LQueue* Q) {
    Node* p = Q->rear;
    Node* q;
    if(p)
     q = p->next;
    while (p != Q->front) {
        free(p);
        //q = q->next;
        p = q;
        q = q->next;
    }
    free(Q);
}
Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == 0 && Q->rear == 0)return TRUE;
    else return FALSE;
}
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (Q->front == 0 && Q->rear == 0) {
        printf("\n空队列无队首\n");
        return FALSE;
    }
    else {
        e = Q->front;
        return TRUE;
    }
}
int LengthLQueue(LQueue* Q) {
    int number = 0;
    Node* p = Q->front;
    if (Q->front == 0)return 0;
    while (p != Q->rear) {
        p = p->next;
        number++;
    }
    return number;
}
Status DeLQueue(LQueue* Q) {
    Node* p = Q->front;
    Node* q = Q->rear;
    if (p == 0) {
        printf("队列为空");
        return FALSE;
    }
    while (q->next != Q->front)q = q->next;
    free(p);
    Q->front = q;
    return TRUE;
}
void ClearLQueue(LQueue* Q) {
    Node* p = Q->front;
    Node* q = Q->front->next;
    while (p != Q->rear) {
        free(p);
        p = q;
        q = q->next;
    }
}
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (Q->front == 0)return FALSE;
    Node* p = Q->rear;
    while (p != Q->front) {
        (*foo)(p->data);
        p = p->next;
    }
    return TRUE;
}
void LPrint(void* q, int typeData)
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
