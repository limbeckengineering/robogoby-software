#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>
#include <stdint.h>
#include <atomic>
//GUIs
#include "serverSettingsDialoge.h"
#include "FPSDialog.h"
//classes
#include "ClientSocket.h"
#include "GamePad.h"
#include "RenderEngine.h"

//global variables

const int MESSAGE_TO_SERVER_BIT_WIDTH = 17;
const int MESSAGE_FROM_SERVER_BIT_WIDTH = 10;

uint8_t generalRecvBuf[MESSAGE_FROM_SERVER_BIT_WIDTH];

//Buffer filled with data to send to server
//General Send Buffer :
//FPS			16 - bit u
//width 		16 - bit u
//height		16 - bit u
//LED PWM		8 - bit u
//Gain			8 - bit u
//Exposure		8 - bit u
//captureLOrR	8 - bit u
//--Sub Thrusters--
//M				8 - bit u
//HB			8 - bit u
//HF			8 - bit u
//VB			8 - bit u
//VF			8 - bit u
//cameraView	8 - bit u
//mainLedPwm	8 - bit u
uint8_t currentGeneralSendBuf[MESSAGE_TO_SERVER_BIT_WIDTH];

//Last buffer to be sent; used as a check to see if anything has changed
uint8_t lastGeneralSendBuf[MESSAGE_TO_SERVER_BIT_WIDTH];

//buffer for the left frame of the camera
std::vector<char> leftFrameBuf(76800);

//buffer for the right frame of the camera
std::vector<char> rightFrameBuf(76800);

//width/height for DUO camera on other side of server
uint16_t width = 320, height = 240;

//width x height
int frameSize;

//result of client read and write
int iResult;

//Indicates which camera to on the duo to capture from: 0 = left, 1 = right, 2 = both and overlay
uint8_t captureLOrR = 0;

//tells whether the server thread should refrain from resizing its current image because the main thread is using the rezised image to put an image in the UI
std::atomic<bool> frameBeingPut(false);

//gamepad
//is controller connected
std::atomic<bool> isConnected(false);

// A B X Y DU DD DL DR LS RS LB RB S B
std::atomic<bool> buttonsPressed[14];

// A B X Y DU DD DL DR LS RS LB RB S B
std::atomic<bool> buttonsDown[14];

//Lx Ly Rx Ry LT RT
std::atomic<float> stickAndTriggers[6];

//end gamepad

//Commands to sub
//M HB HF VB VF
std::atomic<uint8_t> thrusters[5];

//movement of view camera
std::atomic<uint8_t> cameraView = 0;

//PWM of forward LEDs
std::atomic<uint8_t> mainLedPwm = 0;

//end commands to sub

namespace RoboGobyOCU {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// This is the main window for the RoboGoby client 
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			//initialize GUI
			InitializeComponent();

			bgwGamepad->RunWorkerAsync();

			re = new RenderEngine((HWND)subRenderWindow->Handle.ToPointer());
			bgwRenderLoop->RunWorkerAsync();

			bgwCommandParsing->RunWorkerAsync();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}


	private: Imaging::ColorPalette ^ _palette;
	private: Bitmap^ bmpLeftNative;
	private: Bitmap^ bmpRightNative;
	private: Bitmap^ bmpLeftResize;
	private: Bitmap^ bmpRightResize;
	private: ClientSocket * client;
	private: RenderEngine * re;
	private: System::Windows::Forms::PictureBox^  pb1;
	private: System::ComponentModel::BackgroundWorker^  bgwClient;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fPSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  captureSideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  serverToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  startNewConnectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abortConnectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  leftToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rightToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bothToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  serverSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  bgwGamepad;
	private: System::Windows::Forms::RichTextBox^  outputConsol;
	private: System::Windows::Forms::PictureBox^  subRenderWindow;
	private: System::ComponentModel::BackgroundWorker^  bgwRenderLoop;
	private: System::ComponentModel::BackgroundWorker^  bgwCommandParsing;


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
			this->pb1 = (gcnew System::Windows::Forms::PictureBox());
			this->bgwClient = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fPSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->captureSideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->leftToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bothToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->serverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startNewConnectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abortConnectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->serverSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bgwGamepad = (gcnew System::ComponentModel::BackgroundWorker());
			this->outputConsol = (gcnew System::Windows::Forms::RichTextBox());
			this->subRenderWindow = (gcnew System::Windows::Forms::PictureBox());
			this->bgwRenderLoop = (gcnew System::ComponentModel::BackgroundWorker());
			this->bgwCommandParsing = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->subRenderWindow))->BeginInit();
			this->SuspendLayout();
			// 
			// pb1
			// 
			this->pb1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pb1->Location = System::Drawing::Point(12, 27);
			this->pb1->Name = L"pb1";
			this->pb1->Size = System::Drawing::Size(720, 540);
			this->pb1->TabIndex = 0;
			this->pb1->TabStop = false;
			// 
			// bgwClient
			// 
			this->bgwClient->WorkerReportsProgress = true;
			this->bgwClient->WorkerSupportsCancellation = true;
			this->bgwClient->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::bgwClient_DoWork);
			this->bgwClient->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainWindow::bgwClient_ProgressChanged);
			this->bgwClient->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainWindow::bgwClient_RunWorkerCompleted);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->optionsToolStripMenuItem,
					this->serverToolStripMenuItem, this->toolsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1146, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fPSToolStripMenuItem,
					this->captureSideToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// fPSToolStripMenuItem
			// 
			this->fPSToolStripMenuItem->Name = L"fPSToolStripMenuItem";
			this->fPSToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->fPSToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->fPSToolStripMenuItem->Text = L"FPS/Gain/Exposure/LED";
			this->fPSToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::fPSToolStripMenuItem_Click);
			// 
			// captureSideToolStripMenuItem
			// 
			this->captureSideToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->leftToolStripMenuItem,
					this->rightToolStripMenuItem, this->bothToolStripMenuItem
			});
			this->captureSideToolStripMenuItem->Name = L"captureSideToolStripMenuItem";
			this->captureSideToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->captureSideToolStripMenuItem->Text = L"Capture Side";
			// 
			// leftToolStripMenuItem
			// 
			this->leftToolStripMenuItem->Checked = true;
			this->leftToolStripMenuItem->CheckOnClick = true;
			this->leftToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->leftToolStripMenuItem->Name = L"leftToolStripMenuItem";
			this->leftToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->leftToolStripMenuItem->Text = L"Left";
			this->leftToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::leftToolStripMenuItem_Click);
			// 
			// rightToolStripMenuItem
			// 
			this->rightToolStripMenuItem->CheckOnClick = true;
			this->rightToolStripMenuItem->Name = L"rightToolStripMenuItem";
			this->rightToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->rightToolStripMenuItem->Text = L"Right";
			this->rightToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::rightToolStripMenuItem_Click);
			// 
			// bothToolStripMenuItem
			// 
			this->bothToolStripMenuItem->Enabled = false;
			this->bothToolStripMenuItem->Name = L"bothToolStripMenuItem";
			this->bothToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->bothToolStripMenuItem->Text = L"Both ";
			this->bothToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::bothToolStripMenuItem_Click);
			// 
			// serverToolStripMenuItem
			// 
			this->serverToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->startNewConnectionToolStripMenuItem,
					this->abortConnectionToolStripMenuItem, this->serverSettingsToolStripMenuItem
			});
			this->serverToolStripMenuItem->Name = L"serverToolStripMenuItem";
			this->serverToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->serverToolStripMenuItem->Text = L"Server";
			// 
			// startNewConnectionToolStripMenuItem
			// 
			this->startNewConnectionToolStripMenuItem->Name = L"startNewConnectionToolStripMenuItem";
			this->startNewConnectionToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->startNewConnectionToolStripMenuItem->Size = System::Drawing::Size(226, 22);
			this->startNewConnectionToolStripMenuItem->Text = L"Start new connection";
			this->startNewConnectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::startNewConnectionToolStripMenuItem_Click);
			// 
			// abortConnectionToolStripMenuItem
			// 
			this->abortConnectionToolStripMenuItem->Name = L"abortConnectionToolStripMenuItem";
			this->abortConnectionToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->abortConnectionToolStripMenuItem->Size = System::Drawing::Size(226, 22);
			this->abortConnectionToolStripMenuItem->Text = L"Abort connection";
			this->abortConnectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::abortConnectionToolStripMenuItem_Click);
			// 
			// serverSettingsToolStripMenuItem
			// 
			this->serverSettingsToolStripMenuItem->Name = L"serverSettingsToolStripMenuItem";
			this->serverSettingsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->serverSettingsToolStripMenuItem->Size = System::Drawing::Size(226, 22);
			this->serverSettingsToolStripMenuItem->Text = L"Server settings";
			this->serverSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::serverSettingsToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// bgwGamepad
			// 
			this->bgwGamepad->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::bgwGamepad_DoWork);
			// 
			// outputConsol
			// 
			this->outputConsol->Location = System::Drawing::Point(12, 574);
			this->outputConsol->Name = L"outputConsol";
			this->outputConsol->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->outputConsol->Size = System::Drawing::Size(720, 184);
			this->outputConsol->TabIndex = 9;
			this->outputConsol->Text = L"";
			// 
			// subRenderWindow
			// 
			this->subRenderWindow->Location = System::Drawing::Point(739, 28);
			this->subRenderWindow->Name = L"subRenderWindow";
			this->subRenderWindow->Size = System::Drawing::Size(400, 400);
			this->subRenderWindow->TabIndex = 10;
			this->subRenderWindow->TabStop = false;
			// 
			// bgwRenderLoop
			// 
			this->bgwRenderLoop->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::bgwRenderLoop_DoWork);
			// 
			// bgwCommandParsing
			// 
			this->bgwCommandParsing->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::bgwCommandParsing_DoWork);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1146, 761);
			this->Controls->Add(this->subRenderWindow);
			this->Controls->Add(this->outputConsol);
			this->Controls->Add(this->pb1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"RoboGoby Client Beta";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->subRenderWindow))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void bgwClient_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

		//Start communication loop
		do {

			//Read phase 
			//recieve left frame or...
			if (captureLOrR == 0) {

				iResult = client->readCli(&leftFrameBuf[0], frameSize, 0, true);

				if (iResult < 0) break;

				printf("Whole frame gathered\n");

				//calculation for stride
				int stride = width * 8;  // bits per row
				stride += 31;            // round up to next 32-bit boundary
				stride /= 32;            // DWORDs per row
				stride *= 4;             // bytes per row

				bmpLeftNative = gcnew Bitmap(width, height, stride,
					System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr(&leftFrameBuf[0]));

				//create grayscale color pallet for image
				_palette = bmpLeftNative->Palette;

				for (int i = 0; i < 256; i++)
				{
					Color ^ b = gcnew Color();
					_palette->Entries[i] = b->FromArgb(i, i, i);
				}

				bmpLeftNative->Palette = _palette;

				while (frameBeingPut.load(std::memory_order_relaxed) == true) {
					//waste cycles
					//check for data race over Resized bitmap
				}
				printf("going");

				//resize the image to be 720x540
				bmpLeftResize = gcnew Bitmap(bmpLeftNative, 720, 540);
				//TODO make image 640x480 (or whatever final resoulation) whatever the native res is

			}
			//receive right frame
			else if (captureLOrR == 1) {

				iResult = client->readCli(&rightFrameBuf[0], frameSize, 0, true);

				if (iResult < 0) break;

				//calculation for stride
				int stride = width * 8;  // bits per row
				stride += 31;            // round up to next 32-bit boundary
				stride /= 32;            // DWORDs per row
				stride *= 4;             // bytes per row

				printf("Whole frame gathered\n");
				bmpRightNative = gcnew Bitmap(width, height, stride,
					System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr(&rightFrameBuf[0]));

				//create grayscale color pallet for image
				_palette = bmpRightNative->Palette;

				for (int i = 0; i < 256; i++)
				{
					Color ^ b = gcnew Color();
					_palette->Entries[i] = b->FromArgb(i, i, i);
				}

				bmpRightNative->Palette = _palette;
				printf("checking\n");
				while (frameBeingPut.load(std::memory_order_relaxed) == true) {
					//waste cycles
					//check for data race over Resized bitmap
				}
				printf("going\n");

				//resize the image to be 720x540
				bmpRightResize = gcnew Bitmap(bmpRightNative, 720, 540);
			}

			worker->ReportProgress(1);

			iResult = client->readCli((char *)generalRecvBuf, MESSAGE_FROM_SERVER_BIT_WIDTH, 0, false);

			if (iResult < 0) break;

			//Write phase
			//check to see if we need to send another set of orders to the Server (see if they have changed since we last sent them)
			populateSendBuf();
			if (lastGeneralSendBuf != currentGeneralSendBuf) {
				iResult = client->writeCli((char *)currentGeneralSendBuf, MESSAGE_TO_SERVER_BIT_WIDTH, 0, true);
				currentToLastBuf();
				if (iResult < 0) break;
			}

			//check to see if we are cancelled
			if (worker->CancellationPending) {
				e->Cancel = true;
				return;
			}

		} while (true);

	}
	private: System::Void bgwClient_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		std::cout << "Async thread ended" << std::endl;
		delete client;
	}
	private: System::Void bgwClient_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
		printf("stop\n");
		frameBeingPut.store(true, std::memory_order_relaxed);
		if (captureLOrR == 0) {
			pb1->Image = dynamic_cast<Image^>(bmpLeftResize);

		}
		else if (captureLOrR == 1) {
			pb1->Image = dynamic_cast<Image^>(bmpRightResize);
		}
		frameBeingPut.store(false, std::memory_order_relaxed);
		printf("go\n");
		pb1->Refresh();

	}

	private: System::Void bgwGamepad_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		GamePad * gp = new GamePad(1);
		while (true) {
			gp->Update();
			
			while (gp->Connected()) {
				gp->Update();
				isConnected.store(gp->Connected(), std::memory_order_relaxed);

				for (int i = 0; i < 14; i++) {
					buttonsDown[i].store(gp->GetButtonDown(i), std::memory_order_relaxed);
				}

				for (int i = 0; i < 14; i++) {
					buttonsPressed[i].store(gp->GetButtonPressed(i), std::memory_order_relaxed);
				}

				stickAndTriggers[0].store(gp->LeftStick_X(), std::memory_order_relaxed);
				stickAndTriggers[1].store(gp->LeftStick_Y(), std::memory_order_relaxed);
				stickAndTriggers[2].store(gp->RightStick_X(), std::memory_order_relaxed);
				stickAndTriggers[3].store(gp->RightStick_Y(), std::memory_order_relaxed);
				stickAndTriggers[4].store(gp->LeftTrigger(), std::memory_order_relaxed);
				stickAndTriggers[5].store(gp->RightTrigger(), std::memory_order_relaxed);

				gp->RefreshState();
			}

			gp->RefreshState();
		}
	}

	private: System::Void bgwRenderLoop_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		while (true) { re->RenderFrame(0, 0); }
	}

	private: System::Void bgwCommandParsing_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		//5 thruster values
		//1 camera tilt value
		//1 light pwm

		//use x^3 as a scalling function
		//scale raw float value of [-1, 1] through function first
		//multiply by 100 and truncate, leaving a value [-100, 100]
		//add 100 to get a value [0, 200]


		//TODO Zero all commands so nothing caries over from the last loop 

		while (true) {
			//if we are trying to pitch
			if (stickAndTriggers[3].load() != 0.0f) {
				thrusters[4].store((uint8_t)((100 * pow(stickAndTriggers[3].load(), 3)) + 100));
				thrusters[3].store((uint8_t)((-100 * pow(stickAndTriggers[3].load(), 3)) + 100));
			}
			//if we are trying to ascend or descend with the triggers
			else {
				int cumTriggerValue = (uint8_t)((pow(stickAndTriggers[4].load(), 3) * -100) + (pow(stickAndTriggers[5].load(), 3) * 100));

				thrusters[4].store(cumTriggerValue);
				thrusters[3].store(cumTriggerValue);
			}
			//if we are trying to yaw
			if (stickAndTriggers[2].load() != 0) {
				thrusters[2].store((uint8_t)((100 * pow(stickAndTriggers[2].load(), 3)) + 100));
				thrusters[1].store((uint8_t)((-100 * pow(stickAndTriggers[2].load(), 3)) + 100));
			}
			//if we are trying to strafe
			else {
				int thrust = (uint8_t)(100 * pow(stickAndTriggers[2].load(), 3)) + 100;

				thrusters[2].store(thrust);
				thrusters[1].store(thrust);
			}

			//back thruster gets set here; easy because it ony gets used in one manuver
			thrusters[0].store((uint8_t)((100 * pow(stickAndTriggers[1].load(), 3)) + 100));

			//update main lights
			uint8_t pwm = mainLedPwm.load();

			if (buttonsDown[11].load() == true) {
				pwm += 10;
			}
			if (buttonsDown[10].load() == true) {
				pwm -= 10;
			}

			if (pwm < 0) {
				pwm = 0;
			}
			else if (pwm > 90) {
				pwm = 90;
			}

			mainLedPwm.store(pwm);

			//camera servo

			if (buttonsDown[7].load() == true) {
				cameraView.store(110);
			}
			else if (buttonsDown[6] == true) {
				cameraView.store(90);
			}
			else {
				cameraView.store(100);
			}
		}
	}

	private: System::Void startNewConnectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//create client
		client = new ClientSocket("2000", IP, "Client");

		//connect the servers
		client->connectToServer();

		//set the length of the buffers for each frame we are going to read in
		frameSize = width*height;

		//Initial send phase for initial settings
		populateSendBuf();
		currentToLastBuf();

		iResult = client->writeCli((char *)currentGeneralSendBuf, 10, 0, false);

		printf("Width: %u   Height: %u   FPS: %u\n", width, height, fps);

		bgwClient->RunWorkerAsync();

	}

	private: System::Void abortConnectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		bgwClient->CancelAsync();
	}

	private: System::Void fPSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		RoboGobyOCU::FPSDialog ^ fpsDialog = gcnew RoboGobyOCU::FPSDialog();
		fpsDialog->ShowDialog(this);
	}

	private: System::Void leftToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		captureLOrR = 0;

		this->rightToolStripMenuItem->Checked = false;
		this->bothToolStripMenuItem->Checked = false;
	}

	private: System::Void rightToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		captureLOrR = 1;

		this->leftToolStripMenuItem->Checked = false;
		this->bothToolStripMenuItem->Checked = false;
	}

	private: System::Void bothToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		captureLOrR = 2;

		this->leftToolStripMenuItem->Checked = false;
		this->rightToolStripMenuItem->Checked = false;
	}

	private: System::Void serverSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		RoboGobyOCU::serverSettingsDialoge ^ serDialog = gcnew RoboGobyOCU::serverSettingsDialoge();
		serDialog->ShowDialog(this);
	}

			 //populate the currentGeneralSendBuf with current settings 
	private: System::Void populateSendBuf() {
		currentGeneralSendBuf[0] = fps & 0xFF;
		currentGeneralSendBuf[1] = fps >> 8;
		currentGeneralSendBuf[2] = width & 0xFF;
		currentGeneralSendBuf[3] = width >> 8;
		currentGeneralSendBuf[4] = height & 0xFF;
		currentGeneralSendBuf[5] = height >> 8;
		currentGeneralSendBuf[6] = LED;
		currentGeneralSendBuf[7] = gain;
		currentGeneralSendBuf[8] = exposure;
		currentGeneralSendBuf[9] = captureLOrR;
		currentGeneralSendBuf[10] = thrusters[0].load();
		currentGeneralSendBuf[11] = thrusters[1].load();
		currentGeneralSendBuf[12] = thrusters[2].load();
		currentGeneralSendBuf[13] = thrusters[3].load();
		currentGeneralSendBuf[14] = thrusters[4].load();
		currentGeneralSendBuf[15] = cameraView.load();
		currentGeneralSendBuf[16] = mainLedPwm.load();
	}

			 //sets the lastGeneralSendBuf to the currentGeneralSendBuf
	private: System::Void currentToLastBuf() {
		memcpy(lastGeneralSendBuf, currentGeneralSendBuf, MESSAGE_TO_SERVER_BIT_WIDTH);
	}


	};

}
