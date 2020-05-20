#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "Servicios.h"
#include "Noteboocks.h"
#include "Marca.h"
#include "Tipo.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    int isEmpty;
    eFecha unaFecha;
}eTrabajo;


/** \brief Inicializa los trabajos igualando isEmpty a 1 (libre) las veces del numero del tamanio
 *
 * \param eTrabajo estructura
 * \param int TAM
 * \return void
 *
 */
void incializarTrabajos(eTrabajo [], int);




/** \brief busca lugar libre para agregar con alta
 *
 * \param eTrabajo estructura
 * \param int tam
 * \return indice
 *
 */
int buscarLibreTrabajos(eTrabajo[], int);




/** \brief da de alta un trabajo y muesta las netbooks y los servicios para que el usuario pueda elejirlos segun su id
 *
 * \param int idx, que permite autoincrementar el id del usuario y darlo de alta automaticamente.
 * \param eTrabajo[] estructura
 * \param int tam tamanio
 * \param int tamt tamanio de la lista de servicios
 * \param eNotebook[] estructura
 * \param eServicio[] estructura
 * \param eMarca[] estructura
 * \param eTipo[] estructura
 * \return confirmo
 *
 */
int altaTrabajos(int, eTrabajo[], int,int, eNotebook[], eServicio[],eMarca[], eTipo[]);




/** \brief Enseña 1 trabajo
 *
 * \param etrabajo estructura
 * \param eNotebook estructura
 * \param eServicio estructura
 * \param int tam
 * \param int tamHardcodeo
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo, eNotebook[], eServicio[], int, int);





/** \brief  enseña todos los trabajadores en el sistema
 *
 * \param eTrabajo estructura
 * \param int tam
 * \param int tamhardcodeados
  * \param eNotebook estructura
   * \param eServicio estructura
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo[], int,int, eNotebook[], eServicio[]);


int identificarId(int , eNotebook [], int );

#endif // TRABAJOS_H_INCLUDED
