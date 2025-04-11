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
    if (pn == "상처약") {
        price = 300;
    }
    else if (pn == "잠깨는약") {
        price = 300;
    }
    else if (pn == "기력치료제") {
        price = 500;
    }
    else if (pn == "화상치료제") {
        price = 300;
    }
    else if (pn == "기력의조각") {
        price = 1000;
    }
    else if (pn == "고급상처약") {
        price = 1000;
    }
    else if (pn == "벌레회피스프레이") {
        price = 300;
    }
    else if (pn == "실버스프레이") {
        price = 400;
    }
    else if (pn == "몬스터볼") {
        price = 300;
    }
    else if (pn == "슈퍼볼") {
        price = 1000;
    }
}

int Product::GetPrice(const char* pn)
{
    if (pn == "상처약") {
        price = 300;
    }
    else if (pn == "잠깨는약") {
        price = 300;
    }
    else if (pn == "기력치료제") {
        price = 500;
    }
    else if (pn == "화상치료제") {
        price = 300;
    }
    else if (pn == "기력의조각") {
        price = 1000;
    }
    else if (pn == "고급상처약") {
        price = 1000;
    }
    else if (pn == "벌레회피스프레이") {
        price = 300;
    }
    else if (pn == "실버스프레이") {
        price = 400;
    }
    else if (pn == "몬스터볼") {
        price = 300;
    }
    else if (pn == "슈퍼볼") {
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
    cout << "  " << pname << ": " << pnum << "개" << endl;
}
