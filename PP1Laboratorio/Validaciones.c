#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Validaciones.h"

int getInt(char mensaje[], char mensajeError[])
{
    char auxiliarChar[20];
    int enteroADevolver;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", auxiliarChar);
    enteroADevolver = atoi(auxiliarChar);

    while(getInti(auxiliarChar)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%s", auxiliarChar);
        enteroADevolver = atoi(auxiliarChar);
    }


    return enteroADevolver;
}

int getInti(char str[])
{
    int retorno = 1;
    for(int i =0; str[i]!='\0'; i++)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

void getnombre(char mensaje[],char mensajeError[], char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);

    strlwr(input);
    input[0] = toupper(input[0]);
    while(nombresValidos(input)!= 1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(input);
        input[0] = toupper(input[0]);
    }

}

int letraValida(char letra)
{
    int retorno = 1;
    if(letra <'A' || (letra>'Z' && letra<'a') || letra>'z')
    {
        retorno = 0;
    }
    return retorno;
}
char getLetra(char mensaje[], char mensajeError[])
{
    char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);

    while(letraValida(letra)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &letra);

    }
    return letra;
}
int nombresValidos(char str[])
{
    int retorno = 1;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]<'A' || (str[i]>'Z' && str[i]<'a') || str[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

float getFloat(char mensaje[])
{
    char auxiliarChar[10];
    float floatADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    floatADevolver = atof(auxiliarChar);

    while(floatADevolver == 0)
    {
        printf("%s", "Error. Ingrese un numero decimal valido\n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        floatADevolver = atof(auxiliarChar);
    }


    return floatADevolver;

}

int getSexo(char mensaje[])
{
    /*char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);
    while(!(isalpha(letra)))
    {
        printf("Error. Introduzca solo 1 caracter");
        scanf("%c", &letra);
    }*/
    char sexo;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &sexo);
    sexo = toupper(sexo);
    while(sexo != 'F' && sexo != 'M')
    {
        printf("Error. Introduzca los caracteres validos F/M: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = toupper(sexo);
    }
    return sexo;
}

int getEdad(char mensaje[], char mensajeError[])
{
    int edad;
    edad = getInt("Ingrese edad: ", "Error. Ingrese numeros: ");

    while(edad >= 100 || edad<= 0)
    {
        edad = getInt("Error. Ingrese una edad valida (entre 1 y 99 años): ","Solo numeros");
    }
    return edad;
}

void gotFecha(int* dia, int* mes, int* anio)
{
    *mes = getInt("Ingrese mes: ","Error. solo puede ingrese numeros: ");
    while(*mes < 1 || *mes > 12)
    {
        *mes = getInt("Error. Solo puede ingresar los meses validos 1-12: ","Error. solo puede ingrese numeros: ");
    }
    *dia =getInt("Ingrese dia: ", "Error. solo puede ingresar numeros: ");

    if(*mes == 1 || *mes ==3 || *mes == 5 || *mes ==7 || *mes ==8 || *mes == 10 || *mes == 12)
    {
    while(*dia < 1 || *dia > 31)
    {
        *dia = getInt("Error. Solo puede ingresar los dias validos 1-31: ","Error. Solo ingrese numeros: ");
    }
    }else if(*mes ==4 || *mes == 6 || *mes == 9 || *mes == 11)
    {
        while(*dia < 1 || *dia >30)
        {
            *dia = getInt("Error. Solo puede ingresar los dias validos 1-30: ","Error. Solo ingrese numeros: ");
        }
    }else
    {
        while(*dia < 1 || *dia >28)
        {
            *dia = getInt("Error. Solo puede ingresar los dias validos 1-28: ","Error. Solo ingrese numeros: ");
        }
    }
    *anio = getInt("Ingrese anio: ", "Error. Solo ingrese numeros: ");
    while(*anio < 1982 || *anio > 2020)
    {
        *anio = getInt("Error. Solo puede ingresar los anios validos 1982-2020): ","Error. Solo ingrese numeros: ");
    }

}