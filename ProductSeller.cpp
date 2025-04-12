#include "ProductSeller.h"

void ProductSeller::ShowMenu()
{
	cout << "====== 포켓몬 프렌들리숍 ======" << endl;
	cout << "  사러 왔다" << endl;
	cout << "  팔러 왔다" << endl;
	cout << "  물품 보기" << endl;
	cout << "  아무것도 아니다" << endl;
	cout << "===============================" << endl;
}

void ProductSeller::ShowProductMenu()
{
	cout << "========== 상품 메뉴 ==========" << endl;
	cout << "  상처약" << setw(19) << "300원" << endl;
	cout << "  잠깨는약" << setw(17) << "300원" << endl;
	cout << "  기력치료제" << setw(15) << "500원" << endl;
	cout << "  화상치료제" << setw(15) << "300원" << endl;
	cout << "  기력의조각" << setw(15) << "1000원" << endl;
	cout << "  고급상처약" << setw(15) << "1000원" << endl;
	cout << "  벌레회피스프레이" << setw(9) << "300원" << endl;
	cout << "  실버스프레이" << setw(13) << "400원" << endl;
	cout << "  몬스터볼" << setw(17) << "300원" << endl;
	cout << "  슈퍼볼" << setw(19) << "1000원" << endl;
	cout << "===============================" << endl;
}
