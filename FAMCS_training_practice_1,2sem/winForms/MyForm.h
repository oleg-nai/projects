#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label4;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(163, 26);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Операнд 1:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Операнд 2:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(16, 105);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(163, 26);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(16, 171);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(338, 26);
			this->textBox3->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 148);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Ответ:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"И (AND - &)", L"ИЛИ (OR - |)", L"ИСК. ИЛИ (XOR - ^)" });
			this->comboBox1->Location = System::Drawing::Point(191, 229);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(207, 28);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Text = L"(Не выбрано)";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 229);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(173, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Побитовая операция:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 380);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (textBox1->Text != "" && textBox2->Text != "")
		{
			switch (comboBox1->SelectedIndex)
			{
			case 0: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) & Convert::ToInt32(textBox2->Text)); break;
			case 1: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) | Convert::ToInt32(textBox2->Text)); break;
			case 2: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) ^ Convert::ToInt32(textBox2->Text)); break;
			}
		}
		else
		{
			textBox3->Text = "Операнды не определены";
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		/*
			И (AND - &)
			ИЛИ (OR - |)
			ИСК. ИЛИ (XOR - ^)
		*/
		if (textBox1->Text != "" && textBox2->Text != "")
		{
			switch (comboBox1->SelectedIndex)
			{
			case 0: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) & Convert::ToInt32(textBox2->Text)); break;
			case 1: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) | Convert::ToInt32(textBox2->Text)); break;
			case 2: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) ^ Convert::ToInt32(textBox2->Text)); break;
			}
		}
		else
		{
			textBox3->Text = "Операнды не определены";
		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (textBox1->Text != "" && textBox2->Text != "")
		{
			switch (comboBox1->SelectedIndex)
			{
			case 0: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) & Convert::ToInt32(textBox2->Text)); break;
			case 1: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) | Convert::ToInt32(textBox2->Text)); break;
			case 2: textBox3->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) ^ Convert::ToInt32(textBox2->Text)); break;
			}
		}
		else
		{
			textBox3->Text = "Операнды не определены";
		}
	}
};
}
