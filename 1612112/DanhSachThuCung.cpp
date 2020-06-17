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

void RemoveHead(LINKEDLIST& l) {
	if (l.head != NULL) {
		NODE* node = l.head;
		l.head = node->next;
		delete node;
		if (l.head == NULL) {
			l.tail = NULL;
		}
	}
}

void PrintList(LINKEDLIST l) {
	if (l.head != NULL) {
		NODE* node = l.head;
		int index = 0;
		while (node != NULL) {
			cout << "THU CUNG " << ++index << endl;
			cout << node->data;
			node = node->next;
		}
	}
}

void DeleteList(LINKEDLIST& l) {
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			RemoveHead(l);
			node = l.head;
		}
		l.tail = NULL;
	}
}

THUCUNG* TimKiemTheoMa(LINKEDLIST& l, char* ma) {
	THUCUNG* result = NULL;
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			if (strcmp(node->data.ma, ma) == 0) {
				result = &(node->data);
				break;
			}
			node = node->next;
		}
	}
	return result;
}

THUCUNG* TimKiemTheoTuoiVaMau(LINKEDLIST& l, unsigned int tuoi, char* mau) {
	THUCUNG* result = NULL;
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			if (strcmp(node->data.mau, mau) == 0 && node->data.tuoi == tuoi) {
				result = &(node->data);
				break;
			}
			node = node->next;
		}
	}
	return result;
}

void LayDanhSachTheoTuoiVaMau(LINKEDLIST& src, LINKEDLIST& des, unsigned int tuoi, char* mau)
{
	NODE* node = src.head;
	while (node != NULL) {
		if (strcmp(node->data.mau, mau) == 0 && node->data.tuoi == tuoi) {
			THUCUNG* ThuCung = &(node->data);
			NODE* newNode = CreateNode(*ThuCung);
			AddTail(des, newNode);
		}
		node = node->next;
	}
}

void NhapThuCung(LINKEDLIST& l) {
	cout << "Nhap thu cung" << endl;
	THUCUNG* ThuCung = new THUCUNG;
	cin >> *ThuCung;

	THUCUNG* find = TimKiemTheoMa(l, ThuCung->ma);
	if (find != NULL) {
		cout << "Vui long kiem tra ma cua thu cung ban vua nhap!" << endl;
	}
	else
	{
		NODE* node = CreateNode(*ThuCung);
		AddTail(l, node);
		cout << "Nhap thu cung thanh cong" << endl;
	}
	find = NULL;
}

void BanThuCung(LINKEDLIST& l, char* ma) {
	if (l.head != NULL) {
		NODE* node = l.head;
		bool isExisted = false;
		THUCUNG* find = NULL;
		while (node != NULL)
		{
			if (strcmp(node->data.ma, ma) == 0) {
				find = &(node->data);
				isExisted = true;

				find = &(node->data);
				cout << "Thong tin thu cung can ban: " << endl;
				cout << *find;

				break;
			}
			node = node->next;
		}
		if (!isExisted) {
			cout << "Khong the tim thay thu cung co ma vua nhap" << endl;
			return;
		}

		char confirm = 'n';
		cout << "Xac nhan ban thu cung (y/n):";
		cin >> confirm;
		cin.ignore();
		if (confirm == 'y' || confirm == 'Y') {
			THUCUNG info = *find;
			if (node == l.head) {
				l.head = l.head->next;
				delete node;
			}
			else
			{
				NODE* prevNode = l.head;
				while (prevNode->next != node) {
					prevNode = prevNode->next;
				}
				prevNode->next = node->next;
				node->next = NULL;
				delete node;				
			}
			cout << "Ban thu cung thanh cong voi gia " << 100 + (info.trongLuong * 2) - info.tuoi << " (USD)" << endl;
			return;
		}
	}
	cout << "Khong the tim thay thu cung co ma vua nhap" << endl;
}

void XoaThuCungTheoTrongLuong(LINKEDLIST& l, unsigned int trongLuong) {
	if (l.head != NULL) {
		NODE* node = l.head;
		while (node != NULL) {
			if (node->data.trongLuong > trongLuong) {
				if (node = l.head) {
					NODE* temp = l.head;
					l.head = node->next;
					delete temp;
				}
				else {
					NODE* prevNode = l.head;
					while (prevNode->next != node) {
						prevNode = prevNode->next;
					}
					prevNode->next = node->next;
					delete node;
				}
			}
			node = node->next;
		}
	}
}