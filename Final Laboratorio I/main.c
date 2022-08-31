#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemon.h"
#include "Validaciones.h"
#include "Controller.h"

int main()
{
    LinkedList* listadoPokemon=ll_newLinkedList();
    char nombreArchivo[50];
    int banderaCarga=0;
    int seguir=0;

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(banderaCarga==0)
            {
                validarCadena("Ingrese nombre del archivo(Ej:Data_Pokemones.csv): ","Error, reingrese nombre del archivo(Ej:Data_Pokemones.csv): ",50,nombreArchivo);
                if(More_Pokemon_LoadFromText(nombreArchivo,listadoPokemon))
                {
                    banderaCarga=1;
                }
            }
            else
            {
                printf("\n--------- El archivo ya se encuentra cargado ! ---------  \n");
            }
            break;
        case 2:
            if(banderaCarga)
            {
                More_Pokemon_RemoverPokemon(listadoPokemon);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de eliminar pokemon ! ---------  \n");
            }
            break;
        case 3:
            if(banderaCarga)
            {
                More_Pokemon_MostrarPokemones(listadoPokemon);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de mostrar pokemon ! ---------  \n");
            }
            break;
        case 4:
            if(banderaCarga)
            {
                More_Pokemon_FiltrarTipoWaterShiny(listadoPokemon);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de filtrar los tipos de pokemones ! ---------  \n");
            }
            break;
        case 5:
            if(banderaCarga)
            {
                More_Pokemon_MapeooValoresAtaque(listadoPokemon);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de asignar los valores de ataque ! ---------  \n");
            }
            break;
        case 6:
            if(banderaCarga)
            {
                More_Pokemon_InformeBatallaFinal(listadoPokemon);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de buscar pokemones ! ---------  \n");
            }
            break;
        case 7:
            ll_deleteLinkedList(listadoPokemon);
            seguir=1;
            break;
        }
        system("pause");
    }while(seguir!=1);

    return 0;
}



