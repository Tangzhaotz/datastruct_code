/*
ջ��
2021.1.19 
*/

/* 
#include<stdio.h>
#include<malloc.h>

void f(int k)
{
	int m;
	double *q = (double *) malloc(200);
}

int main()
{
	int i =10;
	int *p = (int *)malloc(100);  //��̬�����ڴ� 
	
	return 0;
 }
 
 */
 
 
 
 //ջ�ĸ��ֲ���
 #include<stdio.h>
 #include<malloc.h>
 #include<stdlib.h>
 #include<stdbool.h>
 

//���������ʽ 
typedef struct Node
{
	int data;
	struct Node * Next;
	
 }NODE,* PNODE;
 
//����ջ�Ľ��
typedef struct stack
{
	PNODE pTop;  //ջ��ָ��
	PNODE pBottom;  //ջ��ָ�� 
}STACK,*PSTACK; 


//����������
void init(PSTACK);  //�������ջ��ָ��
void push(PSTACK,int);  //ѹջ
void traverse(PSTACK);  //����ջ
bool pop(PSTACK,int *);  //��ջ
void clear(PSTACK pS);  //���ջ 


int main()
{
	STACK S;  //�ȼ���struct stack S;
	int val;
	
	//��ʼ��ջ��Ŀ������һ����ջ
	init(&S);
	
	//ѹջ 
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	
	//����ջ
	traverse(&S);
	
	//���ջ
	//clear(&S);
	
	//��ջ
	if(pop(&S,&val))
	{
		printf("��ջ�ɹ�����ջ��Ԫ����%d\n",val);	
	}
	else
	{
		printf("��ջʧ��\n");
	}
	
	traverse(&S);
	
	return 0;
		
}

//1����ʼ��ջ
void init(PSTACK pS)
{
	//�ȷ���һ��ջ�����
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;  //ջ����ջβָ�붼��ͬʱָ����һ�����
		pS->pTop->Next=NULL;  //��Ϊ��û�в������ݣ����������������ָ��ָ��� 
	}	 
} 


//2����ջ����
void push(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));  //������ջ��Ԫ������һ�����
	pNew->data=val;//������������ֵ
	pNew->Next=pS->pTop;  //��������ӵ�ջ��ָ���λ�á�
	pS->pTop=pNew;//�ٽ�ջ��ָ���ƶ����²����Ԫ�ؽ��
	
	return; 
}

//3������ջ
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;  //�趨һ��ָ��ָ��ջ�����
	printf("ջ�е�ǰ��Ԫ���У�\n"); 
	while(p != pS->pBottom)
	{
		printf("%d  ",p->data);
		p= p->Next;
	}
	printf("\n");
	
	return;
}


//4���ж�ջ�Ƿ�Ϊ��
bool empty(PSTACK pS)
{
	if(pS->pTop==pS->pBottom)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

//5����ջ
bool pop(PSTACK pS,int *pVal)
{
	if(empty(pS))
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;  //����Ҫ��ջ��Ԫ�ص�ֵ
		pS->pTop=r->Next;
		free(r);
		r = NULL;		
	}
	return true;
}

//6�����ջ
void clear(PSTACK pS)
{
	if(empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;  //ָ��pָ��ջ��Ԫ��
		PNODE q = p->Next;  //qָ��p����һ���
		while(p != pS->pBottom)
		{
			q=p->Next;
			free(p);
			p=q;	
		}
		pS->pTop=pS->pBottom;  //���ջ��ָ���ջ��ָ��ָ��ͬһ���	
	}	
} 







































