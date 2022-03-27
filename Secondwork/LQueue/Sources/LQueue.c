#include "LQueue.h" 

/*��ʼ������*/
void InitLQueue(LQueue* Q) {
	Q->front = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\r\n");
		return FALSE;
	}
	Q->rear = Q->front;
	Q->front->next == NULL;
	Q->length = 0;
	printf("��ʼ���ɹ�!\r\n");

}

/*���ٶ���*/
void DestoryLQueue(LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("���ȳ�ʼ��������\r\n");
	}
	else
	{	
		while (Q->front != Q->rear)			/*��ն���*/
		{	
			Node* p;						
			p = Q->front->next;				/*����ɾ���Ķ�ͷ����ݴ��p*/
			Q->front->next = p->next;		/*��ԭ��ͷ�����p->next��ֵ��ͷ�����*/
			if (Q->rear == p)				/*����ͷ�Ƕ�β��ɾ����rearָ��ͷ���*/
				Q->rear = Q->front;
			free(p);
		}
		free(Q->front);						/*���ٶ���*/
		Q->front = Q->rear = NULL;
		printf("���ٳɹ���\r\n");
	}
}

/* �������Ƿ�Ϊ��*/
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("���ȳ�ʼ��������\r\n");
		return FALSE;
	}
	LQueue* p;
	p = Q;
	if (p->front == p->rear)
	{
		printf("����һ���ն��У�\r\n");
		return TRUE;
	}
	else
	{
		printf("�ⲻ��һ���ն��У�\r\n");
		return TRUE;
	}
}

/*�鿴��ͷԪ��*/
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

 /*ȷ�����г���*/
int LengthLQueue(LQueue* Q) {

	int len;
	len = Q->length;
	return len;

}

 /*��Ӳ���*/
Status EnLQueue(LQueue* Q, void* data) {

	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("����ʧ�ܣ�������ֹ��\r\n");
		return FALSE;
	}
	new->data = data;
	new->next = NULL;
	Q->rear->next = new;		/*��ӵ��Ԫ��data�½��new��ֵ��ԭ��β���ĺ��*/
	Q->rear = new;				/*�ѵ�ǰ��new����Ϊ��β��㣬rearָ��new*/
	Q->length++;
	return TRUE;
}

/*���Ӳ���*/
Status DeLQueue(LQueue* Q) {

	if (Q->front == Q->rear)
	{
		printf("���Ӵ��󣬶���Ϊ�գ�\r\n");
		return FALSE;
	}
	Node* p;
	p = Q->front->next;				/*����ɾ���Ķ�ͷ����ݴ��p*/
	Q->front->next = p->next;		/*��ԭ��ͷ�����p->next��ֵ��ͷ�����*/
	if (Q->rear == p)				/*����ͷ�Ƕ�β��ɾ����rearָ��ͷ���*/
		Q->rear = Q->front;
	free(p);
	Q->length--;
	return TRUE;
	
}

/*��ն���*/
void ClearLQueue(LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("���ȳ�ʼ��������\r\n");
	}
	else if (Q->front == Q->rear)
	{
		printf("��ǰ������Ϊ�գ��������!\r\n");
	}
	else
	{
		while (Q->front->next != NULL)
		{
			DeLQueue(Q);
		}
		printf("��ճɹ���");
	}
}

/*��������*/
Status TraverseLQueue(const LQueue* Q /*, void (*foo)(void* q)*/) {
	if (Q->front == NULL)
	{
		printf("���ȳ�ʼ��������\r\n");
		return FALSE;
	}
	else if (Q->front == Q->rear)
	{
		printf("����Ϊ��!\r\n");
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

