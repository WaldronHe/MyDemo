#include"E-commerce.h"

/*���������̼���Ϣ���ļ�*/
void CreateFile2()
{
	FILE* fp;
	fp = fopen("sellers.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("sellers.txt", "w+");
		if (fp == NULL)
		{
			printf("�޷������ļ���\r\n");
			exit(0);
		}
	}
	fclose(fp);
}

/*ע��*/
void regist2()
{
	CreateFile2();
	printf(YELLOW"        ��ӭ����ע����棡\r\n"NONE);
	FILE* fp = fopen("sellers.txt", "r");		
	SELLER a, b;
	char temp[20];
	fread(&b, sizeof(SELLER), 1, fp);		/*�����̼ҽṹ��Ԫ�ص�b*/
	printf("�������û�����");
	scanf("%s", a.name);
	while (1)
	{
		if (strcmp(a.name, b.name))			/*��������ַ��������*/
		{
			if (!feof(fp))						/*����ѭ�������к������*/
				fread(&b, sizeof(SELLER), 1, fp);
			else
				break;
		}
		else
		{
			printf("���û����Ѵ��ڣ�������ѡ�����ѡ�\r\n");
			printf("�����������");
			fclose(fp);						/*�ر��ļ�*/
			return;							/*�˳�����*/
		}
	}
	printf("�������ֻ��ţ�");
	scanf("%s", a.phone);
	printf("�������������");
	scanf("%s", a.shop);
	a.RMB = 0.0;
	printf("�������û����룺");
	scanf("%s", a.passwd);
	printf("��ȷ�����룺");
	scanf("%s", temp);
	while (1)
	{
		if ((strcmp(a.passwd, temp)) == 0)			
		{
			fp = fopen("sellers.txt", "w+");
			fwrite(&a, sizeof(SELLER), 1, fp);
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
int enter2()
{
	CreateFile2();
	printf(YELLOW"        ��ӭ������¼���棡\r\n"NONE);
	FILE* fp = fopen("sellers.txt", "r");
	SELLER a, b;
	fread(&b, sizeof(SELLER), 1, fp);
	printf("�������û�����");
	scanf("%s", a.name);
	while (1)
	{
		if ((strcmp(a.name, b.name)) == 0)
		{
			if (!feof(fp))						/*����ѭ�������к������*/
				fread(&b, sizeof(SELLER), 1, fp);
			else
				break;
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
			Ensuccess_sellers();
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
void findpwd2()
{
	CreateFile2();
	printf(YELLOW"      ��ӭ�����һ�������棡\r\n"NONE);
	FILE* fp = fopen("sellers.txt", "r");
	SELLER a, b;
	char temp[20];
	fread(&b, sizeof(SELLER), 1, fp);
	printf("�������û�����");
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
			printf("���û��������ڣ�������ѡ�����ѡ�\r\n");
			printf("�����������");
			fclose(fp);
			return;
		}
	}
	printf("�������ֻ��ţ�");
	scanf("%s", a.phone);
	while ((strcmp(a.phone, b.phone)))
	{
		printf("�ֻ�������������������룺");
		scanf("%s", a.phone);
	}
	printf("�һ�����ɹ���");
	printf("���������ǣ�%s\r\n", b.passwd);
	printf("�����ѡ�������");
}





