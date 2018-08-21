/*
	Library Apiwin vrs.1 16/08/2018
	- Create of MessageBox, using Winapi
	
	Author : Erick Steven Yenque Medina
*/
#include "apiwin.hpp"



int main(){
	
	//Creando objeto mensaje de la clase Apiwin - Lbreria apiwin.h
	//Create Object message of class Apiwin - Library apiwin.h
	WindowMessageBox message;
	
	//Mensaje con icono de Pregunta
	//Icon Question
	message.iconType('?'); //Param -> Char ? 
	message.createMessageBox("Question", "?");
	
	//Mensaje con icono de Error
	//Icon Error
	message.iconType('X'); //Param -> Char X
	message.createMessageBox("Error", "X");
	
	//Mensaje con icono de Información
	//Icon Information
	message.iconType('i');  //Param -> Char i 
	message.createMessageBox("Information!", "i");
	
	//Mensaje con icono de Exclamación
	//Icon Exclamation
	message.iconType('!');  //Param -> Char !
	message.createMessageBox("Exclamation!", "!");

	return 0;
}
