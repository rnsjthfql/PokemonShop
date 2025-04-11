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

	cout << "���� ������ �ִ� �ݾ���? ";
	cin >> mn;
	ProductBuyer* pb = new ProductBuyer(mn);
	
	const char* pstr[10] = { "��ó��","����¾�","���ġ����","ȭ��ġ����","���������","��޻�ó��",
	"����ȸ�ǽ�������","�ǹ���������","���ͺ�","���ۺ�" };

	int key = 0, x = 0, y = 1;
	while (1) {
		//key = 0, x = 0, y = 1;
		cursor(0);
		system("cls");
		
		ps->ShowMenu();
		
		key = _getch();

		if (key == 224) {
			key = _getch();
		}
		if (key == UP) {
			y--;
			if (y < 1)
				y = 1;
			gotoxy(x, y);
			cout << "��";
		}
		else if (key == DOWN) {
			y++;
			if (y > 4)
				y = 4;
			gotoxy(x, y);
			cout << "��";
		}
		else if (key == ENTER) {
			if (y == 1) {		//�緯�Դ�
				key = 0, x = 0, y = 2;
				while (1) {		
					int productNum;
					cursor(0);
					system("cls");

					cout << "�ܾ�: " << pb->GetMoney() << "��" << endl;
					ps->ShowProductMenu();

					key = _getch();

					if (key == 224) {
						key = _getch();
					}
					if (key == UP) {
						y--;
						if (y < 2)
							y = 2;
						gotoxy(x, y);
						cout << "��";
					}
					else if (key == DOWN) {
						y++;
						if (y > 11)
							y = 11;
						gotoxy(x, y);
						cout << "��";
					}
					else if (key == ENTER) {
						int rm;
						Product* p = new Product();
						cout << "��ǰ: " << pstr[y - 2] << endl;
						cout << "�� ���� �����Ͻðڽ��ϱ�? ";
						cin >> productNum;
						if (pb->GetMoney() < p->GetPrice(pstr[y - 2]) * productNum) {
							cout << "���� �����մϴ�." << endl;
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
			else if (y == 2) {		//�ȷ��Դ�
				key = 0, x = 0, y = 2;
				while (1) {		
					int productNum;
					cursor(0);
					system("cls");

					cout << "�ܾ�: " << pb->GetMoney() << "��" << endl;
					pb->ShowAllProduct();

					key = _getch();

					if (key == 224) {
						key = _getch();
					}
					if (key == UP) {
						y--;
						if (y < 2)
							y = 2;
						gotoxy(x, y);
						cout << "��";
					}
					else if (key == DOWN) {
						y++;
						if (y > 11)
							y = 11;
						gotoxy(x, y);
						cout << "��";
					}
					else if (key == ENTER) {
						int rm;
						const char* pn;
						Product* p = new Product();
						p = pb->GetProduct2(y - 2);
						cout << "��ǰ: " << p->GetPName() << endl;
						cout << "�� ���� �Ǹ��Ͻðڽ��ϱ�? ";
						cin >> productNum;
						if (p->GetPNum() < productNum) {
							cout << "�Ǹ��ϰ��� �ϴ� ��ǰ�� �����մϴ�." << endl;
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
			else if (y == 3) {		//��ǰ����
				pb->ShowAllProduct();
				continue;
			}
			else if (y == 4) {		//�ƹ��͵��ƴϴ�
				return 0;
			}
		}
	}

	return 0;
}