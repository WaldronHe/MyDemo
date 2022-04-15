#include "binary_sort_tree.h"


int main()
{
	BinarySortTree T;
	T.root = NULL;

	int len;
	ElemType key;

	while (1)
	{
		
		int num = menu();
		getchar();
	
		switch (num)
		{
		case 1:
			if (NULL != T.root)
				printf("请勿重复初始化！\r\n");
			else
				BST_init(&T);
			break;

		case 2:
			if (NULL == T.root)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
				break;
			}
			printf("请输入查找的元素：");
			scanf("%d", &key);
			BST_search(&T, key);
			break;

		case 3:
			if (NULL == T.root)						/*先判断栈是否初始化*/
			{
				printf("请先初始化!!！\r\n");
				break;
			}
			else
			{
				printf("请输入插入元素个数：");
				scanf("%d", &len);
				for (int i = 0; i < len; ++i)
				{
					printf("请输入第%d个元素：", i + 1);
					scanf("%d",&key);
					BST_insert(&T, key);
				}
				
				break;
			}

		case 4:
			printf("请输入删除的元素：");
			scanf("%d", &key);
			BST_delete(&T, key);

			break;

		case 5:
			BST_preorderI(&T, visit);
			break;

		case 6:
			BST_inorderI(&T, visit);
			break;

		case 7:
			BST_postorderI(&T, visit);
			break;

		case 8:

			break;

		case 0:
			printf("退出成功!\r\n");
			return 0;

		default:
			printf("输入不合法，请重新输入：");
			break;
		}

	}

	return 0;
}