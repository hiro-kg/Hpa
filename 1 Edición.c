/*La Universidad Tecnológica de Panamá tiene planificado implementar 
nuevamente un autobús exclusivamente para los estudiantes que se movilicen 
del campus hacia el sector de Panamá Este y viceversa. Se desea experimentar 
con un prototipo tecnológico la reservación de asientos del autobús. El autobús 
tiene una capacidad máxima de 50 pasajeros, sin embargo, solo podrá ingresar 
30 pasajero. El prototipo deberá almacenar la información del estudiante que 
reserva el puesto por un monto de 45 centavos. El autobús tendrá dos horarios 
de salida del campus universitario (12:30 pm y 3:30 pm). (Funcionamiento para un día).*/
/* Hacer un menú de opciones (Reservar bus: 12:30 / 3:30), Ver lista de pasajeros del bus 12:30 / 03:30, y salir del programa.
*Para guardar la información de cada pasajero, utilizaremos 2 arreglos de estructuras, la estructura contendrá (nombre y apellido, ID, estado de compra)
*Utilizaremos un switch dentro de un ciclo infinito do-while para que el programa no se cierre hasta que se le ordene.
*Utilizaremos condicionales para evaluar si ya se alcanzó el límite de pasajeros
*Cosas que faltan:
-Mejorar el sistema de pago
-Agregar la posibilidad de editar los arreglos (ej: quitar una persona para agregar otra)
-Agregar la posibilidad de que se puedan reservar más de un puesto en la opción de reservar puesto
-La interfaz gráfica

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombreApellido[30];
    char cedulaOpasaporte[20];
    char estadoDecompra[10];
}bus;

void bienvenidos();
int imprimirMenu(void);
void formularioBus(bus horaDelBus[], int k);
void mensajeBusLleno(int g);
void imprimirListaPasajeros(int g, int *i, bus horaDelBus[]);

int main(){
    //Bloque de declarativa de variables
    
    /*Varibles del bus de las 12:30*/
    bus doceYmedia[30];
    int i = 0;
    
    /*Varibles del bus de las 03:30*/
    bus tresYmedia[30];
    int k = 0;
    
    /*Otras variables*/
    int respuesta = 0, y = 1, g;
    
    //Bloque de Instrucciones
    do{
        respuesta = imprimirMenu();
        
        if (respuesta != 1 && respuesta != 2 && respuesta != 3 && respuesta != 4 && respuesta != 5)
        {
            printf("\n\t\tValor no valido");
            printf("\n\nPresione cualquier tecla para regresar al menu principal ->");  
            getch();
            system("cls");
        }
        else
        {
            switch(respuesta)
            {
                case 1:
                    g = 12;
                    (i < 30) ? formularioBus(doceYmedia, i) : mensajeBusLleno(g);
                    i++;
                    break;
                case 2:
                    g = 03;
                    (k < 30) ? formularioBus(tresYmedia, k) : mensajeBusLleno(g);
                    k++;
                    break;
                case 3:
                    g = 12;
                    imprimirListaPasajeros(g, &i, doceYmedia);
                    break;
                case 4:
                    g = 03;
                    imprimirListaPasajeros(g, &k, tresYmedia);
                    break;
                case 5:
                    return 0;
                    break;  
            }
        }
        
    }while(y == 1);
    
    return 0;
}
//Bloque de Bienvenida
void Bienvenida()
{
	int via;
	printf("\t\tBienvenidos al Sistema de Buses");
    printf("\n\t      ___________________________________\n\n");
    printf("Viaja a donde sea con tu bus confiable, siempre a tiempo nunca tarde\n\n");
    printf("\t\t\tDesea viajar?\n\n");
    printf("\tSi -> (1)			No-> (2)\n");
    scanf("%d", &via);
	system("cls");
}

//Bloque del Menu
int imprimirMenu(void)
{
    int via, resp;
    
    printf("\t\tBienvenidos al Sistema de Buses");
    printf("\n\t      ___________________________________\n\n");
    printf("Viaja a donde sea con tu bus confiable, siempre a tiempo nunca tarde\n\n");
    printf("\t\t\tDesea viajar?\n\n");
    printf("\tSi -> (1)			No-> (2)\n");
    scanf("%d", &via);
    if (via == 1)
    {
    	
	}
    //printf("\t\tMenu Principal\n");
    printf("\nReservar un asiento -> 12:30 (1) || 3:30 (2)\n");
    printf("Ver pasajeros del bus 12:30 -> (3) ");
    printf("\nVer pasajeros del bus 03:30 -> (4) ");
    printf("\nCerrar el programa -> (5) \n");
    printf("\nEligir opcion: ");
    scanf("%d", &resp);
    return (resp);
}

void formularioBus(bus horaDelBus[], int k)
{
    int edp;
    fflush(stdin);
    printf("\nIngrese su nombre y apellido: ");
    fgets(horaDelBus[k].nombreApellido,30,stdin);
    printf("\nIngrese su cedula o pasaporte: ");
    fgets(horaDelBus[k].cedulaOpasaporte,30,stdin);
    printf("\nIngrese el estado de compra Pago (1) Moroso (2): ");
    scanf("%d", &edp);
    if (edp == 1)
    {
        strcpy(horaDelBus[k].estadoDecompra,"Pago");
    }
    else
        if (edp == 2)
        {
            strcpy(horaDelBus[k].estadoDecompra,"Moroso");
        }
    system("cls");
}

void mensajeBusLleno(int g)
{
    printf("\n\t\tEl bus de las %d:30 ya esta lleno", g);
    printf("\n\nPresione cualquier tecla para regresar al menu principal ->");
    getch();
    system("cls");
}

void imprimirListaPasajeros(int g, int *i, bus horaDelBus[])
{
    int h;
    printf("\n\t\tPasajeros del bus de las %d:30\n", g);
    for (h = 0; h < *i; h++)
    {
        printf("\n\nPasajero %d\nNombre: %sCedula/pasaporte: %sEstado de compra: %s", h+1, horaDelBus[h].nombreApellido, horaDelBus[h].cedulaOpasaporte, horaDelBus[h].estadoDecompra);
    }
    printf("\n\nPresione cualquier tecla para regresar al menu principal ->");
    getch();
    system("cls");
}
