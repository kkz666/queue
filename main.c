#include"AQueue.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int t;
int q;
void* num = NULL;
void (*foo)(void* q, int typeData);
int main(void) {
	AQueue* Q = (AQueue*)malloc(sizeof(AQueue));
	printf("�Ƿ񴴽�һ������------1����/0�˳�\n");
	int n = 0;
	printf("����������ִ�еĲ���:");
	while (inputCheck(&n) == FALSE)
	{
		printf("�����������������:");
	}
	if (n != 0 && n != 1) {
		printf("\n��������-----����");
	}
	if (n == 1) {
		InitAQueue(Q);
	}
	if (n == 0) {
		free(Q);
		return 0;
	}
	while (q != 9) {
		printf("ѡ��:\n");
		printf("1.���\n");
		printf("2.����\n");
		printf("3.�ж϶����Ƿ���\n");
		printf("4.�ж϶����Ƿ��\n");
		printf("5.�鿴��ͷԪ��\n");
		printf("6.��ȡ���г���\n");
		printf("7.��ն���\n");
		printf("8.��������\n");
		printf("9.�˳�\n");
		printf("����������ִ�еĲ���:");
		while (inputCheck(&q) == FALSE)
		{
			printf("�����������������:");
		}
		switch (q) {
		case 1:
			printf("��������������ͣ�:\n");
			printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
			scanf("%d", &t);
			while (t < 1 || t>4)
			{
				printf("Ӧ������[1,4]֮���������\n�����䣺");
				scanf("%d", &t);
			}
			printf("����ӵ����� :");
			switch (t)
			{
			case 1: {
				int a;
				scanf("%d", &a);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &a);
				break;
			}
			case 2: {
				char a;
				getchar();
				scanf("%c", &a);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &a);
				break;
			}
			case 3: {
				double a;
				scanf("%lf", &a);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &a);
				break;
			}
			case 4: {
				char a[20];
				printf("��󳤶�Ϊ20Ŷ��\n");
				scanf("%s", a);
				Q->type[Q->rear] = t;
				EnAQueue(Q, a);
				break;
			}
			}break;
		case 2:
			DeAQueue(Q); break;
		case 3:
			if (IsFullAQueue(Q) == TRUE) {
				printf("\n��������");
			}
			else printf("\n����δ��");
			break;
		case 4:
			if (IsEmptyAQueue(Q) == TRUE) {
				printf("\n����Ϊ��");
			}
			else printf("\n���в�Ϊ��");
				break;
		case 5:GetHeadAQueue(Q, num);
			switch (t) {
			case 1:printf("��ͷ������Ϊ:%d", *(int*)num); break;
			case 2:printf("��ͷ���ַ���Ϊ:%c", *(char*)num); break;
			case 3:printf("��ͷ�ĸ�����Ϊ:%lld", *(double*)num); break;
			case 4:printf("��ͷ���ַ���Ϊ:%s", *(char*)num); break;
			}break;
		case 6:printf("\n���еĳ���Ϊ%d\n",LengthAQueue(Q)); break;
		case 7:ClearAQueue(Q); break;
		case 8:TraverseAQueue(Q, APrint); break;
		}
	}
	DestoryAQueue(Q);
	return 0;
}