#include "Product.h"

const char*& Product::GetPName()
{
    return pname;
}

void Product::SetPName(const char* pn)
{
    pname = pn;
}

void Product::SetPrice(const char* pn)
{
    if (pn == "��ó��") {
        price = 300;
    }
    else if (pn == "����¾�") {
        price = 300;
    }
    else if (pn == "���ġ����") {
        price = 500;
    }
    else if (pn == "ȭ��ġ����") {
        price = 300;
    }
    else if (pn == "���������") {
        price = 1000;
    }
    else if (pn == "��޻�ó��") {
        price = 1000;
    }
    else if (pn == "����ȸ�ǽ�������") {
        price = 300;
    }
    else if (pn == "�ǹ���������") {
        price = 400;
    }
    else if (pn == "���ͺ�") {
        price = 300;
    }
    else if (pn == "���ۺ�") {
        price = 1000;
    }
}

int Product::GetPrice(const char* pn)
{
    if (pn == "��ó��") {
        price = 300;
    }
    else if (pn == "����¾�") {
        price = 300;
    }
    else if (pn == "���ġ����") {
        price = 500;
    }
    else if (pn == "ȭ��ġ����") {
        price = 300;
    }
    else if (pn == "���������") {
        price = 1000;
    }
    else if (pn == "��޻�ó��") {
        price = 1000;
    }
    else if (pn == "����ȸ�ǽ�������") {
        price = 300;
    }
    else if (pn == "�ǹ���������") {
        price = 400;
    }
    else if (pn == "���ͺ�") {
        price = 300;
    }
    else if (pn == "���ۺ�") {
        price = 1000;
    }
    return price;
}

void Product::SetPNum(int n)
{
    pnum = n;
}

int Product::GetPNum()
{
    return pnum;
}

void Product::ShowProduct()
{
    cout << "  " << pname << ": " << pnum << "��" << endl;
}
