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

	private: System::Windows::Forms::Label^  exposureLabel;

	private: System::Windows::Forms::Label^  gainLabel;



	private: System::Windows::Forms::Button^  ok;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TrackBar^  FPS;
	private: System::Windows::Forms::Label^  FPSLabel;

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
			this->exposureLabel = (gcnew System::Windows::Forms::Label());
			this->gainLabel = (gcnew System::Windows::Forms::Label());
			this->ok = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->FPSLabel = (gcnew System::Windows::Forms::Label());
			this->FPS = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Gain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Exposure))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LED_PWM))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FPS))->BeginInit();
			this->SuspendLayout();
			// 
			// Gain
			// 
			this->Gain->Location = System::Drawing::Point(0, 150);
			this->Gain->Maximum = 100;
			this->Gain->Name = L"Gain";
			this->Gain->Size = System::Drawing::Size(568, 45);
			this->Gain->TabIndex = 0;
			this->Gain->Value = 15;
			this->Gain->Scroll += gcnew System::EventHandler(this, &FPSDialog::Gain_Scroll);
			// 
			// Exposure
			// 
			this->Exposure->Location = System::Drawing::Point(0, 214);
			this->Exposure->Maximum = 100;
			this->Exposure->Name = L"Exposure";
			this->Exposure->Size = System::Drawing::Size(568, 45);
			this->Exposure->TabIndex = 1;
			this->Exposure->Value = 15;
			this->Exposure->Scroll += gcnew System::EventHandler(this, &FPSDialog::Exposure_Scroll);
			// 
			// LED_PWM
			// 
			this->LED_PWM->Location = System::Drawing::Point(0, 278);
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
			this->LEDLabel->Location = System::Drawing::Point(245, 262);
			this->LEDLabel->Name = L"LEDLabel";
			this->LEDLabel->Size = System::Drawing::Size(79, 13);
			this->LEDLabel->TabIndex = 3;
			this->LEDLabel->Text = L"LED PWM:  15";
			// 
			// exposureLabel
			// 
			this->exposureLabel->AutoSize = true;
			this->exposureLabel->Location = System::Drawing::Point(245, 198);
			this->exposureLabel->Name = L"exposureLabel";
			this->exposureLabel->Size = System::Drawing::Size(72, 13);
			this->exposureLabel->TabIndex = 5;
			this->exposureLabel->Text = L"Exposure:  15";
			// 
			// gainLabel
			// 
			this->gainLabel->AutoSize = true;
			this->gainLabel->Location = System::Drawing::Point(259, 134);
			this->gainLabel->Name = L"gainLabel";
			this->gainLabel->Size = System::Drawing::Size(50, 13);
			this->gainLabel->TabIndex = 7;
			this->gainLabel->Text = L"Gain:  15";
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->FPSLabel);
			this->groupBox1->Controls->Add(this->FPS);
			this->groupBox1->Controls->Add(this->LED_PWM);
			this->groupBox1->Controls->Add(this->gainLabel);
			this->groupBox1->Controls->Add(this->LEDLabel);
			this->groupBox1->Controls->Add(this->Gain);
			this->groupBox1->Controls->Add(this->exposureLabel);
			this->groupBox1->Controls->Add(this->Exposure);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(568, 330);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// FPSLabel
			// 
			this->FPSLabel->AutoSize = true;
			this->FPSLabel->Location = System::Drawing::Point(260, 67);
			this->FPSLabel->Name = L"FPSLabel";
			this->FPSLabel->Size = System::Drawing::Size(48, 13);
			this->FPSLabel->TabIndex = 9;
			this->FPSLabel->Text = L"FPS:  15";
			// 
			// FPS
			// 
			this->FPS->Location = System::Drawing::Point(0, 86);
			this->FPS->Maximum = 120;
			this->FPS->Name = L"FPS";
			this->FPS->Size = System::Drawing::Size(568, 45);
			this->FPS->TabIndex = 8;
			this->FPS->Value = 15;
			this->FPS->Scroll += gcnew System::EventHandler(this, &FPSDialog::FPS_Scroll);
			// 
			// FPSDialog
			// 
			this->AcceptButton = this->ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 383);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->groupBox1);
			this->Name = L"FPSDialog";
			this->Text = L"FPS/Gain/Exposure/LED";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Gain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Exposure))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LED_PWM))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FPS))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Gain_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->gainLabel->Text = "Gain:  " + this->Gain->Value.ToString();
		gain = this->Gain->Value;
	}
	private: System::Void Exposure_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->exposureLabel->Text = "Exposure:  " + this->Exposure->Value.ToString();
		exposure = this->Exposure->Value;
	}
	private: System::Void LED_PWM_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->LEDLabel->Text = "LED PWM:  " + this->LED_PWM->Value.ToString();
		LED = this->LED_PWM->Value;
	}
	private: System::Void ok_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void FPS_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->FPSLabel->Text = "FPS:  " + this->FPS->Value.ToString();
		fps = this->FPS->Value;
	}
	};
}
