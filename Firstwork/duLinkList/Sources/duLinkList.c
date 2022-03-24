#include "duLinkList.h"
extern void print_du_interface();
extern void print_creat();
extern void print_traverse();
extern void print_insertbefore();
extern void print_insertafter();
extern void print_del();
extern void print_destroy();

/*初始化并创建链表*/
DuLinkedList InitList_DuL(DuLinkedList* L)
{
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));
	if ((*L) == NULL)
	{
		printf("分配失败，程序终止！\n");
		exit(OVERFLOW);
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;

	int len;			/*用来存放结点个数*/
	int i;
	int val;			/*用来临时存放用户输入结点的值*/
	printf("请输入您需要生成链表结点的个数: len=");
	scanf("%d", &len);
	if (len == 0)
	{
		return *L;
	}
	else
	{
		DuLinkedList head = *L;
		for (i = 0; i < len; ++i)
		{
			printf("请输入第%d个结点的值:", i + 1);
			scanf("%d", &val);
			DuLinkedList new = (DuLinkedList)malloc(sizeof(DuLNode));
			if (new == NULL)
			{
				printf("分配失败，程序终止！\n");
				exit(OVERFLOW);
			}
			new->prior = NULL;
			new->next = NULL;
			new->data = val;
			head->next = new;				/*前驱结点的next指针指向新结点*/
			new->prior = head;				/*新结点的piior指针指向前驱结点*/
			head = new;						/*将new赋值给head*/
		}
		return *L;
	}
}

/*整表删除并退出*/
void DestroyList_DuL(DuLinkedList* L)
{
	DuLinkedList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

DuLinkedList Position_1(DuLinkedList L, ElemType e)		/*用于在指定元素前面插入元素，找到指定元素的前一个元素*/
{
	DuLinkedList temp = L;
	for (int i = 0; i < e - 1; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

DuLinkedList Position_2(DuLinkedList L, ElemType e)		/*用于在指定元素后面插入元素，找到指定的元素*/
{
	DuLinkedList temp = L;
	for (int i = 0; i < e; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

DuLinkedList InsertValue()					/*新建结点，用于存放插入的数据*/
{
	int b;
	printf("请输入要插入的数据:");
	scanf("%d", &b);
	DuLinkedList new = (DuLinkedList)malloc(sizeof(DuLNode));
	if (new == NULL)
	{
		printf("分配失败，程序终止！\n");
		exit(OVERFLOW);
	}
	else
	{
		new->data = b;
		new->prior = NULL;
		new->next = NULL;
	}
	return new;
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	if (p->next == NULL)				/*选定结点为尾结点，特殊考虑*/
	{
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	else
	{
		q->prior = p;
		q->next = p->next;
		p->next->prior = q;
		p->next = q;
	}
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	DuLNode* temp = p;
	int i;
	for (i = 0; i < *e; i++)		/*遍历寻找要删除的元素*/
	{
		temp = temp->next;
	}

	if (temp->next == NULL)		/*判断是否是尾结点，特殊考虑*/
	{
		temp->prior->next = NULL;
		free(temp);
		return SUCCESS;
	}
	else
	{
		temp->prior->next = temp->next;
		temp->next->prior = temp->prior;
		free(temp);
		printf("删除成功！\n");
		return SUCCESS;
	}
}

/*遍历链表*/
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList p = L->next;			/*声明一指针p，并让p指向链表L的第一个结点*/
	while (p != NULL)				/*当p不为NULL时，执行循环*/
	{
		visit(p->data);				/*调用visit打印结点p的数据*/
		p = p->next;				/*p指向下一个结点*/
	}
	printf("\n");
}

/*计算链表长度*/
int length(DuLinkedList L)
{
	int len = 0;
	while (L != NULL)
	{
		++len;
		L = L->next;
	}
	return len - 1;
}

void visit(ElemType e)
{
	printf("%d ", e);
}

int main()
{
	int flag = 1;
	int num;
	DuLinkedList head = NULL;
	print_du_interface();

	while (flag)
	{
		printf("\n");
		printf("请输入编号：");
		scanf("%d", &num);
		if (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num != 5)
		{
			printf("输入不合法，程序终止!\n");
			flag = 0;
		}

		switch (num)
		{
		case 1:
			print_creat();
			InitList_DuL(&head);

			break;

		case 2:
			print_traverse();
			TraverseList_DuL(head, visit);
			break;

		case 3:
			print_insertbefore();
			printf("当前链表为：\n");
			TraverseList_DuL(head, visit);
			int len_1 = length(head);
			int a;
			printf("请输入要在第几个元素之前插入:");
			scanf("%d", &a);
			if (a > len_1 || a == 0)					/*判断选择元素是否在链表范围内*/
			{
				printf("插入无效,选择的位置不在链表范围内!\n");
			}
			else
			{
				DuLinkedList p = Position_1(head, a);
				DuLinkedList q = InsertValue();
				InsertBeforeList_DuL(p, q);
				printf("插入成功!");
			}
			printf("当前链表为：\n");
			TraverseList_DuL(head, visit);
			break;

		case 4:
			print_insertafter();
			printf("当前链表为：\n");
			TraverseList_DuL(head, visit);
			int len_2 = length(head);
			int b;
			printf("请输入要在第几个元素之后插入:");
			scanf("%d", &b);
			if (b > len_2 || b == 0)				/*判断选择元素是否在链表范围内*/
			{
				printf("插入无效,选择的位置不在链表范围内!\n");
			}
			else
			{
				DuLinkedList m = Position_2(head, b);
				DuLinkedList n = InsertValue();
				InsertAfterList_DuL(m, n);
				printf("插入成功!");
			}
			printf("当前链表为：\n");
			TraverseList_DuL(head, visit);
			break;

		case 5:
			print_del();
			printf("当前链表为：\n");
			TraverseList_DuL(head, visit);
			int c;
			printf("请问删除的位置是：");
			scanf("%d", &c);
			ElemType* e;
			e = &c;
			int len = length(head);
			if (c > len || c == 0)
			{
				printf("删除失败，删除的位置不在链表范围内！\n");
			}
			else
			{
				DeleteList_DuL(head, e);
				printf("删除成功!\n");
			}
			printf("当前链表为：\n");
			TraverseList_DuL(head, visit);
			break;

		case 0:
			print_destroy();
			DestroyList_DuL(&head);
			printf("整表删除成功，程序已退出！\n");
			flag = 0;
			break;
		}
	}
	return 0;
}