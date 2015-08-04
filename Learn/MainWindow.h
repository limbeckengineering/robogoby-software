#pragma once

#define WIN32_LEAN_AND_MEAN

#include <stdint.h>
#include <atomic>
#include "serverSettingsDialoge.h"
#include "FPSDialog.h"
#include "ClientSocket.h"

//global variables

uint8_t generalRecvBuf[10];

//Buffer filled with data to send to server
//General Send Buffer :
//FPS		16 - bit u
//width 		16 - bit u
//height		16 - bit u
//LED PWM		8 - bit u
//Gain		8 - bit u
//Exposure	8 - bit u
//captureLOrR	8 - bit u
uint8_t currentGeneralSendBuf[10];

//Last buffer to be sent; used as a check to see if anything has changed
uint8_t lastGeneralSendBuf[10];

//buffer for the left frame of the camera
std::vector<uint8_t> leftFrameBuf(307200);

//buffer for the right frame of the camera
std::vector<uint8_t> rightFrameBuf(307200);

//width/height for DUO camera on other side of server
uint16_t width = 320, height = 240;

//width x height
int frameSize;

//result of client read and write
int iResult;

//Indicates which camera to on the duo to capture from: 0 = left, 1 = right, 2 = both and overlay
uint8_t captureLOrR = 0;

namespace Learn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TestForm
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			//initialize GUI
			InitializeComponent();

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->BeginInit();
			this->menuStrip1->SuspendLayout();
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->optionsToolStripMenuItem,
					this->serverToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1184, 24);
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
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 761);
			this->Controls->Add(this->pb1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"RoboGoby Client Beta";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void bgwClient_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
		
		//Start communication loop
		do {

			//Read phase 

			int bytesLeft = frameSize;
			int currentFramePointer = 0;

			//recieve left frame or...
			if (captureLOrR == 0) {
				while (bytesLeft > 0) {
					iResult = client->readCli((char *)&leftFrameBuf[currentFramePointer], bytesLeft, 0);
					if (iResult == 0) {
						printf("Connection closed\n");
						//ZeroMemory(&leftFrameBuf[0], sizeof(leftFrameBuf));
						break;
					}
					else if(iResult < 0){
						printf("recv failed with error: %d\n", WSAGetLastError());
						break;
					}

					currentFramePointer += iResult;
					bytesLeft -= iResult;

				}

				if (iResult < 0) break;

				printf("Whole frame gathered\n");

				//calculation for stride
				int stride = width*8;  // bits per row
				stride += 31;            // round up to next 32-bit boundary
				stride /= 32;            // DWORDs per row
				stride *= 4;             // bytes per row

				bmpLeftNative = gcnew Bitmap(width, height, stride,
					System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr((char *)&leftFrameBuf[0]));

				//create grayscale color pallet for image
				_palette = bmpLeftNative->Palette;

				for (int i = 0; i < 256; i++)
				{
					Color ^ b = gcnew Color();
					_palette->Entries[i] = b->FromArgb(i, i, i);
				}

				bmpLeftNative->Palette = _palette;

				//resize the image to be 720x540
				bmpLeftResize = gcnew Bitmap(bmpLeftNative, 720, 540);
				//TODO make image 640x480 (or whatever final resoulation) whatever the native res is

			}
			//receive right frame
			else if (captureLOrR == 1) {

				while (bytesLeft > 0) {
					iResult = client->readCli((char *)&rightFrameBuf[currentFramePointer], bytesLeft, 0);
					if (iResult == 0) {
						printf("Connection closed\n");
						//ZeroMemory(&rightFrameBuf[0], sizeof(rightFrameBuf));
						break;
					}
					else if(iResult < 0){
						printf("recv failed with error: %d\n", WSAGetLastError());
					}

					currentFramePointer += iResult;
					bytesLeft -= iResult;
				}

				if (iResult < 0) break;

				//calculation for stride
				int stride = width * 8;  // bits per row
				stride += 31;            // round up to next 32-bit boundary
				stride /= 32;            // DWORDs per row
				stride *= 4;             // bytes per row

				printf("Whole frame gathered\n");
				bmpRightNative = gcnew Bitmap(width, height, stride,
					System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr((char *)&rightFrameBuf[0]));

				//create grayscale color pallet for image
				_palette = bmpRightNative->Palette;

				for (int i = 0; i < 256; i++)
				{
					Color ^ b = gcnew Color();
					_palette->Entries[i] = b->FromArgb(i, i, i);
				}

				bmpRightNative->Palette = _palette;

				//resize the image to be 720x540
				bmpRightResize = gcnew Bitmap(bmpRightNative, 720, 540);
				//TODO make image 640x480 (or whatever final resoulation) whatever the native res is
			}

			worker->ReportProgress(1);

			bytesLeft = 10;
			currentFramePointer = 0;

			//Recv sensor data and such 
			while (bytesLeft > 0) {
				iResult = client->readCli((char *)&generalRecvBuf[currentFramePointer], bytesLeft, 0);
				if (iResult == 0) {
					printf("Connection closed\n");
					break;
				}
				else if (iResult < 0){
					printf("recv failed with error: %d\n", WSAGetLastError());
					break;
				}

				currentFramePointer += iResult;
				bytesLeft -= iResult;
			}

			if (iResult < 0) break;

			/*	//start recieving frames
				int bytesLeft = frameBufLength;
				int currentFramePointer = 0;

				//recieve left frame or...
				if (captureLOrR == 0) {
					while (bytesLeft > 0) {
						iResultMessage = recv(MessageSocket, (char *)&leftFrameBuf[currentFramePointer], bytesLeft, 0);
						if (iResultMessage > 0) {
							printf("Bytes received left frame: %d\n", iResultMessage);

						}
						else if (iResultMessage == 0) {
							printf("Connection closed\n");
							int bytesLeft = frameBufLength;
							int currentFramePointer = 0;
							break;
						}
						else {
							printf("recv failed with error: %d\n", WSAGetLastError());
						}

						currentFramePointer += iResultMessage;
						bytesLeft -= iResultMessage;

					}

					left->imageData = (char *)&leftFrameBuf[0];
					printf("Whole frame gathered\n");
					bmpLeftNative = gcnew Bitmap(width, height, left->widthStep,
						System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr(left->imageData));

					//create grayscale color pallet for image
					_palette = bmpLeftNative->Palette;

					for (int i = 0; i < 256; i++)
					{
						Color ^ b = gcnew Color();
						_palette->Entries[i] = b->FromArgb(i, i, i);
					}

					bmpLeftNative->Palette = _palette;

					//resize the image to be 720x540
					bmpLeftResize = gcnew Bitmap(bmpLeftNative, 720, 540);
					//TODO make image 640x480 (or whatever final resoulation) whatever the native res is

				}
				//receive right frame
				else if (captureLOrR == 1) {

					while (bytesLeft > 0) {
						iResultMessage = recv(MessageSocket, (char *)&rightFrameBuf[currentFramePointer], bytesLeft, 0);
						if (iResultMessage > 0) {
							printf("Bytes received left frame: %d\n", iResultMessage);

						}
						else if (iResultMessage == 0) {
							printf("Connection closed\n");
							int bytesLeft = frameBufLength;
							int currentFramePointer = 0;
							break;
						}
						else {
							printf("recv failed with error: %d\n", WSAGetLastError());
						}

						currentFramePointer += iResultMessage;
						bytesLeft -= iResultMessage;
					}

					right->imageData = (char *)&rightFrameBuf[0];
					printf("Whole frame gathered\n");
					bmpRightNative = gcnew Bitmap(width, height, right->widthStep,
						System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr(right->imageData));

					//create grayscale color pallet for image
					_palette = bmpRightNative->Palette;

					for (int i = 0; i < 256; i++)
					{
						Color ^ b = gcnew Color();
						_palette->Entries[i] = b->FromArgb(i, i, i);
					}

					bmpRightNative->Palette = _palette;

					//resize the image to be 720x540
					bmpRightResize = gcnew Bitmap(bmpRightNative, 720, 540);
					//TODO make image 640x480 (or whatever final resoulation) whatever the native res is
				}
				//put frames in Main Form
				worker->ReportProgress(1);*/

			//Write phase
			//check to see if we need to send another set of orders to the Server (see if they have changed since we last sent them)
			populateSendBuf();
			if (lastGeneralSendBuf != currentGeneralSendBuf) {
				iResult = client->writeCli((char *)&currentGeneralSendBuf, 10, 0);
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
		if (captureLOrR == 0) {
			pb1->Image = dynamic_cast<Image^>(bmpLeftResize);

		}
		else if (captureLOrR == 1) {
			pb1->Image = dynamic_cast<Image^>(bmpRightResize);
		}
		pb1->Refresh();
	}

	private: System::Void startNewConnectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//create client
		client = new ClientSocket("2000", IP, "Client");
		
		//connect the servers
		client->connectToServer();

		//set the length of the buffers for each frame we are going to read in
		frameSize = width*height;

		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
		//Initial send phase for initial settings

		populateSendBuf();
		currentToLastBuf();

		iResult = client->writeCli((char *)&currentGeneralSendBuf, 10, 0);
		printf("Width: %u   Height: %u   FPS: %u\n", width, height, fps);

		bgwClient->RunWorkerAsync();

	}

	private: System::Void abortConnectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		bgwClient->CancelAsync();
	}

	private: System::Void fPSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Learn::FPSDialog ^ fpsDialog = gcnew Learn::FPSDialog();
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
		Learn::serverSettingsDialoge ^ serDialog = gcnew Learn::serverSettingsDialoge();
		serDialog->ShowDialog(this);
	}

			 //populate the currentGeneralSendBuf with current settings 
	private: System::Void populateSendBuf() {
		//TODO redo this with bit math and shifts 
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
	}

			 //sets the lastGeneralSendBuf to the currentGeneralSendBuf
	private: System::Void currentToLastBuf() {
		memcpy(lastGeneralSendBuf, currentGeneralSendBuf, 10);
	}


	};
}
