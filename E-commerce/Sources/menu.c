#include"E-commerce.h"

/*������*/
void menu_platform()
{
	printf("========================================================================================================================\r\n");
	printf("                                           "BLUE"��ӭʹ��"NONE">>"PUPRLE"QG�����߱���"NONE"<<"GREEN"����ƽ̨"NONE"        \r\n");
	printf("========================================================================================================================\r\n");
	printf(YELLOW"                            ������������ǣ� 1.�û�  2.�̼�             �˳�ƽ̨�밴��0\r\n"NONE);
	int choice;
	printf("������ѡ�");
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
			printf("����������������룺");
			break;
		}
	}
}




/*�û�����*/
void menu_users()
{	
	printf("\r\n");
	printf(YELLOW"         ��ӭ�����û���¼����\r\n"NONE);
	print();
	int num = 0;
	printf("�����������");
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
			printf("����������������룺");
			break;
		}
	}
}

/*�̼ҽ���*/
void menu_sellers()
{
	printf("\r\n");
	printf(YELLOW"         ��ӭ�����̼ҵ�¼����\r\n"NONE);
	print();
	int choice;
	printf("�����������");
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
			printf("����������������룺");
			break;
		}
	}
}

void print()
{
	printf("========================================================================================================================\r\n");
	printf("   _______________________________    \r\n");
	printf("  |                               |   \r\n");
	printf("  |"RED"            ��ѡ��"NONE"             |  \r\n");
	printf("  |                               |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"GREEN"      �������û�--�밴 1"NONE  "       |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"BLUE"      ǰ����¼--�밴 2"NONE  "         |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"PUPRLE"      ��������--�밴 3"NONE  "         |   \r\n");
	printf("  |                               |   \r\n");
	printf("  |"CYAN"      �˳�--�밴 0"NONE  "             |   \r\n");
	printf("  |_______________________________|   \r\n");
}

/*�û���¼�ɹ����ҳ��*/
void Ensucces_users()
{
	printf("===============================================================================================================\r\n");
	printf("                                        "RED"��ӭ�����û�����ϵͳ"NONE"        \r\n");
	printf("===============================================================================================================\r\n");
	printf(YELLOW"     1. �鿴��Ʒ    2. ��Ʒ����		3.�����Ʒ�����ﳵ    4. ɾ�����ﳵ��Ʒ    5. �鿴���ﳵ        \r\n"NONE);
	printf(YELLOW"     6. ����    7. �����ջ���ַ    8. �鿴�˺���Ϣ    9.��ֵ���    0.�˳�������\r\n"NONE);
	printf("\r\n");
	printf("******************************************************************************************************\r\n");
	PLIST pList = NULL;
	pList = creation();
	readData(pList); 
	int choice = 0;
	printf("�����������");
	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			printf("\r\n");
			printf(CYAN"                      *****��ӭ�鿴��Ʒ******\r\n"NONE);
			visit_goods(pList);
			printf("�����ѡ�������");
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
			printf(CYAN"      *****��ӭ�鿴�˺���Ϣ******\r\n"NONE);
			look_message1();
			printf("�����ѡ�������");
			break;

		case 9:

			break;

		case 0:
			return;

		default:
			printf("����������������룺");
			break;
		}
	}
}

/*�̼ҵ�¼��*/
void Ensuccess_sellers()
{
	printf("===============================================================================================================\r\n");
	printf("                                        "RED"��ӭ�����̼�����ϵͳ"NONE"        \r\n");
	printf("===============================================================================================================\r\n");
	printf(YELLOW"     1. ����    2. ��ѯ�ֿ���Ʒ    3. �鿴����    4. �鿴�˻���Ϣ    5. �鿴�������   6. �˳�������\r\n"NONE);
	printf("\r\n");
	printf("******************************************************************************************************\r\n");
	PLIST pList = NULL;
	pList = creation();
	readData(pList);		/*��ȡ����*/
	int choice = 0;
	printf("�����������");
	while (1)
	{
		scanf("%d", &choice);
		gets();
		switch (choice)
		{
		case 1:
			printf("\r\n");
			printf(CYAN"      *****��ӭ��������ϵͳ******\r\n"NONE);
			insert(pList);
			printf("�����ѡ�������");
			break;

		case 2:
			printf("\r\n");
			printf(CYAN"      *****��ӭ�鿴�ֿ�******\r\n"NONE);
			show_goods(pList);
			printf("�����ѡ�������");
			break;

		case 3:
			printf("\r\n");
			printf(CYAN"      *****��ӭ�鿴����******\r\n"NONE);

			printf("�����ѡ�������");
			break;

		case 4:
			printf("\r\n");
			printf(CYAN"      *****��ӭ�鿴�˺���Ϣ******\r\n"NONE);
			look_message2();
			printf("�����ѡ�������");
			break;

		case 5:
			printf("\r\n");
			printf(CYAN"      *****��ӭ�鿴�������******\r\n"NONE);

			printf("�����ѡ�������");
			break;

		case 6:
			saveData(pList);
			printf("\r\n");
			return 0;

		default:
			printf("����������������룺");
			break;
		}
	}
}