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

/*�û��ṹ��*/
typedef struct user
{
	char name[20];	/*�û���*/
	char passwd[20];	/*����*/
	char address[50];	/*��ַ*/
	char phone[15];		/*�ֻ���*/
	float RMB;		/*Ǯ*/
}USER,*PUSER;

/*��Ʒ�ṹ��*/
typedef struct good
{
	char name[20];		/*��Ʒ��*/
	char shop[20];		/*�����̵�*/
	int count;		/*���*/
	float price;	/*�۸�*/
	char desc[100];		/*��Ʒ����*/

}GOOD,*PGOOD;

/*�̼Ҳֿ�*/
typedef struct list
{
	GOOD data;
	struct list* next;
}LIST, * PLIST;

/*�̼ҽṹ��*/
typedef struct seller
{
	char name[20];	/*�û���*/
	char shop[20];		/*������*/
	char passwd[20];	/*����*/
	char phone[15];		/*�ֻ���*/
	float RMB;		/*Ǯ*/

}SELLER, * PSELLER;


/*�û����ﳵ*/
typedef struct car
{
	GOOD data;
	struct scar* next;
}CAR,*PCAR;

/*�˵�*/
void menu_platform();
void menu_users();
void menu_sellers();
void print();

/*�̼�ע���¼�һ����빦��*/
void CreateFile2();		/*���������̼���Ϣ���ļ�*/
void regist2();		/*ע��*/
int enter2();		/*��¼*/
void findpwd2();	/*�һ�����*/


/*�̼�ģ�鹦��*/
void CreateFile3();		/*����������Ʒ��Ϣ���ļ�*/
PLIST creation();		/*�����ս��*/
Status add_goods(char name[], int count, float price, char desc[], char shop[], LIST* p);		/*����*/
Status insert(PLIST pList);
void saveData(PLIST pList);			/*������Ʒ��Ϣ*/
void readData(PLIST pList);			/*��ȡ��Ʒ��Ϣ*/
Status show_goods(PLIST pList);		/*�鿴��Ʒ*/
void look_message2();		/*�鿴�˻���Ϣ*/


/*�û�ע���¼�һ����빦��*/
void CreateFile1();		/*���������û���Ϣ���ļ�*/
void regist1();		/*ע��*/
int enter1();		/*��¼*/
void findpwd1();	/*�һ�����*/


/*�û�ģ�鹦��*/
void look_message1();		/*�鿴�˻���Ϣ*/
Status visit_goods(PLIST pList);	/*�鿴��Ʒ*/
Status search_goods(PLIST pList);		/*������Ʒ*/

#endif // !_E-COMMERCE_H_



