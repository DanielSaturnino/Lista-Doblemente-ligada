/**
Daniel Manzano Saturnino
*/
# include "Nodo.h"
Nodo::Nodo(int Dato)
{
	this->Dato=Dato;
	this->Ant=NULL;
	this->Sig=NULL;
}
Nodo::Nodo(int Dato,Nodo* Ant,Nodo* Sig)
{
	this->Dato=Dato;
	this->Ant=Ant;
	this->Sig=Sig;
}
void Nodo::setDato(int Dato)
{
	this->Dato=Dato;
}
void Nodo::setSig(Nodo* Sig)
{
	this->Sig=Sig;
}
void Nodo::setAnt(Nodo* Ant)
{
	this->Ant=Ant;
}
int Nodo::getDato()
{
	return this->Dato;
}
Nodo* Nodo::getSig()
{
	return this->Sig;
}
Nodo* Nodo::getAnt()
{
	return this->Ant;
}