
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dataStore.h"

#define TAM 3

typedef struct{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct{
    int idTipo;
    char descripcion[25];
    int isEmpty;
} eTipo;

typedef struct{
    int id;
    int iMascota;
    int idServicio;
    eFecha fNac;
    int isEmpty;
} eTrabajo;

typedef struct{
    int isEmpty;
    int idServicio;
    char descripcion[25];
    int precio;
} eServicio;

typedef struct{
    int isEmpty;
    int idColor;
    char nombre[20];
} eColor;

typedef struct{
    int legajo;
    char nombre[20];
    int idTipo;
    int idColor;
    /*eTrabajo tTra;
    eServicio sSer;
    *//*eColor cCol;
    *///eTipo tTip;
    /**/int edad;
    //eFecha fNac;
    int isEmpty;

} eMascota;

void harcodearTipos(eTipo tipos[], int tam, int cantidad);
void mostrarTipo(eTipo unTipo);
int mostrarTipos(eTipo tipos[], int tam);
int inicializarMascotas(eMascota mascotas[], int tam);
void harcodearMascotas(eMascota mascotas[], int tam, int cantidad);
void harcodearTipos(eTipo tipos[], int tam, int cantidad);
void harcodearColores(eColor colores[], int tam, int cantidad);
void harcodearServicios(eServicio servicios[], int tam, int cantidad);
void harcodearTrabajos(eTrabajo trabajo[], int tam, int cantidad);
char menu();
int mostrarMascotas(eMascota mascotas[], int tam);
int mostrarTipos(eTipo tipos[], int tam);
int mostrarColores(eColor colores[], int tam);
int mostrarServicios(eServicio servicios[], int tam);
int mostrarTrabajos(eTrabajo trabajos[], int tam);
void mostrarTrabajo(eTrabajo unTrabajo);
void mostrarServicio(eServicio unServicio);
void mostrarColor(eColor unColor);
void mostrarTipo(eTipo unTipo);
void mostrarMascota(eMascota unaMascota);

int buscarLibre(eMascota mascotas[], int tam);
int altaMascota(eMascota mascotas[], int tam, int legajo);
int buscarMascota(eMascota mascotas[], int tam, int legajo);
int bajaMascota(eMascota mascotas[], int tam);
//void mostrarFecha(eFecha unaFecha);
int modificarMascota(eMascota mascotas[], int tam);

/*int validarIdColor(eMascota mascotas[], int tam, int id)
{
    int esValido = 0;

    if( mascotas != NULL && tam > 0 && id >= 1000)
    {
        for(int i=0; i < tam; i++)
        {
            if( mascotas[i].idColor == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}*/

void informeMostrarMascotaTipo(eMascota mascotas[], eTipo tipos[], int tam){
    eMascota nuevaMascota;
    int error = 1;
    char auxDescripcion[25];
    int indice;
    system("cls");


    printf("Ingrese descripcion");
    fflush(stdin);
    gets(auxDescripcion);

    printf("Mascotas del Color seleccionado\n\n");

    if(mascotas!=NULL && tam > 0){
        for(int i=0; i < tam; i++)
        {
            if(mascotas[i].isEmpty == 0 && strcmp(tipos[i].descripcion, auxDescripcion)==0)
            {
                for(int j=0;j<tam;j++){
                    if(mascotas[i].idTipo == tipos[j].idTipo)
                    {
                        //indice = buscarMascota(mascotas, tam, mascotas[i].legajo);
                        nuevaMascota.legajo = mascotas[i].legajo;
                        nuevaMascota.idColor = mascotas[i].idColor;
                        nuevaMascota.idTipo = mascotas[i].idTipo;
                        nuevaMascota.isEmpty = mascotas[i].isEmpty;
                        strcpy(nuevaMascota.nombre, mascotas[i].nombre);
                        nuevaMascota.edad = mascotas[i].edad;
                        //mascotas[indice] = nuevaMascota;
                        mostrarMascota(nuevaMascota);
                        //mostrarMascota(nuevaMascota);
                    }
                }
            }
        }
        error = 0;
    }
    return error;
}

void informeMostrarMascotaColor(eMascota mascotas[], eColor colores[], int tam)
{
    eMascota nuevaMascota;
    int error = 1;
    char auxNombre[20];
    int indice;
    system("cls");


    printf("Ingrese nombre");
    fflush(stdin);
    gets(auxNombre);

    printf("Mascotas del Color seleccionado\n\n");

    if(mascotas!=NULL && tam > 0){
        for(int i=0; i < tam; i++)
        {
            if(mascotas[i].isEmpty == 0 && strcmp(colores[i].nombre, auxNombre)==0)
            {
                for(int j=0;j<tam;j++){
                    if(mascotas[i].idColor == colores[j].idColor)
                    {
                        //indice = buscarMascota(mascotas, tam, mascotas[i].legajo);
                        nuevaMascota.legajo = mascotas[i].legajo;
                        nuevaMascota.idColor = mascotas[i].idColor;
                        nuevaMascota.idTipo = mascotas[i].idTipo;
                        nuevaMascota.isEmpty = mascotas[i].isEmpty;
                        strcpy(nuevaMascota.nombre, mascotas[i].nombre);
                        nuevaMascota.edad = mascotas[i].edad;
                        //mascotas[indice] = nuevaMascota;
                        mostrarMascota(nuevaMascota);
                        //mostrarMascota(nuevaMascota);
                    }
                }
            }
        }
        error = 0;
    }
    return error;
}
int informeMascotasMenorEdad(eMascota mascotas[], int tam)
{
    eMascota nuevaMascota;
    int error = 1;
    int indice;
    system("cls");
    printf("Mascotas menores de edad\n\n");
    if(mascotas!=NULL && tam > 0){
        for(int i=0; i < tam; i++)
        {
            if(mascotas[i].isEmpty == 0 && mascotas[i].edad <= 18)
            {
                //indice = buscarMascota(mascotas, tam, mascotas[i].legajo);
                nuevaMascota.legajo = mascotas[i].legajo;
                nuevaMascota.idColor = mascotas[i].idColor;
                nuevaMascota.idTipo = mascotas[i].idTipo;
                nuevaMascota.isEmpty = mascotas[i].isEmpty;
                strcpy(nuevaMascota.nombre, mascotas[i].nombre);
                nuevaMascota.edad = mascotas[i].edad;
                //mascotas[indice] = nuevaMascota;
                mostrarMascota(nuevaMascota);
                //mostrarMascota(nuevaMascota);
            }
        }
        error = 0;
    }
    return error;
}

int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo = 20000;
    int rta=0;

    eMascota lista [TAM];
    eTipo listaTipo[TAM];
    eColor listaColor[TAM];
    eServicio listaServicio[TAM];
    eTrabajo listaTrabajo[TAM];

    if(inicializarMascotas(lista, TAM)==0)
    {
        printf("Mascotas inicializadas con exito!");
    }else
    {
        printf("Ha ocurrido un problema al inicializar mascotas");
    }

    harcodearMascotas(lista, TAM, 3);
    harcodearTipos(listaTipo,TAM,3);
    harcodearColores(listaColor,TAM,3);
    harcodearServicios(listaServicio,TAM,3);
    harcodearTrabajos(listaTrabajo,TAM,3);

    mostrarMascotas(lista, TAM);

    mostrarTipos(listaTipo, TAM);

    mostrarColores(listaColor, TAM);

    mostrarServicios(listaServicio, TAM);

    mostrarTrabajos(listaTrabajo, TAM);

    proximoLegajo +=3;

    system("pause");

    if(altaMascota(lista, TAM, proximoLegajo) == 0)
    {
        proximoLegajo++;
        printf("ALTA EXITOSA!\n");
    }
    else
    {
        printf("Problema para realizar el alta");
    }

    mostrarMascotas(lista, TAM);

    do
    {
        switch(menu())
        {

            case 'a':
                if(altaMascota(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;
                    printf("ALTA EXITOSA!\n");
                }
                else
                {
                    printf("Problema para realizar el alta");
                }


                break;
            case 'b':
                rta = bajaMascota(lista, TAM);
                if( rta == 0)
                {
                    printf("Baja exitosa\n");
                }
                else if(rta == 2)
                {
                    printf("Baja cancelada por usuario\n");
                }
                else
                {
                    printf("Se ha producido un error en la baja\n");
                }

                break;
            case 'c':
                rta = modificarMascota(lista, TAM);
                if( rta == 0)
                {
                    printf("Modificacion exitosa\n");
                }
                else if(rta == 2)
                {
                    printf("La modificacion ha sido cancelada por usuario\n");
                }else
                {
                    printf("Se ha producido un error en la modificacion\n");
                }
                break;
            case 'd':
                system("cls");
                rta = mostrarMascotas(lista,TAM);

                break;
            case 'e':
                system("cls");
                informeMascotasMenorEdad(lista, TAM);
                break;
            case 'f':
                if(altaTrabajo(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;
                    printf("ALTA EXITOSA!\n");
                }
                else
                {
                    printf("Problema para realizar el alta");
                }

                break;
            case 'x':
                informeMostrarMascotaTipo(lista, listaTipo , TAM);
            case 'y':
                informeMostrarMascotaColor(lista, listaColor , TAM);
                break;
            case 'z':
                printf("Confirma salida?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }

                break;
            default:
                printf("Opcion invalida!!!\n");
                system("pause");

                break;
        }system("pause");
    }
    while( seguir == 's');


    return 0;
}

int inicializarMascotas(eMascota mascotas[], int tam){

    int error = 1;
    if (mascotas!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void harcodearTipos(eTipo tipos[], int tam, int cantidad){

    int error = 1;

    //int indice;
    //if( mascotas != NULL && tam > 0 && cantidad > 0 && cantidad <= tam){
        for(int i=0; i < tam; i++){
            tipos[i].isEmpty=0;
            tipos[i].idTipo = idsTipos[i];
            strcpy(tipos[i].descripcion, descripcionesTipos[i]);//indice = buscarPersona(mascotas, tam, proximoLegajo);
            //mostrarMascota(mascotas[indice]);

            //strcpy(mascotas[i].sSer.descripcion, descripcionesServicios[i]);

            //printf("%s",tTip.descripcion);
            //system("pause");

            // mascotas[i].cCol.idColor = idsColores[i];
            //strcpy(mascotas[i].cCol.nombre, nombresColores[i]);

       }
        //mostrarMascotas(mascotas, tam);
        system("pause");



}



void harcodearServicios(eServicio servicios[], int tam, int cantidad){

    int error = 1;

    //servicios[0].idServicio = idsServicios[0];
    //printf("%d lall\n",servicios[0].idServicio);
    //        system("pause");

    //int indice;
    //if( mascotas != NULL && tam > 0 && cantidad > 0 && cantidad <= tam){
        for(int i=0; i < tam; i++){
            servicios[i].isEmpty=0;
            servicios[i].idServicio = idsServicios[i];
            servicios[i].precio = precios[i];
            strcpy(servicios[i].descripcion, descripcionesServicios[i]);//indice = buscarPersona(mascotas, tam, proximoLegajo);
            //printf("%d lall\n",servicios[i].idServicio);
            //system("pause");
            //mostrarMascota(mascotas[indice]);

            //strcpy(mascotas[i].sSer.descripcion, descripcionesServicios[i]);

            //printf("%s",tTip.descripcion);
            //system("pause");

            // mascotas[i].cCol.idColor = idsColores[i];
            //strcpy(mascotas[i].cCol.nombre, nombresColores[i]);

       }
        //mostrarMascotas(mascotas, tam);
        //system("pause");



}


void harcodearColores(eColor colores[], int tam, int cantidad){

    int error = 1;

    //int indice;
    //if( mascotas != NULL && tam > 0 && cantidad > 0 && cantidad <= tam){
        for(int i=0; i < tam; i++){
            colores[i].isEmpty=0;
            colores[i].idColor = idsColores[i];
            strcpy(colores[i].nombre, nombresColores[i]);//indice = buscarPersona(mascotas, tam, proximoLegajo);
            //mostrarMascota(mascotas[indice]);

            //strcpy(mascotas[i].sSer.descripcion, descripcionesServicios[i]);

            //printf("%s",tTip.descripcion);
            //system("pause");

            // mascotas[i].cCol.idColor = idsColores[i];
            //strcpy(mascotas[i].cCol.nombre, nombresColores[i]);

       }
        //mostrarMascotas(mascotas, tam);
        system("pause");



}

void harcodearMascotas(eMascota mascotas[], int tam, int cantidad){


    //int error = 1;
    int proximoLegajo = 20000;
    //int indice;
    //if( mascotas != NULL && tam > 0 && cantidad > 0 && cantidad <= tam){
        for(int i=0; i < tam; i++){

            mascotas[i].isEmpty=0;

            mascotas[i].edad = NULL;
            mascotas[i].idColor = idsColores[i];
            mascotas[i].idTipo = idsTipos[i];
            mascotas[i].legajo = proximoLegajo;
            strcpy(mascotas[i].nombre, "");
            //indice = buscarPersona(mascotas, tam, proximoLegajo);
            //mostrarMascota(mascotas[indice]);

            //strcpy(mascotas[i].sSer.descripcion, descripcionesServicios[i]);

            //printf("%s",tTip.descripcion);
            //system("pause");
            proximoLegajo++;
            // mascotas[i].cCol.idColor = idsColores[i];
            //strcpy(mascotas[i].cCol.nombre, nombresColores[i]);

       }
        //mostrarMascotas(mascotas, tam);
     //   system("pause");

       //printf("%d",mascotas[0].edad);
        //mostrarMascota(mascotas[indice]);



       //mostrarMascotas(mascotas, tam);
    //}
    /*for(int i=0; i < tam; i++)
    {
        mascotas[i].edad =NULL;
        printf("%d lall\n",mascotas[i].edad);
        mascotas[i].idColor = idsColores[i];
        printf("%d lall\n",mascotas[i].idColor);
        mascotas[i].idTipo = idsTipos[i];
        printf("%d lala\n",mascotas[i].idTipo);
        strcpy(mascotas[i].nombre, "");
        printf("%s laal \n",mascotas[i].nombre);
        printf("%d lala\n",mascotas[i].isEmpty);
        mascotas[i].legajo = proximoLegajo;
        printf("%d la\n",mascotas[i].legajo);
        proximoLegajo++;
        system("pause");
   }*/
       system("pause");
      //  error = 0;

    //return error;
}

void harcodearTrabajos(eTrabajo trabajo[], int tam, int cantidad){

    int error = 1;

    //int indice;
    //if( mascotas != NULL && tam > 0 && cantidad > 0 && cantidad <= tam){
        for(int i=0; i < tam; i++){
            trabajo[i].isEmpty=0;
            trabajo[i].id=i;
            trabajo[i].idServicio = idsServicios[i];
            trabajo[i].iMascota = idsMascotas[i];
            trabajo[i].fNac.dia = 0;
            trabajo[i].fNac.mes = 0;
            trabajo[i].fNac.anio = 0;

            //indice = buscarPersona(mascotas, tam, proximoLegajo);
            //mostrarMascota(mascotas[indice]);

            //strcpy(mascotas[i].sSer.descripcion, descripcionesServicios[i]);

            //printf("%s",tTip.descripcion);
            //system("pause");

            // mascotas[i].cCol.idColor = idsColores[i];
            //strcpy(mascotas[i].cCol.nombre, nombresColores[i]);

       }
        //mostrarMascotas(mascotas, tam);
        system("pause");
}

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificacion\n");
    printf("d Listar\n");
    printf("e Ordenar\n");
    printf("f Informes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int mostrarColores(eColor colores[], int tam){

    int error = 1;
    int flag = 0;

    if( colores != NULL && tam > 0)
    {
        //system("cls");
        printf(" idColor NombreColor\n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(colores[i].isEmpty == 0)
            {
                mostrarColor(colores[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}



int mostrarMascotas(eMascota mascotas[], int tam){

    int error = 1;
    int flag = 0;

    if( mascotas != NULL && tam > 0)
    {
        //system("cls");
        printf(" Legajo    Nombre    idColor    idTipo    Edad\n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                mostrarMascota(mascotas[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}



int mostrarServicios(eServicio servicios[], int tam){

    int error = 1;
    int flag = 0;

    if( servicios != NULL && tam > 0)
    {
        //system("cls");
        printf(" Legajo Precio  Descripcion\n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(servicios[i].isEmpty == 0)
            {
                mostrarServicio(servicios[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}

int mostrarTrabajos(eTrabajo trabajos[], int tam)
{
    int error = 1;
    int flag = 0;

    if( trabajos != NULL && tam > 0)
    {
        //system("cls");
        printf(" LegajoTrabajo LejajoServicio Legajo  Fecha de nacimiento\n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;
}
void mostrarTrabajo(eTrabajo unTrabajo){

    //printf(" %4d    %10s    %d  %d %d\n", unaMascota.legajo, unaMascota.nombre, unaMascota.idColor, unaMascota.idTipo, unaMascota.edad);

    /*printf(" Legajo    Descripcion\n");
    printf("----------------------------------------------------------\n\n");
*/
    //printf(" %4d    %10s\n",unColor.idColor, unColor.nombre);

   /* printf(" Legajo    Nombre\n");
    printf("----------------------------------------------------------\n\n");

  */  //printf(" %4d    %10s\n", unaMascota.cCol.idColor, unaMascota.cCol.nombre);

    /*printf(" Legajo    Precio    Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    */printf(" %4d    %3d   %10d %02d/%02d/%04d\n",unTrabajo.id, unTrabajo.idServicio, unTrabajo.iMascota, unTrabajo.fNac.dia, unTrabajo.fNac.mes, unTrabajo.fNac.anio);
/*
    printf(" Legajo    Precio Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);*/
}




void mostrarServicio(eServicio unServicio){

    //printf(" %4d    %10s    %d  %d %d\n", unaMascota.legajo, unaMascota.nombre, unaMascota.idColor, unaMascota.idTipo, unaMascota.edad);

    /*printf(" Legajo    Descripcion\n");
    printf("----------------------------------------------------------\n\n");
*/
    //printf(" %4d    %10s\n",unColor.idColor, unColor.nombre);

   /* printf(" Legajo    Nombre\n");
    printf("----------------------------------------------------------\n\n");

  */  //printf(" %4d    %10s\n", unaMascota.cCol.idColor, unaMascota.cCol.nombre);

    /*printf(" Legajo    Precio    Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    */printf(" %4d    %3d   %10s", unServicio.idServicio, unServicio.precio, unServicio.descripcion);
/*
    printf(" Legajo    Precio Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);*/
}

void mostrarColor(eColor unColor){

    //printf(" %4d    %10s    %d  %d %d\n", unaMascota.legajo, unaMascota.nombre, unaMascota.idColor, unaMascota.idTipo, unaMascota.edad);

    /*printf(" Legajo    Descripcion\n");
    printf("----------------------------------------------------------\n\n");
*/
    printf(" %4d    %10s\n",unColor.idColor, unColor.nombre);

   /* printf(" Legajo    Nombre\n");
    printf("----------------------------------------------------------\n\n");

  */  //printf(" %4d    %10s\n", unaMascota.cCol.idColor, unaMascota.cCol.nombre);

    /*printf(" Legajo    Precio    Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);

    printf(" Legajo    Precio Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);*/
}



void mostrarMascota(eMascota unaMascota){

    //eTipo tTip;
    system("pause");
    printf(" %4d    %10s    %d  %d %d\n", unaMascota.legajo, unaMascota.nombre, unaMascota.idColor, unaMascota.idTipo, unaMascota.edad);

    /*printf(" Legajo    Descripcion\n");
    printf("----------------------------------------------------------\n\n");
*/
    //printf(" %4d    %10s\n", tTip.idTipo, tTip.descripcion);

   /* printf(" Legajo    Nombre\n");
    printf("----------------------------------------------------------\n\n");

  */  //printf(" %4d    %10s\n", unaMascota.cCol.idColor, unaMascota.cCol.nombre);

    /*printf(" Legajo    Precio    Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);

    printf(" Legajo    Precio Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);*/
}

int buscarLibre(eMascota mascotas[], int tam) //////para dar de alta
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaMascota(eMascota mascotas[], int tam, int legajo){

    int error = 1;
    int indice;
    eMascota nuevaMascota;

    if(mascotas!=NULL && tam > 0 && legajo > 0)
    {
        indice = buscarLibre(mascotas, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevaMascota.legajo = legajo;
            nuevaMascota.isEmpty = 0;
            printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaMascota.nombre);
            printf("Ingrese idColor: ");
            fflush(stdin);
            scanf("%d", &nuevaMascota.idColor);
            printf("Ingrese idTipo: ");
            scanf("%d", &nuevaMascota.idTipo);
            printf("Ingrese edad: ");
            scanf("%d", &nuevaMascota.edad);

            mascotas[indice] = nuevaMascota;
            error = 0;
        }
    }

    return error;
}

int altaTrabajo(eTrabajo trabajos[], int tam, int legajo){

    int error = 1;
    int indice;
    eTrabajo nuevoTrabajo;

    if(trabajos!=NULL && tam > 0 && legajo > 0)
    {
        indice = buscarLibre(trabajos, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevoTrabajo.id = legajo;
            nuevoTrabajo.isEmpty = 0;
            printf("Ingrese idServicio: ");
            fflush(stdin);
            scanf("%d", &nuevoTrabajo.idServicio);
            printf("Ingrese idServicio: ");
            scanf("%d", &nuevoTrabajo.iMascota);
            printf("Ingrese Fecha de nacimiento: ");
            scanf("%d", &nuevoTrabajo.fNac.dia, &nuevoTrabajo.fNac.mes, &nuevoTrabajo.fNac.anio);

            trabajos[indice] = nuevoTrabajo;
            error = 0;
        }
    }

    return error;
}


int buscarPersona(eMascota mascotas[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].legajo == legajo && mascotas[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int bajaMascota(eMascota mascotas[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;

    if(mascotas != NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE MASCOTA ***\n");
        mostrarMascotas(mascotas, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(mascotas, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una mascota con ese legajo.\n");
        }
        else
        {
            mostrarMascota(mascotas[indice]);
            printf("Confirma baja: 1 - SI 2 - NO");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                mascotas[indice].isEmpty = 1;
                error = 0;
            }else
            {
                error = 2;
            }
        }

    }

    return error;

}
/*
void mostrarFecha(eFecha unaFecha){
    printf("%02d/%02d/%d\n\n",unaFecha.dia, unaFecha.mes, unaFecha.anio);
}
*/

int modificarMascota(eMascota mascotas[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;
//    eFecha nuevaFecha;
    eMascota nuevaMascota;

    if(mascotas != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICACION DE MASCOTA ***\n");
        mostrarMascotas(mascotas, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(mascotas, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            //mostrarMascota(mascotas[indice]);
            nuevaMascota.legajo = legajo;
            //printf("%d", nuevaMascota.legajo);
            printf("\nIngrese nuevo IdTipo: ");
            scanf("%d" , &nuevaMascota.idTipo);

            printf("\nIngrese nueva edad: ");
            scanf("%d" , &nuevaMascota.edad);
            //mostrarMascota(nuevaMascota);

            //printf("%s", nuevaMascota.nombre);
            //printf("%s",mascotas[indice].nombre);
            //char nombre[20];

            nuevaMascota.idColor =  mascotas[indice].idColor;

            strcpy(nuevaMascota.nombre, mascotas[indice].nombre);
            nuevaMascota.isEmpty = mascotas[indice].isEmpty;

            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                mascotas[indice] = nuevaMascota;
                mostrarMascota(nuevaMascota);

                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }

    return error;

}

/*

int ordenarMascotasNombre(eMascota mascotas[], int tam, int criterio)
{
    int error = 1;
    eMascota auxMascota;

    if(mascotas!=NULL && tam>0 && criterio>=0 && criterio<=1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

                if(strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0 && criterio == 1)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if(strcmp(mascotas[i].nombre, mascotas[j].nombre) < 0 && criterio == 0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }

                ///////////////////////////////// OTRA FORMA DE HACERLO //////////////////////

                if((strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0 && criterio == 1) || (strcmp(mascotas[i].nombre, mascotas[j].nombre) < 0 && criterio == 0))
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
        error = 0;
    }

    return 0;

}

int ordenarMascotasSexoAltura(eMascota mascotas[], int tam, int criterioS, int criterioA)
{

    int error = 1;
    eMascota auxMascota;

    if(mascotas!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                //a- comparando personas del mismo sexos desempata la altura
                //b- comparando personas de distinto sexo
                ///////////ORDENAMIENTO POR SEXO ASCENDENTE O DESCENDENTE
                if( mascotas[i].idColor > mascotas[j].idColor && criterioS == 1)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if(mascotas[i].idColor < mascotas[j].idColor && criterioS == 0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if(mascotas[i].idColor == mascotas[j].idColor && mascotas[i].idTipo > mascotas[j].idTipo && criterioA == 1)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if(mascotas[i].idColor == mascotas[j].idColor && mascotas[i].idTipo < mascotas[j].idTipo && criterioA == 0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
        error = 0;
    }

    return 0;

}
*/


void mostrarTipo(eTipo unTipo){

    //printf(" %4d    %10s    %d  %d %d\n", unaMascota.legajo, unaMascota.nombre, unaMascota.idColor, unaMascota.idTipo, unaMascota.edad);

    /*printf(" Legajo    Descripcion\n");
    printf("----------------------------------------------------------\n\n");
*/
    printf(" %4d    %10s\n",unTipo.idTipo, unTipo.descripcion);

   /* printf(" Legajo    Nombre\n");
    printf("----------------------------------------------------------\n\n");

  */  //printf(" %4d    %10s\n", unaMascota.cCol.idColor, unaMascota.cCol.nombre);

    /*printf(" Legajo    Precio    Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);

    printf(" Legajo    Precio Descripcion\n");
    printf("----------------------------------------------------------\n\n");

    printf(" %4d    %3.2f   %10s\n", unaMascota.sSer.id, unaMascota.sSer.precio, unaMascota.sSer.descripcion);*/
}



int mostrarTipos(eTipo tipos[], int tam){

    int error = 1;
    int flag = 0;

    if( tipos != NULL && tam > 0)
    {
        //system("cls");
        printf(" idTipo Descripcion\n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(tipos[i].isEmpty == 0)
            {
                mostrarTipo(tipos[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
