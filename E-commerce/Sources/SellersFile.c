#include"E-commerce.h"

/*创建储存商家信息的文件*/
void CreateFile2()
{
	FILE* fp;
	fp = fopen("sellers.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("sellers.txt", "w+");
		if (fp == NULL)
		{
			printf("无法建立文件！\r\n");
			exit(0);
		}
	}
	fclose(fp);
}

/*注册*/
void regist2()
{
	CreateFile2();
	printf(YELLOW"        欢迎来到注册界面！\r\n"NONE);
	FILE* fp = fopen("sellers.txt", "r");		
	SELLER a, b;
	char temp[20];
	fread(&b, sizeof(SELLER), 1, fp);		/*读入商家结构体元素到b*/
	printf("请输入用户名：");
	scanf("%s", a.name);
	while (1)
	{
		if (strcmp(a.name, b.name))			/*如果两个字符串不相等*/
		{
			if (!feof(fp))						/*跳出循环，进行后面操作*/
				fread(&b, sizeof(SELLER), 1, fp);
			else
				break;
		}
		else
		{
			printf("此用户名已存在，请重新选择操作选项！\r\n");
			printf("请输入操作：");
			fclose(fp);						/*关闭文件*/
			return;							/*退出函数*/
		}
	}
	printf("请输入手机号：");
	scanf("%s", a.phone);
	printf("请输入店铺名：");
	scanf("%s", a.shop);
	a.RMB = 0.0;
	printf("请输入用户密码：");
	scanf("%s", a.passwd);
	printf("请确认密码：");
	scanf("%s", temp);
	while (1)
	{
		if ((strcmp(a.passwd, temp)) == 0)			
		{
			fp = fopen("sellers.txt", "w+");
			fwrite(&a, sizeof(SELLER), 1, fp);
			printf("注册成功，请继续选择操作：");
			fclose(fp);
			break;

		}
		else
		{
			printf("两次密码不匹配，请重新输入：");
			scanf("%s", a.passwd);
			printf("请确认密码：");
			scanf("%s", temp);
		}
	}
}

/*登录*/
int enter2()
{
	CreateFile2();
	printf(YELLOW"        欢迎来到登录界面！\r\n"NONE);
	FILE* fp = fopen("sellers.txt", "r");
	SELLER a, b;
	fread(&b, sizeof(SELLER), 1, fp);
	printf("请输入用户名：");
	scanf("%s", a.name);
	while (1)
	{
		if ((strcmp(a.name, b.name)) == 0)
		{
			if (!feof(fp))						/*跳出循环，进行后面操作*/
				fread(&b, sizeof(SELLER), 1, fp);
			else
				break;
		}
		else
		{
			printf("此用户名不存在，请重新选择操作选项！\r\n");
			printf("请输入操作：");
			fclose(fp);
			return 0;
		}
	}
	printf("请输入密码：");
	scanf("%s", a.passwd);
	while (1)
	{
		if ((strcmp(a.passwd, b.passwd)) == 0)
		{
			printf("登录成功 *_* ！\r\n");
			fclose(fp);
			Ensuccess_sellers();
			return 0;
		}
		else
		{
			printf("密码不正确，请重新输入：");
			scanf("%s", a.passwd);
		}
	}
}

/*找回密码*/
void findpwd2()
{
	CreateFile2();
	printf(YELLOW"      欢迎来到找回密码界面！\r\n"NONE);
	FILE* fp = fopen("sellers.txt", "r");
	SELLER a, b;
	char temp[20];
	fread(&b, sizeof(SELLER), 1, fp);
	printf("请输入用户名：");
	scanf("%s", a.name);
	while (1)
	{
		if ((strcmp(a.name, b.name)) == 0)
		{
			if (!feof(fp))						
				fread(&b, sizeof(SELLER), 1, fp);
			else
				break;
		}
		else
		{
			printf("此用户名不存在，请重新选择操作选项！\r\n");
			printf("请输入操作：");
			fclose(fp);
			return;
		}
	}
	printf("请输入手机号：");
	scanf("%s", a.phone);
	while ((strcmp(a.phone, b.phone)))
	{
		printf("手机号输入错误，请重新输入：");
		scanf("%s", a.phone);
	}
	printf("找回密码成功！");
	printf("您的密码是：%s\r\n", b.passwd);
	printf("请继续选择操作：");
}





