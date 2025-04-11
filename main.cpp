#include "Product.h"
#include "ProductBuyer.h"
#include "ProductSeller.h"
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define ENTER 13

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void cursor(int n) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {


	int mn = 0;
	ProductSeller* ps = new ProductSeller();

	cout << "현재 가지고 있는 금액은? ";
	cin >> mn;
	ProductBuyer* pb = new ProductBuyer(mn);
	
	const char* pstr[10] = { "상처약","잠깨는약","기력치료제","화상치료제","기력의조각","고급상처약",
	"벌레회피스프레이","실버스프레이","몬스터볼","슈퍼볼" };

	int key = 0, x = 0, y = 1;
	while (1) {
		cursor(0);
		system("cls");
		
		ps->ShowMenu();

		key = _getch();

		/*if (key == 224) {
			key = _getch();
		}*/
		if (key == UP) {
			y--;
			if (y < 1)
				y = 1;
			gotoxy(x, y);
			cout << "▶";
			key = _getch();
		}
		else if (key == DOWN) {
			y++;
			if (y > 4)
				y = 4;
			gotoxy(x, y);
			cout << "▶";
			key = _getch();
		}
		if (key == ENTER) {
			if (y == 1) {		//사러왔다
				key = 0, x = 0, y = 2;
				while (1) {		
					int productNum;
					cursor(0);
					system("cls");

					cout << "잔액: " << pb->GetMoney() << "원" << endl;
					ps->ShowProductMenu();

					key = _getch();

					/*if (key == 224) {
						key = _getch();
					}*/
					if (key == UP) {
						y--;
						if (y < 2)
							y = 2;
						gotoxy(x, y);
						cout << "▶";
						key = _getch();
					}
					else if (key == DOWN) {
						y++;
						if (y > 11)
							y = 11;
						gotoxy(x, y);
						cout << "▶";
						key = _getch();
					}
					if (key == ENTER) {
						cursor(0);
						system("cls");

						int rm;
						Product* p = new Product();
						cout << "물품: " << pstr[y - 2] << endl;
						cout << "몇 개를 구입하시겠습니까? ";
						cin >> productNum;
						if (pb->GetMoney() < p->GetPrice(pstr[y - 2]) * productNum) {
							cout << "돈이 부족합니다." << endl;
							break;
						}
						else {
							cout << y << endl;
							rm = pb->GetMoney() - p->GetPrice(pstr[y - 2]) * productNum;
							if (pb->FindIDX(pstr[y-2]) == 100) {
								p->SetPNum(productNum);
								p->SetPName(pstr[y - 2]);
								p->SetPrice(pstr[y - 2]);
								pb->SetProduct(p);
								pb->SetMoney(rm);
								break;
							}
							else {
								p = pb->GetProduct(pstr[y - 2]);
								p->SetPNum(productNum + p->GetPNum());
								pb->SetProduct2(p, pb->GetIDX());
								break;
							}
						}
						break;
					}
				}
				continue;
			}
			else if (y == 2) {		//팔러왔다
				key = 0, x = 0, y = 2;
				while (1) {		
					int productNum;
					cursor(0);
					system("cls");

					cout << "잔액: " << pb->GetMoney() << "원" << endl;
					pb->ShowAllProduct();

					key = _getch();

					/*if (key == 224) {
						key = _getch();
					}*/
					if (key == UP) {
						y--;
						if (y < 2)
							y = 2;
						gotoxy(x, y);
						cout << "▶";
						key = _getch();
					}
					else if (key == DOWN) {
						y++;
						if (y > 11)
							y = 11;
						gotoxy(x, y);
						cout << "▶";
						key = _getch();
					}
					if (key == ENTER) {
						cursor(0);
						system("cls");
						pb->ShowAllProduct();

						int rm;
						Product* p = new Product();
						p = pb->GetProduct2(y - 2);
						cout << "물품: " << p->GetPName() << endl;
						cout << "몇 개를 판매하시겠습니까? ";
						cin >> productNum;
						if (p->GetPNum() < productNum) {
							cout << "판매하고자 하는 물품이 부족합니다." << endl;
							break;
						}
						else {
							rm = pb->GetMoney() + p->GetPrice(p->GetPName()) * productNum;
							p->SetPNum(p->GetPNum() - productNum);
							pb->SetMoney(rm);
							pb->SetProduct2(p, pb->FindIDX(p->GetPName()));
						}
						break;
					}

				}
				continue;
			}
			else if (y == 3) {		//물품보기
				pb->ShowAllProduct();
				cin.get();
				continue;
			}
			else if (y == 4) {		//아무것도아니다
				return 0;
			}
		}
	}

	return 0;
}