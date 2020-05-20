#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

void listarServicios(eServicio[], int);
int cargarDescripcionServicio(char[], int, eServicio[], int);
int cargarPrecioServicio(int*, int, eServicio[], int);

#endif // SERVICIOS_H_INCLUDED
