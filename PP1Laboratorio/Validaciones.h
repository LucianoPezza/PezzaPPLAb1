#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int getInti(char[]);
int getint(char[], char[]);
int getEdad();
int nombresValidos(char[]);
int letraValida(char);
char getLetra(char[], char[]);
void getnombre(char [],char [], char []);
int getSexo(char[]);
int getDia(char mensaje[], char mensajeError[]);
int getMes(char mensaje[], char mensajeError[]);
int getAnio(char mensaje[], char mensajeError[]);
void gotFecha(int*, int*, int*);
int getIdServicio(char[], char[]);
int getIdTipo();
int getId();
int getIdMarca();
int getPrecio();
float getFloat(char[]);


#endif // VALIDACIONES_H_INCLUDED
