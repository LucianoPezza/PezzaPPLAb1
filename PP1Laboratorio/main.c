#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Noteboocks.h"
#include "Trabajos.h"
#include "Informes.h"

#define TAM 10
#define HARDCODEADOS 4

int main()
{
    int opcion;
    char seguis = 's';
    char opcionInformes;
    int idtrabajo= 100;
    int flag = 0;
    int flag2 =0;

    eNotebook unaNotebook[TAM];
    eNotebook unaNotebookSola;
    eTipo unTipo[HARDCODEADOS];
    eMarca unaMarca[HARDCODEADOS];
    eServicio unServicio[HARDCODEADOS];
    eCliente unCliente [HARDCODEADOS];
    eTrabajo unTrabajo[TAM];


    inicializarNoteboocks(unaNotebook, TAM);
    incializarTrabajos(unTrabajo, TAM);
    hardcodearMarcaTipoYServicios(unTipo, unaMarca, HARDCODEADOS, unServicio, unCliente);
    hardcodearNotebooks(unaNotebook, HARDCODEADOS);

    do
    {
        printf("********************Primer Parcial********************\n");
        opcion = getInt("Ingrese una opcion \n1.Alta\n2.Modificacion\n3.Baja\n4.Listar Notebooks\n5.Listar Marcas\n6.Listar tipos\n7.Listar servicios\n8.Alta Trabajo\n9.Listar trabajos\n10.Listar Cliente\n11.Informes\n12.Salir\nElija:","Ingrese solo numeros: ");
        switch(opcion)
        {
        case 1:
            if(flag == 0 || flag ==1)
            {
                system("cls");
                altaNotebooks(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS, unCliente);
                flag =1;
            }
            break;
        case 2:
            if(flag ==1)
            {
                system("cls");
                modificarNotebook(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS,unCliente);
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
                bajaNotebook(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS,unCliente);
            }
            else
            {
                printf("Primero tiene quedar de alta\n");
                system("pause");
            }
            break;
        case 4:
        //    if(flag ==1)
          //  {
                system("cls");
                //ordenarPorMarcaYPrecio(unaMarca, HARDCODEADOS, unaNotebook);
                mostrarNotebooks(unaNotebook, TAM, unaMarca, unTipo, HARDCODEADOS,unCliente);
                printf(" \n\n");
                system("pause");
            //}
            //else
            //{
                //printf("Primero tiene quedar de alta\n");
              //  system("pause");
            //}
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
            printf(" \n\n");
            system("pause");
            break;
        case 7:
            system("cls");
            listarServicios(unServicio, HARDCODEADOS);
            printf(" \n\n");
            system("pause");
            break;
        case 8:
            if((flag2 == 0 || flag2 == 1)&& flag == 1)
            {
                if(altaTrabajos(idtrabajo, unTrabajo, TAM,HARDCODEADOS, unaNotebook, unServicio, unaMarca, unTipo, unCliente))
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
            system("cls");
            mostrarClientes(unCliente, HARDCODEADOS);
            printf(" \n\n");
            system("pause");
            break;
        case 11:
              system("cls");
             opcionInformes = getLetra("Ingrese El informe que quiera \na.Mostrar las notebooks del tipo seleccionado por el usuario\nb.Mostrar Notebooks de una marca seleccionada\nc.Mostrar la o las notebooks mas baratas(SIN TERMINAR)\nd.Mostrar notebooks separadas por marca\ne.Elejir tipo y marca y contar cuantas Notebooks hay\nf.Mostrar la o las marcas mas elegidas por los clientes(NO TERMINADA).\nElija: ","Error. solo letras: ");
              switch(opcionInformes)
              {
                case 'a':
                system("cls");
                MostrarNotebooksDelTipoSeleccionadoPorElUsuario(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                printf("\n\n");
                system("pause");
                break;
                case 'b':
                system("cls");
                mostrarNotebooksDeUnaMarcaSeleccionada(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                printf("\n\n");
                system("pause");
                break;
                case 'c':
                system("cls");
               // mostrarNotebooksMasBaratas(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
               printf("NO FUNCIONA");
                system("pause");
                break;
                case 'd':
                    system("cls");
                    mostrarNotebooksSeparadasPorMarca(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                    printf("\n\n");
                    system("pause");
                break;
                case 'e':
                    system("cls");
                    elejirTipoYMarcaYContarNotebooks(unaNotebookSola,unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                    printf("\n\n");
                    system("pause");
                break;
                case 'f':
                system("cls");
           //     mostrarLasMarcasMasElejidasPorLosClientes(unaNotebook, unTipo, unaMarca, unCliente, TAM, HARDCODEADOS);
                system("pause");
                break;
                default:
                    opcionInformes = getLetra("Ingrese una opcion valida","Error. Solo letras: ");
                    break;
              }
              break;
        case 12:
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
