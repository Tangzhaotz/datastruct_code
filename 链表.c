#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

//定义链表中的一个结点
typedef struct Node
{
	int data;  //数据域
	struct Node * Next;  //指针域，指向一个与当前结点数据类型的结点	
} NODE,*PNODE;  //NODE等价于struct Node,PNODE等价于struct Node *


//函数声明
PNODE create_list(void);  //创建链表
void traverse_list(PNODE pHead);  //遍历链表
bool is_empty(PNODE pHead);  //判断链表是否为空
int length_list(PNODE);
bool insert_list(PNODE,int,int);  //在pHead所指向链表的第pos个结点前面插入一个新的结点，该结点的值是val，并且pos是从1开始的
bool delete_list(PNODE,int ,int *);
void sort_list(PNODE);  //对链表进行排序 

int main()
{
	PNODE pHead = NULL; //等价于struct Node * pHead = NULL,生成一个头结点指向NULL
	int val;
	
	pHead = create_list();  //创建一个非循环单链表，并将该链表的头结点的地址赋给pHead	
	
	traverse_list(pHead);  //遍历链表 
	
	insert_list(pHead,4,33);
	if(delete_list(pHead,4,&val))
	{
		printf("删除成功，您删除的元素是：%d\n",val);
	}
	else
	{
		printf("删除失败，您要删除的元素不存在！\n");
	}
	
	traverse_list(pHead);  //遍历链表 
	
	int len = length_list(pHead);
	printf("链表的长度为：%d\n",len);
	
	sort_list(pHead);
	traverse_list(pHead);
	
	if(is_empty(pHead))
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表不为空\n");
	}
	
	return 0;
} 


//1、创建链表
PNODE create_list(void)
{
	int len;  //用来存放有效节点的个数
	int i;
	int val;  //用来临时存放用户输入的结点的值
	
	//分配一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL ==pHead)
	{
		printf("分配失败，终止程序\n");
		exit(-1);
	}
	PNODE pTail = pHead;  //生成另外一个指针指向头结点
	pTail->Next = NULL; 
	
	printf("请输入您要生成的链表结点的个数：len= ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个结点的值：",i+1);
		scanf("%d",&val);
		
		//创建结点
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL==pNew)
		{
			printf("分配失败，程序终止\n");
			exit(-1);	
		}
		//如果分配成功
		pNew->data=val;  //将值赋给新的结点 
		pTail->Next=pNew;  //头结点指向新结点 
		pNew->Next=NULL;  //新结点指向空 
		pTail = pNew;   //将pTail移动到新结点，指向新结点 
	}
	return pHead;  //返回头结点 
}


//2、遍历链表
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->Next;  //创建一个指针p指向第一个有效结点，即指向头结点的下一个结点
	while(NULL != p)
	{
		printf("%d ",p->data);  //打印出数据 
		p=p->Next;  //p指向下一个位置 
	}
	printf("\n");
	
	return; 
}

//3、判断链表是否为空
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


//4、求链表的长度
int length_list(PNODE pHead)
{
	PNODE p = pHead->Next;  //创建一个指针p指向头结点的下一个结点
	int len=0;
	
	while(NULL != p)
	{
		++len;
		p=p->Next;	
	}
	
	return len;
}


//5、对链表进行排序
void sort_list(PNODE pHead)
{
	int i,j,t;
	int len = length_list(pHead);  //求链表的长度
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


//6、在pHead所指向的链表的pos个结点前面插入一个新的结点，该结点的值是val，并且pos是从1开始的
bool insert_list(PNODE pHead,int pos,int val)
{
	int i=0;
	PNODE p = pHead;  //定义一个指针指向头结点
	
	while(NULL != p && i < pos-1)
	{
		p=p->Next;
		++i;
	}
	if(i>pos-1 || NULL == p)
	{
		return false;
	}
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));  //生成一个新的结点
	if(NULL == pNew)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	pNew->data=val;
	PNODE q = p->Next;  //指针q指向p的下一个结点的位置
	p->Next=pNew;
	pNew->Next=q;
	
	return true; 
}


//7、删除链表的元素
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
	
	PNODE q = p->Next;  //q指向要删除的元素的结点 
	*pVal = q->data;
	
	p->Next=p->Next->Next;
	free(q);
	q=NULL;
	
	return true;
} 
