#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"

typedef struct
{
    int numero;
    char nombre[50];
    char tipo[50];
    char tamanio[50];
    char ataqueCargado[50];
    int valorAtaque;
    int esVarioColor;
}Pokemon;

#endif // POKEMON_H_INCLUDED

int menuPrincipal();
Pokemon* pokemon_new();
Pokemon* pokemon_newParam(char* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, char* valorAtaque, char* esVarioColor);
void pokemon_delete(Pokemon* this);
int pokemon_setNumero(Pokemon* this, int numero);
int pokemon_getNumero(Pokemon* this, int* numero);
int pokemon_setNombre(Pokemon* this,char* nombre);
int pokemon_getNombre(Pokemon* this,char* nombre);
int pokemon_setTipo(Pokemon* this,char* tipo);
int Pokemon_getTipo(Pokemon* this,char* tipo);
int pokemon_setTamanio(Pokemon* this,char* tamanio);
int Pokemon_getTamanio(Pokemon* this,char* tamanio);
int pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado);
int Pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado);
int pokemon_setValorAtaque(Pokemon* this,int valorAtaque);
int pokemon_getValorAtaque(Pokemon* this,int* valorAtaque);
int pokemon_setEsVarioColor(Pokemon* this,int esVarioColor);
int pokemon_getEsVarioColor(Pokemon* this,int* esVarioColor);
int mostrarPokemon(Pokemon* unPokemon);
int filtrarPokemonTipoWater(void* pElement);
int pokemon_tipoWater(LinkedList* listadoPokemon);
void* pokemon_asignarValorAtaque(void* pElement);
int pokemon_eliminarPokemon(LinkedList* listadoPokemon);
void* pokemon_buscarPokemonFuertes(void* pElement);
void pokemon_informeBatalla(LinkedList* listadoPokemon);
