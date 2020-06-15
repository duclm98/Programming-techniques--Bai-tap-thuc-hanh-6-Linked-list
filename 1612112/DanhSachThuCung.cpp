#include "DanhSachThuCung.h"

NODE* CreateNode(THUCUNG data) {
	NODE* node = new NODE;
	node->data = data;
	node->next = NULL;
	return node;
}

void CreateList(LINKEDLIST& l) {
	l.head = NULL;
	l.tail = NULL;
}

void AddTail(LINKEDLIST& l, NODE* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		l.tail->next = node;
		l.tail = node;
	}
}

void PrintList(LINKEDLIST l) {
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			cout << node->data;
			node = node->next;
		}
	}
}

void NhapThuCung(LINKEDLIST& l, THUCUNG ThuCung) {
	cout << "Nhap thu cung" << endl;
	cin >> ThuCung;

	THUCUNG* find = TimKiemTheoMa(l, ThuCung.ma);
	if (find != NULL) {
		cout << "Vui long kiem tra ma cua thu cung ban vua nhap!" << endl;
		return;
	}

	NODE* node = CreateNode(ThuCung);
	AddTail(l, node);
	cout << "NHap thu cung thanh cong" << endl;
}

THUCUNG* TimKiemTheoMa(LINKEDLIST l, char* ma) {
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			if (strcmp(node->data.ma, ma) == 0) {
				return &(node->data);
			}
			node = node->next;
		}
	}
	return NULL;
}