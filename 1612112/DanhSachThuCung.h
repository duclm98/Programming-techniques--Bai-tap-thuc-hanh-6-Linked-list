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
void RemoveHead(LINKEDLIST& l);
void RemoveNode(LINKEDLIST& l, NODE* node);
void PrintList(LINKEDLIST l);
void DeleteList(LINKEDLIST& l);

THUCUNG* TimKiemTheoMa(LINKEDLIST& l, char* ma);
THUCUNG* TimKiemTheoTuoiVaMau(LINKEDLIST& l, unsigned int tuoi, char* mau);
void LayDanhSachTheoTuoiVaMau(LINKEDLIST& src, LINKEDLIST& des, unsigned int tuoi, char* mau);
void NhapThuCung(LINKEDLIST& l);
void BanThuCung(LINKEDLIST& l, char* ma);
void XoaThuCungTheoTrongLuong(LINKEDLIST& l, unsigned int trongLuong);