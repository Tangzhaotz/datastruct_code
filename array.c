//���Խṹ
/*
���ݽṹ
2021.1.16 
*/ 

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

struct Arr  //������һ���������ͣ����������͵����ֽ���struct Arr��������������������Ա���ֱ���pBase��len��cnt 
{
	int * pBase;   //�洢���������һ��Ԫ�صĵ�ַ
	int len;  // �洢���������������ɵ����Ԫ�ظ���
	int cnt;  //��ǰ������ЧԪ�صĸ��� 
};


//�������� 
void init_arr(struct Arr *pArr,int length);  //��ʼ������ 
bool append_arr(struct Arr *pArr,int val); //׷��Ԫ��
bool insert_arr(struct Arr *pArr,int pos,int val);  //����Ԫ��
bool delete_arr(struct Arr *pArr,int pos,int *pVal);  //ɾ��Ԫ��
int get();
bool is_empty(struct Arr *pArr);  //�ж������Ƿ�Ϊ��
bool is_full(struct Arr *pArr);  //�ж������Ƿ�����
void sort_arr(struct Arr *pArr);  //�������������
void show_arr(struct Arr *pArr);   //��ʾ����
void inversion_arr(struct Arr *pArr);  //�������飬��һ��Ԫ�غ����һ��Ԫ�ضԵ� 
 

int main()
{
	struct Arr arr;  //�����ṹ�����
	int val;  //�������
	
	//1����ʼ������
	init_arr(&arr,6); //�������� 
	
	//2����ʾ����
	show_arr(&arr);
	
	//3��������׷��Ԫ��
	append_arr(&arr,1); 
	append_arr(&arr,2); 
	append_arr(&arr,3); 
	append_arr(&arr,4); 
	append_arr(&arr,5); 
	
	//4��ɾ��Ԫ��
	if(delete_arr(&arr,4,&val))
	{
		printf("ɾ���ɹ���\n");
		printf("��ɾ����Ԫ���ǣ�%d\n",val);
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
	
	//5����ʾ����
	show_arr(&arr);
	
	//6����������
	inversion_arr(&arr);
	printf("���ú������Ϊ��\n"); 
	show_arr(&arr);
	printf("\n");
	
	//7������������
	sort_arr(&arr);
	printf("����������Ϊ��\n");
	show_arr(&arr); 
	
	return 0;
}


//���庯��
//1����ʼ������ 
void init_arr(struct Arr *pArr,int length)  //�������ܵ��ǽṹ��ָ�룬ָ������ĵ�һ��Ԫ�صĵ�ַ������һ���������������ܴ洢��Ԫ�صĸ��� 
{
	//��̬����һƬ�ռ�洢����
	pArr->pBase=(int *)malloc(sizeof(int) * length); //��̬�����ַ����������ĳ�������
	if(pArr->pBase==NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
	}
	else
	{
		pArr->len=length;  //����ĳ��� 
		pArr->cnt=0;  //�����е�ǰԪ�صĸ���Ϊ0 
	}
	return; 
}

//2���鿴�����Ƿ�Ϊ��
bool is_empty(struct Arr *pArr)
{
	if(pArr->cnt == 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
} 

//3���鿴�����Ƿ�����
bool is_full(struct Arr *pArr)
{
	if(pArr->cnt == pArr->len)  //�����е�ǰ�е�Ԫ�ظ�����������ĳ��� 
	{
		return true;
	}
	else
	{
		return false;
	}
} 

//4����ʾ�����Ԫ��
void show_arr(struct Arr *pArr)
{
	int i;
	if(is_empty(pArr))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		for(i=0;i < pArr->cnt;++i)
		{
			printf("%d ",pArr->pBase[i]);
		}
		printf("\n");
	}
}

//5��������׷��Ԫ��
bool append_arr(struct Arr *pArr,int val)
{
	if(is_full(pArr))
	{
		return false;
	}
	//����ʱ׷��Ԫ��
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true; 
} 

//6������Ԫ��
bool insert_arr(struct Arr *pArr,int pos,int val)
{
	int i;
	if(is_full(pArr))
	{
		return false;
	}
	if(pos < 1 || pos >pArr->cnt+1)  //�ж�Ҫ�����λ���Ƿ�Խ�� 
	{
		return false;
	}
	for(i=pArr->cnt-1;i>pos-1;++i)
	{
		pArr->pBase[i+1]=pArr->pBase[i];  //�����һ��Ԫ�ؿ�ʼ����Ųλ�ã��ٽ�Ҫ�����Ԫ�ز��ȥ 
	}
	pArr->pBase[pos-1]=val;  //����Ԫ��
	(pArr->cnt)++;  //Ԫ�ظ�����һ
	return true; 
}

//7��ɾ��Ԫ��
bool delete_arr(struct Arr *pArr,int pos,int *pVal)
{
	int i;
	if(is_empty(pArr))
	{
		return false;
	}
	if(pos <1 ||pos>pArr->cnt)
	{
		return false;
	}
	*pVal = pArr->pBase[pos-1];  //��Ҫɾ����Ԫ�ط���
	for(i=pos;i<pArr->cnt;++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];  //��ǰ��������ŲԪ�أ����Ǳ�ɾ����Ԫ�صĿ�λ 
	} 
}


//8����תԪ��
void inversion_arr(struct Arr *pArr)
{
	int i=0;
	int j = pArr->cnt-1;
	int t;
	
	while(i < j)
	{
		//��������Ԫ�� 
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j; 
	}
	return;
}

//9����Ԫ������
void sort_arr(struct Arr *pArr)
{
	int i,j,t;
	for(i=0;i<pArr->cnt;++i)
	{
		for(j=i+1;j<pArr->cnt;++j)
		{
			if(pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;	
			}
		}
	}
} 
