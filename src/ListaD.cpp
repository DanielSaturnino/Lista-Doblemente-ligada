/**
Daniel Manzano Saturnino 
*/
#include "ListaD.h"
/**
Constructor
@Parametros:void
@Result: void
Crea una lista con los nodos T y H  apuntando a NULL
*/
ListaD::ListaD()
{
	this->H=NULL;
	this->T=NULL;
}
/**
Constructor
@Parametros:void
@Result: void
Crea una lista con un nodo  con und ato de referencia y tanto H como 
T apuntan a este nodo
*/
ListaD::ListaD(int Dato)
{
	Nodo* aux=new Nodo(Dato);
	this->H=aux;
	this->T=aux;
}
/**
Lista Vacia
@Parametros:void
@Result: bool
Pregunta si H Y T apuntan a Null DEVUELVE  UN TRUE SI NO UN FALSE
*/
bool ListaD::ListaVacia()
{
	if (this->H==NULL&&this->T==NULL)
	{
		return true;
	}
	return false;
}
/**
Add Inicio
@Parametros:int
@Result: void
Crea un Nodo con el dato de parametro, que su apuntador anterior apunta a T y el siguiente 
a T pregunta si la lista esta vacia si esta vacia  T ahora es auxiliar si no 
H ahora sera el auxiliar
*/
void ListaD::AddInicio(int Dato)
{
	Nodo* aux=new Nodo(Dato,this->T,this->H);
	if(ListaVacia())
	{
		this->T=aux;
	}
	this->H=aux;
}
/**
AddFinal
@Parametros:int
@Result: void
Crea un nodo con Dato y que apunta  NULL en ambos lados pregunta
si la lista esta vacia con el metodo lista vacia si esto se cumple 
tanto H y T se les asiga el nuevo nodo si esto no se cumple el nuevo 
nodo le asigna T por un lado y T le asigna el nuevo nodo y finalmente 
a T se le asigna el nuevo nodo y el nuevo nodo ahor es T

*/
void ListaD::AddFinal(int Dato)
{
	Nodo*aux=new Nodo(Dato);
	if(ListaVacia())
	{
		this->H=aux;
		this->T=aux;
	}else
	{
		aux->setAnt(this->T);
		this->T->setSig(aux);
		this->T=aux;
	}
}
/**
AddRef
@Parametros:int,int
@Result: void
Recibe dos parametros enteros verifica si la lista esta vacia 
si esta vacia crea un nodo auxiliar con el primer parametro como referencia
ahora a H se le asigna el nodo creado y aus vez a T se le asigna H y arroja una leyenda 
de que se no hay referencia porque la lista esta vacia
si no el nodo creado apunta a H y recorre la lista diciendo obten el dato 
del nodo creado y si es diferente al segundo parametro  y tambien 
es diferente a T vas a puntar al siguiente valor posteriormente
pregunta si este  valor llega y es diferente de NULL entonces creara un 
segundo nodo con el valor del primer parametro el apuntador anterior
apuntara a  el primer nodo creadoy el siguiente apuntara el siguiente del
 primer nodo creado posteriormente crearemos un tercer nodo 
que apuntara al siguiente del primer nodo , ahora al primer nodo hacemos que apunte
al segundo nodo creado y al auxiliar tres se le asigna el anterior del segundo auxliar
si no se cumple que sea NULL  dice que  no se encotro la referencia 
*/
void ListaD::AddRef(int Dato,int Ref)
{
	if (ListaVacia())
	{
		Nodo* aux=new Nodo(Dato);
		this->H=aux;
		this->T=this->H;
		std::cout<<"No se encontro la referencia porque la lista esta vacia"<<std::endl;
		return;	
	}else
	{
		Nodo* aux=this->H;
		while(aux->getDato()!=Ref&&aux!=this->T)
		{
			aux=aux->getSig();
		}
			if(aux!=NULL)
			{
				Nodo*aux2=new Nodo(Dato,aux,aux->getSig());
				Nodo * auxilio = aux->getSig();
				aux->setSig(aux2);
				auxilio->setAnt(aux2);
			}
			else
			{
				std::cout<<"No existe la referenci aen la lista"<<std::endl;
			}

	}
}
/**
RemoveInicio
@Parametros:void
@Result: int
Verifica si esta vacia la lista si NO  esta vacia obtenemos el dato de H en una variable
 y preguntamos si H es igual  NULL entonces T es igual  NULL si no 
H apunta al siguiente de H y el anterior a H apunta a NULL  y regresamos el dato ,
si no arrojamos la leyenda de que esta vacia 
*/
int ListaD::RemoveInicio()
{
	if (!ListaVacia())
	{
		int Dato =this->H->getDato();	
		if (this->H==NULL)
		{
			this->T=NULL;
		}
		this->H=this->H->getSig();
		this->H->setAnt(NULL);
		return Dato;
	}
	else
	{
		std::cout<<"La lista esta vacia"<<std::endl;		
	}	
}
/**
RemoveFInal
@Parametros:void
@Result: int
Verifica si la lista esta vacia llama al metodo lista vacia si esta vacia arroja una 
leyenda de que esta vacia, si no respaldamos el dato de T en una variable 
luego preguntamos si H es diferente T creamos un nodo auxliliar que apunta 
a H y recorremos la lista hasta llegar uno antes de  T una vez que llegamos 
 le asignamos el nodo creado a T y el siguiente apunta a NULL 
Y se pierde la referencia, si H y T no son Diferentes entoces ambos puntan a NULL
y retorna el dato 
*/
int ListaD::RemoveFinal()
{
	if (ListaVacia())
	{
		std::cout<<"La lista esta vacia"<<std::endl;
	}
	int Dato =T->getDato();
	if (this->H!=this->T)
	{
		Nodo * aux = this->H;		
		while(aux->getSig()!=this->T)
		{
			aux = aux->getSig();
		}
		this->T=aux;
		this->T->setSig(NULL);
	}
	else
	{
		this->H=NULL;
		this->T=NULL;
	}
	return Dato;
}
/**
RemoveRef
@parametros: int
@Result: int 
Verifica si la lista esta vacia si esta vacia dice que esta vacia y regresa, 
si no crea dos nodos que apuntan  a H, el primer nodo recorrera la lista hasta que 
sea diferente a T, y el segundo hasta que sea diferente del primer nodo preguntamos
si el primer nodo es diferente de NULLsi es diferente a NULL
creamos un tercer nodo que apuntara al siguiente del primer nodo  y  al segundo 
nodo le asignamos el siguiente del primer nodo y al tercer nodo le asignamos 
que su apuntador anterior apunte al segundo nodo, si esto no se cumpliera es decir
que fuera NULL decimos que no se encontro y retornamos.
*/
int ListaD::RemoveRef(int Ref)
{
	if (ListaVacia())
	{
		std::cout<<"No se encontro la referencia porque la lista esta vacia"<<std::endl;
		return 0;		
	}
	Nodo * aux = this->H;
	Nodo * aux2 = this->H;
	while(aux->getDato()!=Ref&&aux!=this->T)
	{
		aux = aux->getSig();
	}
	while(aux2->getSig()!=aux)
	{
		aux2 = aux2->getSig();
	}

		if (aux!=NULL)
		{		
			Nodo * auxilio = aux->getSig();
			aux2->setSig(aux->getSig());
			auxilio->setAnt(aux2);
		}
	else
	{
		std::cout<<"No existe la referencia"<<std::endl;
	}
	return 0;
}	
/**
Buscar Elemento
@Parametros:int
@Result: Nodo
Verifica si la lista esta vacia con el metodo lista vacia si esta vacia 
envia una leyenda de que esta vacia y regresa un NULL
si no crea un nodo que apunta a H y se recorre la lista 
hasta encontrar el dato y el nodo creado sea diferente de NULL 
terminado el ciclo pregunta si el dato del nodo donde se quedo es 
el del parametro si no lo es arroja una leyenda de que no lo encontro ,si no 
retorna un IMPRIME EL ELEMENTO Y RETORNA EL NODO DONDE SE ENCUENTRA
*/
Nodo * ListaD::BuscarElemento(int Dato)
{ 
	if (ListaVacia())
	{
		std::cout<<"No se encuentra el elemento"<<std::endl;
		return NULL;		
	}
	Nodo * aux = this->H;
	while(aux->getDato()!=Dato&&aux!=NULL)
	{
		aux=aux->getSig();
	}
		
	if (aux->getDato()==Dato)
	{
		std::cout<<aux->getDato()<<" se encuentra en la lista"<<std::endl;	
		return aux;
	}
	std::cout<<"NO se encontro el elemento"<<std::endl;
	return NULL;
}
/**
VaciarLista
@Parametros:void
@Result:int 
apunta a H y a T a NULL
*/
int ListaD::VaciarLista()
{
	this->H=NULL;
	this->T=NULL;
	std::cout<<"He vaciado la lista"<<std::endl;	
	return 0;
}
/**
Show
@Parametros:void
@Result:void
Crea un Nodo que apunta a H y recorre 
la lista hasta encontrar un NULL  durante eso 
va imprimendo el dato del nodo donde se encuentra 
luego apunta al siguiente hasta llegar a NULL
*/
void ListaD::Show()
{
	Nodo* aux = this->H;
	while(aux!=NULL)
	{
		std::cout<<aux->getDato()<<std::endl;
		aux=aux->getSig();
	}
}