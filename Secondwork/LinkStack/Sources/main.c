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
			if (s.top == NULL)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
				break;
			}
			else
			{
				a = popLStack(&s, &b);
				if (a == 0)
				{
					printf("取栈顶元素错误，目前栈为空！\r\n");
					break;
				}
				else
					printf("栈顶元素为：%d", b);
				break;
			}

		case 4:
			if (s.top == NULL)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
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
			if (s.top == NULL)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
				break;
			}
			else
			{
				LStackLength(&s, &b);
				printf("当前元素个数为：%d", b);
				break;
			}

		case 7:
			if (s.top == NULL)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
				break;
			}
			else
			{
				printf("请输入入栈元素个数：");
				scanf("%d", &len_1);
				for (i = 0; i < len_1; ++i)
				{
					printf("请输入第%d个元素：", i + 1);
					scanf("%d", &e);
					pushLStack(&s, e);
				}
				break;
			}

		case 8:
			if (s.top == NULL)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
				break;
			}
			else
			{
				printf("请输入出栈元素的个数：");
				scanf("%d", &len_2);
				for (i = 0; i < len_2; ++i)
				{
					a = popLStack(&s, &b);
					if (a == 0)
					{
						printf("出栈错误，目前栈为空！\r\n");
						break;
					}
					printf("出栈的元素为：%d\r\n", b);
				}
				break;
			}
			
		case 0:
			printf("退出成功！\r\n");
			return 0;

		default:
			printf("输入不合法，请重新输入！！！\r\n");
			break;
		}
	}
	return 0;
}