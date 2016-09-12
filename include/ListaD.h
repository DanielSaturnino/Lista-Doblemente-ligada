/**
Daniel Manzano Saturnino
Descripicion:
Este Metodo Crea una lista doblemente 
ligada con los metos de agregracion y de 
eliminacion busqueda y mostrar
Atributos:
Nodos T y H 
*/
#include "Nodo.h"

class ListaD
{
public:
	Nodo* H;
	Nodo* T;	
	ListaD();
	ListaD(int Dato);
	bool ListaVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	void AddRef(int Dato, int Ref);
	int RemoveInicio();
	int RemoveFinal();
	int RemoveRef(int Ref);
	int VaciarLista();
	Nodo* BuscarElemento(int Dato);
	void Show();
};