#pragma once

#define WIN32_LEAN_AND_MEAN

#include <opencv2\opencv.hpp>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "serverSettingsDialoge.h"
#include "FPSDialog.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

//default port for the server
#define DEFAULT_PORT "2000"

//global variables


//start - server

WSADATA wsaData;
SOCKET ConnectSocket = INVALID_SOCKET;
struct addrinfo *result = NULL,
	*ptr = NULL,
	hints;

//result of read an write
int iResult;

//end - server

char generalRecvBuf[256];

//Buffer filled with data to send to server
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
int frameBufLength;

//Indicates which camera to on the duo to capture from: 0 = left, 1 = right, 2 = both and overlay
uint8_t captureLOrR = 0;

//opencv image for initial storage of the left frame
IplImage *left;

//opencv image for initial storage of the right frame
IplImage *right;

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
	private: System::Windows::Forms::PictureBox^  pb1;
	private: System::ComponentModel::BackgroundWorker^  bgw1;
	protected:

	protected:

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resolutionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fPSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  x240ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  x480ToolStripMenuItem;
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
			this->bgw1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resolutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->x240ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->x480ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->pb1->Location = System::Drawing::Point(80, 27);
			this->pb1->Name = L"pb1";
			this->pb1->Size = System::Drawing::Size(640, 480);
			this->pb1->TabIndex = 0;
			this->pb1->TabStop = false;
			// 
			// bgw1
			// 
			this->bgw1->WorkerReportsProgress = true;
			this->bgw1->WorkerSupportsCancellation = true;
			this->bgw1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::backgroundWorker1_DoWork);
			this->bgw1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainWindow::bgw1_ProgressChanged);
			this->bgw1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainWindow::bgw1_RunWorkerCompleted);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->optionsToolStripMenuItem,
					this->serverToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(801, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->resolutionToolStripMenuItem,
					this->fPSToolStripMenuItem, this->captureSideToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// resolutionToolStripMenuItem
			// 
			this->resolutionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->x240ToolStripMenuItem,
					this->x480ToolStripMenuItem
			});
			this->resolutionToolStripMenuItem->Name = L"resolutionToolStripMenuItem";
			this->resolutionToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->resolutionToolStripMenuItem->Text = L"Resolution";
			// 
			// x240ToolStripMenuItem
			// 
			this->x240ToolStripMenuItem->Checked = true;
			this->x240ToolStripMenuItem->CheckOnClick = true;
			this->x240ToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->x240ToolStripMenuItem->Name = L"x240ToolStripMenuItem";
			this->x240ToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->x240ToolStripMenuItem->Text = L"320x240";
			this->x240ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::x240ToolStripMenuItem_Click);
			// 
			// x480ToolStripMenuItem
			// 
			this->x480ToolStripMenuItem->CheckOnClick = true;
			this->x480ToolStripMenuItem->Name = L"x480ToolStripMenuItem";
			this->x480ToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->x480ToolStripMenuItem->Text = L"640x480";
			this->x480ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::x480ToolStripMenuItem_Click);
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
			this->ClientSize = System::Drawing::Size(801, 561);
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
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

		//server start

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed with error: %d\n", iResult);
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		printf("address of server %s\n", IP);

		// Resolve the server address and port
		iResult = getaddrinfo(IP.c_str(), DEFAULT_PORT, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed with error: %d\n", iResult);
		}

		// Attempt to connect to an address until one succeeds
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

			// Create a SOCKET for connecting to server
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ConnectSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
			}

			// Connect to server.
			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);

		if (ConnectSocket == INVALID_SOCKET) {
			printf("Unable to connect to server!\n");
		}

		//server initialized 

		printf("Width: %u   Height: %u   FPS: %u\n", width, height, fps);

		// Send three initial buffer containing the width, height and fps of the DUO camera

		populateSendBuf();
		currentToLastBuf();

		iResult = send(ConnectSocket, (char *)&currentGeneralSendBuf, 10, 0);

		/*iResult = send(ConnectSocket, (char *)&width, sizeof(uint16_t), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
		}

		iResult = send(ConnectSocket, (char *)&height, sizeof(uint16_t), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
		}

		iResult = send(ConnectSocket, (char *)&fps, sizeof(uint16_t), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
		}*/

		printf("Frame length is %u\n", frameBufLength);

		// Receive DUO frames until the peer closes the connection
		do {

			//start recieving frames 
			int bytesLeft = frameBufLength;
			int currentFramePointer = 0;

			//recieve left frame or...
			if (captureLOrR == 0) {
				while (bytesLeft > 0) {
					iResult = recv(ConnectSocket, (char *)&leftFrameBuf[currentFramePointer], bytesLeft, 0);
					if (iResult > 0) {
						printf("Bytes received left frame: %d\n", iResult);

					}
					else if (iResult == 0) {
						printf("Connection closed\n");
					}
					else {
						printf("recv failed with error: %d\n", WSAGetLastError());
					}

					currentFramePointer += iResult;
					bytesLeft -= iResult;

				}

				left->imageData = (char *)&leftFrameBuf[0];
				printf("Whole frame gathered\n");
			}
			//receive right frame
			else if (captureLOrR == 1) {
				
				while (bytesLeft > 0) {
					iResult = recv(ConnectSocket, (char *)&rightFrameBuf[currentFramePointer], bytesLeft, 0);
					if (iResult > 0) {
						printf("Bytes received left frame: %d\n", iResult);

					}
					else if (iResult == 0) {
						printf("Connection closed\n");
					}
					else {
						printf("recv failed with error: %d\n", WSAGetLastError());
					}

					currentFramePointer += iResult;
					bytesLeft -= iResult;
				}

				right->imageData = (char *)&rightFrameBuf[0];
				printf("Whole frame gathered\n");
			}
			//put frames in Main Form
			worker->ReportProgress(1);

			//check to see if we need to send another set of orders to the Server (see if they have changed since we last sent them)
			populateSendBuf();
			if (lastGeneralSendBuf != currentGeneralSendBuf) {
				iResult = send(ConnectSocket, (char *)&currentGeneralSendBuf, 10, 0);
				currentToLastBuf();
			}

		} while (!worker->CancellationPending);

	}

	private: System::Void bgw1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		std::cout << "Async thread ended" << std::endl;

		// cleanup server
		closesocket(ConnectSocket);
		WSACleanup();
	}

	private: System::Void bgw1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {

		Bitmap^ bmpleft = gcnew Bitmap(width, height, left->widthStep,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr(left->imageData));

		Bitmap^ bmpright = gcnew Bitmap(width, height, right->widthStep,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed, IntPtr(right->imageData));

		pb1->ClientSize = System::Drawing::Size(width, height);
		/*if (this->lframeradio->Checked == true) {
			pb1->Image = dynamic_cast<Image^>(bmpleft);
		}
		else if (this->rframeradio->Checked == true) {
			pb1->Image = dynamic_cast<Image^>(bmpright);
		}*/
		pb1->Refresh();

	}

	private: System::Void startNewConnectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		//set the length of the buffers for each frame we are going to read in
		frameBufLength = width*height;

		// Create image headers for left & right frames
		left = cvCreateImageHeader(cvSize(width, height), IPL_DEPTH_8U, 1);
		right = cvCreateImageHeader(cvSize(width, height), IPL_DEPTH_8U, 1);

		bgw1->RunWorkerAsync();

	}

	private: System::Void abortConnectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		bgw1->CancelAsync();
	}

	private: System::Void x240ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		width = 320;
		height = 240;

		this->x480ToolStripMenuItem->Checked = false;
	}

	private: System::Void x480ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		width = 640;
		height = 480;

		this->x240ToolStripMenuItem->Checked = false;
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
		currentGeneralSendBuf[0] = *(&fps);
		currentGeneralSendBuf[1] = *((&fps) + 1);
		currentGeneralSendBuf[2] = *(&width);
		currentGeneralSendBuf[3] = *((&width) + 1); 
		currentGeneralSendBuf[4] = *(&height);
		currentGeneralSendBuf[5] = *((&height) + 1);
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
