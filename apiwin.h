/*
	Library Apiwin vrs.1 16/08/2018
	- Create of MessageBox, using Winapi
	
	Author : Erick Steven Yenque Medina
*/

#ifndef APIWIN_H_INCLUDED
#define APIWIN_H_INCLUDED

#include <iostream>
#include <windows.h>
using namespace std;


class Apiwin{
	private:
		UINT uType;
		string lpText;
		string lpCaption;
		int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow);		
	public:
		void iconType(char _uType);
		void createMessageBox(string _lpText, string _lpCaption);
};

int	Apiwin::WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox( NULL,(LPCSTR) lpText.c_str(), (LPCSTR) lpCaption.c_str(), uType);
	return 0;
}

void Apiwin::iconType(char _uType){
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

void Apiwin::createMessageBox(string _lpText, string _lpCaption){
	
	lpText = _lpText;
	lpCaption = _lpCaption;
	
	HINSTANCE hInst, hPrev;
	LPSTR lpCmdLine;
	int nCmdShow;
	WinMain(hInst, hPrev, lpCmdLine, nCmdShow);
}



#endif //APIWIN_H_INCLUDED
