#include"E-commerce.h"
/*商家进货并放入仓库*/

/*储存商品信息*/
void CreateFile3()
{
	FILE* fp;
	fp = fopen("goods.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("goods.txt", "w+");
		if (fp == NULL)
		{
			printf("无法建立文件！\r\n");
			exit(0);
		}
	}
	fclose(fp);
}

/*创建空结点*/
PLIST creation()
{
	PLIST pList = NULL;		/*定义指针变量*/
	pList = (PLIST)malloc(sizeof(LIST));
	if (pList == NULL)		/*判断，初始化*/
	{
		printf("内存分配失败！\r\n");
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
	if (pList == NULL)		/*判断链表是否存在*/
	{
		return ERROR;
	}
	PLIST p = creation();
	char name[20];
	int count = 0;
	float price = 0;
	char desc[100];
	char shop[20];
	printf("请输入商品名：");
	scanf("%s", &name);
	printf("请输入您的店铺名：");
	scanf("%s", shop);
	printf("请输入商品数量：");
	scanf("%d", &count);
	printf("进货成功！\r\n");
	printf("请设置商品销售单价：");
	scanf("%f", &price);
	printf("请介绍商品信息：");
	scanf("%s", desc);
	if (add_goods(name, count, price, desc, shop, p))
	{
		p->next = pList->next;
		pList->next = p;
		printf("商品 %s 已经成功添加至仓库\r\n", p->data.name);
		return SUCCESS;
	}
}

void saveData(PLIST pList)
{
	if (NULL == pList || NULL == pList->next)		/*判断链表是否为空*/
	{
		printf("您没有商品信息不用保存\r\n");
		return;
	}
	CreateFile3();
	FILE* fp;		/*定义一个文件指针*/
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
	fclose(fp);		/*关闭文件*/
	printf("信息已保存！\r\n");
	return;
}

/*读取数据*/
void readData(PLIST pList)
{
	if (NULL == pList)
	{
		printf("读取数据失败！\r\n");
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
		p->next = pList->next;			/*头插法插入结点*/
		pList->next = p;
		count++;
		p = creation();					/*创建结点*/
		fread(&p->data, sizeof(LIST), 1, fp);		/*赋值给结点*/
	}
	fclose(fp);				/*关闭文件*/
	return;
}

Status show_goods(PLIST pList)
{
	if (NULL == pList || NULL == pList->next)		/*链表为空*/
	{
		printf("您的仓库内没有商品！\r\n");
		return ERROR;
	}
	int count = 0;
	LIST* p = pList->next;
	while (NULL != p)
	{
		count++;
		printf("商品的名称：%s\r\n", p->data.name);
		printf("商品的数量：%d\r\n", p->data.count);
		printf("商品所属店铺：%s\r\n", p->data.shop);
		printf("\r\n");
		p = p->next;
	}
	printf("商品的种类为 %d \r\n", count);

	return SUCCESS;
}

void look_message2()
{
	SELLER a;
	char passwd[20];
	printf("请输入密码：");
	scanf("%s", passwd);
	FILE* fp = fopen("sellers.txt", "r");
	fread(&a, sizeof(SELLER), 1, fp);
	while (1)
	{
		if ((strcmp(a.passwd,passwd)) == 0)
		{
			printf("密码正确 *_* ！\r\n");
			fclose(fp);
			printf("用户名：%s\t密码：%s\t手机号：%s\t店铺名：%s\r\n", a.name, a.passwd, a.phone, a.shop);
			return 0;
		}
		else
		{
			printf("密码不正确，请重新输入：");
			scanf("%s", passwd);
		}
	}
}