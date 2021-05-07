#include <windows.h>
#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

HANDLE event1;
HANDLE event2;
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

struct ProcessInformation {
	STARTUPINFO info;
	PROCESS_INFORMATION processInformation;

	ProcessInformation() {
		ZeroMemory(&info, sizeof(STARTUPINFO));
		info.cb = sizeof(STARTUPINFO);
	}
};

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
	setlocale(LC_ALL, "Russian");

	event1 = CreateEvent(NULL, FALSE, FALSE, L"event1");
	event2 = CreateEvent(NULL, FALSE, FALSE, L"event2");
	semaphore = CreateSemaphore(NULL, 3, 3, L"Semaphore");
	writerEndEvent = CreateEvent(NULL, FALSE, FALSE, L"WriterEndEvent");
	readerEndEvent = CreateEvent(NULL, FALSE, FALSE, L"ReaderEndEvent");
	mutex = CreateMutex(NULL, FALSE, L"mutex");
	if (mutex == NULL)
	{
		cout << "Create mutex failed." << endl;
		cout << "Press any key to exit." << endl;
		cin.get();
		return GetLastError();
	}

	HANDLE writerEndThread;
	DWORD IDThread1;
	HANDLE readerEndThread;
	DWORD IDThread2;
	
	PROCESS_INFORMATION pi1;
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi1, sizeof(pi1));
	si.cb = sizeof(STARTUPINFO);


	wchar_t messageCount[10];
	cout<<"Введите кол-во отправленных сообщений для процессов \"Writer\" и  кол-во принятых сообщений для процесса  \"Reader\":\n";
	_getws_s(messageCount);

	cout<<"Введите кол-во процессов \"Reader\" и \"Writer\":\n";
	int processCount;
	cin >> processCount;
	
	ReleaseMutex(mutex);

	writerEndThread = CreateThread(NULL, 0, waitWriterEndEvent, (void*)writerEndEvent, 0, &IDThread1);
	readerEndThread = CreateThread(NULL, 0, waitReaderEndEvent, (void*)readerEndEvent, 0, &IDThread2);

	for (int i = 0; i < processCount*2; i += 2) {
		wchar_t dir1[200] = L"C:\\Users\\Xiaomi\\source\\repos\\Project7\\x64\\Debug\\Writer.exe ";
		wcscat_s(dir1, 100, messageCount);
		if (!CreateProcess(NULL, dir1, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1)) {
			cout << "Writer not created\n";
		}

		wchar_t dir[200] = L"C:\\Users\\Xiaomi\\source\\repos\\Project7\\x64\\Debug\\Reader.exe ";
		wcscat_s(dir, 100, messageCount);
		if (!CreateProcess(NULL, dir, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1)) {
			cout << "Reader not created\n";
		}
		
	}
	

	
	while ((messageWriterEndCount < processCount || messageReaderEndCount < processCount));
		
	WaitForSingleObject(waitReaderEndEvent, INFINITE);
	WaitForSingleObject(waitWriterEndEvent, INFINITE);

	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);
	CloseHandle(writerEndThread);
	CloseHandle(readerEndThread);
	CloseHandle(mutex);

	return 0;
}