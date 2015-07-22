#include <iostream>
#include "FPSDialouge.h"
#include "MainWindow.h"

//using namespace cv;
using namespace System;
using namespace System::Windows::Forms;

int main(cli::array<System::String ^> ^args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Learn::MainWindow form;
	Application::Run(%form);


	std::cout << "program over" << std::endl;

	return 0;
}
