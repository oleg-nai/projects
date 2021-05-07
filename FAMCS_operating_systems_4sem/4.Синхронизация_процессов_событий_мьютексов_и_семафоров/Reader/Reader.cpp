#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	cout << "Reader process\n";
	HANDLE* handleArray = new HANDLE[3];
	handleArray[0] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event1");
	handleArray[1] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event2");
	handleArray[2] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event3");


	HANDLE readerEndEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"ReaderEndEvent");

	HANDLE semaphore = OpenSemaphore(EVENT_ALL_ACCESS, FALSE, L"Semaphore");

	cout << "Не активен\n";
	WaitForSingleObject(semaphore, INFINITE);
	system("cls");
	cout << "Writer process\n";
	cout << "Активен\n";


	for (int i = 0; i < argc; i++) {
		// Для ожидания перехода в сигнальное состояние нескольких нескольких 
		// объектов синхронизации объектов синхронизации или одного из
		switch (WaitForMultipleObjects(3, handleArray, FALSE, INFINITE))
		{
		case 0:
			cout << "Получено сообщение A\n";
			break;
		case 1:
			cout << "Получено сообщение B\n";
			break;
		case 2:
			cout << "Получено сообщение С\n";
			break;
		}
	}

	// Функция SetEvent() меняет состояние на сигнальное
	SetEvent(readerEndEvent);

	// Мьютекс захватывается потоком посредством любой функции ожидания, а освобождается функцией ReleaseMutex
	ReleaseSemaphore(semaphore, 1, NULL);

	system("pause");
	return 1;
}