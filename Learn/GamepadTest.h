#pragma once

#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "GamePad.h"

//remember to use \r\n to return in rich text box

GamePad * gp;

bool buttonsPressed[14];

namespace Learn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GamepadTest
	/// </summary>
	public ref class GamepadTest : public System::Windows::Forms::Form
	{
	public:
		GamepadTest(void)
		{
			InitializeComponent();
			gp = new GamePad(1);
			bgwUpdateController->RunWorkerAsync();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GamepadTest()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::BackgroundWorker^  bgwUpdateController;
	private: System::Windows::Forms::RadioButton^  rbA;
	private: System::Windows::Forms::RadioButton^  rbB;
	private: System::Windows::Forms::RadioButton^  rbX;
	private: System::Windows::Forms::RadioButton^  rbY;
	private: System::Windows::Forms::RadioButton^  rbDPAD_UP;
	private: System::Windows::Forms::RadioButton^  rbDPAD_DOWN;
	private: System::Windows::Forms::RadioButton^  rbDPAD_LEFT;
	private: System::Windows::Forms::RadioButton^  rbDPAD_RIGHT;
	private: System::Windows::Forms::RadioButton^  rbLEFT_SHOULDER;
	private: System::Windows::Forms::RadioButton^  rbRIGHT_SHOULDER;
	private: System::Windows::Forms::RadioButton^  rbLEFT_THUMB;
	private: System::Windows::Forms::RadioButton^  rbRIGHT_THUMB;
	private: System::Windows::Forms::RadioButton^  rbSTART;
	private: System::Windows::Forms::RadioButton^  rbBACK;
	private: System::Windows::Forms::ProgressBar^  pbLEFT_TRIGGER;
	private: System::Windows::Forms::ProgressBar^  pbRIGHT_TRIGGER;
	private: System::Windows::Forms::Label^  lLTRIGGER;
	private: System::Windows::Forms::Label^  lRTRIGGER;
	private: System::Windows::Forms::Label^  lLSTICK;
	private: System::Windows::Forms::Label^  lRSTICK;
	private: System::Windows::Forms::Label^  lLX;
	private: System::Windows::Forms::Label^  lLY;
	private: System::Windows::Forms::Label^  lRX;
	private: System::Windows::Forms::Label^  lRY;
	private: System::Windows::Forms::Label^  lLXOUTPUT;
	private: System::Windows::Forms::Label^  lLYOUTPUT;
	private: System::Windows::Forms::Label^  lRXOUTPUT;
	private: System::Windows::Forms::Label^  lRYOUTPUT;
	private: System::Windows::Forms::RichTextBox^  rtbOUTPUT_GENERAL;


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
			this->bgwUpdateController = (gcnew System::ComponentModel::BackgroundWorker());
			this->rbA = (gcnew System::Windows::Forms::RadioButton());
			this->rbB = (gcnew System::Windows::Forms::RadioButton());
			this->rbX = (gcnew System::Windows::Forms::RadioButton());
			this->rbY = (gcnew System::Windows::Forms::RadioButton());
			this->rbDPAD_UP = (gcnew System::Windows::Forms::RadioButton());
			this->rbDPAD_DOWN = (gcnew System::Windows::Forms::RadioButton());
			this->rbDPAD_LEFT = (gcnew System::Windows::Forms::RadioButton());
			this->rbDPAD_RIGHT = (gcnew System::Windows::Forms::RadioButton());
			this->rbLEFT_SHOULDER = (gcnew System::Windows::Forms::RadioButton());
			this->rbRIGHT_SHOULDER = (gcnew System::Windows::Forms::RadioButton());
			this->rbLEFT_THUMB = (gcnew System::Windows::Forms::RadioButton());
			this->rbRIGHT_THUMB = (gcnew System::Windows::Forms::RadioButton());
			this->rbSTART = (gcnew System::Windows::Forms::RadioButton());
			this->rbBACK = (gcnew System::Windows::Forms::RadioButton());
			this->pbLEFT_TRIGGER = (gcnew System::Windows::Forms::ProgressBar());
			this->pbRIGHT_TRIGGER = (gcnew System::Windows::Forms::ProgressBar());
			this->lLTRIGGER = (gcnew System::Windows::Forms::Label());
			this->lRTRIGGER = (gcnew System::Windows::Forms::Label());
			this->lLSTICK = (gcnew System::Windows::Forms::Label());
			this->lRSTICK = (gcnew System::Windows::Forms::Label());
			this->lLX = (gcnew System::Windows::Forms::Label());
			this->lLY = (gcnew System::Windows::Forms::Label());
			this->lRX = (gcnew System::Windows::Forms::Label());
			this->lRY = (gcnew System::Windows::Forms::Label());
			this->lLXOUTPUT = (gcnew System::Windows::Forms::Label());
			this->lLYOUTPUT = (gcnew System::Windows::Forms::Label());
			this->lRXOUTPUT = (gcnew System::Windows::Forms::Label());
			this->lRYOUTPUT = (gcnew System::Windows::Forms::Label());
			this->rtbOUTPUT_GENERAL = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// bgwUpdateController
			// 
			this->bgwUpdateController->WorkerReportsProgress = true;
			this->bgwUpdateController->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GamepadTest::bgwUpdateController_DoWork);
			this->bgwUpdateController->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &GamepadTest::bgwUpdateController_ProgressChanged);
			// 
			// rbA
			// 
			this->rbA->AutoSize = true;
			this->rbA->Location = System::Drawing::Point(13, 13);
			this->rbA->Name = L"rbA";
			this->rbA->Size = System::Drawing::Size(32, 17);
			this->rbA->TabIndex = 0;
			this->rbA->TabStop = true;
			this->rbA->Text = L"A";
			this->rbA->UseVisualStyleBackColor = true;
			// 
			// rbB
			// 
			this->rbB->AutoSize = true;
			this->rbB->Location = System::Drawing::Point(13, 37);
			this->rbB->Name = L"rbB";
			this->rbB->Size = System::Drawing::Size(32, 17);
			this->rbB->TabIndex = 1;
			this->rbB->TabStop = true;
			this->rbB->Text = L"B";
			this->rbB->UseVisualStyleBackColor = true;
			// 
			// rbX
			// 
			this->rbX->AutoSize = true;
			this->rbX->Location = System::Drawing::Point(13, 61);
			this->rbX->Name = L"rbX";
			this->rbX->Size = System::Drawing::Size(32, 17);
			this->rbX->TabIndex = 2;
			this->rbX->TabStop = true;
			this->rbX->Text = L"X";
			this->rbX->UseVisualStyleBackColor = true;
			// 
			// rbY
			// 
			this->rbY->AutoSize = true;
			this->rbY->Location = System::Drawing::Point(13, 85);
			this->rbY->Name = L"rbY";
			this->rbY->Size = System::Drawing::Size(32, 17);
			this->rbY->TabIndex = 3;
			this->rbY->TabStop = true;
			this->rbY->Text = L"Y";
			this->rbY->UseVisualStyleBackColor = true;
			// 
			// rbDPAD_UP
			// 
			this->rbDPAD_UP->AutoSize = true;
			this->rbDPAD_UP->Location = System::Drawing::Point(13, 109);
			this->rbDPAD_UP->Name = L"rbDPAD_UP";
			this->rbDPAD_UP->Size = System::Drawing::Size(76, 17);
			this->rbDPAD_UP->TabIndex = 4;
			this->rbDPAD_UP->TabStop = true;
			this->rbDPAD_UP->Text = L"DPAD_UP";
			this->rbDPAD_UP->UseVisualStyleBackColor = true;
			// 
			// rbDPAD_DOWN
			// 
			this->rbDPAD_DOWN->AutoSize = true;
			this->rbDPAD_DOWN->Location = System::Drawing::Point(13, 133);
			this->rbDPAD_DOWN->Name = L"rbDPAD_DOWN";
			this->rbDPAD_DOWN->Size = System::Drawing::Size(96, 17);
			this->rbDPAD_DOWN->TabIndex = 5;
			this->rbDPAD_DOWN->TabStop = true;
			this->rbDPAD_DOWN->Text = L"DPAD_DOWN";
			this->rbDPAD_DOWN->UseVisualStyleBackColor = true;
			// 
			// rbDPAD_LEFT
			// 
			this->rbDPAD_LEFT->AutoSize = true;
			this->rbDPAD_LEFT->Location = System::Drawing::Point(13, 157);
			this->rbDPAD_LEFT->Name = L"rbDPAD_LEFT";
			this->rbDPAD_LEFT->Size = System::Drawing::Size(87, 17);
			this->rbDPAD_LEFT->TabIndex = 6;
			this->rbDPAD_LEFT->TabStop = true;
			this->rbDPAD_LEFT->Text = L"DPAD_LEFT";
			this->rbDPAD_LEFT->UseVisualStyleBackColor = true;
			// 
			// rbDPAD_RIGHT
			// 
			this->rbDPAD_RIGHT->AutoSize = true;
			this->rbDPAD_RIGHT->Location = System::Drawing::Point(13, 181);
			this->rbDPAD_RIGHT->Name = L"rbDPAD_RIGHT";
			this->rbDPAD_RIGHT->Size = System::Drawing::Size(95, 17);
			this->rbDPAD_RIGHT->TabIndex = 7;
			this->rbDPAD_RIGHT->TabStop = true;
			this->rbDPAD_RIGHT->Text = L"DPAD_RIGHT";
			this->rbDPAD_RIGHT->UseVisualStyleBackColor = true;
			// 
			// rbLEFT_SHOULDER
			// 
			this->rbLEFT_SHOULDER->AutoSize = true;
			this->rbLEFT_SHOULDER->Location = System::Drawing::Point(13, 205);
			this->rbLEFT_SHOULDER->Name = L"rbLEFT_SHOULDER";
			this->rbLEFT_SHOULDER->Size = System::Drawing::Size(97, 17);
			this->rbLEFT_SHOULDER->TabIndex = 8;
			this->rbLEFT_SHOULDER->TabStop = true;
			this->rbLEFT_SHOULDER->Text = L"L_SHOULDER";
			this->rbLEFT_SHOULDER->UseVisualStyleBackColor = true;
			// 
			// rbRIGHT_SHOULDER
			// 
			this->rbRIGHT_SHOULDER->AutoSize = true;
			this->rbRIGHT_SHOULDER->Location = System::Drawing::Point(13, 229);
			this->rbRIGHT_SHOULDER->Name = L"rbRIGHT_SHOULDER";
			this->rbRIGHT_SHOULDER->Size = System::Drawing::Size(99, 17);
			this->rbRIGHT_SHOULDER->TabIndex = 9;
			this->rbRIGHT_SHOULDER->TabStop = true;
			this->rbRIGHT_SHOULDER->Text = L"R_SHOULDER";
			this->rbRIGHT_SHOULDER->UseVisualStyleBackColor = true;
			// 
			// rbLEFT_THUMB
			// 
			this->rbLEFT_THUMB->AutoSize = true;
			this->rbLEFT_THUMB->Location = System::Drawing::Point(13, 253);
			this->rbLEFT_THUMB->Name = L"rbLEFT_THUMB";
			this->rbLEFT_THUMB->Size = System::Drawing::Size(76, 17);
			this->rbLEFT_THUMB->TabIndex = 10;
			this->rbLEFT_THUMB->TabStop = true;
			this->rbLEFT_THUMB->Text = L"L_THUMB";
			this->rbLEFT_THUMB->UseVisualStyleBackColor = true;
			// 
			// rbRIGHT_THUMB
			// 
			this->rbRIGHT_THUMB->AutoSize = true;
			this->rbRIGHT_THUMB->Location = System::Drawing::Point(13, 277);
			this->rbRIGHT_THUMB->Name = L"rbRIGHT_THUMB";
			this->rbRIGHT_THUMB->Size = System::Drawing::Size(78, 17);
			this->rbRIGHT_THUMB->TabIndex = 11;
			this->rbRIGHT_THUMB->TabStop = true;
			this->rbRIGHT_THUMB->Text = L"R_THUMB";
			this->rbRIGHT_THUMB->UseVisualStyleBackColor = true;
			// 
			// rbSTART
			// 
			this->rbSTART->AutoSize = true;
			this->rbSTART->Location = System::Drawing::Point(13, 301);
			this->rbSTART->Name = L"rbSTART";
			this->rbSTART->Size = System::Drawing::Size(61, 17);
			this->rbSTART->TabIndex = 12;
			this->rbSTART->TabStop = true;
			this->rbSTART->Text = L"START";
			this->rbSTART->UseVisualStyleBackColor = true;
			// 
			// rbBACK
			// 
			this->rbBACK->AutoSize = true;
			this->rbBACK->Location = System::Drawing::Point(13, 325);
			this->rbBACK->Name = L"rbBACK";
			this->rbBACK->Size = System::Drawing::Size(53, 17);
			this->rbBACK->TabIndex = 13;
			this->rbBACK->TabStop = true;
			this->rbBACK->Text = L"BACK";
			this->rbBACK->UseVisualStyleBackColor = true;
			// 
			// pbLEFT_TRIGGER
			// 
			this->pbLEFT_TRIGGER->Location = System::Drawing::Point(246, 37);
			this->pbLEFT_TRIGGER->Name = L"pbLEFT_TRIGGER";
			this->pbLEFT_TRIGGER->Size = System::Drawing::Size(100, 23);
			this->pbLEFT_TRIGGER->Step = 1;
			this->pbLEFT_TRIGGER->TabIndex = 14;
			// 
			// pbRIGHT_TRIGGER
			// 
			this->pbRIGHT_TRIGGER->Location = System::Drawing::Point(246, 85);
			this->pbRIGHT_TRIGGER->Name = L"pbRIGHT_TRIGGER";
			this->pbRIGHT_TRIGGER->Size = System::Drawing::Size(100, 23);
			this->pbRIGHT_TRIGGER->Step = 1;
			this->pbRIGHT_TRIGGER->TabIndex = 15;
			// 
			// lLTRIGGER
			// 
			this->lLTRIGGER->AutoSize = true;
			this->lLTRIGGER->Location = System::Drawing::Point(264, 17);
			this->lLTRIGGER->Name = L"lLTRIGGER";
			this->lLTRIGGER->Size = System::Drawing::Size(68, 13);
			this->lLTRIGGER->TabIndex = 16;
			this->lLTRIGGER->Text = L"L_TRIGGER";
			// 
			// lRTRIGGER
			// 
			this->lRTRIGGER->AutoSize = true;
			this->lRTRIGGER->Location = System::Drawing::Point(264, 65);
			this->lRTRIGGER->Name = L"lRTRIGGER";
			this->lRTRIGGER->Size = System::Drawing::Size(70, 13);
			this->lRTRIGGER->TabIndex = 17;
			this->lRTRIGGER->Text = L"R_TRIGGER";
			// 
			// lLSTICK
			// 
			this->lLSTICK->AutoSize = true;
			this->lLSTICK->Location = System::Drawing::Point(246, 181);
			this->lLSTICK->Name = L"lLSTICK";
			this->lLSTICK->Size = System::Drawing::Size(47, 13);
			this->lLSTICK->TabIndex = 18;
			this->lLSTICK->Text = L"L STICK";
			// 
			// lRSTICK
			// 
			this->lRSTICK->AutoSize = true;
			this->lRSTICK->Location = System::Drawing::Point(249, 253);
			this->lRSTICK->Name = L"lRSTICK";
			this->lRSTICK->Size = System::Drawing::Size(49, 13);
			this->lRSTICK->TabIndex = 19;
			this->lRSTICK->Text = L"R STICK";
			// 
			// lLX
			// 
			this->lLX->AutoSize = true;
			this->lLX->Location = System::Drawing::Point(208, 205);
			this->lLX->Name = L"lLX";
			this->lLX->Size = System::Drawing::Size(14, 13);
			this->lLX->TabIndex = 20;
			this->lLX->Text = L"X";
			// 
			// lLY
			// 
			this->lLY->AutoSize = true;
			this->lLY->Location = System::Drawing::Point(208, 229);
			this->lLY->Name = L"lLY";
			this->lLY->Size = System::Drawing::Size(14, 13);
			this->lLY->TabIndex = 21;
			this->lLY->Text = L"Y";
			// 
			// lRX
			// 
			this->lRX->AutoSize = true;
			this->lRX->Location = System::Drawing::Point(208, 277);
			this->lRX->Name = L"lRX";
			this->lRX->Size = System::Drawing::Size(14, 13);
			this->lRX->TabIndex = 22;
			this->lRX->Text = L"X";
			// 
			// lRY
			// 
			this->lRY->AutoSize = true;
			this->lRY->Location = System::Drawing::Point(208, 301);
			this->lRY->Name = L"lRY";
			this->lRY->Size = System::Drawing::Size(14, 13);
			this->lRY->TabIndex = 23;
			this->lRY->Text = L"Y";
			// 
			// lLXOUTPUT
			// 
			this->lLXOUTPUT->AutoSize = true;
			this->lLXOUTPUT->Location = System::Drawing::Point(246, 205);
			this->lLXOUTPUT->Name = L"lLXOUTPUT";
			this->lLXOUTPUT->Size = System::Drawing::Size(13, 13);
			this->lLXOUTPUT->TabIndex = 24;
			this->lLXOUTPUT->Text = L"0";
			// 
			// lLYOUTPUT
			// 
			this->lLYOUTPUT->AutoSize = true;
			this->lLYOUTPUT->Location = System::Drawing::Point(246, 228);
			this->lLYOUTPUT->Name = L"lLYOUTPUT";
			this->lLYOUTPUT->Size = System::Drawing::Size(13, 13);
			this->lLYOUTPUT->TabIndex = 25;
			this->lLYOUTPUT->Text = L"0";
			// 
			// lRXOUTPUT
			// 
			this->lRXOUTPUT->AutoSize = true;
			this->lRXOUTPUT->Location = System::Drawing::Point(246, 277);
			this->lRXOUTPUT->Name = L"lRXOUTPUT";
			this->lRXOUTPUT->Size = System::Drawing::Size(13, 13);
			this->lRXOUTPUT->TabIndex = 26;
			this->lRXOUTPUT->Text = L"0";
			// 
			// lRYOUTPUT
			// 
			this->lRYOUTPUT->AutoSize = true;
			this->lRYOUTPUT->Location = System::Drawing::Point(246, 301);
			this->lRYOUTPUT->Name = L"lRYOUTPUT";
			this->lRYOUTPUT->Size = System::Drawing::Size(13, 13);
			this->lRYOUTPUT->TabIndex = 27;
			this->lRYOUTPUT->Text = L"0";
			// 
			// rtbOUTPUT_GENERAL
			// 
			this->rtbOUTPUT_GENERAL->Location = System::Drawing::Point(376, 12);
			this->rtbOUTPUT_GENERAL->Name = L"rtbOUTPUT_GENERAL";
			this->rtbOUTPUT_GENERAL->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->rtbOUTPUT_GENERAL->Size = System::Drawing::Size(196, 340);
			this->rtbOUTPUT_GENERAL->TabIndex = 28;
			this->rtbOUTPUT_GENERAL->Text = L"";
			this->rtbOUTPUT_GENERAL->WordWrap = false;
			// 
			// GamepadTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 365);
			this->Controls->Add(this->rtbOUTPUT_GENERAL);
			this->Controls->Add(this->lRYOUTPUT);
			this->Controls->Add(this->lRXOUTPUT);
			this->Controls->Add(this->lLYOUTPUT);
			this->Controls->Add(this->lLXOUTPUT);
			this->Controls->Add(this->lRY);
			this->Controls->Add(this->lRX);
			this->Controls->Add(this->lLY);
			this->Controls->Add(this->lLX);
			this->Controls->Add(this->lRSTICK);
			this->Controls->Add(this->lLSTICK);
			this->Controls->Add(this->lRTRIGGER);
			this->Controls->Add(this->lLTRIGGER);
			this->Controls->Add(this->pbRIGHT_TRIGGER);
			this->Controls->Add(this->pbLEFT_TRIGGER);
			this->Controls->Add(this->rbBACK);
			this->Controls->Add(this->rbSTART);
			this->Controls->Add(this->rbRIGHT_THUMB);
			this->Controls->Add(this->rbLEFT_THUMB);
			this->Controls->Add(this->rbRIGHT_SHOULDER);
			this->Controls->Add(this->rbLEFT_SHOULDER);
			this->Controls->Add(this->rbDPAD_RIGHT);
			this->Controls->Add(this->rbDPAD_LEFT);
			this->Controls->Add(this->rbDPAD_DOWN);
			this->Controls->Add(this->rbDPAD_UP);
			this->Controls->Add(this->rbY);
			this->Controls->Add(this->rbX);
			this->Controls->Add(this->rbB);
			this->Controls->Add(this->rbA);
			this->Name = L"GamepadTest";
			this->Text = L"GamepadTest";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bgwUpdateController_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
		while (true) {
			if (gp->Connected()) {
				gp->Update();
				worker->ReportProgress(1);
				gp->RefreshState();
			}
		}

	}
	private: System::Void bgwUpdateController_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
		//buttons
		rbA->Checked = gp->GetButtonPressed(0);
		rbB->Checked = gp->GetButtonPressed(1);
		rbX->Checked = gp->GetButtonPressed(2);
		rbY->Checked = gp->GetButtonPressed(3);

		rbDPAD_UP->Checked = gp->GetButtonPressed(4);
		rbDPAD_DOWN->Checked = gp->GetButtonPressed(5);
		rbDPAD_LEFT->Checked = gp->GetButtonPressed(6);
		rbDPAD_RIGHT->Checked = gp->GetButtonPressed(7);

		rbLEFT_SHOULDER->Checked = gp->GetButtonPressed(8);
		rbRIGHT_SHOULDER->Checked = gp->GetButtonPressed(9);

		rbLEFT_THUMB->Checked = gp->GetButtonPressed(10);
		rbRIGHT_THUMB->Checked = gp->GetButtonPressed(11);

		rbSTART->Checked = gp->GetButtonPressed(12);
		rbBACK->Checked = gp->GetButtonPressed(13);

		//triggers
		pbLEFT_TRIGGER->Value = (int)100 * gp->LeftTrigger();
		pbRIGHT_TRIGGER->Value = (int)100 * gp->RightTrigger();

		//sticks
		lLXOUTPUT->Text = gp->LeftStick_X().ToString();
		lLYOUTPUT->Text = gp->LeftStick_Y().ToString();

		lRXOUTPUT->Text = gp->RightStick_X().ToString();
		lRYOUTPUT->Text = gp->RightStick_Y().ToString();

		//button down
		if (gp->GetButtonDown(0)) outputText("A pressed");
		if (gp->GetButtonDown(1)) outputText("B pressed");
		if (gp->GetButtonDown(2)) outputText("X pressed");
		if (gp->GetButtonDown(3)) outputText("Y pressed");

		if (gp->GetButtonDown(4)) outputText("DPAD UP pressed");
		if (gp->GetButtonDown(5)) outputText("DPAD DOWN pressed");
		if (gp->GetButtonDown(6)) outputText("DPAD LEFT pressed");
		if (gp->GetButtonDown(7)) outputText("DPAD RIGHT pressed");

		if (gp->GetButtonDown(8)) outputText("L SHOULDER pressed");
		if (gp->GetButtonDown(9)) outputText("R SHOULDER pressed");

		if (gp->GetButtonDown(10)) outputText("L THUMB pressed");
		if (gp->GetButtonDown(11)) outputText("R THUMB pressed");

		if (gp->GetButtonDown(12)) outputText("START pressed");
		if (gp->GetButtonDown(13)) outputText("BACK pressed");
		this->Refresh();
		
	}

	private: System::Void outputText(System::String ^ str) {
		msclr::interop::marshal_context context;
		rtbOUTPUT_GENERAL->Text = rtbOUTPUT_GENERAL->Text + str + "\r\n";
	}

	};
}
