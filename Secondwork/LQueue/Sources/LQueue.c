#include "LQueue.h" 

/*初始化队列*/
void InitLQueue(LQueue* Q) {
	Q->front = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL)
	{
		printf("分配失败，程序终止！\r\n");
		return FALSE;
	}
	Q->rear = Q->front;
	Q->front->next == NULL;
	Q->length = 0;
	printf("初始化成功!\r\n");

}

/*销毁队列*/
void DestoryLQueue(LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("请先初始化！！！\r\n");
	}
	else
	{	
		while (Q->front != Q->rear)			/*清空队列*/
		{	
			Node* p;						
			p = Q->front->next;				/*将欲删除的队头结点暂存给p*/
			Q->front->next = p->next;		/*将原队头结点后继p->next赋值给头结点后继*/
			if (Q->rear == p)				/*若队头是队尾，删除后将rear指向头结点*/
				Q->rear = Q->front;
			free(p);
		}
		free(Q->front);						/*销毁队列*/
		Q->front = Q->rear = NULL;
		printf("销毁成功！\r\n");
	}
}

/* 检查队列是否为空*/
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("请先初始化！！！\r\n");
		return FALSE;
	}
	LQueue* p;
	p = Q;
	if (p->front == p->rear)
	{
		printf("这是一个空队列！\r\n");
		return TRUE;
	}
	else
	{
		printf("这不是一个空队列！\r\n");
		return TRUE;
	}
}

/*查看队头元素*/
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (Q->front == Q->rear)
	{
		return FALSE;
	}
	else
	{
		e = Q->front->data;
		return TRUE;
	}
}

 /*确定队列长度*/
int LengthLQueue(LQueue* Q) {

	int len;
	len = Q->length;
	return len;

}

 /*入队操作*/
Status EnLQueue(LQueue* Q, void* data) {

	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("分配失败，程序终止！\r\n");
		return FALSE;
	}
	new->data = data;
	new->next = NULL;
	Q->rear->next = new;		/*把拥有元素data新结点new赋值给原队尾结点的后继*/
	Q->rear = new;				/*把当前的new设置为队尾结点，rear指向new*/
	Q->length++;
	return TRUE;
}

/*出队操作*/
Status DeLQueue(LQueue* Q) {

	if (Q->front == Q->rear)
	{
		printf("出队错误，队列为空！\r\n");
		return FALSE;
	}
	Node* p;
	p = Q->front->next;				/*将欲删除的队头结点暂存给p*/
	Q->front->next = p->next;		/*将原队头结点后继p->next赋值给头结点后继*/
	if (Q->rear == p)				/*若队头是队尾，删除后将rear指向头结点*/
		Q->rear = Q->front;
	free(p);
	Q->length--;
	return TRUE;
	
}

/*清空队列*/
void ClearLQueue(LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("请先初始化！！！\r\n");
	}
	else if (Q->front == Q->rear)
	{
		printf("当前队列已为空，无需清空!\r\n");
	}
	else
	{
		while (Q->front->next != NULL)
		{
			DeLQueue(Q);
		}
		printf("清空成功！");
	}
}

/*遍历队列*/
Status TraverseLQueue(const LQueue* Q /*, void (*foo)(void* q)*/) {
	if (Q->front == NULL)
	{
		printf("请先初始化！！！\r\n");
		return FALSE;
	}
	else if (Q->front == Q->rear)
	{
		printf("队列为空!\r\n");
		return FALSE;
	}
	else
	{
		Node* p;
		p = Q->front->next;
		
		while (p != NULL)
		{
			LPrint(p->data);
			p = p->next;
		}
		printf("\n");
	}
}


void LPrint(void* q) {
	printf("%s",q);
}

