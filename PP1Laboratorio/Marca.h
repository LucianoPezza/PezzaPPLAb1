#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcionMarca[20];
}eMarca;

int cargarDescripcionMarca(char[],int,eMarca[], int);
void mostrarMarcas(eMarca[], int);

#endif // MARCA_H_INCLUDED
