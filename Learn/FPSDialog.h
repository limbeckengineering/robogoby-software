#pragma once

#include <stdint.h>

uint16_t fps = 15; 
uint8_t gain = 15, exposure = 15, LED = 15;


namespace Learn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// Summary for FPSDialouge
	/// </summary>
	public ref class FPSDialog : public System::Windows::Forms::Form
	{
	public:
		FPSDialog()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FPSDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TrackBar^  Gain;
	private: System::Windows::Forms::TrackBar^  Exposure;
	private: System::Windows::Forms::TrackBar^  LED_PWM;
	private: System::Windows::Forms::Label^  LEDLabel;
	private: System::Windows::Forms::Label^  LEDValues;
	private: System::Windows::Forms::Label^  exposureLabel;
	private: System::Windows::Forms::Label^  exposureValue;
	private: System::Windows::Forms::Label^  gainLabel;
	private: System::Windows::Forms::Label^  gainValue;
	private: System::Windows::Forms::TextBox^  FPSTextBox;
	private: System::Windows::Forms::Button^  FPSButton;
	private: System::Windows::Forms::Button^  ok;
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
			this->Gain = (gcnew System::Windows::Forms::TrackBar());
			this->Exposure = (gcnew System::Windows::Forms::TrackBar());
			this->LED_PWM = (gcnew System::Windows::Forms::TrackBar());
			this->LEDLabel = (gcnew System::Windows::Forms::Label());
			this->LEDValues = (gcnew System::Windows::Forms::Label());
			this->exposureLabel = (gcnew System::Windows::Forms::Label());
			this->exposureValue = (gcnew System::Windows::Forms::Label());
			this->gainLabel = (gcnew System::Windows::Forms::Label());
			this->gainValue = (gcnew System::Windows::Forms::Label());
			this->FPSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FPSButton = (gcnew System::Windows::Forms::Button());
			this->ok = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Gain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Exposure))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LED_PWM))->BeginInit();
			this->SuspendLayout();
			// 
			// Gain
			// 
			this->Gain->Location = System::Drawing::Point(12, 146);
			this->Gain->Maximum = 100;
			this->Gain->Name = L"Gain";
			this->Gain->Size = System::Drawing::Size(568, 45);
			this->Gain->TabIndex = 0;
			this->Gain->Value = 15;
			this->Gain->Scroll += gcnew System::EventHandler(this, &FPSDialog::Gain_Scroll);
			// 
			// Exposure
			// 
			this->Exposure->Location = System::Drawing::Point(12, 210);
			this->Exposure->Maximum = 100;
			this->Exposure->Name = L"Exposure";
			this->Exposure->Size = System::Drawing::Size(568, 45);
			this->Exposure->TabIndex = 1;
			this->Exposure->Value = 15;
			this->Exposure->Scroll += gcnew System::EventHandler(this, &FPSDialog::Exposure_Scroll);
			// 
			// LED_PWM
			// 
			this->LED_PWM->Location = System::Drawing::Point(12, 274);
			this->LED_PWM->Maximum = 100;
			this->LED_PWM->Name = L"LED_PWM";
			this->LED_PWM->Size = System::Drawing::Size(568, 45);
			this->LED_PWM->TabIndex = 2;
			this->LED_PWM->Value = 15;
			this->LED_PWM->Scroll += gcnew System::EventHandler(this, &FPSDialog::LED_PWM_Scroll);
			// 
			// LEDLabel
			// 
			this->LEDLabel->AutoSize = true;
			this->LEDLabel->Location = System::Drawing::Point(224, 258);
			this->LEDLabel->Name = L"LEDLabel";
			this->LEDLabel->Size = System::Drawing::Size(58, 13);
			this->LEDLabel->TabIndex = 3;
			this->LEDLabel->Text = L"LED PWM";
			// 
			// LEDValues
			// 
			this->LEDValues->AutoSize = true;
			this->LEDValues->Location = System::Drawing::Point(315, 258);
			this->LEDValues->Name = L"LEDValues";
			this->LEDValues->Size = System::Drawing::Size(19, 13);
			this->LEDValues->TabIndex = 4;
			this->LEDValues->Text = L"15";
			// 
			// exposureLabel
			// 
			this->exposureLabel->AutoSize = true;
			this->exposureLabel->Location = System::Drawing::Point(224, 194);
			this->exposureLabel->Name = L"exposureLabel";
			this->exposureLabel->Size = System::Drawing::Size(51, 13);
			this->exposureLabel->TabIndex = 5;
			this->exposureLabel->Text = L"Exposure";
			// 
			// exposureValue
			// 
			this->exposureValue->AutoSize = true;
			this->exposureValue->Location = System::Drawing::Point(315, 194);
			this->exposureValue->Name = L"exposureValue";
			this->exposureValue->Size = System::Drawing::Size(19, 13);
			this->exposureValue->TabIndex = 6;
			this->exposureValue->Text = L"15";
			// 
			// gainLabel
			// 
			this->gainLabel->AutoSize = true;
			this->gainLabel->Location = System::Drawing::Point(224, 130);
			this->gainLabel->Name = L"gainLabel";
			this->gainLabel->Size = System::Drawing::Size(29, 13);
			this->gainLabel->TabIndex = 7;
			this->gainLabel->Text = L"Gain";
			// 
			// gainValue
			// 
			this->gainValue->AutoSize = true;
			this->gainValue->Location = System::Drawing::Point(315, 130);
			this->gainValue->Name = L"gainValue";
			this->gainValue->Size = System::Drawing::Size(19, 13);
			this->gainValue->TabIndex = 8;
			this->gainValue->Text = L"15";
			// 
			// FPSTextBox
			// 
			this->FPSTextBox->Location = System::Drawing::Point(227, 78);
			this->FPSTextBox->Name = L"FPSTextBox";
			this->FPSTextBox->Size = System::Drawing::Size(100, 20);
			this->FPSTextBox->TabIndex = 9;
			this->FPSTextBox->Text = L"15";
			// 
			// FPSButton
			// 
			this->FPSButton->Location = System::Drawing::Point(240, 49);
			this->FPSButton->Name = L"FPSButton";
			this->FPSButton->Size = System::Drawing::Size(75, 23);
			this->FPSButton->TabIndex = 10;
			this->FPSButton->Text = L"Set FPS";
			this->FPSButton->UseVisualStyleBackColor = true;
			this->FPSButton->Click += gcnew System::EventHandler(this, &FPSDialog::FPSButton_Click);
			// 
			// ok
			// 
			this->ok->Location = System::Drawing::Point(505, 348);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(75, 23);
			this->ok->TabIndex = 11;
			this->ok->Text = L"Ok";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &FPSDialog::ok_Click);
			// 
			// FPSDialouge
			// 
			this->AcceptButton = this->ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 383);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->FPSButton);
			this->Controls->Add(this->FPSTextBox);
			this->Controls->Add(this->gainValue);
			this->Controls->Add(this->gainLabel);
			this->Controls->Add(this->exposureValue);
			this->Controls->Add(this->exposureLabel);
			this->Controls->Add(this->LEDValues);
			this->Controls->Add(this->LEDLabel);
			this->Controls->Add(this->LED_PWM);
			this->Controls->Add(this->Exposure);
			this->Controls->Add(this->Gain);
			this->Name = L"FPSDialouge";
			this->Text = L"FPS/Gain/Exposure/LED";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Gain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Exposure))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LED_PWM))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void FPSButton_Click(System::Object^  sender, System::EventArgs^  e) {
		fps = uint16_t::Parse(this->FPSTextBox->Text);
	}
	private: System::Void Gain_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->gainValue->Text = this->Gain->Value.ToString();
		gain = this->Gain->Value;
	}
	private: System::Void Exposure_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->exposureValue->Text = this->Exposure->Value.ToString();
		exposure = this->Exposure->Value;
	}
	private: System::Void LED_PWM_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->LEDValues->Text = this->LED_PWM->Value.ToString();
		LED = this->LED_PWM->Value;
	}
	private: System::Void ok_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
