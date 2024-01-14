#pragma once
#include "MainApp//Graph.h"
#include "Reference.h"
#include <msclr\marshal_cppstd.h>


namespace MainApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
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
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ input_text;
	private: System::Windows::Forms::TextBox^ input_field;
	private: System::Windows::Forms::Button^ calc_btn;
	private: System::Windows::Forms::Label^ info_text;


	private: Reference^ Reference_form = nullptr;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ choise_txt;
	private: System::Windows::Forms::Label^ input_choice_text;
	private: System::Windows::Forms::ListBox^ input_choice;
	private: System::Windows::Forms::Button^ ref_btn;
	private: System::Windows::Forms::TextBox^ textBox1;


	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->input_text = (gcnew System::Windows::Forms::Label());
			this->input_field = (gcnew System::Windows::Forms::TextBox());
			this->calc_btn = (gcnew System::Windows::Forms::Button());
			this->info_text = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->choise_txt = (gcnew System::Windows::Forms::Label());
			this->input_choice_text = (gcnew System::Windows::Forms::Label());
			this->input_choice = (gcnew System::Windows::Forms::ListBox());
			this->ref_btn = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// input_text
			// 
			this->input_text->AutoSize = true;
			this->input_text->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_text->Location = System::Drawing::Point(12, 47);
			this->input_text->Name = L"input_text";
			this->input_text->Size = System::Drawing::Size(369, 31);
			this->input_text->TabIndex = 0;
			this->input_text->Text = L"Введите граф списком ребер:";
			// 
			// input_field
			// 
			this->input_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_field->Location = System::Drawing::Point(17, 86);
			this->input_field->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->input_field->Multiline = true;
			this->input_field->Name = L"input_field";
			this->input_field->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->input_field->Size = System::Drawing::Size(383, 877);
			this->input_field->TabIndex = 1;
			// 
			// calc_btn
			// 
			this->calc_btn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->calc_btn->Location = System::Drawing::Point(439, 723);
			this->calc_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->calc_btn->Name = L"calc_btn";
			this->calc_btn->Size = System::Drawing::Size(421, 86);
			this->calc_btn->TabIndex = 2;
			this->calc_btn->Text = L"Найти ";
			this->calc_btn->UseVisualStyleBackColor = true;
			this->calc_btn->Click += gcnew System::EventHandler(this, &main::calc_btn_Click);
			// 
			// info_text
			// 
			this->info_text->AutoSize = true;
			this->info_text->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info_text->Location = System::Drawing::Point(433, 47);
			this->info_text->Name = L"info_text";
			this->info_text->Size = System::Drawing::Size(270, 31);
			this->info_text->TabIndex = 3;
			this->info_text->Text = L"Формат ввода графа:\r\n";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(1010, 86);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1000, 800);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 27;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Мосты", L"Точки сочленения", L"Компоненты связности " });
			this->listBox1->Location = System::Drawing::Point(439, 594);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(421, 85);
			this->listBox1->TabIndex = 8;
			// 
			// choise_txt
			// 
			this->choise_txt->AutoSize = true;
			this->choise_txt->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->choise_txt->Location = System::Drawing::Point(434, 564);
			this->choise_txt->Name = L"choise_txt";
			this->choise_txt->Size = System::Drawing::Size(394, 27);
			this->choise_txt->TabIndex = 9;
			this->choise_txt->Text = L"Выберите что хотите найти в графе:\r\n";
			// 
			// input_choice_text
			// 
			this->input_choice_text->AutoSize = true;
			this->input_choice_text->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_choice_text->Location = System::Drawing::Point(434, 428);
			this->input_choice_text->Name = L"input_choice_text";
			this->input_choice_text->Size = System::Drawing::Size(337, 27);
			this->input_choice_text->TabIndex = 10;
			this->input_choice_text->Text = L"Выберите способ ввода графа:";
			// 
			// input_choice
			// 
			this->input_choice->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_choice->FormattingEnabled = true;
			this->input_choice->ItemHeight = 27;
			this->input_choice->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ввод с клавиатуры", L"Ввод файлом" });
			this->input_choice->Location = System::Drawing::Point(439, 458);
			this->input_choice->Name = L"input_choice";
			this->input_choice->Size = System::Drawing::Size(332, 58);
			this->input_choice->TabIndex = 11;
			// 
			// ref_btn
			// 
			this->ref_btn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ref_btn->Location = System::Drawing::Point(439, 877);
			this->ref_btn->Name = L"ref_btn";
			this->ref_btn->Size = System::Drawing::Size(421, 86);
			this->ref_btn->TabIndex = 12;
			this->ref_btn->Text = L"Открыть справочную информацию";
			this->ref_btn->UseVisualStyleBackColor = true;
			this->ref_btn->Click += gcnew System::EventHandler(this, &main::ref_btn_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(439, 86);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(421, 308);
			this->textBox1->TabIndex = 13;
			this->textBox1->Text = L"В первой строке введите через пробел два числа N и M: количество вершин и ребер с"
				L"оответственно\r\nДалее в M строках введите через пробел концы ребер.\r\n\r\nПример:\r\n4"
				L" 4\r\n1 2\r\n3 2\r\n4 3\r\n3 1";
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ref_btn);
			this->Controls->Add(this->input_choice);
			this->Controls->Add(this->input_choice_text);
			this->Controls->Add(this->choise_txt);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->info_text);
			this->Controls->Add(this->calc_btn);
			this->Controls->Add(this->input_field);
			this->Controls->Add(this->input_text);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"form1";
			this->Text = L"Graph Layout";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void calc_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string s = msclr::interop::marshal_as<std::string>(input_field->Text);

		if (input_choice->SelectedIndex == -1) {
			MessageBox::Show(this, "Выберите способ ввода графа", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (s.empty()) {
			MessageBox::Show(this, "Поле входных данных пустое", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Graph G(s, input_choice->SelectedIndex);

		std::string error = "";
		if (!G.correct(error)) {
			MessageBox::Show(this, gcnew String(error.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (listBox1->SelectedIndex == 0) {
			G.Show_Bridges();
			pictureBox1->ImageLocation = "..\\..\\Images\\Bridges.png";
		}
		else if (listBox1->SelectedIndex == 1) {
			G.Show_ArticulationPoints();
			pictureBox1->ImageLocation = "..\\..\\Images\\ArticulationPoints.png";
		}
		else if (listBox1->SelectedIndex == 2) {
			G.Show_Components();
			pictureBox1->ImageLocation = "..\\..\\Images\\Components.png";
		}
		else {
			MessageBox::Show(this, "Выберите что хотите найти в графе", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void ref_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Reference_form == nullptr || Reference_form->IsDisposed) {
			Reference_form = gcnew Reference();
		}

		if (Reference_form->Visible) {
			Reference_form->Hide();
		}
		else {
			Reference_form->Show();
		}

	}
	};
}

