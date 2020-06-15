#include "ThuCung.h"

istream& operator>>(istream& in, THUCUNG& p) {
	cout << "Nhap ma thu cung: ";
	in.getline(p.ma, 10);

	cout << "Nhap ten thu cung: ";
	in.getline(p.ten, 100);

	do {
		cout << "Nhap trong luong thu cung: ";
		in >> p.trongLuong;
	} while (p.trongLuong <= 0);

	do {
		cout << "Nhap tuoi thu cung: ";
		in >> p.tuoi;
	} while (p.tuoi <= 0);

	in.ignore();

	cout << "Nhap mau thu cung: ";
	in.getline(p.mau, 50);

	return in;
}

ostream& operator<<(ostream& out, THUCUNG& p) {
	out << "Ma thu cung: " << p.ma << endl;
	out << "Ten thu cung: " << p.ten << endl;
	out << "Trong luong thu cung: " << p.trongLuong << endl;
	out << "Tuoi thu cung: " << p.tuoi << endl;
	out << "Mau thu cung: " << p.mau << endl;

	return out;
}