#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

//���������е�һ�����
typedef struct Node
{
	int data;  //������
	struct Node * Next;  //ָ����ָ��һ���뵱ǰ����������͵Ľ��	
} NODE,*PNODE;  //NODE�ȼ���struct Node,PNODE�ȼ���struct Node *


//��������
PNODE create_list(void);  //��������
void traverse_list(PNODE pHead);  //��������
bool is_empty(PNODE pHead);  //�ж������Ƿ�Ϊ��
int length_list(PNODE);
bool insert_list(PNODE,int,int);  //��pHead��ָ������ĵ�pos�����ǰ�����һ���µĽ�㣬�ý���ֵ��val������pos�Ǵ�1��ʼ��
bool delete_list(PNODE,int ,int *);
void sort_list(PNODE);  //������������� 

int main()
{
	PNODE pHead = NULL; //�ȼ���struct Node * pHead = NULL,����һ��ͷ���ָ��NULL
	int val;
	
	pHead = create_list();  //����һ����ѭ�������������������ͷ���ĵ�ַ����pHead	
	
	traverse_list(pHead);  //�������� 
	
	insert_list(pHead,4,33);
	if(delete_list(pHead,4,&val))
	{
		printf("ɾ���ɹ�����ɾ����Ԫ���ǣ�%d\n",val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ���Ҫɾ����Ԫ�ز����ڣ�\n");
	}
	
	traverse_list(pHead);  //�������� 
	
	int len = length_list(pHead);
	printf("����ĳ���Ϊ��%d\n",len);
	
	sort_list(pHead);
	traverse_list(pHead);
	
	if(is_empty(pHead))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����Ϊ��\n");
	}
	
	return 0;
} 


//1����������
PNODE create_list(void)
{
	int len;  //���������Ч�ڵ�ĸ���
	int i;
	int val;  //������ʱ����û�����Ľ���ֵ
	
	//����һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL ==pHead)
	{
		printf("����ʧ�ܣ���ֹ����\n");
		exit(-1);
	}
	PNODE pTail = pHead;  //��������һ��ָ��ָ��ͷ���
	pTail->Next = NULL; 
	
	printf("��������Ҫ���ɵ�������ĸ�����len= ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		printf("�������%d������ֵ��",i+1);
		scanf("%d",&val);
		
		//�������
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL==pNew)
		{
			printf("����ʧ�ܣ�������ֹ\n");
			exit(-1);	
		}
		//�������ɹ�
		pNew->data=val;  //��ֵ�����µĽ�� 
		pTail->Next=pNew;  //ͷ���ָ���½�� 
		pNew->Next=NULL;  //�½��ָ��� 
		pTail = pNew;   //��pTail�ƶ����½�㣬ָ���½�� 
	}
	return pHead;  //����ͷ��� 
}


//2����������
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->Next;  //����һ��ָ��pָ���һ����Ч��㣬��ָ��ͷ������һ�����
	while(NULL != p)
	{
		printf("%d ",p->data);  //��ӡ������ 
		p=p->Next;  //pָ����һ��λ�� 
	}
	printf("\n");
	
	return; 
}

//3���ж������Ƿ�Ϊ��
bool is_empty(PNODE pHead)
{
	if(NULL == pHead->Next)
	{
		return true;
	}
	else
	{
		return false;
	}
} 


//4��������ĳ���
int length_list(PNODE pHead)
{
	PNODE p = pHead->Next;  //����һ��ָ��pָ��ͷ������һ�����
	int len=0;
	
	while(NULL != p)
	{
		++len;
		p=p->Next;	
	}
	
	return len;
}


//5���������������
void sort_list(PNODE pHead)
{
	int i,j,t;
	int len = length_list(pHead);  //������ĳ���
	PNODE p,q;
	
	for(i=0,p=pHead->Next;i<len-1;++i,p=p->Next)
	{
		for(j=i+1,q=p->Next;j<len;++j,q=q->Next)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data=q->data;
				q->data=t;
			}
		}
	}
	return;	
}


//6����pHead��ָ��������pos�����ǰ�����һ���µĽ�㣬�ý���ֵ��val������pos�Ǵ�1��ʼ��
bool insert_list(PNODE pHead,int pos,int val)
{
	int i=0;
	PNODE p = pHead;  //����һ��ָ��ָ��ͷ���
	
	while(NULL != p && i < pos-1)
	{
		p=p->Next;
		++i;
	}
	if(i>pos-1 || NULL == p)
	{
		return false;
	}
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));  //����һ���µĽ��
	if(NULL == pNew)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	pNew->data=val;
	PNODE q = p->Next;  //ָ��qָ��p����һ������λ��
	p->Next=pNew;
	pNew->Next=q;
	
	return true; 
}


//7��ɾ�������Ԫ��
bool delete_list(PNODE pHead,int pos,int *pVal)
{
	int i=0;
	PNODE p =pHead;
	
	while(NULL != p->Next && i < pos-1)
	{
		p=p->Next;
		++i;
	}
	if(i>pos-1 || NULL == p->Next)
	{
		return false;
	}
	
	PNODE q = p->Next;  //qָ��Ҫɾ����Ԫ�صĽ�� 
	*pVal = q->data;
	
	p->Next=p->Next->Next;
	free(q);
	q=NULL;
	
	return true;
} 
