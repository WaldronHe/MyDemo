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
				printf("�����ظ���ʼ����\r\n");
			else
				BST_init(&T);
			break;

		case 2:
			if (NULL == T.root)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			printf("��������ҵ�Ԫ�أ�");
			scanf("%d", &key);
			BST_search(&T, key);
			break;

		case 3:
			if (NULL == T.root)						/*���ж�ջ�Ƿ��ʼ��*/
			{
				printf("���ȳ�ʼ��!!��\r\n");
				break;
			}
			else
			{
				printf("���������Ԫ�ظ�����");
				scanf("%d", &len);
				for (int i = 0; i < len; ++i)
				{
					printf("�������%d��Ԫ�أ�", i + 1);
					scanf("%d",&key);
					BST_insert(&T, key);
				}
				
				break;
			}

		case 4:
			printf("������ɾ����Ԫ�أ�");
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
			printf("�˳��ɹ�!\r\n");
			return 0;

		default:
			printf("���벻�Ϸ������������룺");
			break;
		}

	}

	return 0;
}