//
//  pokemon.cpp
//  Lab 3
//
//  Created by Nils Streedain on 10/4/21.
//

#include "pokemon.hpp"

pokemon::pokemon() {
	dexNumber = 0;
	name = "";
	type = "";
}

pokemon::pokemon(int dexNumber, std::string name, std::string type) {
	this -> dexNumber = dexNumber;
	this -> name = name;
	this -> type = type;
}

int pokemon::getDexNumber() {
	return dexNumber;
}

std::string pokemon::getName() {
	return name;
}

std::string pokemon::getType() {
	return type;
}

void pokemon::setDexNumber(int dexNumber) {
	this -> dexNumber = dexNumber;
}

void pokemon::setName(std::string name) {
	this -> name = name;
}

void pokemon::setType(std::string type) {
	this -> type = type;
}

void pokemon::print() {
	std::cout << "Dex Number: " << dexNumber << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: " << type << std::endl;
}
