#pragma once
#include <set>
#include <fstream>
#include <iostream>
#include <string>

std::set<__int8>mySet;
void ReadFromFile();
//void writeAllItems(std::set<__int8>);



namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ListBox^ listBox1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(62, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ёлемент:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ƒобавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(195, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(31, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 33);
			this->button2->TabIndex = 3;
			this->button2->Text = L"”далить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(31, 220);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(148, 33);
			this->button4->TabIndex = 5;
			this->button4->Text = L"—читать данные";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(213, 25);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(460, 324);
			this->listBox1->TabIndex = 6;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 381);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void writeAllItems(std::set<__int8> _set)
	{
		listBox1->Items->Clear();
		int i = 0;
		auto it = _set.begin();
		String^ tmpStr;
		for (it; it != _set.end(); it++)
		{
			tmpStr = (*it).ToString();
			listBox1->Items->Insert(i++, tmpStr);
		}
		i = 0;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		//if (textBox1->Text != "")
		//{			
		//}
		//else
		//{
		//}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) // добавить число
	{
		String^ message = Convert::ToString(textBox1->Text);
		if (textBox1->Text == "")
			return;
		if (isdigit(textBox1->Text[0]) == false && ((textBox1->Text[0]) != '-') && (textBox1->Text[0]) != '0')
		{
			message += " не €вл€етс€ числом";
			MessageBox::Show(message, "ќповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int _number = Convert::ToInt32(textBox1->Text);
		if (_number > 127)
		{
			message += " слишком большое дл€ __int8";
			MessageBox::Show(message, "ќповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (_number < -128)
		{
			message += " слишком маленькое дл€ __int8";
			MessageBox::Show(message, "ќповещение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		mySet.insert(_number);
		writeAllItems(mySet);
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) // считать данные
	{
		ReadFromFile();
		writeAllItems(mySet);
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)	// сортировка
	{
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int item = listBox1->SelectedIndex;
		auto it = mySet.begin();
		if (item < mySet.size() && item >= 0) 
		{
			advance(it, item);
			mySet.erase(it);
		}
		writeAllItems(mySet);
	}
};
}

