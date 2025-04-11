#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
	const char* pname;
	int price;
	int pnum;
public:
	Product() : price(0), pnum(0)
	{
		pname = NULL;
	}
	Product(char* name, int pprice) : pnum(0)
	{
		int len = strlen(name);
		pname = new char[len];
		pname = name;
		price = pprice;
	}
	const char*& GetPName();
	void SetPName(const char* pn);
	void SetPrice(const char* pn);
	int GetPrice(const char* pn);
	void SetPNum(int n);
	int GetPNum();
	void ShowProduct();
	~Product() {
		if(pname != NULL)
			delete[] pname;
	}
};

