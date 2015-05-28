#include "ListaImp.h"

#ifndef LISTAIMP_CPP
#define LISTAIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ListaImp<T> &l) {
	for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
		out << i++ << " ";
	}
	return out;
}

template <class T>
ListaImp<T>::ListaImp(){
	ppio=fin=NULL;
	largo=0;

}

template <class T>
ListaImp<T>::ListaImp(const Lista<T> &l) {
	ppio=fin=NULL;
	largo=0;
	//inicializo la lista con un estado válido
	*this=l;
}

template <class T>
ListaImp<T>::ListaImp(const ListaImp<T> &l) {
	ppio=fin=NULL;
	largo=0;
	//inicializo la lista con un estado válido
	*this=l;
}

template <class T>
Lista<T> &ListaImp<T>::operator=(const Lista<T> &l) { 
	if (this != &l) {
			this->Vaciar();

			for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
				AgregarFin(i++);
			}
		}
		return *this;
}

template <class T>
Lista<T> &ListaImp<T>::operator=(const ListaImp<T> &l) { 
		if (this != &l) {
			this->Vaciar();

			for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
				AgregarFin(i++);
			}
		}
		return *this;
}

template <class T>
ListaImp<T>::~ListaImp(){
	this->Vaciar();
}

template <class T>
void ListaImp<T>::AgregarPpio(const T &e){
	NodoLista <T> * nuevo= new NodoLista<T>(e,NULL,ppio);
	if(this->EsVacia()){
		fin=nuevo;
	}else{
		ppio->ant=nuevo;
	}
	ppio=nuevo;
	largo=largo+1;
}

template <class T>
void ListaImp<T>::AgregarFin(const T &e){
	NodoLista <T> * nuevo= new NodoLista<T>(e,fin,NULL);
	if(this->EsVacia()){
		ppio=nuevo;
	}else{
		fin->sig=nuevo;
	}
	fin=nuevo;
	largo=largo+1;
}

template <class T>
void ListaImp<T>::AgregarOrd(const T &e){
	if(this->EsVacia()){
		this->AgregarPpio(e);
	}else{

		NodoLista <T> *aux=ppio;
		while(aux!=NULL){
			if(aux->dato>=e){
				NodoLista<T>*nuevo= new NodoLista<T>(e,NULL,NULL);
				nuevo->sig=aux;
				nuevo->ant=aux->ant;
				aux->ant->sig=nuevo;
				aux->ant=nuevo;
				largo=largo+1;
				return;
			}
			aux=aux->sig;
		}

		if(aux==NULL){
			this->AgregarFin(e);
		
		}

	
	
	
	}
}

template <class T>
void ListaImp<T>::BorrarPpio(){
	if(!this->EsVacia()){
		NodoLista <T> * aBorrar = ppio;
		ppio=ppio->sig;
		ppio->ant=NULL;
		aBorrar->sig=NULL;
		delete aBorrar;
		aBorrar=NULL;
		largo=largo-1;
		//lo hacemos en el caso que borremos el unico elemento de la lista para que fin no quede apuntando a basura.
		if(largo==0){
			fin=NULL;
		}
	}
}

template <class T>
void ListaImp<T>::BorrarFin(){
	if(!this->EsVacia()){
		NodoLista <T> * aBorrar = fin;
		if(largo==1){
			fin=ppio=NULL;
		}else{
			fin = aBorrar->ant;	
			fin->sig=NULL;
			aBorrar->ant=NULL;
		}
		
		delete aBorrar;
		aBorrar=NULL;
		largo = largo -1;
	}
}

template <class T>
void ListaImp<T>::Borrar(const T &e){
	//CASO BASE 1: LISTA ES VACIA
	if(!this->EsVacia){
		//CASO BASE 2: ELEMENTO EN PRINCIPIO
		if(ppio->dato==e){
			this->BorrarPpio;
		}
		else{
			//CASO 3: ELEMENTO EN FINAL
			if(fin->dato==e){
				this->BorrarFin;
			}else{

				//CASO 4: ELEMENTO EN EL MEDIO DE LA LISTA
				NodoLista <T> * aux = ppio;
				while(aux!=NULL){
					if(aux->dato==e){
						NodoLista <T> * aBorrar = aux;
						aux->ant->sig = aBorrar->sig;
						aux->sig->ant = aBorrar->ant;
						delete aBorrar;
						aBorrar=NULL;
						largo=largo-1;
						return;
					}
				aux=aux->sig;
				}
			
			
			
			}
		}
	}
	
}

template <class T>
const T& ListaImp<T>::Recuperar(const T &e) const {
 if(!this->Existe(e)){
		return *(new T()); 
	}else{
		NodoLista <T> *aux=ppio;
		while(aux!=NULL){
			if(aux->dato==e){
				return aux->dato;			
			}
		aux=aux->sig;
		}
	
	
	}	
		
	
}

template <class T>
bool ListaImp<T>::Existe(const T &e) const {
	if(this->EsVacia()){
		return false;
	}else{
		NodoLista <T> *aux=ppio;
		while(aux!=NULL){
			if(aux->dato==e){
				return true;			
			}
		aux=aux->sig;
		}
		return aux==NULL;
	
	}	
	
}

template <class T>
void ListaImp<T>::Vaciar(){
	if(!this->EsVacia()){
		NodoLista <T> *aux=ppio;
		while(aux!=NULL){
			this->BorrarPpio();
			aux=ppio;
		
		}
	}
}

template <class T>
unsigned int ListaImp<T>::Largo()const { 	
	return this->largo; 
}

template <class T>
bool ListaImp<T>::EsVacia()const { 
	
	return this->largo == 0; 
}

template <class T>
bool ListaImp<T>::EsLlena()const { 
	return false; 
}

template <class T>
Iterador<T> ListaImp<T>::GetIterador() const {
	return IteradorListaImp<T>(*this);
}

#endif