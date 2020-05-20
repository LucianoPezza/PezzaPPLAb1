#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char sexos;
    char nombres[20];
    int id;

}eCliente;

int cargarNombreCliente(char [],int ,eCliente [], int );
void mostrarClientes(eCliente [], int );

#endif // CLIENTE_H_INCLUDED
