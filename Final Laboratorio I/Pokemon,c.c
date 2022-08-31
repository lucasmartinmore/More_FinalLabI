#include "Pokemon.h"
#include "Validaciones.h"

int menuPrincipal()
{
    system("cls");
    int opcion;
    printf(" ________________________________________________________\n");
    printf("|                >>> LINKEDLIST POKEMON <<<              |\n");
    printf("|________________________________________________________|\n\n");
    printf("|              1) Cargar archivo modo txt                |\n");
    printf("|              2) Eliminar pokemon                       |\n");
    printf("|              3) Imprimir pokemon                       |\n");
    printf("|              4) Filtrar tipo water shiny               |\n");
    printf("|              5) Mapear ataque cargado                  |\n");
    printf("|              6) Informe batalla final                  |\n");
    printf("|              7) Salir                                  |\n");
    printf("|________________________________________________________|\n\n");
    printf("---------------------------------------------------------\n");
    opcion=validarEntero(">>>>   Ingrese opcion: ",">>>>   Reingrese opcion: ",1,7);
    return opcion;
}

Pokemon* pokemon_new()
{
    return(Pokemon*)malloc(sizeof(Pokemon));
}

Pokemon* pokemon_newParam(char* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, char* valorAtaque, char* esVarioColor)
{
	Pokemon* nuevoPokemon=pokemon_new();

	if(nuevoPokemon!=NULL && pokemon_setNumero(nuevoPokemon,atoi(numero)) && pokemon_setNombre(nuevoPokemon, nombre) &&
    pokemon_setTipo(nuevoPokemon, tipo) && pokemon_setTamanio(nuevoPokemon, tamanio) && pokemon_setAtaqueCargado(nuevoPokemon,ataqueCargado)
    && pokemon_setValorAtaque(nuevoPokemon,atoi(valorAtaque)) && pokemon_setEsVarioColor(nuevoPokemon,atoi(esVarioColor)))
	{
		return nuevoPokemon;
	}
	free(nuevoPokemon);
    nuevoPokemon=NULL;

	return nuevoPokemon;
}

void pokemon_delete(Pokemon* this)
{
	free(this);
}

int pokemon_setNumero(Pokemon* this, int numero)
{
	int retorno=0;

	if(this!=NULL && numero>0)
	{
		this->numero=numero;
	    retorno=1;
	}
	return retorno;
}

int pokemon_getNumero(Pokemon* this, int* numero)
{
	int retorno=0;
	if(this!=NULL && numero!=NULL)
	{
	    *numero=this->numero;
		retorno=1;
	}
	return retorno;
}

int pokemon_setNombre(Pokemon* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL && strlen(nombre)<50 && strlen(nombre)>0)
	{
		strcpy(this->nombre, nombre);
	    retorno=1;
	}
	return retorno;
}

int pokemon_getNombre(Pokemon* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL && strlen(nombre)<50 && strlen(nombre)>0)
	{
		strcpy(nombre, this->nombre);
	    retorno=1;
	}
	return retorno;
}

int pokemon_setTipo(Pokemon* this,char* tipo)
{
	int retorno=0;

	if(this!=NULL && tipo!=NULL && strlen(tipo)<50 && strlen(tipo)>0)
	{
		strcpy(this->tipo, tipo);
		retorno=1;
	}
	return retorno;
}

int Pokemon_getTipo(Pokemon* this,char* tipo)
{
	int retorno=0;

	if(this!=NULL && tipo!=NULL && strlen(tipo)<50 && strlen(tipo)>0)
	{
		strcpy(tipo, this->tipo);
		retorno=1;
	}
	return retorno;
}

int pokemon_setTamanio(Pokemon* this,char* tamanio)
{
	int retorno=0;

	if(this!=NULL && tamanio!=NULL && strlen(tamanio)<50 && strlen(tamanio)>0)
	{
		strcpy(this->tamanio, tamanio);
		retorno=1;
	}
	return retorno;
}

int Pokemon_getTamanio(Pokemon* this,char* tamanio)
{
	int retorno=0;

	if(this!=NULL && tamanio!=NULL && strlen(tamanio)<50 && strlen(tamanio)>0)
	{
		strcpy(tamanio, this->tamanio);
		retorno=1;
	}
	return retorno;
}

int pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int retorno=0;

	if(this!=NULL && ataqueCargado!=NULL && strlen(ataqueCargado)<50 && strlen(ataqueCargado)>0)
	{
		strcpy(this->ataqueCargado, ataqueCargado);
		retorno=1;
	}
	return retorno;
}

int Pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int retorno=0;

	if(this!=NULL && ataqueCargado!=NULL && strlen(ataqueCargado)<50 && strlen(ataqueCargado)>0)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		retorno=1;
	}
	return retorno;
}

int pokemon_setValorAtaque(Pokemon* this,int valorAtaque)
{
	int retorno=0;

	if(this!=NULL && valorAtaque>=0)
	{
		this->valorAtaque=valorAtaque;
		retorno=1;
	}
	return retorno;
}

int pokemon_getValorAtaque(Pokemon* this,int* valorAtaque)
{
	int retorno=0;

	if(this!=NULL && valorAtaque!=NULL)
	{
		*valorAtaque=this->valorAtaque;
		retorno=1;
	}
	return retorno;
}

int pokemon_setEsVarioColor(Pokemon* this,int esVarioColor)
{
	int retorno=0;

	if(this!=NULL && (esVarioColor==0 || esVarioColor==1))
	{
		this->esVarioColor=esVarioColor;
		retorno=1;
	}
	return retorno;
}

int pokemon_getEsVarioColor(Pokemon* this,int* esVarioColor)
{
	int retorno=0;

	if(this!=NULL && esVarioColor!=NULL)
	{
		*esVarioColor=this->esVarioColor;
		retorno=1;
	}
	return retorno;
}

int filtrarPokemonTipoWater(void* pElement)
{
    Pokemon* unPokemon=(Pokemon*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unPokemon->tipo,"WATER")==0 && unPokemon->esVarioColor==1) //FILTRO QUE SEA TIPO WATER Y QUE SEA VARIO COLOR
        {
            retorno=1;
        }
    }
    return retorno;


}

void* pokemon_asignarValorAtaque(void* pElement)
{
    Pokemon* unPokemon=(Pokemon*)pElement;
    void* retorno=NULL;
    int nuevoValorAtaque;

    if(pElement!=NULL && (stricmp(unPokemon->tipo,"FIRE")==0 || stricmp(unPokemon->tipo,"GROUND")==0 || stricmp(unPokemon->tipo,"GRASS")==0))
    {
        nuevoValorAtaque=unPokemon->valorAtaque+unPokemon->valorAtaque*0.1;
        pokemon_setValorAtaque(unPokemon,nuevoValorAtaque);
        retorno=(void*)unPokemon;
    }
    return retorno;
}

void* pokemon_buscarPokemonFuertes(void* pElement)
{
    Pokemon* unPokemon=(Pokemon*)pElement;
    void* retorno=NULL;

    if(pElement!=NULL && (stricmp(unPokemon->tipo,"FIRE")==0 && stricmp(unPokemon->tamanio,"XL")==0 && stricmp(unPokemon->ataqueCargado,"LANZALLAMAS")==0 && unPokemon->valorAtaque>80)
    || pElement!=NULL && (stricmp(unPokemon->tipo,"WATER")==0 && stricmp(unPokemon->tamanio,"L")==0 && stricmp(unPokemon->ataqueCargado,"HIDROBOMBA")==0 && unPokemon->valorAtaque>=80))
    {
        retorno=1;
    }
    return retorno;
}

int mostrarPokemon(Pokemon* unPokemon)
{
    int retorno=0;
    if(unPokemon!=NULL)
    {
        printf("       %3d  %12s %12s %12s        %12s          %2d              %2d\n",unPokemon->numero,unPokemon->nombre,unPokemon->tipo,unPokemon->tamanio,
        unPokemon->ataqueCargado,unPokemon->valorAtaque,unPokemon->esVarioColor);
        printf("________________________________________________________________________________________________________\n");
        retorno=1;
    }
    return retorno;
}

