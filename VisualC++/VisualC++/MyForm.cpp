#include "MyForm.h"

#include <Windows.h>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "..\..\tStack\TCalc.h"
#include "..\..\tStack\TCalc.h"
using namespace VisualC;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;
}