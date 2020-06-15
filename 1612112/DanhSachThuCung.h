#pragma once
#include "ThuCung.h"

struct node
{
	THUCUNG data;
	node* next;
};
typedef struct node NODE;

struct list
{
	NODE* head;
	NODE* tail;
};
typedef struct list LINKEDLIST;

NODE* CreateNode(THUCUNG data);
void CreateList(LINKEDLIST& l);
void AddTail(LINKEDLIST& l, NODE* node);
void PrintList(LINKEDLIST l);

void NhapThuCung(LINKEDLIST& l, THUCUNG ThuCung);
THUCUNG* TimKiemTheoMa(LINKEDLIST l, char* ma);