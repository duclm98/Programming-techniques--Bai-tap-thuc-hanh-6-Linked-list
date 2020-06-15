#pragma once
#include <iostream>
using namespace std;

struct thucung
{
	char* ma = new char[11];
	char* ten = new char[101];
	unsigned int trongLuong, tuoi;
	char* mau = new char[51];
};
typedef struct thucung THUCUNG;

istream& operator>>(istream& in, THUCUNG& p);
ostream& operator<<(ostream& out, THUCUNG& p);