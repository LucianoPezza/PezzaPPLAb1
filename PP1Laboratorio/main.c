#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"

#define TAM 10
#define HARDCODEADOS 4

int main()
{
    int opcion;
    char seguis = 's';
    int idtrabajo= 100;
    int flag = 0;
    int flag2 =0;

    eNotebook unaNotebook[TAM];
    eTipo unTipo[HARDCODEADOS];
    eMarca unaMarca[HARDCODEADOS];
    eServicio unServicio[HARDCODEADOS];
    eTrabajo unTrabajo[TAM];


    inicializarNoteboocks(unaNotebook, TAM);
    incializarTrabajos(unTrabajo, TAM);
    hardcodearMarcaTipoYServicios(unTipo, unaMarca, HARDCODEADOS, unServicio);


    do
    {
        printf("********************Primer Parcial********************\n");
        opcion = getInt("Ingrese una opcion \n1.Alta\n2.Modificacion\n3.Baja\n4.Listar Notebooks\n5.Listar Marcas\n6.Listar tipos\n7.Listar servicios\n8. Alta Trabajo\n9. Listar trabajos\n10. Salir \n Elija:","Ingrese solo numeros: ");
        switch(opcion)
        {
        case 1:
            if(flag == 0 || flag ==1)
            {
                system("cls");
                altaNotebooks(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS);
                flag =1;
            }
            break;
        case 2:
            if(flag ==1)
            {
                system("cls");
                modificarNotebook(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS);
            }
            else
            {
                printf("Primero tiene quedar de alta\n");
                system("pause");
            }
            break;
        case 3:
            if(flag ==1)
            {
                system("cls");
                bajaNotebook(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS);
            }
            else
            {
                printf("Primero tiene quedar de alta\n");
                system("pause");
            }
            break;
        case 4:
            if(flag ==1)
            {
                system("cls");
                //ordenarPorMarcaYPrecio(unaMarca, HARDCODEADOS, unaNotebook);
                mostrarNotebooks(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS);
                printf(" \n");
                system("pause");
            }
            else
            {
                printf("Primero tiene quedar de alta\n");
                system("pause");
            }
            break;
        case 5:
            system("cls");
            mostrarMarcas(unaMarca,HARDCODEADOS);
            printf("\n");
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarTipos(unTipo, HARDCODEADOS);
            printf(" \n");
            system("pause");
            break;
        case 7:
            system("cls");
            listarServicios(unServicio, HARDCODEADOS);
            printf(" \n");
            system("pause");
            break;
        case 8:
            if((flag2 == 0 || flag2 == 1)&& flag == 1)
            {
                if(altaTrabajos(idtrabajo, unTrabajo, TAM,HARDCODEADOS, unaNotebook, unServicio, unaMarca, unTipo))
            {
                idtrabajo++;
            }
                flag2 =1;
            }else
            {
                printf("Primero debe dar de alta 1 notebook, con su respectivo id");
            }
            break;
        case 9:
            if(flag2 == 1)
            {
                 system("cls");
            mostrarTrabajos(unTrabajo, TAM, HARDCODEADOS, unaNotebook, unServicio);
            printf("\n");
            system("pause");
            }else
            {
                printf("Primero de de alta un trabajo\n");
                system("pause");
            }
            break;
        case 10:
            seguis = 'n';
            break;
        default:
            opcion = getInt("Ingrese una opcion correcta: ", "Solo numeros: ");
            break;
        }
        system("cls");
    }
    while(seguis == 's');
    return 0;
}
