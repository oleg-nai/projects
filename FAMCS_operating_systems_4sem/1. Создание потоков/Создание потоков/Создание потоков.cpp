#include <iostream>
#include <windows.h>

using namespace std;


struct Data {
	int size;
	int* arr;
};

DWORD WINAPI Worker(void* data) {

	cout << "---Thread (Worker) is started---\n";
	
	Data* data_local = (Data*) data;
	int boot = 0;
	for (int i = 0; i < data_local->size; i++) {
		boot += data_local->arr[i];
		Sleep(12);
	}
	cout << "The sum of array is (worker): " << boot << endl;
	cout << "---Thread (Worker) is finished---\n\n";
	return 0;
}

DWORD WINAPI Count() {

	cout << "---Thread (Count) is started---\n";
	int i1 = 1, i2 = 0, i3 = 0;
	while (i3 < 100000) {
		i3 = i1 + i2;
		cout << i3 << " ";
		i1 = i2;
		i2 = i3;
	}

	cout << "\n---Thread (Count) is finished---\n\n";
	return 0;
}


int main(void) {
	
	Data data;
	int time;

	// input data
	cout << "Enter the size of array: "; 
	cin >> data.size;
	data.arr = new int[data.size];
	cout << "Enter elements of array: ";
	for (int i = 0; i < data.size; i++)
		cin >> data.arr[i];
	cout << "Enter the time (in milliseconds) at which the worker will be stopped: ";
	cin >> time;


	HANDLE worker;
	DWORD IDThread; // unsigned long = DWORD
	DWORD dwCount;

	worker = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Worker, &data, 0, &IDThread);

	if (worker == NULL)
		return GetLastError();

	// Suspend thread "worker"
	cout << "\nStop 'worker' by SuspendThread\n";
	IDThread = SuspendThread(worker);
	cout << "Number of suspended threads, count = " << IDThread << endl << endl;
	Sleep(time);
	dwCount = ResumeThread(worker);

	WaitForSingleObject(worker, INFINITE);
	CloseHandle(worker);

	// Addition task

	cout << "\n\n---Fibonacci Numbers---\n";
	HANDLE count;
	count = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Count, NULL, CREATE_SUSPENDED, &IDThread);

	if (count == NULL)
		return GetLastError();

	ResumeThread(count);
	WaitForSingleObject(count, INFINITE);
	CloseHandle(count);


	return 0;
}