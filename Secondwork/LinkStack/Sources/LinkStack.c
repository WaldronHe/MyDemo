#include "LinkStack.h"
//链栈

//初始化栈
Status initLStack(LinkStack* s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));		/*分配内存*/
	if (s->top == NULL)
	{
		printf("分配失败，程序终止！\r\n");
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	printf("初始化成功!\r\n");
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s->top == NULL)					/*先判断栈是否初始化*/
	{
		printf("请先初始化!!！\r\n");
		return ERROR;
	}
	if (s->top->next == NULL)
	{
		printf("这是一个空栈!\r\n");
		return SUCCESS;
	}
	else
	{
		printf("这不是一个空栈!\r\n");
		return ERROR;
	}
}

//得到栈顶元素
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

//清空栈
Status clearLStack(LinkStack* s) {
	LinkStackPtr p, q;
	p = s->top;
	if (s->top->next == NULL)			/*先判断栈是否为空*/
	{
		printf("当前栈已为空，无需清空!\r\n");
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
		printf("清空栈成功!\r\n");
		return SUCCESS;
	}
}

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL)					/*先判断栈是否初始化*/
	{
		printf("销毁失败，请先初始化!!！\r\n");
		return ERROR;
	}
	LinkStackPtr p;
	while (s->top->next)				/*清空栈*/
	{
		p = s->top;
		s->top = p->next;
		s->count--;
		free(p);
	}
	free(s->top);						/*释放栈内存*/
	s->top = NULL;
	printf("销毁成功！\r\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	if (s->top == NULL)				/*先判断栈是否初始化*/
	{
		printf("请先初始化!!！\r\n");
		return ERROR;
	}
	else
	{
		*length = s->count;
		return SUCCESS;
	}
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (new == NULL)
	{
		printf("分配失败，程序终止！\r\n");
		return ERROR;
	}
	new->data = data;
	new->next = s->top;		/*把当前的栈顶元素赋值给新结点的直接后继*/
	s->top = new;			/*将新的结点赋值给栈顶指针*/
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	LinkStackPtr p;
	if (s->count == 0)		/*考虑栈为空*/
	{
		return ERROR;
	}
	*data = s->top->data;
	p = s->top;				/*将栈顶结点赋值给p*/
	s->top = s->top->next;		/*使得栈顶指针下移一位，指向后一结点*/
	free(p);				/*释放结点p*/
	s->count--;
	return SUCCESS;
}
