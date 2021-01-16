//线性结构
/*
数据结构
2021.1.16 
*/ 

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

struct Arr  //定义了一个数据类型，该数据类型的名字叫做struct Arr，该数据类型有三个成员，分别是pBase，len，cnt 
{
	int * pBase;   //存储的是数组第一个元素的地址
	int len;  // 存储的是数组所能容纳的最大元素个数
	int cnt;  //当前数组有效元素的个数 
};


//函数声明 
void init_arr(struct Arr *pArr,int length);  //初始化数组 
bool append_arr(struct Arr *pArr,int val); //追加元素
bool insert_arr(struct Arr *pArr,int pos,int val);  //插入元素
bool delete_arr(struct Arr *pArr,int pos,int *pVal);  //删除元素
int get();
bool is_empty(struct Arr *pArr);  //判断数组是否为空
bool is_full(struct Arr *pArr);  //判断数组是否已满
void sort_arr(struct Arr *pArr);  //对数组进行排序
void show_arr(struct Arr *pArr);   //显示数组
void inversion_arr(struct Arr *pArr);  //逆序数组，第一个元素和最后一个元素对调 
 

int main()
{
	struct Arr arr;  //创建结构体变量
	int val;  //定义变量
	
	//1、初始化数组
	init_arr(&arr,6); //函数调用 
	
	//2、显示数组
	show_arr(&arr);
	
	//3、数组中追加元素
	append_arr(&arr,1); 
	append_arr(&arr,2); 
	append_arr(&arr,3); 
	append_arr(&arr,4); 
	append_arr(&arr,5); 
	
	//4、删除元素
	if(delete_arr(&arr,4,&val))
	{
		printf("删除成功！\n");
		printf("你删除的元素是：%d\n",val);
	}
	else
	{
		printf("删除失败\n");
	}
	
	//5、显示数组
	show_arr(&arr);
	
	//6、逆置数组
	inversion_arr(&arr);
	printf("逆置后的数组为：\n"); 
	show_arr(&arr);
	printf("\n");
	
	//7、对数组排序
	sort_arr(&arr);
	printf("排序后的数组为：\n");
	show_arr(&arr); 
	
	return 0;
}


//定义函数
//1、初始化数组 
void init_arr(struct Arr *pArr,int length)  //参数接受的是结构体指针，指向数组的第一个元素的地址，另外一个参数是数组所能存储的元素的个数 
{
	//动态申请一片空间存储数组
	pArr->pBase=(int *)malloc(sizeof(int) * length); //动态申请地址，根据数组的长度申请
	if(pArr->pBase==NULL)
	{
		printf("动态内存分配失败！\n");
	}
	else
	{
		pArr->len=length;  //数组的长度 
		pArr->cnt=0;  //数组中当前元素的个数为0 
	}
	return; 
}

//2、查看数组是否为空
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

//3、查看数组是否已满
bool is_full(struct Arr *pArr)
{
	if(pArr->cnt == pArr->len)  //数组中当前有的元素个数等于数组的长度 
	{
		return true;
	}
	else
	{
		return false;
	}
} 

//4、显示数组的元素
void show_arr(struct Arr *pArr)
{
	int i;
	if(is_empty(pArr))
	{
		printf("数组为空\n");
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

//5、数组中追加元素
bool append_arr(struct Arr *pArr,int val)
{
	if(is_full(pArr))
	{
		return false;
	}
	//不满时追加元素
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true; 
} 

//6、插入元素
bool insert_arr(struct Arr *pArr,int pos,int val)
{
	int i;
	if(is_full(pArr))
	{
		return false;
	}
	if(pos < 1 || pos >pArr->cnt+1)  //判断要插入的位置是否越界 
	{
		return false;
	}
	for(i=pArr->cnt-1;i>pos-1;++i)
	{
		pArr->pBase[i+1]=pArr->pBase[i];  //从最后一个元素开始往后挪位置，再将要插入的元素插进去 
	}
	pArr->pBase[pos-1]=val;  //插入元素
	(pArr->cnt)++;  //元素个数加一
	return true; 
}

//7、删除元素
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
	*pVal = pArr->pBase[pos-1];  //将要删除的元素返回
	for(i=pos;i<pArr->cnt;++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];  //从前往后依次挪元素，覆盖被删除的元素的空位 
	} 
}


//8、逆转元素
void inversion_arr(struct Arr *pArr)
{
	int i=0;
	int j = pArr->cnt-1;
	int t;
	
	while(i < j)
	{
		//交换两个元素 
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j; 
	}
	return;
}

//9、将元素排序
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
