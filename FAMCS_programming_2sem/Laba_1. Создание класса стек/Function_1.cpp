#include "Header_1.h"

void queue::push(int data_number, char* data_name) // �������� � �������
{
	human* tmp = new human;
	strcpy(tmp->name, data_name);
	tmp->number = data_number;
	tmp->next = 0;
	if (head == 0)
	{
		head = tmp;
		tail = head;
		return;
	}
	tail->next = tmp;
	tmp->prev = tail;
	tail = tmp;
	tail->next = 0;
	head->prev = 0;
}

void queue::Add_from_file()
{
	ifstream file;
	file.open("gift.txt");

	if (!file.is_open()) // �������� �� �������� �����
	{
		cout << "������ �������� �����, ��������� ������� ����� � �����!" << endl;
		return;
	}

	int count = 0;

	int data_number;
	char data_name[20];

	char* pch;
	char* line = new char[50];

	cout << "���� gift.txt ������!" << endl;
	while (file.getline(line, 200)) // � line ��� ������
	{
		pch = strtok(line, " _-:");
		while (pch != NULL)
		{
			if (count++ % 2 == 0)
			{
				strcpy(data_name, pch);
				pch = strtok(NULL, line); // ����� ��������� �������� � ������
				continue;
			}
			data_number = atoi(pch);
			push(data_number, data_name);
			pch = strtok(NULL, line); // ����� ��������� �������� � ������
		}
	}
}

void queue::Add_from_user(queue q)
{
	int data_number;
	char data_name[20];

	cout << "\n������� ����� ��������: "; cin >> data_number;
	cout << "������� ��� ���������: "; cin >> data_name;
	push(data_number, data_name);
}

void queue::Pop(queue q)
{

	if (!isEmpty())
	{
		char data_name[20];
		human* tmp = head;
		int data_number = head->number;
		strcpy(data_name, head->name);
		if (head->next == 0)
		{
			delete tmp;
			head = 0;
			tail = 0;
			cout << "\n������ ������!";
			return;
		}
		head = head->next;
		head->prev = 0;
		delete tmp;
		cout << "�� ������� ������ �������: \n���: " << data_name << " �����: " << data_number;
	}
	else
	{
		cout << "\n���� ���������!";
		return;
	}
		
}

void queue::Print(queue q)
{
	if (isEmpty() == true)
	{
		cout << "������� ������. �������� ����� ��������\n";
		return;
	}
	while (!isEmpty())
	{
		cout << "\n���: " << head->name << " �����: " << head->number << "\n";
		head = head->next;
		head->prev = 0;
	}
	return;
}

bool queue::isEmpty()
{
	return head == 0 ? true : false;
}

void queue::Delete_all_elements(queue q)
{
	if (isEmpty() == true)
	{
		cout << "������� ��� ������\n";
		return;
	}
		//head = head->next;
		//human* tmp = head;

		cout << "\n������� ��������";
		
		while(tail->prev != NULL)
		{
			tail = tail->prev;

			if (tail->prev == NULL)
			{
				return;
			}
			delete tail->next;
		}
}

void Panel(queue q)
{
	int user_data = 123;
	cout << "\n��� ������ ������� 111\n";
	cout << "\n1. �������� � ������� �������� �� �����";
	cout << "\n2. �������� ������� � �������";
	cout << "\n3. �������� ���������� ��������";
	cout << "\n4. �������� ���� ���������";
	cout << "\n5. ����� ��� �� �����";

	while (user_data != 111)
	{
			cout << "\n������� ����� ��������: ";  cin >> user_data;
		switch (user_data)
		{
		case(111):
			return;
		case(1):
		{
			Add_from_file();
			break;
		}
		case(2):
		{
			Add_from_user(q);
			break;
		}
		case(3):
		{
			Pop(q);
			break;
		}
		case(4):
		{
			Delete_all_elements(q);
			break;
		}
		case(5):
		{
			Print(q);
			break;
		}
		default:
		{
			cout << "\n�� ����� �������� ��������: ";
			break;
		}
		}
	}
}