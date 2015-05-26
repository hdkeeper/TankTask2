#pragma once
#include "TankView.h"

namespace WindowsFormsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Главное окно программы
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			// Создать представление модели
			view = gcnew TankView(viewBox->Width, viewBox->Height);
			tank = view->tank;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			delete view;
		}
	private: System::Windows::Forms::PictureBox^  viewBox;
	private: System::Windows::Forms::Panel^  topPanel;
	private: System::Windows::Forms::HScrollBar^  inPerflBar;
	private: System::Windows::Forms::Panel^  leftPanel;
	private: System::Windows::Forms::VScrollBar^  openHeightBar;
	private: System::Windows::Forms::Panel^  rightPanel;
	private: System::Windows::Forms::VScrollBar^  closeHeightBar;
	private: System::Windows::Forms::Label^  topLabel;
	private: System::Windows::Forms::Label^  leftLabel;
	private: System::Windows::Forms::Label^  rightLabel;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Timer^  simTimer;
	private: System::Windows::Forms::Label^  bottomLabel;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		
		// Ссылка на представление
		TankView ^view = nullptr;

		// Ссылка на модель
		Tank *tank = 0;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->viewBox = (gcnew System::Windows::Forms::PictureBox());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->inPerflBar = (gcnew System::Windows::Forms::HScrollBar());
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->openHeightBar = (gcnew System::Windows::Forms::VScrollBar());
			this->rightPanel = (gcnew System::Windows::Forms::Panel());
			this->closeHeightBar = (gcnew System::Windows::Forms::VScrollBar());
			this->topLabel = (gcnew System::Windows::Forms::Label());
			this->leftLabel = (gcnew System::Windows::Forms::Label());
			this->rightLabel = (gcnew System::Windows::Forms::Label());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->simTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->bottomLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewBox))->BeginInit();
			this->topPanel->SuspendLayout();
			this->leftPanel->SuspendLayout();
			this->rightPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// viewBox
			// 
			this->viewBox->BackColor = System::Drawing::SystemColors::Control;
			this->viewBox->Location = System::Drawing::Point(161, 100);
			this->viewBox->Name = L"viewBox";
			this->viewBox->Size = System::Drawing::Size(600, 450);
			this->viewBox->TabIndex = 0;
			this->viewBox->TabStop = false;
			this->viewBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::viewBox_Paint);
			// 
			// topPanel
			// 
			this->topPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->topPanel->Controls->Add(this->inPerflBar);
			this->topPanel->Location = System::Drawing::Point(161, 74);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(600, 20);
			this->topPanel->TabIndex = 2;
			// 
			// inPerflBar
			// 
			this->inPerflBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->inPerflBar->LargeChange = 1;
			this->inPerflBar->Location = System::Drawing::Point(0, 0);
			this->inPerflBar->Name = L"inPerflBar";
			this->inPerflBar->Size = System::Drawing::Size(598, 18);
			this->inPerflBar->TabIndex = 0;
			this->inPerflBar->Value = 50;
			this->inPerflBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::inPerflBar_ValueChanged);
			// 
			// leftPanel
			// 
			this->leftPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->leftPanel->Controls->Add(this->openHeightBar);
			this->leftPanel->Location = System::Drawing::Point(135, 100);
			this->leftPanel->Name = L"leftPanel";
			this->leftPanel->Size = System::Drawing::Size(20, 450);
			this->leftPanel->TabIndex = 3;
			// 
			// openHeightBar
			// 
			this->openHeightBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->openHeightBar->LargeChange = 1;
			this->openHeightBar->Location = System::Drawing::Point(0, 0);
			this->openHeightBar->Name = L"openHeightBar";
			this->openHeightBar->Size = System::Drawing::Size(18, 448);
			this->openHeightBar->TabIndex = 0;
			this->openHeightBar->Value = 10;
			this->openHeightBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::openHeightBar_ValueChanged);
			// 
			// rightPanel
			// 
			this->rightPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rightPanel->Controls->Add(this->closeHeightBar);
			this->rightPanel->Location = System::Drawing::Point(767, 100);
			this->rightPanel->Name = L"rightPanel";
			this->rightPanel->Size = System::Drawing::Size(20, 450);
			this->rightPanel->TabIndex = 4;
			// 
			// closeHeightBar
			// 
			this->closeHeightBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->closeHeightBar->LargeChange = 1;
			this->closeHeightBar->Location = System::Drawing::Point(0, 0);
			this->closeHeightBar->Name = L"closeHeightBar";
			this->closeHeightBar->Size = System::Drawing::Size(18, 448);
			this->closeHeightBar->TabIndex = 0;
			this->closeHeightBar->Value = 40;
			this->closeHeightBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::closeHeightBar_ValueChanged);
			// 
			// topLabel
			// 
			this->topLabel->AutoSize = true;
			this->topLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->topLabel->Location = System::Drawing::Point(220, 51);
			this->topLabel->Name = L"topLabel";
			this->topLabel->Size = System::Drawing::Size(460, 20);
			this->topLabel->TabIndex = 5;
			this->topLabel->Text = L"Производительность потока из подводящей трубы: 2,5 л/с";
			// 
			// leftLabel
			// 
			this->leftLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->leftLabel->Location = System::Drawing::Point(26, 100);
			this->leftLabel->Name = L"leftLabel";
			this->leftLabel->Size = System::Drawing::Size(107, 72);
			this->leftLabel->TabIndex = 6;
			this->leftLabel->Text = L"Высота датчика, открывающего заслонку";
			this->leftLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// rightLabel
			// 
			this->rightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rightLabel->Location = System::Drawing::Point(789, 100);
			this->rightLabel->Name = L"rightLabel";
			this->rightLabel->Size = System::Drawing::Size(108, 72);
			this->rightLabel->TabIndex = 7;
			this->rightLabel->Text = L"Высота датчика, закрывающего заслонку";
			// 
			// startButton
			// 
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->startButton->Location = System::Drawing::Point(342, 12);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(238, 28);
			this->startButton->TabIndex = 8;
			this->startButton->Text = L"Запустить симуляцию";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MainForm::startButton_Click);
			// 
			// simTimer
			// 
			this->simTimer->Tick += gcnew System::EventHandler(this, &MainForm::simTimer_Tick);
			// 
			// bottomLabel
			// 
			this->bottomLabel->AutoSize = true;
			this->bottomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bottomLabel->Location = System::Drawing::Point(306, 553);
			this->bottomLabel->Name = L"bottomLabel";
			this->bottomLabel->Size = System::Drawing::Size(289, 20);
			this->bottomLabel->TabIndex = 9;
			this->bottomLabel->Text = L"Количество жидкости в ёмкости: 0 л";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(933, 595);
			this->Controls->Add(this->bottomLabel);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->rightLabel);
			this->Controls->Add(this->leftLabel);
			this->Controls->Add(this->topLabel);
			this->Controls->Add(this->rightPanel);
			this->Controls->Add(this->leftPanel);
			this->Controls->Add(this->topPanel);
			this->Controls->Add(this->viewBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Модель регулятора";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewBox))->EndInit();
			this->topPanel->ResumeLayout(false);
			this->leftPanel->ResumeLayout(false);
			this->rightPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void viewBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			// Нарисовать ёмкость
			view->draw(e->Graphics);
		}

		private: System::Void inPerflBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			// Пересчитать производительность трубы
			tank->inTube->perfomance = - tank->outTube->perfomance *
				(double)inPerflBar->Value / (double)inPerflBar->Maximum;

			// Обновить верхнюю надпись
			topLabel->Text = String::Format(L"Производительность потока из подводящей трубы: {0} л/с", 
				tank->inTube->perfomance);
		
			// Перерисовать ёмкость
			viewBox->Refresh();
		}

		private: System::Void openHeightBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			// Пересчитать высоту открывающего датчика
			tank->openingSensor->height = 1 - (double)openHeightBar->Value / (double)openHeightBar->Maximum;
		
			// Перерисовать ёмкость
			viewBox->Refresh();
		}

		private: System::Void closeHeightBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			// Пересчитать высоту закрывающего датчика
			tank->closingSensor->height = 1 - (double)closeHeightBar->Value / (double)closeHeightBar->Maximum;
		
			// Перерисовать ёмкость
			viewBox->Refresh();
		}

		private: System::Void simTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			// Пересчитать параметры модели
			tank->update();
		
			// Перерисовать ёмкость
			viewBox->Refresh();
		
			// Обновить нижнюю надпись
			bottomLabel->Text = String::Format(L"Количество жидкости в ёмкости: {0:f3} л", tank->volume);
		}

		private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
			// Включить или выключить таймер
			simTimer->Enabled = !simTimer->Enabled;
		
			// Изменить надпись на кнопке
			startButton->Text = simTimer->Enabled ? L"Остановить симуляцию" : L"Запустить симуляцию";
		}

	};

} // namespace WindowsFormsApp
