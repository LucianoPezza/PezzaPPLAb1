#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcionTipo[20];
}eTipo;






/** \brief iguala los id para poder cargar la descripcion del tipo en una variable
 *
 * \param char descripcion
 * \param int id
 * \param eTipo estructuras
 * \param int tam
 * \return todo ok que confirma si entro al if
 *
 */
int cargarDescripcionTipo(char [],int ,eTipo [], int);








/** \brief iguala los id para poder cargar la descripcion del tipo en una variable
 *
 * \param eTipo estructura
 * \param int tam
 * \return void
 *
 */
void mostrarTipos(eTipo [], int );


#endif // TIPO_H_INCLUDED
