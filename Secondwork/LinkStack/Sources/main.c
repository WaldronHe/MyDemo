#include"LinkStack.h"

int main()
{
	LinkStack s;						
	s.top = NULL;
	int i, len_1, len_2;
	ElemType a, b, e;

	while (1)
	{
		int num = menu();
		getchar();

		switch (num)
		{
		case 1:
			initLStack(&s);
			break;

		case 2:
			isEmptyLStack(&s);
			break;

		case 3:
			if (s.top == NULL)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			else
			{
				a = popLStack(&s, &b);
				if (a == 0)
				{
					printf("ȡջ��Ԫ�ش���ĿǰջΪ�գ�\r\n");
					break;
				}
				else
					printf("ջ��Ԫ��Ϊ��%d", b);
				break;
			}

		case 4:
			if (s.top == NULL)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			else
			{
				clearLStack(&s);
				break;
			}

		case 5:
			destroyLStack(&s);
			break;

		case 6:
			if (s.top == NULL)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			else
			{
				LStackLength(&s, &b);
				printf("��ǰԪ�ظ���Ϊ��%d", b);
				break;
			}

		case 7:
			if (s.top == NULL)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			else
			{
				printf("��������ջԪ�ظ�����");
				scanf("%d", &len_1);
				for (i = 0; i < len_1; ++i)
				{
					printf("�������%d��Ԫ�أ�", i + 1);
					scanf("%d", &e);
					pushLStack(&s, e);
				}
				break;
			}

		case 8:
			if (s.top == NULL)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			else
			{
				printf("�������ջԪ�صĸ�����");
				scanf("%d", &len_2);
				for (i = 0; i < len_2; ++i)
				{
					a = popLStack(&s, &b);
					if (a == 0)
					{
						printf("��ջ����ĿǰջΪ�գ�\r\n");
						break;
					}
					printf("��ջ��Ԫ��Ϊ��%d\r\n", b);
				}
				break;
			}
			
		case 0:
			printf("�˳��ɹ���\r\n");
			return 0;

		default:
			printf("���벻�Ϸ������������룡����\r\n");
			break;
		}
	}
	return 0;
}