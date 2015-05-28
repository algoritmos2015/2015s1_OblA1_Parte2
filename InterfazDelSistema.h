#ifndef INTERFAZ_DEL_SISTEMA_H
#define INTERFAZ_DEL_SISTEMA_H

#include "Constantes.h"
#include "Expresion.h"

/*	
	Todos los m�todos retornan un enumerado correspondiente a si la operaci�n 
	se pudo realizar correctamente, hubo un error o no fue implementada.
   

	NOTA:
			Ver la especificaci�n completa de los diferentes comandos en 
			la letra del obligatorio.

*/

class Expresion;

class InterfazDelSistema abstract
{
	
	public:

		virtual ~InterfazDelSistema() {};

		/*
		*	Crea e inserta una hoja de c�lculo en la planilla, 
		*	la cual tendr� como nombre nombreHoja
		*/
		virtual TipoRetorno InsertarHoja(char *nombreHoja) abstract;
		
		/*
		*	Elimina la hoja de nombre nombreHoja de la planilla, 
		*	si �sta existe, y todos los datos que est�n almacenados en ella.  
		*/
		virtual TipoRetorno EliminarHoja(char *nombreHoja) abstract;

		/*
		*	Lista todas las hojas que forman la planilla (solo el nombre) en orden alfab�tico (orden = ALFABETICO)
		*	o en el orden en que se crearon (orden = DECREACION). Se deber� mostrar cada hoja en una nueva l�nea.
		*	Si no existen hojas, se deber� mostrar un mensaje que lo indique.
		*/
		virtual TipoRetorno ListarHojas(OrdenListado orden) abstract;

		/*
		*	Asigna la expresi�n aExp en la hoja, columna y fila recibidas como par�metro.
		*	Si la celda ya contiene una expresi�n, se debe eliminar e insertar la nueva expresi�n.
		*/
		virtual TipoRetorno AsignarExpresionACelda(char *nombreHoja, unsigned int columna, unsigned int fila, const Expresion &aExp) abstract;

		/*
		*	Retorna la celda a su valor por defecto (0), en la hoja, columna y fila recibidas como par�metro.
		*/
		virtual TipoRetorno EliminarCelda(char *nombreHoja, unsigned int columna, unsigned int fila) abstract;
		
		/*
		*	Muestra el resultado de evaluar las celdas del rango especificado.
		*	Los datos de cada columna se mostrar�n separados por un tabulador y las filas separadas por un fin de l�nea.
		*/
		virtual TipoRetorno ListarCeldasEvaluadas(char *nombreHoja, unsigned int columnaDesde, unsigned int filaDesde, unsigned int columnaHasta, unsigned int filaHasta) abstract;

		/*
		*	Muestra la f�rmula de la celda en la hoja y posici�n especificada.
		*/
		virtual TipoRetorno ListarCeldaSinEvaluar(char *nombreHoja, unsigned int columna, unsigned int fila) abstract;

		/*
		*	Eval�a la referencia recibida. La referencia es un string que contiene el nombre de una hoja, el nombre de una columna y el n�mero de fila. 
		*	Recordar que la celda por defecto tiene el valor cero. El formato es el siguiente, primero se encuentra el nombre de la hoja, 
		*	luego un car�cter signo de exclamaci�n '!', luego el n�mero de columna, el car�cter dos puntos ':' y finalmente el n�mero de fila.
		*/
		virtual int EvaluarReferencia(char *referencia, bool &error) abstract;

		/*
		*	Recupera la �ltima hoja eliminada.
		*/
		virtual TipoRetorno RecuperarHoja() abstract;

		/*
		*	Lista todas las hojas que est�n guardadas para recuperar. 
			Primero deben aparecer las hojas m�s recientemente borradas.
		*/
		virtual TipoRetorno ListarHojasRecuperar() abstract;

};

#endif 