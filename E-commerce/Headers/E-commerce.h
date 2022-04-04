#ifndef _E_COMMERCE_H_
#define _E_COMMERCE_H_

#define _CRT_SECURE_NO_WARNINGS 1

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define NONE "\033[m"
#define PUPRLE "\033[1;35m"
#define CYAN "\033[1;36m"

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

/*用户结构体*/
typedef struct user
{
	char name[20];	/*用户名*/
	char passwd[20];	/*密码*/
	char address[50];	/*地址*/
	char phone[15];		/*手机号*/
	float RMB;		/*钱*/
}USER,*PUSER;

/*商品结构体*/
typedef struct good
{
	char name[20];		/*商品名*/
	char shop[20];		/*所属商店*/
	int count;		/*库存*/
	float price;	/*价格*/
	char desc[100];		/*商品介绍*/

}GOOD,*PGOOD;

/*商家仓库*/
typedef struct list
{
	GOOD data;
	struct list* next;
}LIST, * PLIST;

/*商家结构体*/
typedef struct seller
{
	char name[20];	/*用户名*/
	char shop[20];		/*店铺名*/
	char passwd[20];	/*密码*/
	char phone[15];		/*手机号*/
	float RMB;		/*钱*/

}SELLER, * PSELLER;


/*用户购物车*/
typedef struct car
{
	GOOD data;
	struct scar* next;
}CAR,*PCAR;

/*菜单*/
void menu_platform();
void menu_users();
void menu_sellers();
void print();

/*商家注册登录找回密码功能*/
void CreateFile2();		/*创建储存商家信息的文件*/
void regist2();		/*注册*/
int enter2();		/*登录*/
void findpwd2();	/*找回密码*/


/*商家模块功能*/
void CreateFile3();		/*创建储存商品信息的文件*/
PLIST creation();		/*创建空结点*/
Status add_goods(char name[], int count, float price, char desc[], char shop[], LIST* p);		/*进货*/
Status insert(PLIST pList);
void saveData(PLIST pList);			/*保存商品信息*/
void readData(PLIST pList);			/*读取商品信息*/
Status show_goods(PLIST pList);		/*查看商品*/
void look_message2();		/*查看账户信息*/


/*用户注册登录找回密码功能*/
void CreateFile1();		/*创建储存用户信息的文件*/
void regist1();		/*注册*/
int enter1();		/*登录*/
void findpwd1();	/*找回密码*/


/*用户模块功能*/
void look_message1();		/*查看账户信息*/
Status visit_goods(PLIST pList);	/*查看商品*/
Status search_goods(PLIST pList);		/*查找商品*/

#endif // !_E-COMMERCE_H_



