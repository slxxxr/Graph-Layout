#pragma once
#include "Graph.h"
#include <msclr\marshal_cppstd.h>


namespace kurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для form1
	/// </summary>
	public ref class form1 : public System::Windows::Forms::Form
	{
	public:
		form1(void)
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
		~form1()
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
	private: System::Windows::Forms::Label^ sample_text;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ choise_txt;
	private: System::Windows::Forms::Label^ out_format_txt;
	private: System::Windows::Forms::Label^ out_text;



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
			this->sample_text = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->choise_txt = (gcnew System::Windows::Forms::Label());
			this->out_format_txt = (gcnew System::Windows::Forms::Label());
			this->out_text = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// input_text
			// 
			this->input_text->AutoSize = true;
			this->input_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_text->Location = System::Drawing::Point(12, 47);
			this->input_text->Name = L"input_text";
			this->input_text->Size = System::Drawing::Size(388, 29);
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
			this->calc_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->calc_btn->Location = System::Drawing::Point(439, 485);
			this->calc_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->calc_btn->Name = L"calc_btn";
			this->calc_btn->Size = System::Drawing::Size(421, 86);
			this->calc_btn->TabIndex = 2;
			this->calc_btn->Text = L"Найти ";
			this->calc_btn->UseVisualStyleBackColor = true;
			this->calc_btn->Click += gcnew System::EventHandler(this, &form1::calc_btn_Click);
			// 
			// info_text
			// 
			this->info_text->AutoSize = true;
			this->info_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info_text->Location = System::Drawing::Point(434, 47);
			this->info_text->Name = L"info_text";
			this->info_text->Size = System::Drawing::Size(287, 29);
			this->info_text->TabIndex = 3;
			this->info_text->Text = L"Формат ввода графа:\r\n";
			// 
			// sample_text
			// 
			this->sample_text->AutoSize = true;
			this->sample_text->BackColor = System::Drawing::Color::White;
			this->sample_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sample_text->Location = System::Drawing::Point(435, 86);
			this->sample_text->Name = L"sample_text";
			this->sample_text->Size = System::Drawing::Size(493, 220);
			this->sample_text->TabIndex = 4;
			this->sample_text->Text = L"В первой строке введите через пробел два числа N и M: \r\nколичество вершин и ребер"
				L" соответственно\r\nДалее в M строках введите через пробел концы ребер.\r\n\r\nПример:\r"
				L"\n4 4\r\n1 2\r\n3 2\r\n4 3\r\n3 1";
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
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 25;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Мосты", L"Точки сочленения", L"Компоненты связности " });
			this->listBox1->Location = System::Drawing::Point(439, 364);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(421, 79);
			this->listBox1->TabIndex = 8;
			// 
			// choise_txt
			// 
			this->choise_txt->AutoSize = true;
			this->choise_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->choise_txt->Location = System::Drawing::Point(434, 336);
			this->choise_txt->Name = L"choise_txt";
			this->choise_txt->Size = System::Drawing::Size(395, 25);
			this->choise_txt->TabIndex = 9;
			this->choise_txt->Text = L"Выберите что хотите найти в графе:\r\n";
			// 
			// out_format_txt
			// 
			this->out_format_txt->AutoSize = true;
			this->out_format_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->out_format_txt->Location = System::Drawing::Point(434, 610);
			this->out_format_txt->Name = L"out_format_txt";
			this->out_format_txt->Size = System::Drawing::Size(382, 26);
			this->out_format_txt->TabIndex = 10;
			this->out_format_txt->Text = L"Информация о формате вывода:";
			// 
			// out_text
			// 
			this->out_text->AutoSize = true;
			this->out_text->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->out_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->out_text->Location = System::Drawing::Point(435, 646);
			this->out_text->Name = L"out_text";
			this->out_text->Size = System::Drawing::Size(343, 22);
			this->out_text->TabIndex = 11;
			this->out_text->Text = L"Выберите что хотите найти в графе";
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->out_text);
			this->Controls->Add(this->out_format_txt);
			this->Controls->Add(this->choise_txt);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->sample_text);
			this->Controls->Add(this->info_text);
			this->Controls->Add(this->calc_btn);
			this->Controls->Add(this->input_field);
			this->Controls->Add(this->input_text);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"form1";
			this->Text = L"form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void calc_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string s = msclr::interop::marshal_as<std::string>(input_field->Text);

		if (s.empty()) {
			MessageBox::Show(this, "Введите граф", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Graph G(s);

		if (!G.correct()) {
			MessageBox::Show(this, "Некорректные входные данные", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}



		if (listBox1->SelectedIndex == 0) {
			out_text->Text = "Ребра, являющиеся мостами," + "\n" + "отображены красным цветом";

			G.Show_Bridges();
			pictureBox1->ImageLocation = "D:\\GraphLayout\\Images\\Bridges.png";
		}
		else if (listBox1->SelectedIndex == 1) {
			out_text->Text = "Вершины, являющиеся точками сочленения," + "\n" + "отображены красным цветом";

			G.Show_ArticulationPoints();
			pictureBox1->ImageLocation = "D:\\GraphLayout\\Images\\ArticulationPoints.png";
		}
		else if (listBox1->SelectedIndex == 2) {
			out_text->Text = "Вершины одной комопненты связности " + "\n" + "отображены своим уникальным цветом";

			G.Show_Components();
			pictureBox1->ImageLocation = "D:\\GraphLayout\\Images\\Components.png";
		}
		else {
			MessageBox::Show(this, "Выберите что хотите найти в графе", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	};
}

