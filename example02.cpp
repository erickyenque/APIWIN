/*
	Library Apiwin vrs.1 20/08/2018
	- Create of MessageBox, using Winapi
	
	Author : Erick Steven Yenque Medina
*/

#include "apiwin.hpp" // Librería 

int main(){
	
	WindowParam vParam;//Para enviar como parámetros al WindowDate, (No funciona dinamicamente)
	
	WindowDate ventana;
	
	ventana.setTextTitle = "Ingrese dato: ";
	ventana.setTextButton = "Validar";
	ventana.setColor('b'); //Puede ser: ventana.setColor('w') -> color blanco esta por defecto;
	ventana.textIsNumber = true; // Poder determinar si es cadena o numero(solo funcionan enteros)
	//ventana.setWindowDim(); -> Poder establecer el tamaño de la ventana
	ventana.createWindowDate(vParam);
	
	std::string valor = ventana.getTextDate(); //Obtener valor del dato ingresado
	
	std::cout << valor;

	return 0;
}
