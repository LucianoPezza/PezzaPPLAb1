#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "cliente.h"

int cargarNombreCliente(char nombre[],int idx,eCliente lista[], int tammaster)
{
    int todoOk= 0;
    for(int i =0; i<tammaster; i++)
    {
        if(lista[i].id == idx)
        {
            strcpy(nombre, lista[i].nombres);
            todoOk = 1;
        }
    }
    return todoOk;
}
void mostrarClientes(eCliente lista[], int tammaster)
{
    printf("%s %10s %14s", "ID", "Cliente","Sexo");
    for(int i = 0; i<tammaster; i++)
    {
        printf("\n%d %10s %10c ", lista[i].id , lista[i].nombres , lista[i].sexos);
    }
}
