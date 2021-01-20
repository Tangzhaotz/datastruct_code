//��ʽ����
//2021.1.20


#include<iostream>
using namespace std;

typedef struct node  //������ 
{
	int data;  //������ 
	struct node * next;  //ָ���� 
}NODE,*PNODE;


class Queue
{
private:
	PNODE pHead,pTail;  //pHeadָ�����õ�ͷ��㣬p->Head->Next����ָ�����Ԫ�أ�pTailָ���βԪ�� 
	
public:
	Queue()  //���캯�� 
	{
		this->pHead=this->pTail=new NODE;  //�½�һ�����
		this->pHead->next=NULL; 
	}
	
	void InQueue(int val)
	{
		PNODE pNew = new NODE;
		pNew->data=val;
		pNew->next=NULL;
		
		pTail->next=pNew;  //��pNew�ҵ���β
		pTail=pNew;  //��βָ��ָ�����һ��Ԫ�� 
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
			cout << "����Ϊ�գ��޷����ӣ�" << endl;
		}
		else
		{
			PNODE pTemp = pHead->next;  //pHead���Ƕ���Ԫ�أ�pHead->next����Ҫɾ����Ԫ��
			pHead->next=pTemp->next;
			int val = pTemp->data;
			
			delete pTemp;
			
			if(NULL == pHead->next)  //�����е�Ԫ���Ѿ�ȫ������ 
			{
				pTail = pHead;	//βָ��Ҳָ�����õĽ�� 
			}
			return val;
		}
	}
	
	//��������
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
	
	//��ն���
	void clear()
	{
		while(!this->empty())
		{
			OutQueue();
		}
	}
	
	//��������
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
		Q.InQueue(i+1);  //��� 
	}
	Q.Travers();
	
	Q.OutQueue();
	Q.OutQueue();
	
	Q.Travers();
	Q.clear();
	Q.OutQueue(); 
	
	return 0;
}
