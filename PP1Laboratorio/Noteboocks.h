#ifndef NOTEBOOCKS_H_INCLUDED
#define NOTEBOOCKS_H_INCLUDED
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int isEmpty;

}eNotebook;

int altaNotebooks(eNotebook[], int,eMarca [], eTipo [], int);
void hardcodearMarcaTipoYServicios(eTipo[], eMarca[], int, eServicio []);
void inicializarNoteboocks(eNotebook[], int);
int buscarNotebook(int, eNotebook[], int);
void bajaNotebook(eNotebook [], int, eMarca[], eTipo[], int);
void modificarNotebook(eNotebook[], int, eMarca[], eTipo[], int);
void mostrarNotebooks(eNotebook[], int, eMarca[], eTipo[], int);
void mostrarNotebook(eNotebook, eMarca[], eTipo[], int);
int buscarLibre(eNotebook [], int );
void hardcodear(eNotebook lista[], int tam);
void ordenarPorMarcaYPrecio(eMarca[], int, eNotebook[]);
int cargarModeloyPrecioNotebook(char [],int*,int, eNotebook[], int);

#endif // NOTEBOOCKS_H_INCLUDED

