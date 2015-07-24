#include <iostream>
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

int main(cli::array<System::String ^> ^args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Learn::MainWindow form;
	Application::Run(%form);

	return 0;
}
