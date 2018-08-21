/*
	Library Apiwin vrs.1 16/08/2018
	- Create of MessageBox, using Winapi
	
	Author : Erick Steven Yenque Medina
*/

#ifndef APIWIN_H_INCLUDED
#define APIWIN_H_INCLUDED

#include <iostream>
#include <windows.h>
#define ID_BTN 100
#define ID_TEXTO 101

//Struct for WindowDate (Window Dinamic)

struct WindowParam{
		HINSTANCE hInst, hPrev;
		LPSTR lpCmdLine;
		int nCmdShow;		
};//it does not work dynamically

class WindowMessageBox{
	private:
		UINT uType;
		std::string lpText;
		std::string lpCaption;
		int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow);		
	public:
		void iconType(char _uType);
		void createMessageBox(std::string _lpText, std::string _lpCaption);
};

int	WindowMessageBox::WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox( NULL,(LPCSTR) lpText.c_str(), (LPCSTR) lpCaption.c_str(), uType);
	return 0;
}

void WindowMessageBox::iconType(char _uType){
	switch(_uType){
		case 'X':
		case 'x':
			uType = MB_ICONERROR;
			break;
		case '!':
			uType = MB_ICONEXCLAMATION;
			break;
		case 'i':
			uType = MB_ICONINFORMATION;
			break;
		case '?':
			uType = MB_ICONQUESTION;
			break;		
	}
	
}

void WindowMessageBox::createMessageBox(std::string _lpText, std::string _lpCaption){
	
	lpText = _lpText;
	lpCaption = _lpCaption;
	
	HINSTANCE hInst, hPrev;
	LPSTR lpCmdLine;
	int nCmdShow;
	WinMain(hInst, hPrev, lpCmdLine, nCmdShow);
}

std::string textTitle, textButton;
int lengthText = 20;
char dateText[100] = {0};
bool isNumber = false;

class WindowDate{
	private:
		std::string lpWindowName;
		int val;
		int nWidth;
		int nHeight;
		int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nFunsterStil);
	public:
		WindowDate();
		void createWindowDate(WindowParam);
		void setWindowDim(int _nWidth, int _nHeight);
		void setColor(char color);	
		
		//Ventanas Hijas - Windows Childs
		bool textIsNumber;
		std::string setTextTitle;
		std::string setTextButton;
		void setLengthText(int LengthText);
		std::string getTextDate();
};

void WindowDate::setColor(char color){
	if(color == 'b'){
		val = 1;
	}else{
		if (color == 'w'){
			val = 0;
		}
	}
}

void WindowDate::setLengthText(int LengthText){
	lengthText = LengthText;
}

std::string WindowDate::getTextDate(){
	return dateText;
}

void WindowDate::setWindowDim(int _nWidth, int _nHeight){
	nWidth = _nWidth;
	nHeight = _nHeight;
}

WindowDate::WindowDate(){
	val = 0;
	textIsNumber = false;
	setTextTitle = "Texto de Prueba";
	setTextButton = "Aceptar";
	nWidth = 240;
	nHeight = 150;
}

void WindowDate::createWindowDate(WindowParam winParam){
	isNumber = textIsNumber;
	textTitle = setTextTitle;
	textButton = setTextButton;
	
	WinMain(winParam.hInst, winParam.hPrev, winParam.lpCmdLine, winParam.nCmdShow);
}

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
int WindowDate::WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nFunsterStil)
{
	HWND hwnd;
	MSG mensaje; 
	WNDCLASSEX wincl; 

	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = "NUESTRA_CLASE";
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS; 
	wincl.cbSize = sizeof (WNDCLASSEX);

	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL; 
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0; 

	wincl.hbrBackground = (HBRUSH) COLOR_WINDOW+val;

	if(!RegisterClassEx(&wincl)) return 0;

	hwnd = CreateWindowEx( 0, "NUESTRA_CLASE", (LPCSTR) lpWindowName.c_str(), WS_OVERLAPPEDWINDOW, (GetSystemMetrics(SM_CXSCREEN ) / 2)-(nWidth / 2),(GetSystemMetrics(SM_CYSCREEN ) / 2)-(nHeight / 2), nWidth, nHeight, HWND_DESKTOP, NULL, hThisInstance, NULL);

	ShowWindow(hwnd, SW_SHOWDEFAULT);
	while(TRUE == GetMessage(&mensaje, NULL, 0, 0))
	{
		TranslateMessage(&mensaje);
		DispatchMessage(&mensaje);
	}

	return mensaje.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam){
	HWND Hwnd;
	switch (mensaje)
	{
		case WM_CREATE:			
			CreateWindow("STATIC", (LPCSTR)textTitle.c_str(), WS_CHILD | WS_VISIBLE | SS_CENTER, 10, 10, 200, 20, hwnd, NULL, NULL, NULL);
			if (isNumber) Hwnd = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE| ES_NUMBER, 10, 40, 200, 20, hwnd, (HMENU) ID_TEXTO, NULL, NULL);
			else Hwnd = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 40, 200, 20, hwnd, (HMENU) ID_TEXTO, NULL, NULL);
			SetFocus(Hwnd);
			CreateWindow("BUTTON", (LPCSTR)textButton.c_str(), WS_BORDER | WS_CHILD | WS_VISIBLE | BS_CENTER | WS_TABSTOP, 55, 70, 100, 20, hwnd, (HMENU) ID_BTN, NULL, NULL);
			break;
		case WM_COMMAND:
			if(LOWORD(wParam) == ID_BTN){
				GetDlgItemText(hwnd, ID_TEXTO, dateText, lengthText);
				PostQuitMessage (0); 
			}
			break;
		case WM_DESTROY:
			PostQuitMessage (0); 
			break;
		default: 
			return DefWindowProc (hwnd, mensaje, wParam, lParam);
	}
	return 0;
}

#endif //APIWIN_H_INCLUDED
