#include"sort.h"

void menu1()
{
	/*菜单*/
	printf("\r\n");
	printf("\r\n");
	printf("\r\n");
	printf("	                              ============\r\n");
	printf("                              ********测试排序在不同的大数据量下的用时*****************\r\n");
	printf("                                ···数据量：\r\n");
	printf("                                -------------------1. 10000\r\n");
	printf("                                -------------------2. 50000\r\n");
	printf("                                -------------------3. 200000\r\n");
	printf("                              ******************************************************\r\n");

	/*输入选项*/
	printf("请选择要生成的数据量:");
	int choice;
	int* a;

	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			a = CreateData(10000);
			clock_t start, finish;
			double TheTimes;
			start = clock();
			insertSort(a, 10000);
			finish = clock();
			TheTimes = (double)((finish - start) / CLOCKS_PER_SEC);
			printf("插入排序所用时间为%f秒\n",TheTimes);
			return ;

		case 2:
			a = CreateData(50000);
			
			return a;

		case 3:
			a = CreateData(200000);
			
			return a;

		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}



