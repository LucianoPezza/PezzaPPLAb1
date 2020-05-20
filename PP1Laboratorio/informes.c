#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"
#include "Informes.h"

void MostrarNotebooksDelTipoSeleccionadoPorElUsuario(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    int idTipo;

    printf("*****Mostrar Notebooks del tipo seleccionado por el Usuario*****");

    mostrarTipos(listaT, tammaster);
    printf("\n");
    idTipo = getIdTipo();

    printf("%s %10s %10s %10s %10s %15s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio");

    for(int i =0; i < tam; i++)
    {
        if(listaN[i].isEmpty == 0 && listaN[i].idTipo == idTipo)
        {
            mostrarNotebook(listaN[i], listaM, listaT, tammaster, listaC );
        }
    }
}

void mostrarNotebooksDeUnaMarcaSeleccionada(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    int idMarca;

    printf("*****Mostrar Notebooks de las marcas seleccionadas*****");

    mostrarMarcas(listaM, tammaster);
    printf("\n");
    idMarca = getIdMarca();

    printf("%s %10s %10s %10s %10s %15s", "ID", "Modelo", "Marca", "Tipo","Cliente","Precio");

    for(int i =0; i < tam; i++)
    {
        if(listaN[i].isEmpty == 0 && listaN[i].idMarca == idMarca)
        {
            mostrarNotebook(listaN[i], listaM, listaT, tammaster, listaC );
        }
    }
}
void mostrarNotebooksMasBaratas(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    float minSueldo;
    char modelos[20];
    int flag =0;

    for(int i =0; i < tam; i++ )
    {
        if(listaN[i].isEmpty == 0)
        {
            if(listaN[i].precio < minSueldo || flag ==0)
            {
                minSueldo = listaN[i].precio;
                //             strcpy(modelos[20], listaN[i].modelo);
                flag = 1;

            }
        }
    }
    printf("Las notebooks mas baratas son: %s  y valen: %.2f", modelos, minSueldo);
}
void mostrarNotebooksSeparadasPorMarca(eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    printf("*****Mostrar Notebooks separadas por marca*****");
    int flag = 0;
    for(int m =0; m < tammaster; m++)
    {
        flag =0;
        printf("\n\nMarca: %s", listaM[m].descripcionMarca);
        for(int n =0; n < tam; n++)
        {
            if(listaN[n].isEmpty == 0 && listaN[n].idMarca == listaM[m].id)
            {
                mostrarNotebook(listaN[n], listaM, listaT, tammaster, listaC);
                flag =1;
            }
        }
        if(flag == 0)
        {
            printf("\n No hay empleados que mostrar");
        }
    }
}
void elejirTipoYMarcaYContarNotebooks(eNotebook unaNot,eNotebook listaN[], eTipo listaT[],eMarca listaM[],eCliente listaC[], int tam, int tammaster)
{
    int idTipo;
    int idMarca;
    int contadorMarca = 0;
    int contadorTipo = 0;
    int contadorFinal;
    char marcades[20];
    char tipodes[20];

    cargarDescripcionMarca(marcades, unaNot.idMarca, listaM, tammaster);
    cargarDescripcionTipo(tipodes, unaNot.idTipo, listaT, tammaster);

    printf("*****Mostrar cuantas notebooks hay en los tipos y marcas que elijamos*****\n \n");

    mostrarTipos(listaT, tammaster);
    idTipo = getIdTipo();

    printf("\n \n");

    mostrarMarcas(listaM, tammaster);
    idMarca = getIdMarca();


    for(int i =0; i < tam; i++)
    {
        if(listaN[i].isEmpty == 0 && listaN[i].idTipo == idTipo)
        {
            contadorTipo++;
        }
        if(listaN[i].isEmpty == 0 && listaN[i].idMarca == idMarca)
        {
            contadorMarca++;
        }
    }
    printf("\n En la marca hay: %d Notebooks y el en Tipo: %d Notebooks",contadorMarca, contadorTipo);
}





