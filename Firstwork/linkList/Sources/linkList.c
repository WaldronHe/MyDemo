#include "linkList.h"

extern void print_interface();
extern void print_creat();
extern void print_traverse();
extern void print_insert();
extern void print_del();
extern void print_search();
extern void print_reverse();
extern void print_isloop();
extern void print_reverseeven();
extern void print_findmid();
extern void print_destroy();

int main()
{
	LinkedList head = NULL;
	int num;
	int flag = 1;
	print_interface();
	printf("\n");

	while(flag)
	{	
		printf("\n");
		printf("请输入编号：");
		scanf("%d", &num);
		if (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7 && num != 8 && num != 9)
		{
			printf("输入不合法，程序终止!\n");
			flag = 0;
		}
		switch (num)
		{
		case 1:
			print_creat();
			head = CreateList();
			break;

		case 2:
			print_traverse();
			TraverseList(head, visit);
			break;
		case 3:
			print_insert();
			printf("当前链表为：\n");
			TraverseList(head, visit);
			int len_1 = length(head);
			int a, b;
			printf("请输入插入的位置：");
			scanf("%d", &a);
			if (a > len_1 + 1 || a == 0)					/*判断选择元素是否在链表范围内*/
			{
				printf("插入无效,插入的位置不在链表范围内!\n");
			}
			else
			{
				LinkedList p = Position(head, a);
				LinkedList q = InsertValue();
				InsertList(p, q);
			}
			printf("当前链表为：\n");
			TraverseList(head, visit);
			break;

		case 4:
			print_del();
			printf("当前链表为：\n");
			TraverseList(head, visit);
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
				DeleteList(head, e);
			}
			printf("当前链表为：\n");
			TraverseList(head, visit);
			break;

		case 5:
			print_search();
			int i;
			printf("请输入需要查询的数据：");
			scanf("%d", &i);
			SearchList(head, i);
			break;

		case 6:
			print_reverse();
			ReverseList(&head);
			printf("反转成功！\n");
			printf("当前链表为：\n");
			TraverseList(head, visit);
			break;

		case 7:
			print_isloop();
			IsLoopList(head);
			break;

		case 8:
			print_reverseeven();
			ReverseEvenList(&head);
			printf("交换成功!\n");
			printf("当前链表为：\n");
			TraverseList(head, visit);
			break;

		case 9:
			print_findmid();
			LinkedList mid;
			mid = FindMidNode(&head);
			printf("已找到中间结点，中间结点为%d\n", mid->data);
			break;

		case 0:
			print_destroy();
			DestroyList(&head);
			printf("整表删除成功，已退出！\n");
			flag = 0;
			break;
				
		}
	}
	return 0;
}

//整表删除
void DestroyList(LinkedList* L)
{
	LinkedList p, q;
	p = (*L)->next;
	while (p)				
	{					
		q = p->next;
		free(p);
		p = q;
	}
}

//创建链表
LinkedList CreateList()
{
	int len;			//用来存放结点个数
	int i;
	int val;			//用来临时存放用户输入结点的值

	LinkedList head = (LinkedList)malloc(sizeof(LNode));		//生成头结点
	if (head == NULL)
	{
		printf("分配失败，程序终止！\n");
		return ERROR;
	}
	printf("请输入您需要生成链表结点的个数: len=");
	scanf("%d", &len);
	LinkedList tail = head;
	tail->next = NULL;			//定义一个永远指向尾结点的指针 tail
	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个结点的值:", i + 1);
		scanf("%d", &val);
		LinkedList new = (LinkedList)malloc(sizeof(LNode));			//生成新结点
		new->data = val;		//将输入的val赋值给新结点的数据域
		tail->next = new;		//将new赋值给tail的后继
		new->next = NULL;		//将NULL赋值给new的后继
		tail = new;				//将new赋值给tail
	}
	return head;
}

//遍历链表
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LinkedList p = L->next;			//声明一指针p，并让p指向链表L的第一个结点
	while (p != NULL)				//当p不为NULL时，执行循环
	{
		visit(p->data);				//调用visit打印结点p的数据
		p = p->next;				//p指向下一个结点
	}
	printf("\n");
}

void visit(ElemType e)
{
	printf("%d ", e);
}

//插入元素
LinkedList Position(LinkedList L,ElemType e)      /*找到插入位置的前一个结点*/
{
	LinkedList temp = L;
	for (int i = 0; i < e - 1; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

LinkedList InsertValue()						/*新建结点存放数据*/
{
	int i;
	printf("请输入插入的数据: ");
	scanf("%d", &i);
	LinkedList new = (LinkedList)malloc(sizeof(LNode));
	if (new == NULL)
	{
		printf("分配失败，程序终止！\n");
		return ERROR;
	}
	new->data = i;
	new->next = NULL;
	return new;
}

Status InsertList(LNode* p, LNode* q)
{
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
//删除元素
Status DeleteList(LNode* p, ElemType* e)
{
	LNode* temp = p;
	int i;
	for (i = 1; i < *e; i++)		//遍历寻找删除元素的前一个结点
	{
		temp = temp->next;
	}
	LNode* del = temp->next;
	temp->next = del->next;				//将del的后继赋值给temp的后继
	del->next = NULL;
	free(del);							//让系统回收此结点，释放内存
	printf("删除成功！\n");
	return SUCCESS;
}

//查询元素
Status SearchList(LinkedList L, ElemType e)
{
	int i = 1;
	LinkedList q = L;
	while (q->next != NULL)				
	{
		q = q->next;				//遍历链表
		if (q->data == e)			//发现结点数据与输入值相等时打印	
		{
			printf("查询的的数据位置是:%d\n", i);
			return SUCCESS;
		}
		++i;
	}
	printf("查询失败，查找的元素不在链表里!\n");
	return ERROR;
}

//反转链表
Status ReverseList(LinkedList* L)
{
	LinkedList p, t, q;
	p = NULL;				//p指向NULL
	t = (*L)->next;			//t指向第一个结点
	q = t->next;			//q指向第二个结点
	if ((*L) == NULL || t == NULL || q == NULL)
		return ERROR;
	while (q)
	{
		t->next = p;		//将p赋值给t的后继结点
		p = t;
		t = q;
		q = q->next;		//p,t,q依次向后移一位
	}
	t->next = p;
	(*L)->next = t;
	return SUCCESS;
}

//判断成环
Status IsLoopList(LinkedList L)
{
	LinkedList p, q;
	for (p = L, q = L; p == NULL; p = p->next->next, q = q->next)   //定义两个指针，一个一次走一步，一个一次走两步
	{
		if (p == q)						//当p和q重合时，说明链表成环
		{
			printf("链表成环！\n");
			return SUCCESS;
		}
	}
	printf("链表不成环！\n");
	return ERROR;
}

//奇偶交换
LNode* ReverseEvenList(LinkedList* L)
{
	LinkedList p;
	p = (*L)->next;
	int len = length(*L);		//获取链表长度
	int temp;
	if (len % 2 == 0)			//链表结点个数为偶数
	{
		while (p)				//p不为NULL时执行循环
		{
			temp = p->data;				
			p->data = p->next->data;
			p->next->data = temp;			//奇数结点与偶数结点数据交换
			p = p->next->next;
		}
	}
	else                        //链表结点个数为奇数时
	{
		while (p->next)			//p->next不为NULL时指向循环
		{
			temp = p->data;
			p->data = p->next->data;
			p->next->data = temp;			//奇数结点与偶数结点数据交换
			p = p->next->next;			
		}
	}
	return *L;
}

//计算链表长度
int length(LinkedList L)
{
	int len = 0;
	while (L != NULL)
	{
		++len;
		L = L->next;
	}
	return len - 1;
}

//找到中间结点
LNode* FindMidNode(LinkedList* L)
{
	LinkedList fast, slow;					//定义两个指针，一个每次走一步，一个每次走两步，当快的指针走完时，慢的刚好走到一半

	for (fast = (*L), slow = (*L); fast != NULL && fast->next != NULL; fast = fast->next->next)
	{
		slow = slow->next;
	}
	return slow;							//返回慢指针
}
