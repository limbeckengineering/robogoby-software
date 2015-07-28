#pragma once

//#include <iostream>
#include <msclr\marshal_cppstd.h>

//IP address of the server
std::string IP = "10.0.1.31";

namespace Learn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for serverSettingsDialoge
	/// </summary>
	public ref class serverSettingsDialoge : public System::Windows::Forms::Form
	{
	public:
		serverSettingsDialoge(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~serverSettingsDialoge()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  IPAddressTextBox;
	protected:

	protected:

	private: System::Windows::Forms::GroupBox^  IPGroupBox;

	private: System::Windows::Forms::Button^  Ok;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->IPAddressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IPGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Ok = (gcnew System::Windows::Forms::Button());
			this->IPGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// IPAddressTextBox
			// 
			this->IPAddressTextBox->Location = System::Drawing::Point(79, 37);
			this->IPAddressTextBox->Name = L"IPAddressTextBox";
			this->IPAddressTextBox->Size = System::Drawing::Size(100, 20);
			this->IPAddressTextBox->TabIndex = 0;
			// 
			// IPGroupBox
			// 
			this->IPGroupBox->Controls->Add(this->IPAddressTextBox);
			this->IPGroupBox->Location = System::Drawing::Point(13, 13);
			this->IPGroupBox->Name = L"IPGroupBox";
			this->IPGroupBox->Size = System::Drawing::Size(259, 90);
			this->IPGroupBox->TabIndex = 1;
			this->IPGroupBox->TabStop = false;
			this->IPGroupBox->Text = L"IP Address";
			// 
			// Ok
			// 
			this->Ok->Location = System::Drawing::Point(105, 131);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(75, 23);
			this->Ok->TabIndex = 2;
			this->Ok->Text = L"Ok";
			this->Ok->UseVisualStyleBackColor = true;
			this->Ok->Click += gcnew System::EventHandler(this, &serverSettingsDialoge::Ok_Click);
			// 
			// serverSettingsDialoge
			// 
			this->AcceptButton = this->Ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 166);
			this->Controls->Add(this->Ok);
			this->Controls->Add(this->IPGroupBox);
			this->Name = L"serverSettingsDialoge";
			this->Text = L"Server Settings";
			this->IPGroupBox->ResumeLayout(false);
			this->IPGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Ok_Click(System::Object^  sender, System::EventArgs^  e) {
		msclr::interop::marshal_context context;
		IP = context.marshal_as<std::string>(this->IPAddressTextBox->Text);
		this->Close();
	}
	};
}
