#include"E-commerce.h"
/*�̼ҽ���������ֿ�*/

/*������Ʒ��Ϣ*/
void CreateFile3()
{
	FILE* fp;
	fp = fopen("goods.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("goods.txt", "w+");
		if (fp == NULL)
		{
			printf("�޷������ļ���\r\n");
			exit(0);
		}
	}
	fclose(fp);
}

/*�����ս��*/
PLIST creation()
{
	PLIST pList = NULL;		/*����ָ�����*/
	pList = (PLIST)malloc(sizeof(LIST));
	if (pList == NULL)		/*�жϣ���ʼ��*/
	{
		printf("�ڴ����ʧ�ܣ�\r\n");
		return NULL;
	}
	pList->next = NULL;

	return pList;
}

Status add_goods(char name[], int count, float price, char desc[], char shop[], LIST* p) {
	if (p == NULL)
	{
		return ERROR;
	}
	strcpy(p->data.name, name);
	p->data.count = count;
	p->data.price = price;
	strcpy(p->data.desc, desc);
	strcpy(p->data.shop, shop);
	return SUCCESS;
}

Status insert(PLIST pList)
{
	if (pList == NULL)		/*�ж������Ƿ����*/
	{
		return ERROR;
	}
	PLIST p = creation();
	char name[20];
	int count = 0;
	float price = 0;
	char desc[100];
	char shop[20];
	printf("��������Ʒ����");
	scanf("%s", &name);
	printf("���������ĵ�������");
	scanf("%s", shop);
	printf("��������Ʒ������");
	scanf("%d", &count);
	printf("�����ɹ���\r\n");
	printf("��������Ʒ���۵��ۣ�");
	scanf("%f", &price);
	printf("�������Ʒ��Ϣ��");
	scanf("%s", desc);
	if (add_goods(name, count, price, desc, shop, p))
	{
		p->next = pList->next;
		pList->next = p;
		printf("��Ʒ %s �Ѿ��ɹ�������ֿ�\r\n", p->data.name);
		return SUCCESS;
	}
}

void saveData(PLIST pList)
{
	if (NULL == pList || NULL == pList->next)		/*�ж������Ƿ�Ϊ��*/
	{
		printf("��û����Ʒ��Ϣ���ñ���\r\n");
		return;
	}
	CreateFile3();
	FILE* fp;		/*����һ���ļ�ָ��*/
	fp = fopen("goods.txt", "w+");
	PLIST p = NULL;	
	while (NULL != pList->next)
	{
		p = pList->next;
		pList->next = p->next;
		fwrite(&p->data, sizeof(LIST), 1, fp);
		free(p);
		p = NULL;
	}
	free(pList);
	pList = NULL;
	fclose(fp);		/*�ر��ļ�*/
	printf("��Ϣ�ѱ��棡\r\n");
	return;
}

/*��ȡ����*/
void readData(PLIST pList)
{
	if (NULL == pList)
	{
		printf("��ȡ����ʧ�ܣ�\r\n");
		return;
	}
	FILE* fp = fopen("goods.txt", "r");
	if (NULL == fp)
	{
		return;
	}
	int count = 0;
	LIST* p = NULL;
	p = creation();
	fread(&p->data, sizeof(LIST), 1, fp);
	while (!feof(fp))			
	{
		p->next = pList->next;			/*ͷ�巨������*/
		pList->next = p;
		count++;
		p = creation();					/*�������*/
		fread(&p->data, sizeof(LIST), 1, fp);		/*��ֵ�����*/
	}
	fclose(fp);				/*�ر��ļ�*/
	return;
}

Status show_goods(PLIST pList)
{
	if (NULL == pList || NULL == pList->next)		/*����Ϊ��*/
	{
		printf("���Ĳֿ���û����Ʒ��\r\n");
		return ERROR;
	}
	int count = 0;
	LIST* p = pList->next;
	while (NULL != p)
	{
		count++;
		printf("��Ʒ�����ƣ�%s\r\n", p->data.name);
		printf("��Ʒ��������%d\r\n", p->data.count);
		printf("��Ʒ�������̣�%s\r\n", p->data.shop);
		printf("\r\n");
		p = p->next;
	}
	printf("��Ʒ������Ϊ %d \r\n", count);

	return SUCCESS;
}

void look_message2()
{
	SELLER a;
	char passwd[20];
	printf("���������룺");
	scanf("%s", passwd);
	FILE* fp = fopen("sellers.txt", "r");
	fread(&a, sizeof(SELLER), 1, fp);
	while (1)
	{
		if ((strcmp(a.passwd,passwd)) == 0)
		{
			printf("������ȷ *_* ��\r\n");
			fclose(fp);
			printf("�û�����%s\t���룺%s\t�ֻ��ţ�%s\t��������%s\r\n", a.name, a.passwd, a.phone, a.shop);
			return 0;
		}
		else
		{
			printf("���벻��ȷ�����������룺");
			scanf("%s", passwd);
		}
	}
}