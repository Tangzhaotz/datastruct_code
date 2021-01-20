/*
���е��㷨--ѭ������ 
2021.1.20 
*/ 


#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE;

//��������
void init_queue(QUEUE *pQ);
bool full_queue(QUEUE * pQ);
bool en_queue(QUEUE *pQ,int val);
void travers_queue(QUEUE * pQ);
bool out_queue(QUEUE *pQ,int *pVal);


int main()
{
	QUEUE Q;
	int val;
	
	init_queue(&Q);
	
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	en_queue(&Q,8);
	
	travers_queue(&Q);
	
	if(out_queue(&Q,&val))
	{
		printf("���Գɹ������ӵ�Ԫ��Ϊ%d\n",val);
	}
	else
	{
		printf("����ʧ��\n");
	}
	
	travers_queue(&Q);
	
	
	return 0;
}


//��ʼ������
void init_queue(QUEUE *pQ)
{
	pQ->pBase=(int *)malloc(sizeof(int) * 6);
	pQ->front=0;
	pQ->rear=0; 
}

bool full_queue(QUEUE * pQ)
{
	if((pQ->rear +1) % 6 == pQ->front)  //�ж�ѭ�������Ƿ��� 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool en_queue(QUEUE *pQ,int val)
{
	if(full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear]=val;  //��������
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}

//�ж϶����Ƿ�Ϊ�� 

//��������
void travers_queue(QUEUE * pQ) 
{
	
	int i = pQ->front;
	while(i != pQ->rear)
	{
		printf("%d ",pQ->pBase[i]);
		i = (i + 1) % 6;	
	}
	printf("\n");
}


//�ж϶��п�
bool empty_queue(QUEUE *pQ)
{
	if(pQ->front == pQ->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
 } 

//����
bool out_queue(QUEUE *pQ,int *pVal)
{
	if(empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front=(pQ->front+1) % 6;
		
		return true;
	}
} 
