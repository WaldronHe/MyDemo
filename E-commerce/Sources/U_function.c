#include"E-commerce.h"

void look_message1()
{
	USER a;
	char passwd[20];
	printf("请输入密码：");
	scanf("%s", passwd);
	FILE* fp = fopen("users.txt", "r");
	fread(&a, sizeof(USER), 1, fp);
	while (1)
	{
		if ((strcmp(a.passwd, passwd)) == 0)
		{
			printf("密码正确 *_* ！\r\n");
			fclose(fp);
			printf("用户名：%s\t密码：%s\t手机号：%s\t余额：%f\t收货地址：%s\r\n", a.name, a.passwd, a.phone, a.RMB, a.address);
			return ;
		}
		else
		{
			printf("密码不正确，请重新输入：");
			scanf("%s", passwd);
		}
	}
}
Status visit_goods(PLIST pList)
{

	if (NULL == pList || NULL == pList->next)		/*链表为空*/
	{
		printf("平台上暂还没有商品！\r\n");
		return ERROR;
	}
	int count = 0;
	LIST* p = pList->next;
	while (NULL != p)
	{
		count++;
		printf("****************************************************************************\r\n");
		printf(YELLOW"商品名称\t商品数量\t单价\t\t商品介绍\t商品所属商店\r\n"NONE);
		printf(YELLOW"%s\t\t%d\t\t%f\t%s\t\t%s\r\n"NONE, p->data.name, p->data.count, p->data.price, p->data.desc, p->data.shop);
		p = p->next;
	}
	printf("商品的种类为 %d \r\n", count);

	return SUCCESS;
}

Status search_goods(PLIST pList)
{
	char name[20];
	printf("请输入商品名称：");
	scanf("%s", name);
	LIST* p = pList->next;
	FILE* fp = ("goods.txt", "r");
	fread(&p->data, sizeof(LIST), 1, fp);

	while (NULL != p)
	{
		if ((strcmp(p->data.name, name)) == 0)
		{
			printf("商品的名称：%s\r\n", p->data.name);
			printf("商品的数量：%d\r\n", p->data.count);
			printf("商品的介绍：%s\r\n", p->data.desc);
			printf("商品所属店铺：%s\r\n", p->data.shop);
			printf("\r\n");
			return SUCCESS;
		}
		else
		{
			p = p->next;
		}
	}
	printf("抱歉，找不到此商品！\r\n");

}