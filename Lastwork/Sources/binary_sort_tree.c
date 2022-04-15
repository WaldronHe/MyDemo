#include "binary_sort_tree.h"


Status BST_init(BinarySortTreePtr T)
{

	T->root = (NodePtr)malloc(sizeof(Node));
	if (NULL == T->root)
	{
		printf("�ڴ����ʧ�ܣ�\r\n");
		return failed;
	}
	T->root->left = T->root->right = NULL;
	ElemType key;
	printf("��������ڵ����ݣ�");
	scanf("%d", &key);
	T->root->value = key;
	printf("��ʼ���ɹ���\r\n");
	return succeed;
}

Status BST_insert(BinarySortTreePtr T, ElemType key)
{
	NodePtr p = NULL;
	NodePtr new = (NodePtr)malloc(sizeof(Node));
	if (NULL == new)
	{
		printf("�ڴ����ʧ�ܣ�\r\n");
		return failed;
	}
	new->value = key;
	new->left = NULL;
	new->right = NULL;
	if (key == T->root->value)
	{
		printf("����ʧ�ܣ��Ѵ�����ͬԪ�أ�\r\n");
		return failed;
	}
	else
	{
		if (key < T->root->value)
		{
			if (NULL == T->root->left)
			{
				T->root->left = new;
			}
			else
			{
				p = T->root->left;
				return BST_insert(&p, key);
			}
		}
		else
		{
			if (NULL == T->root->right)
			{
				T->root->right = new;
			}
			else
			{
				p = T->root->right;
				return BST_insert(&p, key);
			}

		}
	}
}

Status BST_delete(BinarySortTreePtr T, ElemType key)
{
	NodePtr p = NULL;
	if (!T->root)
		printf("��Ԫ�ز��ڶ������У�\r\n");
	else if (key < T->root->value)
		T->root->left = BST_delete(&(T->root->left), key);
	else if(key>T->root->value)
		T->root->right= BST_delete(&(T->root->right), key);
	else
	{
		if (T->root->left && T->root->right)
		{
			p = Find_min(T->root->right);
			T->root->value = p->value;
			T->root->right = BST_delete(&(T->root->right), T->root->value);
		}
		else
		{
			if (!T->root->left)
				T->root = T->root->right;
			else if (!T->root->right)
				T->root = T->root->left;
		}
	}
	
}

NodePtr Find_min(NodePtr p)
{
	if (!p)
		return NULL;
	else if (!p->left)
		return p;
	else
		return Find_min(p->left);
}


Status BST_search(BinarySortTreePtr T, ElemType key)
{	
	BinarySortTree p;
	if (NULL == T->root)
	{
		printf("��Ԫ�ز��ڶ�������\r\n");
		return failed;
	}
	else if (key == T->root->value)
	{
		printf("��Ԫ���ڶ�������\r\n");
		return succeed;
	}
	else if (key < T->root->value)
	{
		p.root = T->root->left;
		return BST_search(&p, key);
	}
	else
	{
		p.root = T->root->right;
		return BST_search(&p, key);
	}
	
}


Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
	BinarySortTree p,q;
	visit(T->root);
	if (T->root->left != NULL)
	{
		p.root = T->root->left;
		BST_preorderI(&p, visit);
	}	
	if (NULL != T->root->right)
	{
		q.root = T->root->right;
		BST_preorderI(&q, visit);
	}
}
/*
Status BST_preorderR(BinarySortTreePtr, void (*visit)(NodePtr))
{

}
*/
Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
	BinarySortTree p, q;
	if (T->root->left != NULL)
	{
		p.root = T->root->left;
		BST_preorderI(&p, visit);
	}
	visit(T->root);
	if (NULL != T->root->right)
	{
		q.root = T->root->right;
		BST_preorderI(&q, visit);
	}
}
/*
Status BST_inorderR(BinarySortTreePtr, void (*visit)(NodePtr))
{

}
*/

Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
	BinarySortTree p, q;
	if (T->root->left != NULL)
	{
		p.root = T->root->left;
		BST_preorderI(&p, visit);
	}
	if (NULL != T->root->right)
	{
		q.root = T->root->right;
		BST_preorderI(&q, visit);
	}
	visit(T->root);
}
/*
Status BST_postorderR(BinarySortTreePtr, void (*visit)(NodePtr))
{

}

Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr))
{

}
*/


void visit(NodePtr root)
{
	printf("%d ", root->value);
}

