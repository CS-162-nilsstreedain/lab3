//
//  pokedex.cpp
//  Lab 3
//
//  Created by Nils Streedain on 10/4/21.
//

#include "pokedex.hpp"
#include "pokemon.hpp"

pokedex::pokedex() {
	trainerName = "";
	numPokemon = 0;
	currAdded = 0;
	allPokemon = new Pokemon_hpp::pokemon[151];
}

pokedex::pokedex(std::string trainerName, int numPokemon) {
	this -> trainerName = trainerName;
	this -> numPokemon = numPokemon;
	currAdded = 0;
	allPokemon = new Pokemon_hpp::pokemon[151];
}

pokedex::pokedex(std::string trainerName, int numPokemon, Pokemon_hpp::pokemon* allPokemon) {
	this -> trainerName = trainerName;
	this -> numPokemon = numPokemon;
	this -> allPokemon = allPokemon;
	currAdded = numPokemon;
}

void pokedex::addPokemon(Pokemon_hpp::pokemon pokemonToAdd) {
	allPokemon[currAdded] = pokemonToAdd;
	currAdded++;
}

std::string pokedex::getTrainerName() {
	return trainerName;
}

int pokedex::getNumPokemon() {
	return numPokemon;
}

Pokemon_hpp::pokemon* pokedex::getAllPokemon() {
	return allPokemon;
}

void pokedex::setTrainerName(std::string trainerName) {
	this -> trainerName = trainerName;
}

void pokedex::print() {
	std::cout << "Trainer name: " << trainerName << std::endl;
	std::cout << "Number of Pokemon: " << numPokemon << std::endl;
	std::cout << "Pokemon:" << std::endl;
	for (int i = 0; i < numPokemon - 1; i++)
		std::cout << "\t" << allPokemon[i].getName() << std::endl;
}
