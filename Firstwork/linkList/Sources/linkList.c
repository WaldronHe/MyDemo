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
		printf("�������ţ�");
		scanf("%d", &num);
		if (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7 && num != 8 && num != 9)
		{
			printf("���벻�Ϸ���������ֹ!\n");
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
			printf("��ǰ����Ϊ��\n");
			TraverseList(head, visit);
			int len_1 = length(head);
			int a, b;
			printf("����������λ�ã�");
			scanf("%d", &a);
			if (a > len_1 + 1 || a == 0)					/*�ж�ѡ��Ԫ���Ƿ�������Χ��*/
			{
				printf("������Ч,�����λ�ò�������Χ��!\n");
			}
			else
			{
				LinkedList p = Position(head, a);
				LinkedList q = InsertValue();
				InsertList(p, q);
			}
			printf("��ǰ����Ϊ��\n");
			TraverseList(head, visit);
			break;

		case 4:
			print_del();
			printf("��ǰ����Ϊ��\n");
			TraverseList(head, visit);
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
				DeleteList(head, e);
			}
			printf("��ǰ����Ϊ��\n");
			TraverseList(head, visit);
			break;

		case 5:
			print_search();
			int i;
			printf("��������Ҫ��ѯ�����ݣ�");
			scanf("%d", &i);
			SearchList(head, i);
			break;

		case 6:
			print_reverse();
			ReverseList(&head);
			printf("��ת�ɹ���\n");
			printf("��ǰ����Ϊ��\n");
			TraverseList(head, visit);
			break;

		case 7:
			print_isloop();
			IsLoopList(head);
			break;

		case 8:
			print_reverseeven();
			ReverseEvenList(&head);
			printf("�����ɹ�!\n");
			printf("��ǰ����Ϊ��\n");
			TraverseList(head, visit);
			break;

		case 9:
			print_findmid();
			LinkedList mid;
			mid = FindMidNode(&head);
			printf("���ҵ��м��㣬�м���Ϊ%d\n", mid->data);
			break;

		case 0:
			print_destroy();
			DestroyList(&head);
			printf("����ɾ���ɹ������˳���\n");
			flag = 0;
			break;
				
		}
	}
	return 0;
}

//����ɾ��
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

//��������
LinkedList CreateList()
{
	int len;			//������Ž�����
	int i;
	int val;			//������ʱ����û��������ֵ

	LinkedList head = (LinkedList)malloc(sizeof(LNode));		//����ͷ���
	if (head == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
		return ERROR;
	}
	printf("����������Ҫ����������ĸ���: len=");
	scanf("%d", &len);
	LinkedList tail = head;
	tail->next = NULL;			//����һ����Զָ��β����ָ�� tail
	for (i = 0; i < len; ++i)
	{
		printf("�������%d������ֵ:", i + 1);
		scanf("%d", &val);
		LinkedList new = (LinkedList)malloc(sizeof(LNode));			//�����½��
		new->data = val;		//�������val��ֵ���½���������
		tail->next = new;		//��new��ֵ��tail�ĺ��
		new->next = NULL;		//��NULL��ֵ��new�ĺ��
		tail = new;				//��new��ֵ��tail
	}
	return head;
}

//��������
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LinkedList p = L->next;			//����һָ��p������pָ������L�ĵ�һ�����
	while (p != NULL)				//��p��ΪNULLʱ��ִ��ѭ��
	{
		visit(p->data);				//����visit��ӡ���p������
		p = p->next;				//pָ����һ�����
	}
	printf("\n");
}

void visit(ElemType e)
{
	printf("%d ", e);
}

//����Ԫ��
LinkedList Position(LinkedList L,ElemType e)      /*�ҵ�����λ�õ�ǰһ�����*/
{
	LinkedList temp = L;
	for (int i = 0; i < e - 1; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

LinkedList InsertValue()						/*�½����������*/
{
	int i;
	printf("��������������: ");
	scanf("%d", &i);
	LinkedList new = (LinkedList)malloc(sizeof(LNode));
	if (new == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
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
//ɾ��Ԫ��
Status DeleteList(LNode* p, ElemType* e)
{
	LNode* temp = p;
	int i;
	for (i = 1; i < *e; i++)		//����Ѱ��ɾ��Ԫ�ص�ǰһ�����
	{
		temp = temp->next;
	}
	LNode* del = temp->next;
	temp->next = del->next;				//��del�ĺ�̸�ֵ��temp�ĺ��
	del->next = NULL;
	free(del);							//��ϵͳ���մ˽�㣬�ͷ��ڴ�
	printf("ɾ���ɹ���\n");
	return SUCCESS;
}

//��ѯԪ��
Status SearchList(LinkedList L, ElemType e)
{
	int i = 1;
	LinkedList q = L;
	while (q->next != NULL)				
	{
		q = q->next;				//��������
		if (q->data == e)			//���ֽ������������ֵ���ʱ��ӡ	
		{
			printf("��ѯ�ĵ�����λ����:%d\n", i);
			return SUCCESS;
		}
		++i;
	}
	printf("��ѯʧ�ܣ����ҵ�Ԫ�ز���������!\n");
	return ERROR;
}

//��ת����
Status ReverseList(LinkedList* L)
{
	LinkedList p, t, q;
	p = NULL;				//pָ��NULL
	t = (*L)->next;			//tָ���һ�����
	q = t->next;			//qָ��ڶ������
	if ((*L) == NULL || t == NULL || q == NULL)
		return ERROR;
	while (q)
	{
		t->next = p;		//��p��ֵ��t�ĺ�̽��
		p = t;
		t = q;
		q = q->next;		//p,t,q���������һλ
	}
	t->next = p;
	(*L)->next = t;
	return SUCCESS;
}

//�жϳɻ�
Status IsLoopList(LinkedList L)
{
	LinkedList p, q;
	for (p = L, q = L; p == NULL; p = p->next->next, q = q->next)   //��������ָ�룬һ��һ����һ����һ��һ��������
	{
		if (p == q)						//��p��q�غ�ʱ��˵������ɻ�
		{
			printf("����ɻ���\n");
			return SUCCESS;
		}
	}
	printf("�����ɻ���\n");
	return ERROR;
}

//��ż����
LNode* ReverseEvenList(LinkedList* L)
{
	LinkedList p;
	p = (*L)->next;
	int len = length(*L);		//��ȡ������
	int temp;
	if (len % 2 == 0)			//���������Ϊż��
	{
		while (p)				//p��ΪNULLʱִ��ѭ��
		{
			temp = p->data;				
			p->data = p->next->data;
			p->next->data = temp;			//���������ż��������ݽ���
			p = p->next->next;
		}
	}
	else                        //���������Ϊ����ʱ
	{
		while (p->next)			//p->next��ΪNULLʱָ��ѭ��
		{
			temp = p->data;
			p->data = p->next->data;
			p->next->data = temp;			//���������ż��������ݽ���
			p = p->next->next;			
		}
	}
	return *L;
}

//����������
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

//�ҵ��м���
LNode* FindMidNode(LinkedList* L)
{
	LinkedList fast, slow;					//��������ָ�룬һ��ÿ����һ����һ��ÿ���������������ָ������ʱ�����ĸպ��ߵ�һ��

	for (fast = (*L), slow = (*L); fast != NULL && fast->next != NULL; fast = fast->next->next)
	{
		slow = slow->next;
	}
	return slow;							//������ָ��
}
