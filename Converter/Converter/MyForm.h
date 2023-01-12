#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <memory>
#include <sys/stat.h>
#include <urlmon.h>
#include "Currency.h"
#include <Windows.h>

#pragma comment(lib, "urlmon.lib")


namespace Converter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{
#pragma region DIFFERENT ELEMENT & CONSTRUCTER & DESTRUCTER
	public:
		MyForm(void)
		{
			InitializeComponent();

			System::Threading::Thread::CurrentThread->CurrentCulture = gcnew System::Globalization::CultureInfo("en-US");
			System::Threading::Thread::CurrentThread->CurrentUICulture = gcnew System::Globalization::CultureInfo("en-US");

			carrency1->SelectedIndex = 0;
			carrency2->SelectedIndex = 2;
			
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox^ userInput;
		System::Windows::Forms::TextBox^ result;

		System::Windows::Forms::Button^ convert;
		System::Windows::Forms::ComboBox^ carrency1;
		System::Windows::Forms::ComboBox^ carrency2;
		System::Windows::Forms::Button^ CloseApp;
		System::Windows::Forms::Label^ Title;

		System::ComponentModel::Container^ components;

		// Check that the file that has a name is existing.
		bool IsFileExist(const std::wstring& path)
		{
			std::ifstream in(path, std::ifstream::binary);

			if (!in.is_open())
			{
				return false;
			}
			in.close();
			return true;
		}

		// Check that current date and date when .json file was created are the same.
		bool IsFileDateEqCurrDate()
		{
			std::wstring tempPath{ path };
			if (!IsFileExist(tempPath))
			{
				return false;
			}

			struct stat fileInfo {};
			stat(std::string(tempPath.begin(), tempPath.end()).data(), &fileInfo);
			std::string fileDate = std::ctime(&fileInfo.st_ctime);

			std::time_t result = std::time(nullptr);
			std::string currentDate = std::ctime(&result);

			fileDate.erase(fileDate.begin() + 10, fileDate.end());
			currentDate.erase(currentDate.begin() + 10, currentDate.end());

			return fileDate == currentDate;
		}
		
		// URL is a site where program can download .json file, I took this URL in the National Ukraine Bank.
		wchar_t* URL = L"https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json";
		wchar_t* path = L"exchange.json";

#pragma endregion DIFFERENT ELEMENT & CONSTRUCTER & DESTRUCTER

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->userInput = (gcnew System::Windows::Forms::TextBox());
			this->result = (gcnew System::Windows::Forms::TextBox());
			this->convert = (gcnew System::Windows::Forms::Button());
			this->carrency1 = (gcnew System::Windows::Forms::ComboBox());
			this->carrency2 = (gcnew System::Windows::Forms::ComboBox());
			this->CloseApp = (gcnew System::Windows::Forms::Button());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// userInput
			// 
			this->userInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->userInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->userInput->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->userInput->ForeColor = System::Drawing::Color::White;
			this->userInput->Location = System::Drawing::Point(92, 79);
			this->userInput->Name = L"userInput";
			this->userInput->Size = System::Drawing::Size(126, 22);
			this->userInput->TabIndex = 2;
			this->userInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// result
			// 
			this->result->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->result->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->result->Enabled = false;
			this->result->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result->ForeColor = System::Drawing::Color::White;
			this->result->Location = System::Drawing::Point(92, 170);
			this->result->Name = L"result";
			this->result->ReadOnly = true;
			this->result->Size = System::Drawing::Size(126, 22);
			this->result->TabIndex = 3;
			this->result->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// convert
			// 
			this->convert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->convert->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->convert->ForeColor = System::Drawing::Color::White;
			this->convert->Location = System::Drawing::Point(95, 119);
			this->convert->Name = L"convert";
			this->convert->Size = System::Drawing::Size(123, 30);
			this->convert->TabIndex = 4;
			this->convert->Text = L"CONVERT";
			this->convert->UseVisualStyleBackColor = false;
			this->convert->Click += gcnew System::EventHandler(this, &MyForm::convert_Click);
			// 
			// carrency1
			// 
			this->carrency1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->carrency1->DisplayMember = L"0";
			this->carrency1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->carrency1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->carrency1->ForeColor = System::Drawing::Color::White;
			this->carrency1->FormattingEnabled = true;
			this->carrency1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"EUR", L"USD", L"UAN" });
			this->carrency1->Location = System::Drawing::Point(29, 77);
			this->carrency1->Name = L"carrency1";
			this->carrency1->Size = System::Drawing::Size(46, 24);
			this->carrency1->TabIndex = 9;
			this->carrency1->ValueMember = L"0";
			// 
			// carrency2
			// 
			this->carrency2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->carrency2->DisplayMember = L"0";
			this->carrency2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->carrency2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->carrency2->ForeColor = System::Drawing::Color::White;
			this->carrency2->FormattingEnabled = true;
			this->carrency2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"EUR", L"USD", L"UAN" });
			this->carrency2->Location = System::Drawing::Point(29, 168);
			this->carrency2->Name = L"carrency2";
			this->carrency2->Size = System::Drawing::Size(46, 24);
			this->carrency2->TabIndex = 10;
			this->carrency2->ValueMember = L"0";
			// 
			// CloseApp
			// 
			this->CloseApp->BackColor = System::Drawing::Color::Red;
			this->CloseApp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CloseApp->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CloseApp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseApp->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CloseApp->ForeColor = System::Drawing::Color::White;
			this->CloseApp->Location = System::Drawing::Point(190, 18);
			this->CloseApp->Name = L"CloseApp";
			this->CloseApp->Size = System::Drawing::Size(47, 26);
			this->CloseApp->TabIndex = 11;
			this->CloseApp->Text = L"X";
			this->CloseApp->UseVisualStyleBackColor = false;
			this->CloseApp->Click += gcnew System::EventHandler(this, &MyForm::CloseApp_Click);
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(23, 23);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(128, 15);
			this->Title->TabIndex = 12;
			this->Title->Text = L"Currency Converter";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->CancelButton = this->CloseApp;
			this->ClientSize = System::Drawing::Size(249, 250);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->CloseApp);
			this->Controls->Add(this->carrency2);
			this->Controls->Add(this->carrency1);
			this->Controls->Add(this->convert);
			this->Controls->Add(this->result);
			this->Controls->Add(this->userInput);
			this->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Currency Converter";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void convert_Click(System::Object^ sender, System::EventArgs^ e)
		{
			bool continueCode = true;

			if (!IsFileDateEqCurrDate())
			{
				if (IsFileExist(std::wstring{ *path }))
				{
					int result = _wremove(path);
				}

				if (S_OK != URLDownloadToFile(nullptr, URL, path, 0, nullptr))
				{
					MessageBox::Show("Maybe, You have not internet conection!!!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					continueCode = false;
				}
			}
			
			if (continueCode)
			{
				std::wstring tempPath{ path };
				Currency currency{ std::string(tempPath.begin(), tempPath.end()) };

				float uaserValue;
				if (System::Single::TryParse(userInput->Text, uaserValue))
				{
					if (carrency1->SelectedIndex == static_cast<int>(CurrencyType::EUR))
					{
						if (carrency2->SelectedIndex == static_cast<int>(CurrencyType::USD))
						{
							uaserValue = uaserValue * currency.GetRate("EUR") / currency.GetRate("USD");
						}
						else if (carrency2->SelectedIndex == static_cast<int>(CurrencyType::UAN))
						{
							uaserValue = uaserValue * currency.GetRate("EUR");
						}
					}
					else if (carrency1->SelectedIndex == static_cast<int>(CurrencyType::USD))
					{
						if (carrency2->SelectedIndex == static_cast<int>(CurrencyType::EUR))
						{
							uaserValue = uaserValue * currency.GetRate("USD") / currency.GetRate("EUR");
						}
						else if (carrency2->SelectedIndex == static_cast<int>(CurrencyType::UAN))
						{
							uaserValue = uaserValue * currency.GetRate("USD");
						}
					}
					else if (carrency1->SelectedIndex == static_cast<int>(CurrencyType::UAN))
					{
						if (carrency2->SelectedIndex == static_cast<int>(CurrencyType::EUR))
						{
							uaserValue = uaserValue / currency.GetRate("EUR");
						}
						else if (carrency2->SelectedIndex == static_cast<int>(CurrencyType::USD))
						{
							uaserValue = uaserValue / currency.GetRate("USD");
						}
					}

					result->Text = uaserValue.ToString("F2");
				}
				else
				{
					MessageBox::Show("Incorect input!!!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		System::Void CloseApp_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}
