#pragma once
#include "Product.h"

class ProductBuyer
{
private:
	Product* prd[10];
	int money;
	int idx;
public:
	ProductBuyer(int m) : idx(0)
	{
		money = m;
	}
	const char*& GetPName(const char* pname);
	Product*& GetProduct(const char* pname);
	Product*& GetProduct2(int index);
	int FindIDX(const char* pname);
	void SetProduct(Product* prd1);
	void SetProduct2(Product* prd1, int index);
	int GetMoney();
	void SetMoney(int m);
	int GetIDX();
	void BuyProduct(Product* prd1, int num);
	void SellProduct(Product* prd1, int num);
	void ShowAllProduct();
	~ProductBuyer() {
		for (int i = 0; i < idx; i++)
			delete[] prd[i];
	}
};

