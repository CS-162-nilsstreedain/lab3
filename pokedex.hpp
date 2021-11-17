//
//  pokedex.hpp
//  Lab 3
//
//  Created by Nils Streedain on 10/4/21.
//

#ifndef Pokedex_hpp
#define Pokedex_hpp

#include <iostream>
#include "pokemon.hpp"

class pokedex {
private:
	std::string trainerName;
	int numPokemon, currAdded;
	Pokemon_hpp::pokemon* allPokemon;
public:
	pokedex();
	pokedex(std::string, int);
	pokedex(std::string, int, Pokemon_hpp::pokemon*);
	
	void addPokemon(Pokemon_hpp::pokemon);
	
	std::string getTrainerName();
	int getNumPokemon();
	Pokemon_hpp::pokemon* getAllPokemon();
	
	void setTrainerName(std::string);
	
	void print();
};

#endif /* Pokedex_hpp */
