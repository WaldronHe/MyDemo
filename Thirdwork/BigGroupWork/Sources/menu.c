#include"sort.h"

void menu1()
{
	/*�˵�*/
	printf("\r\n");
	printf("\r\n");
	printf("\r\n");
	printf("	                              ============\r\n");
	printf("                              ********���������ڲ�ͬ�Ĵ��������µ���ʱ*****************\r\n");
	printf("                                ��������������\r\n");
	printf("                                -------------------1. 10000\r\n");
	printf("                                -------------------2. 50000\r\n");
	printf("                                -------------------3. 200000\r\n");
	printf("                              ******************************************************\r\n");

	/*����ѡ��*/
	printf("��ѡ��Ҫ���ɵ�������:");
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
			printf("������������ʱ��Ϊ%f��\n",TheTimes);
			return ;

		case 2:
			a = CreateData(50000);
			
			return a;

		case 3:
			a = CreateData(200000);
			
			return a;

		default:
			printf("����������������룺");
			break;
		}
	}
}



