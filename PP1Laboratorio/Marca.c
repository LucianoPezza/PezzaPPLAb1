#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marca.h"
#include "Validaciones.h"

int cargarDescripcionMarca(char descripcion[],int id,eMarca lista[], int tammaster)
{
    int todoOk= 0;
    for(int i =0; i<tammaster; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(descripcion, lista[i].descripcionMarca);
            todoOk = 1;
        }
    }
    return todoOk;
}
void mostrarMarcas(eMarca lista[], int tammaster)
{
    printf("%s %10s", "ID", "MARCAS");
    for(int i = 0; i<tammaster; i++)
    {
        printf("\n%d %8s ", lista[i].id, lista[i].descripcionMarca);
    }
}
