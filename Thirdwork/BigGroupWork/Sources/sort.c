#include"sort.h"

//插入排序
void insertSort(int* a, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];			/*保存要比较的值*/
			for (j = i - 1; j >= 0 && a[j] > temp; j--)			/*从后面向前查找插入的位置*/
			{
				a[j + 1] = a[j];		/*挪位*/
			}
			a[j + 1] = temp;			/*复制到插入位置*/
		}
	}
}

//归并排序（合并数组）
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{

}

//归并排序
void MergeSort(int* a, int begin, int end, int* temp)
{

}

// 快速排序（递归版）
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int low = begin, high = end;
	int key = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= key)
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= key)
		{
			low++;
		}
		a[high] = a[low];
	}
	a[high] = key;
	QuickSort_Recursion(*a, begin, low - 1);
	QuickSort_Recursion(*a, low + 1, end);
}

//快速排序（非递归版）
void QuickSort(int* a, int size)
{

}

//快速排序（枢轴存放）
int Partition(int* a, int begin, int end)
{

}

//计数排序
void CountSort(int* a, int size, int max)
{
	/*
	assert(a);
	int max = a[0], min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* b = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		b[a[i] - min] += 1;

	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (b[i--])
		{
			a[j++] = i + min;
		}
	}
	free(b);
	b = NULL;
	*/
}

//基数计数排序
void RadixCountSort(int* a, int size)
{

}

// 颜色排序
void ColorSort(int* a, int size)
{

}

int* CreateData(int size) 
{
	int i;
	int* a = (int*)malloc(sizeof(int) * size);//申请存储size个数需要的内存空间
	if (a == NULL) 
	{
		printf("申请动态内存失败！\r\n");
		return NULL;
	}

	srand(time(0));
	//逐个生成，共生成size个元素
	for (i = 0; i < size; i++)
	{
		a[i] = rand();
	}
	return a;
}