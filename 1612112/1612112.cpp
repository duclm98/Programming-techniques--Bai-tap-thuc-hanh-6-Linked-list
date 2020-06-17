// 1612112.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DanhSachThuCung.h"

int main()
{
	LINKEDLIST DanhSachThuCung;
	CreateList(DanhSachThuCung);

	LINKEDLIST DanhSachThuCungTheoTuoiVaMau;
	CreateList(DanhSachThuCungTheoTuoiVaMau);

	NODE* node = NULL;
	char* ma = new char[11];
	unsigned int tuoi;
	char* mau = new char[51];
	unsigned int trongLuong;

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
			NhapThuCung(DanhSachThuCung);
			cout << endl;
			break;
		case 3:
			cout << "BAN THU CUNG" << endl;
			cout << "Nhap ma thu cung:";
			cin.getline(ma, 10);

			BanThuCung(DanhSachThuCung, ma);

			cout << endl;
			break;
		case 4:
			cout << "DANH SACH THU CUNG THEO TUOI VA MAU" << endl;

			cout << "Nhap mau thu cung can tim: ";
			cin.getline(mau, 50);
			cout << "Nhap tuoi thu cung can tim: ";
			cin >> tuoi;
			cin.ignore();

			DeleteList(DanhSachThuCungTheoTuoiVaMau);

			LayDanhSachTheoTuoiVaMau(DanhSachThuCung, DanhSachThuCungTheoTuoiVaMau, tuoi, mau);

			cout << "Danh sach: " << endl;
			PrintList(DanhSachThuCungTheoTuoiVaMau);

			cout << endl;
			break;
		case 5:
			cout << "Nhap muc trong luong: ";
			cin >> trongLuong;
			XoaThuCungTheoTrongLuong(DanhSachThuCung, trongLuong);
			PrintList(DanhSachThuCung);
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
