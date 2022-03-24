#include "duLinkList.h"
extern void print_du_interface();
extern void print_creat();
extern void print_traverse();
extern void print_insertbefore();
extern void print_insertafter();
extern void print_del();
extern void print_destroy();

/*��ʼ������������*/
DuLinkedList InitList_DuL(DuLinkedList* L)
{
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));
	if ((*L) == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(OVERFLOW);
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;

	int len;			/*������Ž�����*/
	int i;
	int val;			/*������ʱ����û��������ֵ*/
	printf("����������Ҫ����������ĸ���: len=");
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
			printf("�������%d������ֵ:", i + 1);
			scanf("%d", &val);
			DuLinkedList new = (DuLinkedList)malloc(sizeof(DuLNode));
			if (new == NULL)
			{
				printf("����ʧ�ܣ�������ֹ��\n");
				exit(OVERFLOW);
			}
			new->prior = NULL;
			new->next = NULL;
			new->data = val;
			head->next = new;				/*ǰ������nextָ��ָ���½��*/
			new->prior = head;				/*�½���piiorָ��ָ��ǰ�����*/
			head = new;						/*��new��ֵ��head*/
		}
		return *L;
	}
}

/*����ɾ�����˳�*/
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

DuLinkedList Position_1(DuLinkedList L, ElemType e)		/*������ָ��Ԫ��ǰ�����Ԫ�أ��ҵ�ָ��Ԫ�ص�ǰһ��Ԫ��*/
{
	DuLinkedList temp = L;
	for (int i = 0; i < e - 1; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

DuLinkedList Position_2(DuLinkedList L, ElemType e)		/*������ָ��Ԫ�غ������Ԫ�أ��ҵ�ָ����Ԫ��*/
{
	DuLinkedList temp = L;
	for (int i = 0; i < e; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

DuLinkedList InsertValue()					/*�½���㣬���ڴ�Ų��������*/
{
	int b;
	printf("������Ҫ���������:");
	scanf("%d", &b);
	DuLinkedList new = (DuLinkedList)malloc(sizeof(DuLNode));
	if (new == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
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
	if (p->next == NULL)				/*ѡ�����Ϊβ��㣬���⿼��*/
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
	for (i = 0; i < *e; i++)		/*����Ѱ��Ҫɾ����Ԫ��*/
	{
		temp = temp->next;
	}

	if (temp->next == NULL)		/*�ж��Ƿ���β��㣬���⿼��*/
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
		printf("ɾ���ɹ���\n");
		return SUCCESS;
	}
}

/*��������*/
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList p = L->next;			/*����һָ��p������pָ������L�ĵ�һ�����*/
	while (p != NULL)				/*��p��ΪNULLʱ��ִ��ѭ��*/
	{
		visit(p->data);				/*����visit��ӡ���p������*/
		p = p->next;				/*pָ����һ�����*/
	}
	printf("\n");
}

/*����������*/
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
		printf("�������ţ�");
		scanf("%d", &num);
		if (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num != 5)
		{
			printf("���벻�Ϸ���������ֹ!\n");
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
			printf("��ǰ����Ϊ��\n");
			TraverseList_DuL(head, visit);
			int len_1 = length(head);
			int a;
			printf("������Ҫ�ڵڼ���Ԫ��֮ǰ����:");
			scanf("%d", &a);
			if (a > len_1 || a == 0)					/*�ж�ѡ��Ԫ���Ƿ�������Χ��*/
			{
				printf("������Ч,ѡ���λ�ò�������Χ��!\n");
			}
			else
			{
				DuLinkedList p = Position_1(head, a);
				DuLinkedList q = InsertValue();
				InsertBeforeList_DuL(p, q);
				printf("����ɹ�!");
			}
			printf("��ǰ����Ϊ��\n");
			TraverseList_DuL(head, visit);
			break;

		case 4:
			print_insertafter();
			printf("��ǰ����Ϊ��\n");
			TraverseList_DuL(head, visit);
			int len_2 = length(head);
			int b;
			printf("������Ҫ�ڵڼ���Ԫ��֮�����:");
			scanf("%d", &b);
			if (b > len_2 || b == 0)				/*�ж�ѡ��Ԫ���Ƿ�������Χ��*/
			{
				printf("������Ч,ѡ���λ�ò�������Χ��!\n");
			}
			else
			{
				DuLinkedList m = Position_2(head, b);
				DuLinkedList n = InsertValue();
				InsertAfterList_DuL(m, n);
				printf("����ɹ�!");
			}
			printf("��ǰ����Ϊ��\n");
			TraverseList_DuL(head, visit);
			break;

		case 5:
			print_del();
			printf("��ǰ����Ϊ��\n");
			TraverseList_DuL(head, visit);
			int c;
			printf("����ɾ����λ���ǣ�");
			scanf("%d", &c);
			ElemType* e;
			e = &c;
			int len = length(head);
			if (c > len || c == 0)
			{
				printf("ɾ��ʧ�ܣ�ɾ����λ�ò�������Χ�ڣ�\n");
			}
			else
			{
				DeleteList_DuL(head, e);
				printf("ɾ���ɹ�!\n");
			}
			printf("��ǰ����Ϊ��\n");
			TraverseList_DuL(head, visit);
			break;

		case 0:
			print_destroy();
			DestroyList_DuL(&head);
			printf("����ɾ���ɹ����������˳���\n");
			flag = 0;
			break;
		}
	}
	return 0;
}