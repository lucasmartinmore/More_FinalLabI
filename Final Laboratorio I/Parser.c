#include "Parser.h"
#include "Pokemon.h"

int parser_PokemonFromText(FILE* pFile, LinkedList* listadoPokemon)
{
    int cantidad;
    Pokemon* unPokemon;
    int retorno=0;
    char buffer[7][50];

    if(pFile!=NULL  && listadoPokemon!=NULL)
    {
        //fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            unPokemon=pokemon_new();
            cantidad=fscanf(pFile,"%[^,] , %[^,], %[^,], %[^,] , %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
            if(cantidad==7)
            {
                unPokemon=pokemon_newParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
                ll_add(listadoPokemon, unPokemon);
                retorno=1;
            }
            else
            {
                break;
            }
        }
    }
    return retorno;
}
