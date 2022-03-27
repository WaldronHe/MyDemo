#include "LinkStack.h"
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));		/*�����ڴ�*/
	if (s->top == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\r\n");
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	printf("��ʼ���ɹ�!\r\n");
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s->top == NULL)					/*���ж�ջ�Ƿ��ʼ��*/
	{
		printf("���ȳ�ʼ��!!��\r\n");
		return ERROR;
	}
	if (s->top->next == NULL)
	{
		printf("����һ����ջ!\r\n");
		return SUCCESS;
	}
	else
	{
		printf("�ⲻ��һ����ջ!\r\n");
		return ERROR;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->count == 0)
	{
		return ERROR;
	}
	else
	{
		*e = s->top->data;
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack* s) {
	LinkStackPtr p, q;
	p = s->top;
	if (s->top->next == NULL)			/*���ж�ջ�Ƿ�Ϊ��*/
	{
		printf("��ǰջ��Ϊ�գ��������!\r\n");
		return ERROR;
	}
	else
	{
		while (p)
		{
			q = p;
			p = p->next;
			free(q);
		}
		s->count = 0;
		s->top->next = NULL;
		printf("���ջ�ɹ�!\r\n");
		return SUCCESS;
	}
}

//����ջ
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL)					/*���ж�ջ�Ƿ��ʼ��*/
	{
		printf("����ʧ�ܣ����ȳ�ʼ��!!��\r\n");
		return ERROR;
	}
	LinkStackPtr p;
	while (s->top->next)				/*���ջ*/
	{
		p = s->top;
		s->top = p->next;
		s->count--;
		free(p);
	}
	free(s->top);						/*�ͷ�ջ�ڴ�*/
	s->top = NULL;
	printf("���ٳɹ���\r\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	if (s->top == NULL)				/*���ж�ջ�Ƿ��ʼ��*/
	{
		printf("���ȳ�ʼ��!!��\r\n");
		return ERROR;
	}
	else
	{
		*length = s->count;
		return SUCCESS;
	}
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (new == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\r\n");
		return ERROR;
	}
	new->data = data;
	new->next = s->top;		/*�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
	s->top = new;			/*���µĽ�㸳ֵ��ջ��ָ��*/
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	LinkStackPtr p;
	if (s->count == 0)		/*����ջΪ��*/
	{
		return ERROR;
	}
	*data = s->top->data;
	p = s->top;				/*��ջ����㸳ֵ��p*/
	s->top = s->top->next;		/*ʹ��ջ��ָ������һλ��ָ���һ���*/
	free(p);				/*�ͷŽ��p*/
	s->count--;
	return SUCCESS;
}
