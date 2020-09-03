/*
 * This file is part of Passcrack, a password cracker.
 * Copyright (C) 2019   fantoro
 *
 * Passcrack is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the license, or
 * (at your option) any later version.
 *
 * Passcrack is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Passcrack. If not, see <https://www.gnu.org/license/>
*/
#ifndef CRACKER_H
#define CRACKER_H

#include <string>

class Passlist;

class Cracker{
public:
	// Constructors
	Cracker();
	Cracker(std::string hash);
	Cracker(Passlist* plist);
	Cracker(std::string hash, Passlist *plist);

	// Setters
	void setHashToCrack(std::string hash);
	void setDictionaryPtr(Passlist *plist);
	
	// Getters
	std::string getHashToCrack();
	Passlist* getDictionaryPtr();

	// Methods
	/* Cracker::crack(std::string *result)
	 * ==================================
	 * If a password has been found it 
	 * returns true and writes the password
	 * into the string pointed by *result.
	*/
	bool crack(std::string *result);
private:
	// Properties
	Passlist* pwlist;
	std::string hashtc;
	bool hashLoaded;
	bool pwlistLoaded;
};

#endif // CRACKER_H
