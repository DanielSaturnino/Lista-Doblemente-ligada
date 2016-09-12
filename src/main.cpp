/**
Daniel Manzano Saturnino 
*/
# include "ListaD.h"
int main()
{
	ListaD D=ListaD();
	D.AddInicio(2);
	D.AddInicio(3);
	D.AddFinal(9);
	D.AddRef(5,2);
	D.AddFinal(45);
	D.Show();
	std::cout<<"Termina insertado"<<std::endl;
	D.RemoveInicio();
	D.RemoveFinal();
	D.RemoveRef(5);
	D.Show();
	std::cout<<"Termina eliminacion"<<std::endl;
	D.VaciarLista();
	return 0;
}