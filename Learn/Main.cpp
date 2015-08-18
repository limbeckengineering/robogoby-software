#include <iostream>
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

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

//		TODO
// Done
//	X	Clean up initial transfer of data to server (have it be one array)
//	X	Make dynamic updates to camera features usable on client side
//	X	Fix dynamic changing of FPS (done) and resolution (may try later)
//		Fix CLient-side abort on server side (partialy done: only works sometimes and if quit is done at certian points in server side)
//		Implement check in case Server starts failing to send data (send something to the server that indicates that it should flush the connection)
//	X	Get a workable stream of data from the camera (you need the correct picture format for this one)
//	X	See if you can do it without OpenCV (Success! no opencv requiered)

//		Xbox controller 

//		IMU and IMU adjusted driving (make IMU adjusted driving optional?)

int main(cli::array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RoboGobyOCU::MainWindow form;
	Application::Run(%form);

	return 0;
}
