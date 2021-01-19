/*
栈：
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
	int *p = (int *)malloc(100);  //动态申请内存 
	
	return 0;
 }
 
 */
 
 
 
 //栈的各种操作
 #include<stdio.h>
 #include<malloc.h>
 #include<stdlib.h>
 #include<stdbool.h>
 

//定义结点的形式 
typedef struct Node
{
	int data;
	struct Node * Next;
	
 }NODE,* PNODE;
 
//定义栈的结点
typedef struct stack
{
	PNODE pTop;  //栈顶指针
	PNODE pBottom;  //栈底指针 
}STACK,*PSTACK; 


//函数的声明
void init(PSTACK);  //传入的是栈的指针
void push(PSTACK,int);  //压栈
void traverse(PSTACK);  //遍历栈
bool pop(PSTACK,int *);  //出栈
void clear(PSTACK pS);  //清空栈 


int main()
{
	STACK S;  //等价于struct stack S;
	int val;
	
	//初始化栈，目的是造一个空栈
	init(&S);
	
	//压栈 
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	
	//遍历栈
	traverse(&S);
	
	//清空栈
	//clear(&S);
	
	//出栈
	if(pop(&S,&val))
	{
		printf("出栈成功，出栈的元素是%d\n",val);	
	}
	else
	{
		printf("出栈失败\n");
	}
	
	traverse(&S);
	
	return 0;
		
}

//1、初始化栈
void init(PSTACK pS)
{
	//先分配一个栈顶结点
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;  //栈顶和栈尾指针都先同时指向这一个结点
		pS->pTop->Next=NULL;  //因为还没有插入数据，所以先让这个结点的指针指向空 
	}	 
} 


//2、入栈操作
void push(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));  //对于入栈的元素生成一个结点
	pNew->data=val;//给结点的数据域赋值
	pNew->Next=pS->pTop;  //将这个结点接到栈顶指针的位置。
	pS->pTop=pNew;//再将栈顶指针移动到新插入的元素结点
	
	return; 
}

//3、遍历栈
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;  //设定一个指针指向栈顶结点
	printf("栈中当前的元素有：\n"); 
	while(p != pS->pBottom)
	{
		printf("%d  ",p->data);
		p= p->Next;
	}
	printf("\n");
	
	return;
}


//4、判断栈是否为空
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

//5、出栈
bool pop(PSTACK pS,int *pVal)
{
	if(empty(pS))
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;  //返回要出栈的元素的值
		pS->pTop=r->Next;
		free(r);
		r = NULL;		
	}
	return true;
}

//6、清空栈
void clear(PSTACK pS)
{
	if(empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;  //指针p指向栈顶元素
		PNODE q = p->Next;  //q指向p的下一结点
		while(p != pS->pBottom)
		{
			q=p->Next;
			free(p);
			p=q;	
		}
		pS->pTop=pS->pBottom;  //最后将栈顶指针和栈底指针指向同一结点	
	}	
} 







































