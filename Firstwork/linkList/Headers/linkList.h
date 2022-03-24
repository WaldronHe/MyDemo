#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define _CRT_SECURE_NO_WARNINGS 1
#define OVERFLOW -1

#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

void DestroyList(LinkedList* L);

Status InsertList(LNode* p, LNode* q);

Status DeleteList(LNode* p, ElemType* e);

void TraverseList(LinkedList L, void (*visit)(ElemType e));

Status SearchList(LinkedList L, ElemType e);

Status ReverseList(LinkedList* L);

Status IsLoopList(LinkedList L);

LNode* ReverseEvenList(LinkedList* L);

LNode* FindMidNode(LinkedList* L);

LinkedList CreateList();

LinkedList Position(LinkedList L, ElemType e);

LinkedList InsertValue();

void visit(ElemType e);

int length(LinkedList L);

#endif
