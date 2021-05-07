#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Test::MyForm form;
    Application::Run(% form);
}



void ReadFromFile()
{
	std::ifstream FILE;
	FILE.open("Data.txt");

	if (!FILE.is_open())
	{
		MessageBox::Show("Данного файла нет", "Оповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	char line[15];
	int tmp;
	String^ message;
	while (FILE.getline(line, 15)) // .txt numbers shood be in column
	{
		//if (isdigit(line[0]) == false && line[0] != '-' && line[0] != '0')
		//{
		//	message = Convert::ToString(line) + " не является числом";
		//	MessageBox::Show(message, "Оповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		//	continue;
		//}
		tmp = atoi(line);
		if (tmp > 127)
		{
			message = Convert::ToString(tmp)  + " слишком большое для __int8";
			MessageBox::Show(message, "Оповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			continue;
		}
		if (tmp < -128)
		{
			message = Convert::ToString(tmp) + " слишком маленькое для __int8";
			MessageBox::Show(message, "Оповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			continue;
		}
		mySet.insert(tmp);
	}
	FILE.close();
}

