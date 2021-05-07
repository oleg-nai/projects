#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

volatile bool flag = true;

void sendMessage(char type, HANDLE Event1, HANDLE Event2) {
	switch (type) {
	case 'A':
		SetEvent(Event1);
		break;
	case 'B':
		SetEvent(Event2);
	}
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	cout << "Writer process\n";
	HANDLE* handleArray = new HANDLE[3];
	HANDLE event1 = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event1");
	HANDLE event2 = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event2");
	HANDLE writerEndEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"WriterEndEvent");
	HANDLE semaphore = OpenSemaphore(EVENT_ALL_ACCESS, FALSE, L"Semaphore");

	cout << "Не активен\n";
	WaitForSingleObject(semaphore, INFINITE);
	system("cls");
	cout << "Writer process\n";
	cout << "Активен\n";

	for (int i = 0; i < argc; i++) {
		cout << "Введите сообщение (A-B):\n";
		char message;
		cin >> message;
		sendMessage(message, event1, event2);
	}

	SetEvent(writerEndEvent);
	ReleaseSemaphore(semaphore, 1, NULL);


	return 1;
}