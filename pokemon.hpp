//
//  pokemon.hpp
//  Lab 3
//
//  Created by Nils Streedain on 10/4/21.
//

#ifndef Pokemon_hpp
#define Pokemon_hpp

#include <iostream>

class pokemon {
private:
	int dexNumber;
	std::string name;
	std::string type;
public:
	pokemon();
	pokemon(int, std::string, std::string);
	
	int getDexNumber();
	std::string getName();
	std::string getType();
	
	void setDexNumber(int);
	void setName(std::string);
	void setType(std::string);
	
	void print();
};
#endif /* Pokemon_hpp */
