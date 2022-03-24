#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#define _CRT_SECURE_NO_WARNINGS 1
#define OVERFLOW -1

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

DuLinkedList InitList_DuL(DuLinkedList* L);

void DestroyList_DuL(DuLinkedList* L);

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);

Status DeleteList_DuL(DuLNode* p, ElemType* e);

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));

DuLinkedList Position_1(DuLinkedList L);

DuLinkedList Position_2(DuLinkedList L);

DuLinkedList InsertValue();

void visit(ElemType e);

int length(DuLinkedList L);

#endif
