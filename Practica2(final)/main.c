#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // libreria para el uso de time()
#include <conio.h>

/*constantes*/
#define TRUE 1
#define FALSE 0

/*tamaños arrays*/
#define MAXIMO_VUELOS 20
#define MAXIMO_RESERVAS 200
#define letraDNI 23


/*array de estructuras para almacenar los vuelos */
struct estructura_datos_vuelo
{
    int clave_unica;
    int numero_vuelo;
    char ciudad_origen [50];
    char ciudad_destino[50];
    char dia_semana[50];
    char hora_salida[50];
    char hora_llegada[50];
    int num_plazas;
    int billetes_reservar;
}datos_vuelo[MAXIMO_VUELOS];

struct estructura_reservas
{
    int numero_dni;
    char letra_dni[1];
    int num_vuelo_reserva;
    char nombre[50];
    char apellido[50];
    float num_max_reservas;
    char validar_billete[1];
}reservas[MAXIMO_RESERVAS];



/*Variables*/
int opcion, opcion_1, opcion_2, opcion_3;
int clave_unica;
int contador_vuelo=1;
int contador_reserva=1;
int dni;
int dni_2;
char validar;
int contador_billete;


/*Subprogramas*/
int Menu();
int Menu_1();
int Menu_2();
int Menu_3();
void Pausa();
void limpiarPantalla();
void limpiarBuffer();
void Pausa();
/*Parte 1 del programa*/
void Agregar_vuelo(struct estructura_datos_vuelo *datos_vuelo,int contador_vuelo);
void Eliminar_vuelo(struct estructura_datos_vuelo *datos_vuelo);
void Listado_vuelos(int contador_vuelo);
void Modificar_vuelo(struct estructura_datos_vuelo *datos_vuelo);
/*parte 2*/
int ValidarDNI(int dni);
char CalcularLetra (int dni);
int verificarNIF(char letra1, char letra2);
void Agregar_reserva(struct estructura_reservas *reservas, int contador_reserva, struct estructura_datos_vuelo *datos_vuelo, int contador_vuelo);
int Dni(int *dni, int contador_reserva);
int Dni_2(int *dni_2, int reserva_modificar);
char LetraDni(int dni, int contador_reserva);
char LetraDni_2(int dni_2, int reserva_modificar);
void Listado_reservas(int contador_reserva);
void Eliminar_reserva(struct estructura_reservas *reservas);
void Modificar_reserva(struct estructura_reservas *reservas);
/*parte 3*/
void VenderBillete(struct estructura_reservas *reservas, int contador_billete);
void SalidaVuelo(struct estructura_reservas *reservas);





int main()
{
    srand(time(NULL));//funcion para crear un numero aleatorio y asi la clave unica de la funcion Agregar_vuelo()

    do
    {
        Menu();//Menu principal
        switch(opcion)
        {

        case 1://Administración de vuelos.


                do
                {
                    Menu_1();//Muno de Administración de vuelos.
                    switch(opcion_1)
                    {

                        case 1://Agregar Vuelo.
                            limpiarPantalla();
                            Agregar_vuelo(datos_vuelo, contador_vuelo);
                            contador_vuelo++;
                            break;

                        case 2://Eliminar Vuelo.
                            limpiarPantalla();
                            Eliminar_vuelo(datos_vuelo);
                            contador_vuelo--;
                            limpiarBuffer();
                            break;


                        case 3://Modificar Vuelo.
                            limpiarPantalla();
                            Modificar_vuelo(datos_vuelo);

                            break;

                        case 4://Listado de Vuelos.
                            limpiarPantalla();
                            Listado_vuelos(contador_vuelo);

                            break;


                        case 0://Volver al menú anterior.
                            limpiarPantalla();
                    }

                }while(opcion_1!=0);

        break;

        case 2://Reservas.

                        do
                {

                    Menu_2();//Menu de Reservas.
                    switch(opcion_2)
                    {

                        case 1://Realizar Reserva.
                            limpiarPantalla();
                            Agregar_reserva(reservas, contador_reserva, datos_vuelo, contador_vuelo);
                            contador_reserva++;
                            break;

                        case 2://Modificar Reserva.
                            limpiarPantalla();
                            Modificar_reserva(reservas);
                            break;


                        case 3://Anular reserva.
                            Eliminar_reserva(reservas);
                            contador_reserva--;
                            break;

                        case 4://Mostrar listado de reserva.
                            limpiarPantalla();
                            Listado_reservas(contador_reserva);
                            break;


                        case 0://Volver al menú anterior.
                            limpiarPantalla();
                    }

                }while(opcion_2!=0);

        break;


        case 3://Confirmación de reservas o Ventas de billetes.
                             do
                {

                    Menu_3();//Menu de Confirmación de reservas o Ventas de billetes.
                    switch(opcion_3)
                    {

                        case 1://Vender un billete.
                            printf("Introduzca el numero de reserva: ");
                            scanf("%d", &contador_billete);
                            VenderBillete(reservas, contador_billete);
                            break;

                        case 2://Salida de un vuelo.
                            SalidaVuelo(reservas);
                            break;


                        case 0://Volver al menú anterior.
                            limpiarPantalla();
                    }

                }while(opcion_3!=0);
        break;


        case 0://Salir del programa
        limpiarPantalla();
        }

    }while(opcion!=0);




    return 0;
}

/*Subprograma para limpiar pantalla*/
void limpiarPantalla()
{
    system("cls");
}


/*Subprograma para limpiar el buffer del teclado*/
void limpiarBuffer()
{
    fflush(stdin);
}


/*Subprograma para realizar una pausa en el programa*/
void Pausa()
{
    getchar();
}


/*Subprograma que muestra el menu principal*/
int Menu()
   {
            limpiarPantalla();
            printf("\t------------------------------------------------\n");
            printf("\t\t\t\t MENU \n");
            printf("\t------------------------------------------------\n\n");
            printf("1.- Administracion de vuelos\n");
            printf("2.- Reservas\n");
            printf("3.- Confirmacion de reservas o Venta de billetes\n");
            printf("0.- Salir \n");
            printf("\n Elija una opci%cn: ",162);
            limpiarBuffer();
                scanf("%d", &opcion);
    return opcion;
   }


   /*Subprograma que muestra el submenu del apartado Administracion de vuelo*/
   int Menu_1()
   {
            limpiarPantalla();
            printf("\t----------------------------------------------------------\n");
            printf("\t\t\t MENU de Administracion de vuelos \n");
            printf("\t-----------------------------------------------------------\n\n");
            printf("1.- Agregar Vuelo\n");
            printf("2.- Eliminar Vuelo\n");
            printf("3.- Modificar Vuelo\n");
            printf("4.- Listado de Vuelos\n");
            printf("0.- Volver al menu anterior\n");
            printf("\n Elija una opci%cn: ",162);
            limpiarBuffer();
            scanf("%d", &opcion_1);
        return opcion_1;
   }

   /*Subprograma que muestra el submenu del apartado de Reservas*/
   int Menu_2()
   {
            limpiarPantalla();
            printf("\t------------------------------------------------\n");
            printf("\t\t\t MEN%c de Reservas \n", 233);
            printf("\t------------------------------------------------\n\n");
            printf("1.- Realizar Reserva\n");
            printf("2.- Modificar Reserva\n");
            printf("3.- Anular reserva\n");
            printf("4.- Mostrar listado de reserva\n");
            printf("0.- Volver al menu anterior\n");
            printf("\n Elija una opci%cn: ",162);
            limpiarBuffer();
            scanf("%d", &opcion_2);
    return opcion_2;
   }


   /*Subprograma que muestra el submenu del apartado Confirmación de reservas o Ventas de billetes.*/
   int Menu_3()
   {
            limpiarPantalla();
            printf("\t---------------------------------------------------\n");
            printf("\t\t\t MEN%c de Venta de billetes \n", 233);
            printf("\t---------------------------------------------------\n\n");
            printf("1.- Vender un billete\n");
            printf("2.- Salida de un vuelo\n");
            printf("0.- Volver al menu anterior\n");
            printf("\n Elija una opci%cn: ",162);
            limpiarBuffer();
            scanf("%d", &opcion_3);
    return opcion_3;
   }

   /*Subprograma que agrega los datos de un vuelo en un array de estructuras, se le pasa la variable contador por referencia para
    tener controlado que posiciones del array estan ocupadas o no, mas adelante se necesitaran para las funciones de borrado,
    modificado y listado. El subprograma consta de un bucle do while del que siempre sale ya que la condicion nunca se va a cumlpir,
    de esta forma solo introduciremos un vuelo cada vez que llamemos a la funcion*/
    void Agregar_vuelo(struct estructura_datos_vuelo *datos_vuelo,int contador_vuelo)
    {
        if(contador_vuelo==MAXIMO_VUELOS)
        {
            printf("No se pueden arregar m%cs vuelos, ya existen 20 vuelos",162);
        }
        else
        {
            do
            {
                printf("\n Numero de plazas del vuelo: ");
                scanf("%d", &datos_vuelo[contador_vuelo].num_plazas);
                limpiarBuffer();

                if(datos_vuelo[contador_vuelo].num_plazas>0 && datos_vuelo[contador_vuelo].num_plazas<=166)
                {
                    validar='t';
                }
                else
                {
                    validar='f';
                    printf("\n\n");
                    printf("El numero introducido es incorrecto, pulse intro para continuar: ");
                    Pausa();
                    printf("\n\n");
                    limpiarBuffer();
                }
            }while(validar=='f');

            srand(time(NULL));
            clave_unica=100000+rand()%(999999+1-100000);
            printf("\n La clave unica es %d. \n\n",clave_unica);
            datos_vuelo[contador_vuelo].clave_unica=clave_unica;
            limpiarBuffer();

            datos_vuelo[contador_vuelo].numero_vuelo=contador_vuelo;
            printf("El numero de vuelo dentro del registro es %d. \n\n",datos_vuelo[contador_vuelo].numero_vuelo);

            printf(" Introduzca la ciudad de origen: ");
            gets(datos_vuelo[contador_vuelo].ciudad_origen);
            limpiarBuffer();

            printf("\n Introduzca la ciudad de destino: ");
            gets(datos_vuelo[contador_vuelo].ciudad_destino);
            limpiarBuffer();

            printf("\nIntroduzca el dia de la semana: ");
            scanf("%s", datos_vuelo[contador_vuelo].dia_semana);
            limpiarBuffer();

            printf("\n Introduzca la hora de salida (Formato 24h: HH:MM): ");
            scanf("%s", datos_vuelo[contador_vuelo].hora_salida);
            limpiarBuffer();

            printf("\n Introduzca la hora de llegada (Formato 24h: HH:MM): ");
            scanf("%s", datos_vuelo[contador_vuelo].hora_llegada);
            limpiarBuffer();

            datos_vuelo[contador_vuelo].billetes_reservar=datos_vuelo[contador_vuelo].num_plazas+(datos_vuelo[contador_vuelo].num_plazas*0.2);
            limpiarBuffer();
        }

    }

   /*Subprograma que sirva para eliminar una estructura del array, la forma de conseguirlo es retrasando una posicion las estructuras
    que tengan un numero de contador mayor, es decir si se quiere eliminar la estructura del indice 2 el indice 3 se convertira en el 2
    sobreescribiendo encima y moviendo sucesivamente las siguienntes*/
    void Eliminar_vuelo(struct estructura_datos_vuelo *datos_vuelo)
    {
        int vuelo_borrar;//el vuelo que desea borrar el usuario
        int i=0;
        int posicion;


        printf("Introduzca el vuelo que desea eliminar: ");
        scanf("%d", &vuelo_borrar);

        for(i=0;i<MAXIMO_VUELOS;i++)
        {
            if(datos_vuelo[i].numero_vuelo==vuelo_borrar)//cuando el contador i es igual al introducido por el usuario se sale del bucle
            {
                posicion=i;
                break;
            }
        }
        for(i=posicion;i<MAXIMO_VUELOS;i++)//este bucle es el que traslado una posicion a la izq todos los elementos que estaban a la derecha del elemento seleccionado
        {
            datos_vuelo[i]=datos_vuelo[i+1];
        }
        limpiarPantalla();
        limpiarBuffer();
        printf("Registro borrado correctamente\n\n");
        printf("Pulse intro para volver al menu principal");
        Pausa();


    }


    /*Subprograma que sirve para modificar un elemento del array, para empezar se pide el vuelo que se desea modificar y a continuacion,
    se piden los nuevos datos del vuelo que se guardaran en la posicion indicada por el usuario*/
    void Modificar_vuelo(struct estructura_datos_vuelo *datos_vuelo)
    {
        int vuelo_modificar;



        printf("Indique el numero de vuelo que desea modificar: ");
        scanf("%d",&vuelo_modificar);
        limpiarBuffer();

        printf("\nIngrese los nuevos datos de vuelo, por favor\n\n");

            do
            {
            printf("\n Numero de plazas del vuelo: ");
            scanf("%d", &datos_vuelo[vuelo_modificar].num_plazas);
            limpiarBuffer();

            if(datos_vuelo[vuelo_modificar].num_plazas>0 && datos_vuelo[vuelo_modificar].num_plazas<=166)
            {
                validar='t';
            }
            else
            {
                validar='f';
                printf("\n\n");
                printf("El numero introducido es incorrecto, pulse intro para continuar: ");
                Pausa();
                printf("\n\n");
                limpiarBuffer();
                }
        }while(validar=='f');

        printf("\nIntroduzca la ciudad de origen: ");
        gets(datos_vuelo[vuelo_modificar].ciudad_origen);
        limpiarBuffer();

        printf("\nIntroduzca la ciudad de destino: ");
        gets(datos_vuelo[vuelo_modificar].ciudad_destino);
        limpiarBuffer();

        printf("\nIntroduzca el dia de la semana: ");
        scanf("%s", datos_vuelo[vuelo_modificar].dia_semana);
        limpiarBuffer();

        printf("\nIntroduzca la hora de salida: ");
        scanf("%s", datos_vuelo[vuelo_modificar].hora_salida);
        limpiarBuffer();

        printf("\nIntroduzca la hora de llegada: ");
        scanf("%s", datos_vuelo[vuelo_modificar].hora_llegada);
        limpiarBuffer();
    }



    /*Subprograma que muestra los datos de todos los vuelos, se separa cada vuelo con una pausa para mayor legibilidad*/
    void Listado_vuelos(int contador_vuelo)
    {
        int mostrar=1;

	for( mostrar=1; mostrar<contador_vuelo; mostrar++ ) {
        printf("El numero de vuelo dentro del registro es %d \n\n", datos_vuelo[mostrar].numero_vuelo );
		printf("La ciudad de origen es: %s \n\n", datos_vuelo[mostrar].ciudad_origen );
		printf("La ciudad de destino es: %s \n\n", datos_vuelo[mostrar].ciudad_destino );
		printf("El dia de la semana es: %s \n\n", datos_vuelo[mostrar].dia_semana );
		printf("La hora de salida es: %s \n\n", datos_vuelo[mostrar].hora_salida );
		printf("La hora de llegada es: %s \n\n" , datos_vuelo[mostrar].hora_llegada );
		printf("El numero de plazas del vuelo es de %d plazas \n\n\n" , datos_vuelo[mostrar].num_plazas );

		printf("Pulse intro para continuar");
		limpiarBuffer();
		Pausa();
		limpiarPantalla();
        }
    }



    /*Subprograma que guarda una reserva en la primera posicion libre del array*/
    void Agregar_reserva(struct estructura_reservas *reservas, int contador_reserva, struct estructura_datos_vuelo *datos_vuelo, int contador_vuelo)
    {
        int contador_comparar=0;
        int contador_auxiliar =0;

        printf("Introduce el numero de vuelo del que quiere realizar la reserva: ");
        scanf("%d", &contador_auxiliar);
        limpiarBuffer();
        for(contador_comparar=1; contador_comparar<MAXIMO_VUELOS;contador_comparar++)//sacar el numero de vuelo
        {
            if(datos_vuelo[contador_comparar].numero_vuelo==contador_auxiliar)
            {
                reservas[contador_reserva].num_vuelo_reserva=contador_auxiliar;//contador_auxiliar saca el numero de vuelo
            }
        }
        if(datos_vuelo[contador_auxiliar].billetes_reservar<=0)
        {
            printf("No quedan plazas, vuelva otro dia");
            Pausa();
        }
        else
        {

            limpiarPantalla();
            printf("Introduzca su nombre: ");
            scanf("%s", reservas[contador_reserva].nombre);
            limpiarBuffer();


            printf("Introduzca su primer apellido: ");
            scanf("%s", reservas[contador_reserva].apellido);
            limpiarBuffer();


            Dni(&dni, contador_reserva);
            limpiarBuffer();

            LetraDni(dni, contador_reserva);
            limpiarBuffer();

            datos_vuelo[contador_auxiliar].billetes_reservar--;
            Pausa();

            limpiarPantalla();
        }


    }


    /*Subprograma que sirva para eliminar una estructura del array, la forma de conseguirlo es retrasando una posicion las estructuras
    que tengan un numero de contador mayor, es decir si se quiere eliminar la estructura del indice 2 el indice 3 se convertira en el 2
    sobreescribiendo encima y moviendo sucesivamente las siguienntes*/
    void Eliminar_reserva(struct estructura_reservas *reservas)
    {
        int reserva_borrar;
        int i=0;
        int posicion;

        printf("Introduzca reserva que desea eliminar: ");
        scanf("%d", &reserva_borrar);

        for(i=0;i<MAXIMO_RESERVAS;i++)
        {
            if(reservas[i].num_vuelo_reserva==reserva_borrar)//cuando el contador i es igual al introducido por el usuario se sale del bucle
            {
                posicion=i;
                break;
            }
        }
        for(i=posicion;i<MAXIMO_RESERVAS;i++)//este bucle es el que traslado una posicion a la izq todos los elementos que estaban a la derecha del elemento seleccionado
        {
            reservas[i]=reservas[i+1];
        }
        limpiarPantalla();
        limpiarBuffer();
        printf("Registro borrado correctamente\n\n");
        printf("Pulse intro para volver al menu principal");
        Pausa();
    }


    /*Subprograma que modifica un registro del array de reservas*/
    void Modificar_reserva(struct estructura_reservas *reservas)
    {
        int reserva_modificar;

        printf("Indique el numero de reserva que desea modificar: ");
        scanf("%d",&reserva_modificar);
        limpiarBuffer();

        printf("\nIngrese los nuevos datos de vuelo, por favor\n\n");

        printf("\nIntroduzca el nombre: ");
        scanf("%s", reservas[reserva_modificar].nombre);
        limpiarBuffer();

        printf("\nIntroduzca el apellido: ");
        scanf("%s", reservas[reserva_modificar].apellido);
        limpiarBuffer();

        Dni_2(&dni_2, reserva_modificar);
        limpiarBuffer();

        LetraDni_2(dni_2, reserva_modificar);
        limpiarBuffer();




    }


    /*Muestra por pantalla el listado de reservas*/
    void Listado_reservas(int contador_reserva)
    {
        int mostrar=1;

        for( mostrar=1; mostrar<contador_reserva; mostrar++)
        {
            printf("El numero de vuelo es: %d \n\n", reservas[mostrar].num_vuelo_reserva);
            printf("El nombre es: %s \n\n", reservas[mostrar].nombre);
            printf("El apellido es: %s \n\n", reservas[mostrar].apellido);
            printf("El dni es: %d \n\n", reservas[mostrar].numero_dni);
            printf("La letra del dni es: %s \n\n\n", reservas[mostrar].letra_dni);

            printf("Pulse intro para continuar");
            limpiarBuffer();
            Pausa();
            limpiarPantalla();
        }

    }


    /*Subprograma para verificar la letra del dni en el subprograma agregar_reserva*/
    char LetraDni(int dni, int contador_reserva)
    {
        char letra;

         do
        {
            printf("\n\n\t Introduzca una letra del NIF: ");
            scanf("%c", &letra);

        }while(!verificarNIF(toupper(letra), CalcularLetra(dni)));

        return reservas[contador_reserva].letra_dni[0]=letra;

    }


    /*subprograma que comprueba los digitos del dni introducido en el subprograma de agregar_reserva*/
    int Dni(int *dni, int contador_reserva)
    {
        char resp[1];

         do
        {
            system("cls");
            printf("\tIntroduzca los d%cgitos del DNI: ",161);
            scanf("%8d", &*dni);
            fflush(stdin);
            do
            {
                printf("\nEsta seguro de que es este su dni: %d (S/N)\n\n",*dni);
                resp[0]=getch();
                if(resp[0]=='n' || resp[0]=='N')
                {
                    printf("Vuelva a ingresar el dni: ");
                    scanf("%8d", &*dni);
                }

            }while(resp[0]=='n' || resp[0]=='N');

        }while(!ValidarDNI(*dni));

        return reservas[contador_reserva].numero_dni=*dni;
    }



    /*Subprograma que comprueba que el dni está entre 0 y el número maximo posible de 8 dígitos.
    Recibe la variable dni (introducido en el subprograma ComprobarNIF()).
    Si el número es correcto retorna TRUE, y en caso contrario retorna FALSE.*/
    int ValidarDNI(int dni)
    {
        if(dni>10000000 && dni<999999999)
        {
            printf("\n\nEl DNI introducido es correcto\n");
            Pausa();
            return TRUE;
        }
        else
        {
            printf("\n\nEl DNI es incorrecto, introd%czcalo de nuevo...\n",163);
            Pausa();
            return FALSE;
        }
    }



    /*Subprograma que recibe como dato la variable dni, realiza el módulo y emplea el resto de esta operación para hallar el valor en el array,
    retornando dicho valor.*/
    char CalcularLetra(int dni)
    {
        char letra;
        int contador;
        char letraNIF[letraDNI]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
        for(contador=0; contador<=letraDNI;contador++)
        {
            if((dni%letraDNI)== contador)
            {
                letra = letraNIF[contador];
            }
        }
        return letra;
    }



    /*Subprograma que recibe como parámetro dos caracteres y comprueba si son iguales.
    En caso de serlo, retorna TRUE, y en caso contrario retorna FALSE.*/
    int verificarNIF(char letra1, char letra2)
    {
        if(letra1 == letra2)
            {
                system("cls");
                printf("\n\nLa letra del NIF es correcta. \n");
                fflush(stdin);
                return TRUE;
            }
            else
            {
                system("cls");
                printf("\n\nLa letra del NIF es incorrecta, por favor introduzca una nueva letra. \n");
                fflush(stdin);
                return FALSE;
            }
}


    /*Subprograma para verificar los digitos del dni en el subprograma modificar_reserva*/
    int Dni_2(int *dni_2, int reserva_modificar)
    {
        char resp[1];

         do
        {
            system("cls");
            printf("\tIntroduzca los d%cgitos del DNI: ",161);
            scanf("%8d", &*dni_2);
            fflush(stdin);
            do
            {
                printf("\nEsta seguro de que es este su dni: %d (S/N)\n\n",*dni_2);
                resp[0]=getch();
                if(resp[0]=='n' || resp[0]=='N')
                {
                    printf("Vuelva a ingresar el dni: ");
                    scanf("%8d", &*dni_2);
                }

            }while(resp[0]=='n' || resp[0]=='N');

        }while(!ValidarDNI(*dni_2));

        return reservas[reserva_modificar].numero_dni=*dni_2;
    }


    /*Subprograma para verificar la letra del dni en el subprograma modificar_reserva*/
    char LetraDni_2(int dni_2, int reserva_modificar)
    {
        char letra;

         do
            {
                printf("\n\n\t Introduzca una letra del NIF: ");
                scanf("%c", &letra);

            }while(!verificarNIF(toupper(letra), CalcularLetra(dni)));

            return reservas[reserva_modificar].letra_dni[0]=letra;
    }

    /*subprograma que comprueba si existe la reserva y en caso de que exista la borra del registro de reservas puesto que ya esta realizada la venta*/
    void VenderBillete(struct estructura_reservas *reservas, int contador_billete)
    {
        int i=0;
        //int posicion;
        //int j=0;

         for(i=0;i<MAXIMO_RESERVAS;i++)
         {
             if(reservas[i].num_vuelo_reserva==contador_billete)//cuando el contador i es igual al introducido por el usuario se sale del bucle
             {
                break;
             }
         }

         if(reservas[contador_billete].validar_billete[0]=='t')
         {
             printf("El billete ya esta vendido, introduzca intro para continuar");
             limpiarBuffer();
             Pausa();
         }
         else
         {
            if(reservas[contador_billete].num_vuelo_reserva==contador_billete)
            {
                printf("Se ha realizado la venta del billete");
                reservas[contador_billete].validar_billete[0]='t';
                limpiarBuffer();
                Pausa();

               /* for(j=0;i<MAXIMO_RESERVAS;j++)
                {
                    if(reservas[j].num_vuelo_reserva==contador_billete)//cuando el contador i es igual al introducido por el usuario se sale del bucle
                    {
                        posicion=j;
                        break;
                    }
                }
                for(j=posicion;j<MAXIMO_RESERVAS;j++)//este bucle es el que traslado una posicion a la izq todos los elementos que estaban a la derecha del elemento seleccionado
                {
                    reservas[j]=reservas[j+1];
                }*/

            }
            else
            {
                printf("No existe la reserva, pulse intro para continuar");
                limpiarBuffer();
                Pausa();
            }
         }

    }


    /*Elimina los elementos del array de reservas con la condicion del numero de vuelo*/
    void SalidaVuelo(struct estructura_reservas *reservas)
    {
        int j=0;
        int contador;
        int contador_auxiliar;

        printf("Introduce el numero de vuelo que va a salir: ");
        scanf("%d", &contador_auxiliar);
        for(contador=0; contador<MAXIMO_VUELOS;contador++)
        {
            if(contador==contador_auxiliar)
            {
                for(j=0;j<MAXIMO_RESERVAS;j++)//este bucle es el que traslado una posicion a la izq todos los elementos que estaban a la derecha del elemento seleccionado
                {
                    reservas[j]=reservas[j+1];
                    reservas[0]=reservas[0+1];
                }
            }
        }
        limpiarBuffer();
        printf("Registro eliminado");
        Pausa();
    }




