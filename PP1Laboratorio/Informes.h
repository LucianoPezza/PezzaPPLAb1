#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "Noteboocks.h"
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"
#include "Informes.h"

void MostrarNotebooksDelTipoSeleccionadoPorElUsuario(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);
void mostrarNotebooksDeUnaMarcaSeleccionada(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);
void mostrarNotebooksMasBaratas(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);
void mostrarNotebooksSeparadasPorMarca(eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);
void elejirTipoYMarcaYContarNotebooks(eNotebook, eNotebook[], eTipo[],eMarca listaM[],eCliente listaC[], int, int);


#endif // INFORMES_H_INCLUDED
