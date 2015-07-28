#include <iostream>
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;


//		TODO
// Done
//	X	Clean up initial transfer of data to server (have it be one array)
//	X	Make dynamic updates to camera features usable on client side
//		Fix dynamic changing of FPS and resolution
//		Fix CLient-side abort on server side
//		Implement check in case Server starts failing to send data (send something to the server that indicates that it should flush the connection)
//	X	Get a workable stream of data from the camera (you need the correct picture format for this one)
//		See if you can do it without OpenCV

//		Xbox controller 

//		IMU and IMU adjusted driving (make IMU adjusted driving optional?)

int main(cli::array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Learn::MainWindow form;
	Application::Run(%form);

	return 0;
}
