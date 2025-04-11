#include "ProductBuyer.h"

const char*& ProductBuyer::GetPName(const char* pname)
{
	for (int i = 0; i < idx; i++) {
		if (prd[i]->GetPName() == pname) {
			return prd[i]->GetPName();
		}
	}
}

Product*& ProductBuyer::GetProduct(const char* pname)
{
	for (int i = 0; i < idx; i++) {
		if (prd[i]->GetPName() == pname) {
			return prd[i];
		}
	}
}

Product*& ProductBuyer::GetProduct2(int index)
{
	return prd[index];
}

int ProductBuyer::FindIDX(const char* pname)
{
	for (int i = 0; i < idx; i++) {
		if (prd[i]->GetPName() == pname)
			return i;
	}
	return 100;
}

void ProductBuyer::SetProduct(Product* prd1)
{
	prd[idx] = prd1;
	idx += 1;
}

void ProductBuyer::SetProduct2(Product* prd1, int index)
{
	prd[index] = prd1;
}

int ProductBuyer::GetMoney()
{
	return money;
}

void ProductBuyer::SetMoney(int m)
{
	money = m;
}

int ProductBuyer::GetIDX()
{
	return idx;
}

void ProductBuyer::BuyProduct(Product* prd1, int num)
{
	int n = prd1->GetPNum();
	n += num;
	prd1->SetPNum(n);
	money -= prd1->GetPrice(prd1->GetPName()) * num;
}

void ProductBuyer::SellProduct(Product* prd1, int num)
{
	int n = prd1->GetPNum();
	n -= num;
	prd1->SetPNum(n);
	money += prd1->GetPrice(prd1->GetPName()) * num;
}

void ProductBuyer::ShowAllProduct()
{
	cout << "==== 상품 목록 ====" << endl;
	for (int i = 0; i < idx; i++) {
		prd[i]->ShowProduct();
	}
	cout << "===================" << endl;
}
