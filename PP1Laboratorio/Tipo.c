#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Tipo.h"

int cargarDescripcionTipo(char descripcion[],int id,eTipo lista[], int tammaster)
{
    int todoOk= 0;
    for(int i =0; i<tammaster; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(descripcion, lista[i].descripcionTipo);
            todoOk = 1;
        }
    }
    return todoOk;
}
void mostrarTipos(eTipo lista[], int tammaster)
{
    printf("%s %10s", "ID", "TIPOS");
    for(int i = 0; i<tammaster; i++)
    {
        printf("\n%d %10s ", lista[i].id, lista[i].descripcionTipo);
    }
}
