#include <iostream>
#include <windows.h>

using namespace std;

struct Data {
	int size;
	int k;
	int* arr;
	int sum;
};

CRITICAL_SECTION cs1;
CRITICAL_SECTION cs2;

HANDLE hOutEvent;

DWORD WINAPI work(void* data) {
	EnterCriticalSection(&cs1);
	cout << "---Thread (work) is started---\n";
	Data* data_local = (Data*)data;
	int time;
	cout << "Введите время, на которое будет остоновлен поток (work):\n";
	cin >> time;

	// sorting arr
	int temp = 0;
	for (int i = 0; i < data_local->size; i++) {
		for (int j = i; j < data_local->size; j++) {
			if (data_local->arr[i] < data_local->arr[j]) {
				temp = data_local->arr[i];
				data_local->arr[i] = data_local->arr[j];
				data_local->arr[j] = temp;
			}
		}
		if (i == data_local->k)
		{
			// извещаем main о начале суммирования тогда, когда отсортируем k элементов
			// и продолжаем делать сортировку
			LeaveCriticalSection(&cs1);
		}
		Sleep(time);
	}
	return 0;
}



DWORD WINAPI SumElems(void* data) {

	EnterCriticalSection(&cs2);
	WaitForSingleObject(hOutEvent, INFINITE);
	cout << "---Thread (SumElems) is started---\n";
	Data* data_local = (Data*)data;

	data_local->sum = 0;
	for (int i = 0; i < data_local->k; i++) {
		data_local->sum += data_local->arr[i];
	}
	cout << "Сумма элементов из (SumElems) до к: " << data_local->sum << "\n";
	LeaveCriticalSection(&cs2);
	return 0;
}



int main()
{
	setlocale(LC_ALL, "ru");


	// ------- read data -------

	// input data
	Data data;
	cout << "Enter the size of array: ";
	cin >> data.size;
	data.arr = new int[data.size];
	cout << "Enter elements of array: ";
	for (int i = 0; i < data.size; i++)
		cin >> data.arr[i];

	// ------- read data -------



	// ------- создаем секции и потоки -------

	HANDLE	hThread_1, hThread_2;
	DWORD	IDThread_1, IDThread_2;

	// инициализируем критическую секцию
	InitializeCriticalSection(&cs1);
	InitializeCriticalSection(&cs2);

	// создаем события с автоматическим сбросом
	hOutEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (hOutEvent == NULL)
		return GetLastError();

	// запускаем первый поток (work)
	// CREATE_SUSPENDED - создается поток в подвешенном состоянии
	hThread_1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) work,
		&data, CREATE_SUSPENDED, &IDThread_1);
	if (hThread_1 == NULL)
		return GetLastError();

	// ------- создаем секции и потоки -------


	cout << "Enter k value (k < size_arr): ";
	cin >> data.k;

	// ------- Старт 2-х потоков -------

	ResumeThread(hThread_1); // выводим из подвешенного состояния

	// запускаем второй поток (SumElems)
	hThread_2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SumElems,
		&data, 0, &IDThread_2);
	if (hThread_2 == NULL)
		return GetLastError();

	Sleep(50);

	// ------- Старт 2-х потоков -------


	EnterCriticalSection(&cs1);
	cout << "Вывод результат работы (work), k отсортированных элементов:\n";
	for (int i = 0; i < data.k; i++) {
		cout << data.arr[i] << " ";
	}
	cout << '\n';
	SetEvent(hOutEvent); // позволяю потоку SumElems продолжить работу
	LeaveCriticalSection(&cs1);


	EnterCriticalSection(&cs2);
	cout << "Сумма элементов отсортированного массива до к: " << data.sum << "\n";
	LeaveCriticalSection(&cs2);

	WaitForSingleObject(hThread_1, INFINITE); // ждем отработку потока work, то есть сортировку после К


	cout << "Вывод всех элементов массива из (main): ";
	for (int i = 0; i < data.size; i++) {
		cout << data.arr[i] << " ";
	}
	cout << "\n";
	
	CloseHandle(hThread_1);
	CloseHandle(hThread_2);
	CloseHandle(hOutEvent);

	return 0;
}
