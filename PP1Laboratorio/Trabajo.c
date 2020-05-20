#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Trabajos.h"
#include "Noteboocks.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"

void incializarTrabajos(eTrabajo lista[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int buscarLibreTrabajos(eTrabajo lista[], int tam)
{
    int indice = -1;
    for(int i =0; i<tam; i++)
    {
        if(lista[i].isEmpty ==1)
        {
            indice =i;
            break;
        }
    }
    return indice;
}

int altaTrabajos(int idx, eTrabajo listaT[], int tam,int tamt, eNotebook listaN[], eServicio listaS[], eMarca listaM[], eTipo listaTI[])
{
    int indice = buscarLibreTrabajos(listaT, tam);
    int auxidServicio;
    int indiceId;
    int auxidNotebook;

    int confirmo = 0;

    eTrabajo auxTrabajo;
    if(indice == -1)
    {
        printf("Sistema lleno \n");
    }
    else
    {
        mostrarNotebooks(listaN, tam, listaM, listaTI,tamt );
        auxidNotebook = getInt("\nIngrese el id de la notebook que desee: ","Error. Solo numeros: ");
        indiceId = identificarId(auxidNotebook, listaN, tam);
        if(indiceId != -1)
        {
            listarServicios(listaS, tamt);
            auxidServicio = getInt("\nIngrese el id del servicio que quiera: ","Error. Solo ingrese numeros: ");
            while((auxidServicio> 20003 || auxidServicio < 20000))
            {
                auxidServicio= getInt("\nIngrese solo los ID correctos: 20000 a 20003: ","Error. Solo ingrese numeros: ");
            }
            gotFecha(&auxTrabajo.unaFecha.dia,&auxTrabajo.unaFecha.mes, &auxTrabajo.unaFecha.anio);

            auxTrabajo.isEmpty = 0;
            auxTrabajo.id =idx;
            auxTrabajo.idNotebook = auxidNotebook;
            auxTrabajo.idServicio = auxidServicio;
            listaT[indice] = auxTrabajo;
            confirmo = 1;
        }else
        {
            printf("No se encontro el id");
            system("pause");
        }
    }
    return confirmo;
}
void mostrarTrabajo(eTrabajo lista, eNotebook listaN[], eServicio listaS[], int tamt, int tam)
{
    int* precioS;
    char descripcionS[25];
    int* preciosN;
    char marcaN[20];

    cargarDescripcionServicio(descripcionS, lista.idServicio, listaS, tamt);
    cargarModeloNotebook(marcaN,&preciosN, lista.idNotebook, listaN, tam);
    cargarPrecioServicio(&precioS, lista.idServicio, listaS, tamt);

    printf("\n%d %10s %13d %22s %12d %12d/%d/%d", lista.id, marcaN,preciosN, descripcionS,precioS,lista.unaFecha.dia, lista.unaFecha.mes, lista.unaFecha.anio);
}

void mostrarTrabajos(eTrabajo lista[], int tam,int tamt, eNotebook listaN[], eServicio listaS[])
{
    int flag = 0;

    printf("%s %12s %20s %15s %20s %8s","ID","NOTEBOOK","PRECIOS NOTEBOOK","SERVICIOS","PECIOS SERVICIO","FECHA");
    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty != 1)
        {
            mostrarTrabajo(lista[i], listaN, listaS, tamt, tam);
            flag =1;
        }

    }
    if(flag == 0)
        {
            printf("No hay trabajos que mostrar");
        }
}

void hardcodearTrabajos(eTrabajo lista[], int tam)
{
    int id[] = {100, 101, 102, 103};
    int idS[] = {20000, 20001, 20002, 20003};
    int idN[] = {1,2,3,4};
    int dia[] = {16, 13, 15, 14};
    int mes[] = {1,5,6,8};
    int anio[] = {2001,1999,2015,2008};
    for(int i = 0; i < tam; i++)
    {
        lista[i].id = id[i];
        lista[i].idNotebook = idN[i];
        lista[i].idServicio = idS[i];
        lista[i].unaFecha.dia = dia[i];
        lista[i].unaFecha.mes = mes[i];
        lista[i].unaFecha.anio = anio[i];
        lista[i].isEmpty = 0;
    }
}

int identificarId(int id, eNotebook lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
