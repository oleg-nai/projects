#include "Header.h"

// �������� ����, 7 ������
// � ������ ����������� ����� machine, �� �������� ��������� (base class) ��� ������ car(child class) � truck(child class). 
// ����� machine �������� �������� ����� engine(���������), � �.�. machine - ��� ����� �������� ��� car � truck, �� engine ����� ���� � car � truck
// ������� ������ ������� ������ machine ������������� ID, 
// ������� ����������
// ���� Counter - ����������, ������� ������� ���������� ��������� �������� ������ machine

int Machine::Count = 0;

int main(void)
{
	setlocale(LC_ALL, "rus");
	

	Car volvo("volvo-x-360", 5000);
	cin >> volvo.engine;
	cout << volvo.engine << endl;

	volvo.showAllInfo();


	Truck maz("M-300", 8000, 5000);
	Truck belarus(maz);
	
	maz.showAllInfo();		// ������� ������ �� ������������ ������ Machine

	cin >> belarus.engine;
	cout << belarus << endl;// ������������� ������� ������ � ������ Truck

	cout << "Count of machines : " << volvo.Count << endl; // ���������� ���������� ��������� �������� ������ Machine

	return 0;
}	