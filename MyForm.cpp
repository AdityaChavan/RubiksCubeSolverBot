#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array < System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SerialComm1::MyForm form;
	Application::Run(%form);

}