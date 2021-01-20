//链式队列
//2021.1.20


#include<iostream>
using namespace std;

typedef struct node  //定义结点 
{
	int data;  //数据域 
	struct node * next;  //指针域 
}NODE,*PNODE;


class Queue
{
private:
	PNODE pHead,pTail;  //pHead指向无用的头结点，p->Head->Next才是指向队首元素，pTail指向队尾元素 
	
public:
	Queue()  //构造函数 
	{
		this->pHead=this->pTail=new NODE;  //新建一个结点
		this->pHead->next=NULL; 
	}
	
	void InQueue(int val)
	{
		PNODE pNew = new NODE;
		pNew->data=val;
		pNew->next=NULL;
		
		pTail->next=pNew;  //将pNew挂到队尾
		pTail=pNew;  //队尾指针指向最后一个元素 
		return;
	}
	
	bool empty()const
	{
		if(this->pHead==pTail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	int OutQueue()
	{
		if(empty())
		{
			cout << "队列为空，无法出队！" << endl;
		}
		else
		{
			PNODE pTemp = pHead->next;  //pHead不是队首元素，pHead->next才是要删除的元素
			pHead->next=pTemp->next;
			int val = pTemp->data;
			
			delete pTemp;
			
			if(NULL == pHead->next)  //队列中的元素已经全部出队 
			{
				pTail = pHead;	//尾指针也指向无用的结点 
			}
			return val;
		}
	}
	
	//遍历队列
	void Travers(void)const
	{
		PNODE pTemp = pHead->next;
		while(pTemp != NULL)
		{
			cout << pTemp->data << " ";
			pTemp=pTemp->next;	
		}
		cout << endl;	
	}
	
	//清空队列
	void clear()
	{
		while(!this->empty())
		{
			OutQueue();
		}
	}
	
	//析构函数
	~Queue()
	{
		this->clear();
		delete pHead; 
	} 
};

int main()
{
	Queue Q;
	for(int i=0;i<5;i++)
	{
		Q.InQueue(i+1);  //入队 
	}
	Q.Travers();
	
	Q.OutQueue();
	Q.OutQueue();
	
	Q.Travers();
	Q.clear();
	Q.OutQueue(); 
	
	return 0;
}
