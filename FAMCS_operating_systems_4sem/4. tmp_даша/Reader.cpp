#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	cout << "Reader process\n";
	HANDLE* handleArray = new HANDLE[2];
	handleArray[0] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event1");
	handleArray[1] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event2");
	HANDLE readerEndEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"ReaderEndEvent");
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
		switch (WaitForMultipleObjects(2, handleArray, FALSE, INFINITE))
		{
		case 0:
			cout << "Получено сообщение A\n";
			//ResetEvent(handleArray[0]);
			break;
		case 1:
			cout << "Получено сообщение B\n";
			//ResetEvent(handleArray[1]);
			break;
		}
	}
	
	
	SetEvent(readerEndEvent);

	ReleaseMutex(mutex);
	CloseHandle(mutex);

	system("pause");
	return 1;
}