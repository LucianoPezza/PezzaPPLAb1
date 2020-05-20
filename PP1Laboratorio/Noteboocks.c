#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noteboocks.h"
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"

void hardcodearMarcaTipoYServicios(eTipo unTipo[], eMarca unaMarca[], int tammaster, eServicio unServicio[])
{
    int idT[] = {5000, 5001, 5002, 5003};
    char descripcionT[][20] = {"Gamer","Disenio","Ultrabook","Normalita"};

    int idM [] = {1000, 1001, 1002, 1003};
    char descripcionM[][20]= {"Compaq","Asus","Acer","HP"};

    int idS [] = {20000, 20001, 20002, 20003};
    char descripcionS[][25] = {"Bateria","Antivirus","Actualizacion","Fuente"};
    int precioS[] = {250, 300, 400, 600};
    for(int i =0; i<tammaster; i++)
    {
        strcpy(unTipo[i].descripcionTipo, descripcionT[i]);
        unTipo[i].id = idT[i];

        strcpy(unaMarca[i].descripcionMarca, descripcionM[i]);
        unaMarca[i].id = idM[i];

        unServicio[i].id = idS[i];
        strcpy(unServicio[i].descripcion, descripcionS[i]);
        unServicio[i].precio = precioS[i];
    }

}
void inicializarNoteboocks(eNotebook lista[], int tam)
{

    for(int i =0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}
int altaNotebooks(eNotebook lista[], int tam,eMarca listaM[], eTipo listaT[], int tammaster)
{
    int idx;
    int auxidMarca;
    int auxidTipo;
    int indice;
    int confirmo = 0;
    int indiceID;
    eNotebook auxNot;
    indice = buscarLibre(lista, tam);


    if(indice == -1)
    {
        printf("Sistema completo\n");
        system("pause");
    }
    else
    {
        idx =getInt("Ingrese Id: ","Error. Solo ingrese numeros: ");
        while(idx> 100 || idx < 1)
        {
            idx =getInt("Error. ingrese Id valida entre 1 y 100: ","Error. Solo ingrese numeros: ");
        }
        indiceID = buscarNotebook(idx, lista, tam);
        if(indiceID ==-1)
        {
            auxNot.id = idx;
            getnombre("Ingres Modelo: ","Error. Solo se pueden ingresar letras: ", auxNot.modelo);
            auxNot.precio =getInt("Ingrese el precio: ","Error. Solo se pueden ingresar numeros: ");
            mostrarMarcas(listaM, tammaster);
            auxidMarca = getInt("\nIngrese el id para elejir la marca: ","Error. Solo ingrese numeros: ");
            while((auxidMarca> 1003 || auxidMarca < 1000))
            {
                auxidMarca= getInt("Ingrese solo los ID correctos: 1000 a 1003: ","Error. Solo ingrese numeros: ");
            }
            auxNot.idMarca = auxidMarca;


            mostrarTipos(listaT, tammaster);
            auxidTipo = getInt("\nIngrese el id para elejir el tipo: ", "Error. Solo ingrese numeros: ");
            while((auxidTipo > 5003 || auxidTipo< 5000))
            {
                auxidTipo = getInt("Ingrese solo los ID correctos: 5000 a 5003: ", "Error. Solo ingrese numeros: ");
            }
            auxNot.idTipo =auxidTipo;

            auxNot.isEmpty=0;

            lista[indice] = auxNot;
            confirmo = 1;
        }
        else
        {
            printf("Esa id ya fue introducido\n");
            system("pause");
        }
    }
    return confirmo;
}

int buscarLibre(eNotebook lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarNotebook(int id, eNotebook lista[], int tam)
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


void bajaNotebook(eNotebook lista[], int tam, eMarca listaM[], eTipo listaT[], int tammaster)
{
    int id;
    int indice;
    char confirmacion;
    mostrarNotebooks(lista,tam, listaM, listaT, tammaster);
    id = getInt("\nIngrese legajo: ", "Error. Ingrese numeros: ");

    indice = buscarNotebook(id, lista, tam);

    if(indice == -1)
    {
        printf("No hay registro de ningun empleado con ese legajo \n");
    }
    else
    {
        confirmacion = getLetra("Quiere elminar al usuario? S/N: ","Error. Ingrese lo indicado S/N");

        if(confirmacion == 's' || 'S')
        {
            lista[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito \n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion \n\n");
            system("pause");
        }
    }
}
void modificarNotebook(eNotebook lista[], int tam, eMarca listaM[], eTipo listaT[], int tammaster)
{
    int id;
    int opcion;
    int indice;
    int auxPrecio;
    int auxTipo;

    char follow = 's';

    mostrarNotebooks(lista, tam, listaM, listaT, tammaster);
    id = getInt("\nIngrese ID: ", "Error. Ingrese numeros: ");
    indice = buscarNotebook(id, lista, tam);

    if(indice == -1)
    {
        printf("No hay registro de ningun empleado con ese ID\n");
        system("pause");
    }
    else
    {
        do
        {
            opcion = getInt("Elija lo que quiera modificar: \n1.Precio\n2.Tipo\n3.Salida \n:.","Opcion Erronea, ingrese numeros: ");
            switch(opcion)
            {
            case 1:
                system("cls");
                auxPrecio= getInt("Ingrese el nuevo precio: ","Error. Solo ingrese numeros: ");
                lista[indice].precio = auxPrecio;
                break;
            case 2:
                system("cls");
                mostrarTipos(listaT, tammaster);
                auxTipo = getInt("\nIngrese el id para elejir el nuevo tipo: ", "Error. Solo ingrese numeros: ");
                while((auxTipo > 5003 || auxTipo< 5000))
                {
                    auxTipo = getInt("Ingrese solo los ID correctos: 5000 a 5003: ", "Error. Solo ingrese numeros: ");
                }
                lista[indice].idTipo = auxTipo;
                break;
            case 3:
                follow = 'n';
                break;
            default:
                opcion = getInt("Ingrese una opcion correcta: ","Solo numeros: ");
                break;
            }
        }
        while(follow == 's');
    }
}

void mostrarNotebook(eNotebook lista, eMarca listaM[],eTipo listaT[], int tammaster)
{
    char Tipodes[20];
    char Marcades[20];
    cargarDescripcionMarca(Marcades, lista.idMarca, listaM, tammaster);
    cargarDescripcionTipo(Tipodes, lista.idTipo, listaT, tammaster);
    printf("\n%d %10s %10s %13s %10d",lista.id, lista.modelo, Marcades, Tipodes, lista.precio);
}
void mostrarNotebooks(eNotebook lista[], int tam, eMarca listaM[],eTipo listaT[], int tammaster)
{
    int flag;
    printf("%s %10s %10s %10s %15s", "ID", "Modelo", "Marca", "Tipo", "Precio");

    for(int i =0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarNotebook(lista[i],listaM,listaT,tammaster);
            flag = 1;
        }
    }if(flag == 0)
        {
            printf("No hay trabajos que mostrar");
        }
}

void ordenarPorMarcaYPrecio(eMarca listaM[], int tam, eNotebook lista[])
{
    eNotebook auxnot;
    for(int i =0; i<tam-1; i++)
    {
        for(int j= i+1; j< tam; j++)
            if(strcmp(listaM[i].descripcionMarca, listaM[j].descripcionMarca) > 0)
            {
                auxnot = lista[i];
                lista[i]= lista[j];
                lista[j]= auxnot;

            }/*
            else if(strcmp(listaM[i].descripcionMarca, listaM[j].descripcionMarca) == 0 && lista[i].precio > lista[j].precio)
            {
                auxnot = lista[i];
                lista[i]= lista[j];
                lista[j]= auxnot;
            }*/
    }
}

int cargarModeloNotebook(char modelos[],int* precios,int id, eNotebook lista[], int tam)
{
    int todoOk= 0;
    for(int i =0; i<tam; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(modelos, lista[i].modelo);
            *precios = lista[i].precio;
            todoOk = 1;
        }
    }
    return todoOk;
}
