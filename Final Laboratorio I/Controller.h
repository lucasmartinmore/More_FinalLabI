#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

//int pokemon_loadFromText(char* path, LinkedList* listadoPokemon);
int More_Pokemon_LoadFromText(char* path, LinkedList* ListadoPokemon);
//int pokemon_guardarTexto(char* path, LinkedList* listadoPokemon);
int More_Pokemon_GuardarTexto(char* path, LinkedList* listadoPokemon);
//int pokemon_eliminarPokemon(LinkedList* listadoPokemon)
int More_Pokemon_RemoverPokemon(LinkedList* listadoPokemon);
//int mostrarPokemones(LinkedList* listadoPokemon);
int More_Pokemon_MostrarPokemones(LinkedList* listadoPokemon);
//int pokemon_tipoWater(LinkedList* listadoPokemon);
int More_Pokemon_FiltrarTipoWaterShiny(LinkedList* listadoPokemon);
//armar funcion para mapaear los valores de ataque ll_map(listadoPokemon,pokemon_asignarValorAtaque);
void More_Pokemon_MapeooValoresAtaque(LinkedList* listadoPokemon);
//void pokemon_informeBatalla(LinkedList* listadoPokemon);
void More_Pokemon_InformeBatallaFinal(LinkedList* listadoPokemon);

