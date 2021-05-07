#include <windows.h>
#include <iostream>
#include <conio.h>
#include <list>
using namespace std;


// создаем 3 события (A, B, C)
HANDLE event1;
HANDLE event2;
HANDLE event3;

HANDLE readerEndEvent;
HANDLE writerEndEvent;
HANDLE semaphore;
HANDLE mutex;

bool flag1 = true;
bool flag2 = true;
bool flag3 = true;

volatile int messageWriterEventCount = 0;
volatile int messageWriterEndCount = 0;
volatile int messageReaderEventCount = 0;
volatile int messageReaderEndCount = 0;

DWORD WINAPI waitWriterEndEvent(LPVOID v) {
	while (flag3) {
		WaitForSingleObject(writerEndEvent, INFINITE);
		ResetEvent(waitWriterEndEvent);
		cout << "Процесс Writer завершил работу.\n";
		messageWriterEndCount++;
	}
	return 0;
}

DWORD WINAPI waitReaderEndEvent(LPVOID v) {
	while (flag3) {
		WaitForSingleObject(readerEndEvent, INFINITE);
		ResetEvent(writerEndEvent);
		cout << "Процесс Reader завершил работу.\n";
		messageReaderEndCount++;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RU");

	event1 = CreateEvent(NULL, FALSE, FALSE, L"event1");
	event2 = CreateEvent(NULL, FALSE, FALSE, L"event2");
	event3 = CreateEvent(NULL, FALSE, FALSE, L"event3");

	writerEndEvent = CreateEvent(NULL, FALSE, FALSE, L"WriterEndEvent");
	readerEndEvent = CreateEvent(NULL, FALSE, FALSE, L"ReaderEndEvent");
	
	// начальное значение семафора
	// максимальное значение семафора
	semaphore = CreateSemaphore(NULL, 1, 1, L"Semaphore");


	// check for initing 
	mutex = CreateMutex(NULL, FALSE, L"mutex");
	if (mutex == NULL)
	{
		cout << "Create mutex failed." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();
		return GetLastError();
	}


	HANDLE writerEndThread; 
	HANDLE readerEndThread;
	
	DWORD IDThread2;
	DWORD IDThread1;

	PROCESS_INFORMATION pi1;
	STARTUPINFO si;

	// Функция ZeroMemory заполняет блок памяти нулями.
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi1, sizeof(pi1));
	si.cb = sizeof(STARTUPINFO);
	
	// ------- read data -------
	wchar_t messageCount[10];
	cout << "Введите кол-во отправленных сообщений для процессов \"Writer\" и  кол-во принятых сообщений для процесса  \"Reader\":\n";
	_getws_s(messageCount);

	cout << "Введите кол-во процессов \"Reader\" и \"Writer\":\n";
	int processCount;
	cin >> processCount;


	// Метод используется для освобождения мьютекса, когда он больше не нужен.
	ReleaseMutex(mutex);

	// ------- read data -------

	writerEndThread = CreateThread(NULL, 0, waitWriterEndEvent, (void*)writerEndEvent, 0, &IDThread1);
	readerEndThread = CreateThread(NULL, 0, waitReaderEndEvent, (void*)readerEndEvent, 0, &IDThread2);


	for (int i = 0; i < processCount * 2; i += 2) {
		wchar_t dir1[200] = L"Writer.exe ";
		wcscat_s(dir1, 100, messageCount);
		if (!CreateProcess(NULL, dir1, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1)) {
			cout << "Writer not created\n";
		}

		wchar_t dir[200] = L"Reader.exe ";
		wcscat_s(dir, 100, messageCount);
		if (!CreateProcess(NULL, dir, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1)) {
			cout << "Reader not created\n";
		}
	}


	HANDLE* handleArray = new HANDLE[3];
	handleArray[0] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event1");
	handleArray[1] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event2");
	handleArray[2] = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"event3");


	while ((messageWriterEndCount < processCount || messageReaderEndCount < processCount)) {

		switch (WaitForMultipleObjects(3, handleArray, FALSE, INFINITE))
		{
		case 0:
			cout << "Получено сообщение A\n";
			SetEvent(handleArray[0]);
			break;
		case :
			cout << "Получено сообщение B\n";
			SetEvent(handleArray[1]);
			break;
		case 2:
			cout << "Получено сообщение C\n";
			SetEvent(handleArray[2]);
			break;
		}
	}

	// 1. из writer в admin. admin -> reader

	WaitForSingleObject(waitReaderEndEvent, INFINITE);
	WaitForSingleObject(waitWriterEndEvent, INFINITE);

	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);
	CloseHandle(writerEndThread);
	CloseHandle(readerEndThread);
	CloseHandle(mutex);

	return 0;

	
}

