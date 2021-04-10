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
	printf("是否创建一个队列------1创建/0退出\n");
	int n = 0;
	printf("请输入您想执行的操作:");
	while (inputCheck(&n) == FALSE)
	{
		printf("输入错误！请重新输入:");
	}
	if (n != 0 && n != 1) {
		printf("\n错误输入-----结束");
	}
	if (n == 1) {
		InitAQueue(Q);
	}
	if (n == 0) {
		free(Q);
		return 0;
	}
	while (q != 9) {
		printf("选项:\n");
		printf("1.入队\n");
		printf("2.出队\n");
		printf("3.判断队列是否满\n");
		printf("4.判断队列是否空\n");
		printf("5.查看队头元素\n");
		printf("6.获取队列长度\n");
		printf("7.清空队列\n");
		printf("8.遍历队列\n");
		printf("9.退出\n");
		printf("请输入您想执行的操作:");
		while (inputCheck(&q) == FALSE)
		{
			printf("输入错误！请重新输入:");
		}
		switch (q) {
		case 1:
			printf("你想入队哪种类型？:\n");
			printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
			scanf("%d", &t);
			while (t < 1 || t>4)
			{
				printf("应输入在[1,4]之间的整数！\n请重输：");
				scanf("%d", &t);
			}
			printf("想入队的数据 :");
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
				printf("最大长度为20哦！\n");
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
				printf("\n队列已满");
			}
			else printf("\n队列未满");
			break;
		case 4:
			if (IsEmptyAQueue(Q) == TRUE) {
				printf("\n队列为空");
			}
			else printf("\n队列不为空");
				break;
		case 5:GetHeadAQueue(Q, num);
			switch (t) {
			case 1:printf("队头的整型为:%d", *(int*)num); break;
			case 2:printf("队头的字符型为:%c", *(char*)num); break;
			case 3:printf("队头的浮点型为:%lld", *(double*)num); break;
			case 4:printf("队头的字符串为:%s", *(char*)num); break;
			}break;
		case 6:printf("\n队列的长度为%d\n",LengthAQueue(Q)); break;
		case 7:ClearAQueue(Q); break;
		case 8:TraverseAQueue(Q, APrint); break;
		}
	}
	DestoryAQueue(Q);
	return 0;
}