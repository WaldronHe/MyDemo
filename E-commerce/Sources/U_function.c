#include"E-commerce.h"

void look_message1()
{
	USER a;
	char passwd[20];
	printf("���������룺");
	scanf("%s", passwd);
	FILE* fp = fopen("users.txt", "r");
	fread(&a, sizeof(USER), 1, fp);
	while (1)
	{
		if ((strcmp(a.passwd, passwd)) == 0)
		{
			printf("������ȷ *_* ��\r\n");
			fclose(fp);
			printf("�û�����%s\t���룺%s\t�ֻ��ţ�%s\t��%f\t�ջ���ַ��%s\r\n", a.name, a.passwd, a.phone, a.RMB, a.address);
			return ;
		}
		else
		{
			printf("���벻��ȷ�����������룺");
			scanf("%s", passwd);
		}
	}
}
Status visit_goods(PLIST pList)
{

	if (NULL == pList || NULL == pList->next)		/*����Ϊ��*/
	{
		printf("ƽ̨���ݻ�û����Ʒ��\r\n");
		return ERROR;
	}
	int count = 0;
	LIST* p = pList->next;
	while (NULL != p)
	{
		count++;
		printf("****************************************************************************\r\n");
		printf(YELLOW"��Ʒ����\t��Ʒ����\t����\t\t��Ʒ����\t��Ʒ�����̵�\r\n"NONE);
		printf(YELLOW"%s\t\t%d\t\t%f\t%s\t\t%s\r\n"NONE, p->data.name, p->data.count, p->data.price, p->data.desc, p->data.shop);
		p = p->next;
	}
	printf("��Ʒ������Ϊ %d \r\n", count);

	return SUCCESS;
}

Status search_goods(PLIST pList)
{
	char name[20];
	printf("��������Ʒ���ƣ�");
	scanf("%s", name);
	LIST* p = pList->next;
	FILE* fp = ("goods.txt", "r");
	fread(&p->data, sizeof(LIST), 1, fp);

	while (NULL != p)
	{
		if ((strcmp(p->data.name, name)) == 0)
		{
			printf("��Ʒ�����ƣ�%s\r\n", p->data.name);
			printf("��Ʒ��������%d\r\n", p->data.count);
			printf("��Ʒ�Ľ��ܣ�%s\r\n", p->data.desc);
			printf("��Ʒ�������̣�%s\r\n", p->data.shop);
			printf("\r\n");
			return SUCCESS;
		}
		else
		{
			p = p->next;
		}
	}
	printf("��Ǹ���Ҳ�������Ʒ��\r\n");

}