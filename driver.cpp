//
//  driver.cpp
//  Lab 3
//
//  Created by Nils Streedain on 10/4/21.
//

#include <iostream>
#include <fstream>
#include <string>

#include "pokedex.hpp"
#include "pokemon.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	
	int numPokemon, currentDex;
	string currentLine, currentName, currentType;
	ifstream f("./inputs.txt");
	
	f >> numPokemon;
	pokedex pokedex("Nils", numPokemon);
	
	if (f.is_open()) {
		while (!f.eof()) {
			f >> currentDex;
			f >> currentName;
			f >> currentType;
			
			pokemon currentPokemon(currentDex, currentName, currentType);
			pokedex.addPokemon(currentPokemon);
		}
		
		f.close();
		pokedex.print();
	} else
		cout << "Error: File not opened" << endl;

	return 0;
}
