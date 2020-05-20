#ifndef NOTEBOOCKS_H_INCLUDED
#define NOTEBOOCKS_H_INCLUDED
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "cliente.h"

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int idCliente;
    int precio;
    int isEmpty;

}eNotebook;

int altaNotebooks(eNotebook[], int,eMarca [], eTipo [], int,eCliente []);
void hardcodearMarcaTipoYServicios(eTipo[], eMarca[], int, eServicio [], eCliente[]);
void inicializarNoteboocks(eNotebook[], int);
int buscarNotebook(int, eNotebook[], int);
void bajaNotebook(eNotebook [], int, eMarca[], eTipo[], int,eCliente[]);
void modificarNotebook(eNotebook[], int, eMarca[], eTipo[], int, eCliente[]);
void mostrarNotebooks(eNotebook[], int, eMarca[], eTipo[], int,eCliente[]);
void mostrarNotebook(eNotebook, eMarca[], eTipo[], int,eCliente[]);
int buscarLibre(eNotebook [], int );
void ordenarPorMarcaYPrecio(eMarca[], int, eNotebook[]);
void hardcodearNotebooks(eNotebook [], int );
int cargarModeloyPrecioNotebook(char [],int*,int, eNotebook[], int);

#endif // NOTEBOOCKS_H_INCLUDED

