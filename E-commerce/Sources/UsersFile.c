#include"E-commerce.h"

/*���������û���Ϣ���ļ�*/
void CreateFile1()
{
	FILE* fp;
	fp = fopen("users.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("users.txt", "w+");
		if (fp == NULL)
		{
			printf("�޷������ļ���\r\n");
			exit(0);
		}
	}
	fclose(fp);
}

/*ע��*/
void regist1()
{
	CreateFile1();
	printf(YELLOW"        ��ӭ����ע����棡\r\n"NONE);
	FILE* fp = fopen("users.txt", "r");
	USER a, b;
	char temp[20];
	fread(&b, sizeof(USER), 1, fp);
	printf("�������û�����");
	scanf("%s", a.name);
	while (1)
	{
		if (strcmp(a.name, b.name))
		{
			if (!feof(fp))		/*���δ���ļ�β*/
			{
				fread(&b, sizeof(USER), 1, fp);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("���û����Ѵ��ڣ�������ѡ�����ѡ�\r\n");
			printf("�����������");
			fclose(fp);
			return;
		}
	}
	printf("�������ֻ��ţ�");
	scanf("%s", a.phone);
	printf("�������ֵ��");
	scanf("%f", &a.RMB);
	printf("�������ջ���ַ��");
	scanf("%s", &a.address);
	printf("�������û����룺");
	scanf("%s", a.passwd);
	printf("��ȷ�����룺");
	scanf("%s", temp);
	while (1)
	{
		if ((strcmp(a.passwd, temp)) == 0)
		{
			fp = fopen("users.txt", "a");
			fwrite(&a, sizeof(USER), 1, fp);
			printf("ע��ɹ��������ѡ�������");
			fclose(fp);
			break;
			
		}
		else
		{
			printf("�������벻ƥ�䣬���������룺");
			scanf("%s", a.passwd);
			printf("��ȷ�����룺");
			scanf("%s", temp);
		}
	}
}

/*��¼*/
int enter1()
{
	CreateFile1();
	printf(YELLOW"        ��ӭ������¼���棡\r\n"NONE);
	FILE* fp = fopen("users.txt", "r");
	USER a, b;
	fread(&b, sizeof(USER), 1, fp);
	printf("�������û�����");
	scanf("%s", a.name);
	while (1)
	{
		if ((strcmp(a.name, b.name)) == 0)
		{
			if (!feof(fp))		/*���δ���ļ�β*/
			{
				fread(&b, sizeof(USER), 1, fp);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("���û��������ڣ�������ѡ�����ѡ�\r\n");
			printf("�����������");
			fclose(fp);
			return 0;
		}
	}
	printf("���������룺");
	scanf("%s", a.passwd);
	while (1)
	{
		if ((strcmp(a.passwd, b.passwd)) == 0)
		{
			printf("��¼�ɹ� *_* ��\r\n");
			fclose(fp);
			Ensucces_users();
			return 0;
		}
		else
		{
			printf("���벻��ȷ�����������룺");
			scanf("%s", a.passwd);
		}
	}
}

/*�һ�����*/
void findpwd1()
{
	CreateFile1();
	printf(YELLOW"      ��ӭ�����һ�������棡\r\n"NONE);
	FILE* fp = fopen("users.txt", "r");
	USER a, b;
	char temp[20];
	fread(&b, sizeof(USER), 1, fp);
	printf("�������û�����");
	scanf("%s", a.name);
	while (1)
	{
		if ((strcmp(a.name, b.name)) == 0)
		{
			if (!feof(fp))		/*���δ���ļ�β*/
			{
				fread(&b, sizeof(USER), 1, fp);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("���û��������ڣ�������ѡ�����ѡ�\r\n");
			printf("�����������");
			fclose(fp);
			return ;
		}
	}
	printf("�������ֻ��ţ�");
	scanf("%s", a.phone);
	while ((strcmp(a.phone,b.phone)))
	{
		printf("�ֻ�������������������룺");
		scanf("%s", a.phone);
	}
	printf("�һ�����ɹ���");
	printf("���������ǣ�%s\n", b.passwd);
	printf("�����ѡ�������");
}