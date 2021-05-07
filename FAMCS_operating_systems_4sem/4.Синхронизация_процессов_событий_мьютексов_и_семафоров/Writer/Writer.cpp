#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

void sendMessage(char type, HANDLE Event1, HANDLE Event2, HANDLE Event3) {
	switch (type) {
	case 'A':
		SetEvent(Event1);
		break;
	case 'B':
		SetEvent(Event2);
		break;
	case 'C':
		SetEvent(Event3);
	}
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	cout << "Writer process\n";
	HANDLE* handleArray = new HANDLE[3];
	HANDLE event1 = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event1");
	HANDLE event2 = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event2");
	HANDLE event3 = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event3");

	HANDLE writerEndEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"WriterEndEvent");
	
	

	HANDLE mutex = OpenMutex(SYNCHRONIZE, FALSE, L"mutex");
	if (mutex == NULL)
	{
		cout << "Open mutex failed." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();
		return GetLastError();
	}

	cout << "Не активен\n";
	WaitForSingleObject(mutex, INFINITE);
	system("cls");
	cout << "Reader process\n";
	cout << "Активен\n";

	for (int i = 0; i < argc; i++) {
		cout << "Введите сообщение (A, B, C):\n";
		char message;
		cin >> message;
		sendMessage(message, event1, event2, event3);
	}

	SetEvent(writerEndEvent);

	ReleaseMutex(mutex);
	CloseHandle(mutex);

	return 1;
}