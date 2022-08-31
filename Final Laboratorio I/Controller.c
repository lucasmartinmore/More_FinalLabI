#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"
#include "parser.h"
#include "Pokemon.h"

int More_Pokemon_LoadFromText(char* path, LinkedList* ListadoPokemon)
{
    int retorno=0;
    FILE* pFile=NULL;

    if(path!=NULL && ListadoPokemon!=NULL)
    {
        pFile=fopen(path, "r");
        if(pFile!= NULL)
        {
            if(parser_PokemonFromText(pFile,ListadoPokemon))
            {
                retorno=1;
                printf("\n--------- Carga de archivo realizada exitosamente ! ---------  \n");
            }
            else
            {
                printf("\n--------- El archivo no se pudo cargar correctamente ! ---------  \n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\n--------- Error, el archivo no pudo abrirse o no fue encontrado ! ---------  \n");
        }
    }
    return retorno;
}

int More_Pokemon_GuardarTexto(char* path, LinkedList* listadoPokemon)
{
    FILE* pFile=fopen(path,"w") ;
    int tam =  ll_len(listadoPokemon);
    Pokemon* unPokemon;
    int retorno=0;

    if(pFile!=NULL)
    {
        fprintf(pFile,"numero,nombre,tipo,tamaño,ataqueCargado,valorAtaque,esVarioColor\n");
        for(int i=0; i<tam; i++)
        {
            unPokemon=(Pokemon*)ll_get(listadoPokemon,i);
            if(unPokemon!=NULL)
            {
                fprintf(pFile,"%d,%s,%s,%s,%s,%d,%d\n", unPokemon->numero,unPokemon->nombre,unPokemon->tipo,unPokemon->tamanio,
                unPokemon->ataqueCargado,unPokemon->valorAtaque,unPokemon->esVarioColor);
                retorno=1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int More_Pokemon_MostrarPokemones(LinkedList* listadoPokemon)
{
    int retorno=0;
    Pokemon* unPokemon=NULL;
    int tam=ll_len(listadoPokemon);
    int flagBanderaPokemon=0;

	if(listadoPokemon!=NULL)
	{
	    retorno=1;
		printf(" _______________________________________________________________________________________________________\n");
		printf("|                                     >>> LISTADO DE POKEMONES <<<                                      |\n");
		printf("|_______________________________________________________________________________________________________|\n\n");
		printf("|      Num       Nombre         Tipo         Tamaño        AtaqueCargado    ValorAtaque     esVarioColor|\n");
		printf("|_______________________________________________________________________________________________________|\n");

		for(int i=0; i<tam; i++)
		{
		    unPokemon=(Pokemon*)ll_get(listadoPokemon,i);
		    if(unPokemon!=NULL)
            {
                mostrarPokemon(unPokemon);
                flagBanderaPokemon=1;
            }
		}
	}

    if(flagBanderaPokemon==0)
    {
        printf("\n--------- No se encuentran pokemones cargados ! ---------  \n");
    }
	return retorno;
}

int More_Pokemon_FiltrarTipoWaterShiny(LinkedList* listadoPokemon)
{
    int retorno=0;
    LinkedList* listaNuevaFiltrada=NULL;
    listaNuevaFiltrada=ll_filter(listadoPokemon,filtrarPokemonTipoWater);
    More_Pokemon_MostrarPokemones(listaNuevaFiltrada);
    retorno=1;

    return retorno;
}

void More_Pokemon_MapeooValoresAtaque(LinkedList* listadoPokemon)
{
    ll_map(listadoPokemon,pokemon_asignarValorAtaque);
    printf("\n--------- Se asigno los nuevos valores de ataque correctamente ! ---------  \n");
}

void More_Pokemon_InformeBatallaFinal(LinkedList* listadoPokemon)
{
    if(listadoPokemon!=NULL)
    {
        int cantidad=ll_count(listadoPokemon,pokemon_buscarPokemonFuertes);
        if(cantidad>=3)
        {
            printf("\n--------- Hemos ganado la batalla ya que contamos con un equipo de %d pokemones fuertes! ---------  \n",cantidad);
        }
        else
        {
            printf("\n--------- Hemos perdido la batalla ya que solo contamos con %d pokemones fuertes! ---------  \n",cantidad);
        }
    }
}

int More_Pokemon_RemoverPokemon(LinkedList* listadoPokemon)
{
	int retorno=0;
	int idPokemon;
	Pokemon* unPokemon=NULL;

	if(listadoPokemon!=NULL)
	{
	    More_Pokemon_MostrarPokemones(listadoPokemon);
	    idPokemon=validarEntero("\nIngrese id del pokemon a eliminar: ","\nError. Reingrese id del pokemon a eliminar: ",1,151);
	    for(int i=0; i<ll_len(listadoPokemon); i++)
	    {
	        unPokemon=ll_get(listadoPokemon, i);
            if(unPokemon->numero==idPokemon)
            {
                mostrarPokemon(unPokemon);
                printf("\n--------- Pokemon eliminado exitosamente ! ---------  \n\n");
                ll_remove(listadoPokemon, i);
                retorno=1;
                break;
            }
	    }
	}
	return retorno;
}

