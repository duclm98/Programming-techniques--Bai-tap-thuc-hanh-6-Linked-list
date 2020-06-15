﻿// 1612112.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DanhSachThuCung.h"

int main()
{
	LINKEDLIST DanhSachThuCung;
	CreateList(DanhSachThuCung);

	THUCUNG ThuCung;
	NODE* node = NULL;

	bool flag = true;
	do {
		cout << " =============== QUAN LY CUA HANG THU CUNG ===============" << endl;
		cout << "|| 1.               Danh sach thu cung                   ||" << endl;
		cout << "|| 2.                  Them thu cung                     ||" << endl;
		cout << "|| 3.                  Ban thu cung                      ||" << endl;
		cout << "|| 4.          Tim thu cung theo tuoi va mau             ||" << endl;
		cout << "|| 5.       Xoa mot so thu cung theo trong luong         ||" << endl;
		cout << "|| 6.                      Thoat                         ||" << endl;
		cout << "||                     Xin moi chon:                     ||" << endl;
		cout << " =========================================================" << endl;
		int choose;
		cin >> choose;
		cin.ignore();
		switch (choose)
		{
		case 1:
			cout << "DANH SACH THU CUNG" << endl;
			PrintList(DanhSachThuCung);
			cout << endl;
			break;
		case 2:
			cout << "THEM 1 THU CUNG" << endl;
			NhapThuCung(DanhSachThuCung, ThuCung);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			flag = false;
			break;
		default:
			flag = false;
			break;
		}
	} while (flag);

	return 0;
}