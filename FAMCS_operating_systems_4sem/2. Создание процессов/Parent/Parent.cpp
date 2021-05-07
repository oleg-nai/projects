// Naidovich Oleg, 7gr

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

int main() {

	int n = 0;
	double* arr;
	wstring temp = L"Child.exe";

	cout << "Enter the size of the array: ";
	cin >> n;
	arr = new double[n];

	cout << "\nEnter the numbers of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		temp += L" ";
		temp += to_wstring(arr[i]);
	}
	
	// info from 0.3 - Зrocesses
	STARTUPINFO si;
	PROCESS_INFORMATION Сhild;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	//CreateProcessW(NULL, &temp[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &Сhild);


	// создаем новый консольный процесс
	if (!CreateProcessW(NULL, &temp[0], NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &Сhild))
	{
		_cputs("The new process is not created.\n");
		_cputs("Check a name of the process.\n");
		_cputs("Press any key to finish.\n");
		_getch();
		return 0;
	}

	_cputs("The new process is created.\n");
	// ждем завершения созданного прцесса
	WaitForSingleObject(Сhild.hProcess, INFINITE);
	// закрываем дескрипторы этого процесса в текущем процессе
	CloseHandle(Сhild.hThread);
	CloseHandle(Сhild.hProcess);
	return 0;


}