/*
	Library Apiwin vrs.1 16/08/2018
	- Create of MessageBox, using Winapi
	
	Author : Erick Steven Yenque Medina
*/
#include "apiwin.h"

int main(){
	
	//Create Object message of class Apiwin - Library apiwin.h
	Apiwin message;
	
	//Icon Question
	message.iconType('?');
	message.createMessageBox("Question", "");
	
	//Icon Error
	message.iconType('X');
	message.createMessageBox("Error", "X");
	
	//Icon Information
	message.iconType('i');
	message.createMessageBox("Information!", "i");
	
	//Icon Exclamation
	message.iconType('!');
	message.createMessageBox("Exclamation!", "!");

	return 0;
}
