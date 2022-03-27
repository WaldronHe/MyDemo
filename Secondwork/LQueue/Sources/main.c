#include"LQueue.h"

int main()
{
	LQueue Q;
	Q.front = NULL;
	Q.rear = NULL;
	int len;
	int i, len_1, len_2;
	int a;

	

	while (1)
	{
		int num = menu();
		getchar();

		switch (num)
		{
		case 1:
			InitLQueue(&Q);
			break;

		case 2:
			DestoryLQueue(&Q);
			break;

		case 3:
			IsEmptyLQueue(&Q);
			break;

		case 4:
			if (Q.front == NULL)
			{
				printf("���ȳ�ʼ��������\r\n");
				break;
			}
			else
			{
				a = GetHeadLQueue(&Q, datatype);
				if (a == 0)
				{
					printf("���Ӵ���Ŀǰ��Ϊ�գ�\r\n");
					break;
				}
				else
				{
					printf("��ͷԪ��Ϊ��%s", datatype);
					break;
				}
			}
		

		case 5:
			if (Q.front == NULL)
			{
				printf("���ȳ�ʼ��������\r\n");
				break;
			}
			else
			{
				len = LengthLQueue(&Q);
				printf("���г���Ϊ��%d", len);
				break;
			}
	
		case 6:
			if (Q.front == NULL)
			{
				printf("���ȳ�ʼ��������\r\n");
				break;
			}
			else
			{
				printf("���������Ԫ�ظ�����");
				scanf("%d", &len_1);
				for (i = 0; i < len_1; i++)
				{
					printf("�������%d��Ԫ�أ�", i + 1);
					scanf("%s", datatype);
					EnLQueue(&Q, datatype);
					memset(datatype, '\0', sizeof(datatype));
				}
				
				break;
			}
			break;

		case 7:
			if (Q.front == NULL)
			{
				printf("���ȳ�ʼ��������\r\n");
				break;
			}
			else
			{
				printf("���������Ԫ�ظ�����");
				scanf("%d", &len_2);
				while(len_2--)
				{
					DeLQueue(&Q);
				}
				printf("���ӳɹ���");
				break;
			}
			

		case 8:
			ClearLQueue(&Q);
			break;

		case 9:
			TraverseLQueue(&Q,LPrint);
			break;

		case 0:

			return 0;
		default:
			printf("���벻�Ϸ������������룡����\r\n");
			break;
		}
	}

	return 0;
}