#include"sort.h"

//��������
void insertSort(int* a, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];			/*����Ҫ�Ƚϵ�ֵ*/
			for (j = i - 1; j >= 0 && a[j] > temp; j--)			/*�Ӻ�����ǰ���Ҳ����λ��*/
			{
				a[j + 1] = a[j];		/*Ųλ*/
			}
			a[j + 1] = temp;			/*���Ƶ�����λ��*/
		}
	}
}

//�鲢���򣨺ϲ����飩
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{

}

//�鲢����
void MergeSort(int* a, int begin, int end, int* temp)
{

}

// �������򣨵ݹ�棩
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

//�������򣨷ǵݹ�棩
void QuickSort(int* a, int size)
{

}

//�������������ţ�
int Partition(int* a, int begin, int end)
{

}

//��������
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

//������������
void RadixCountSort(int* a, int size)
{

}

// ��ɫ����
void ColorSort(int* a, int size)
{

}

int* CreateData(int size) 
{
	int i;
	int* a = (int*)malloc(sizeof(int) * size);//����洢size������Ҫ���ڴ�ռ�
	if (a == NULL) 
	{
		printf("���붯̬�ڴ�ʧ�ܣ�\r\n");
		return NULL;
	}

	srand(time(0));
	//������ɣ�������size��Ԫ��
	for (i = 0; i < size; i++)
	{
		a[i] = rand();
	}
	return a;
}