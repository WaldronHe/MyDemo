#include"E-commerce.h"

/*主界面*/
void menu_platform()
{
	printf("========================================================================================================================\r\n");
	printf("                                           "BLUE"欢迎使用"NONE">>"PUPRLE"QG发际线保护"NONE"<<"GREEN"电商平台"NONE"        \r\n");
	printf("========================================================================================================================\r\n");
	printf(YELLOW"                            请问您的身份是： 1.用户  2.商家             退出平台请按：0\r\n"NONE);
	int choice;
	printf("请输入选项：");
	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			menu_users();
			break;

		case 2:
			menu_sellers();
			break;

		case 0:

			return ;

		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}




/*用户界面*/
void menu_users()
{	
	printf("\r\n");
	printf(YELLOW"         欢迎来到用户登录界面\r\n"NONE);
	print();
	int num = 0;
	printf("请输入操作：");
	while (1)
	{
		scanf("%d", &num);
		gets();
		switch (num)
		{
		case 1:
			regist1();
			break;

		case 2:
			enter1();
			break;

		case 3:
			findpwd1();
			break;

		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}

/*商家界面*/
void menu_sellers()
{
	printf("\r\n");
	printf(YELLOW"         欢迎来到商家登录界面\r\n"NONE);
	print();
	int choice;
	printf("请输入操作：");
	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			regist2();
			break;

		case 2:
			enter2();
			break;

		case 3:
			findpwd2();
			break;

		case 0:
			
			return 0;

		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}

void print()
{
	printf("========================================================================================================================\r\n");
	printf("   _______________________________    \r\n");
	printf("  |                               |   \r\n");
	printf("  |"RED"            请选择"NONE"             |  \r\n");
	printf("  |                               |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"GREEN"      我是新用户--请按 1"NONE  "       |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"BLUE"      前往登录--请按 2"NONE  "         |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"PUPRLE"      忘记密码--请按 3"NONE  "         |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"CYAN"      退出--请按 0"NONE  "             |   \r\n");
	printf("  |_______________________________|   \r\n");
}

/*用户登录成功后的页面*/
void Ensucces_users()
{
	printf("===============================================================================================================\r\n");
	printf("                                        "RED"欢迎进入用户购物系统"NONE"        \r\n");
	printf("===============================================================================================================\r\n");
	printf(YELLOW"     1. 查看商品    2. 商品搜索		3.添加商品到购物车    4. 删除购物车商品    5. 查看购物车        \r\n"NONE);
	printf(YELLOW"     6. 结账    7. 管理收货地址    8. 查看账号信息    9.充值金额    0.退出并保存\r\n"NONE);
	printf("\r\n");
	printf("******************************************************************************************************\r\n");
	PLIST pList = NULL;
	pList = creation();
	readData(pList); 
	int choice = 0;
	printf("请输入操作：");
	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			printf("\r\n");
			printf(CYAN"                      *****欢迎查看商品******\r\n"NONE);
			visit_goods(pList);
			printf("请继续选择操作：");
			break;

		case 2:
			search_goods(pList);
			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			break;

		case 6:

			break;
			
		case 7:

			break;

		case 8:
			printf("\r\n");
			printf(CYAN"      *****欢迎查看账号信息******\r\n"NONE);
			look_message1();
			printf("请继续选择操作：");
			break;

		case 9:

			break;

		case 0:
			return;

		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}

/*商家登录后*/
void Ensuccess_sellers()
{
	printf("===============================================================================================================\r\n");
	printf("                                        "RED"欢迎进入商家销售系统"NONE"        \r\n");
	printf("===============================================================================================================\r\n");
	printf(YELLOW"     1. 进货    2. 查询仓库商品    3. 查看订单    4. 查看账户信息    5. 查看收益情况   6. 退出并保存\r\n"NONE);
	printf("\r\n");
	printf("******************************************************************************************************\r\n");
	PLIST pList = NULL;
	pList = creation();
	readData(pList);		/*读取数据*/
	int choice = 0;
	printf("请输入操作：");
	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			printf("\r\n");
			printf(CYAN"      *****欢迎来到进货系统******\r\n"NONE);
			insert(pList);
			printf("请继续选择操作：");
			break;

		case 2:
			printf("\r\n");
			printf(CYAN"      *****欢迎查看仓库******\r\n"NONE);
			show_goods(pList);
			printf("请继续选择操作：");
			break;

		case 3:
			printf("\r\n");
			printf(CYAN"      *****欢迎查看订单******\r\n"NONE);

			printf("请继续选择操作：");
			break;

		case 4:
			printf("\r\n");
			printf(CYAN"      *****欢迎查看账号信息******\r\n"NONE);
			look_message2();
			printf("请继续选择操作：");
			break;

		case 5:
			printf("\r\n");
			printf(CYAN"      *****欢迎查看收益情况******\r\n"NONE);

			printf("请继续选择操作：");
			break;

		case 6:
			saveData(pList);
			printf("\r\n");
			return 0;

		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}