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
#ifndef PASSLIST_H
#define PASSLIST_H

#include <string>

class Cracker;

class Passlist{
	friend Cracker;
public:
	// Constructor, first one is empty and the other one accepts an array containing a list of passwords
	Passlist();
	Passlist(std::string passwords[], size_t arrSize);

	// Deconstructor, mostly frees memory
	~Passlist();

	// Methods
	// Setters
	void setPasswords(std::string pws[], size_t arrSize);
	// Getters
	std::string* getPasswords();
	std::string* getHashedPasswords(bool preHash);

	// Pre-hash (required before trying to get hashed passwords)
	void preHash();

private:
	// Properties
	size_t pwsArrSize;
	// Tells if there are any passwords actually loaded
	bool passesLoaded;
	// Tells if the passwords are hashed
	bool preHashed;

	bool prevPreHashed;
	bool prevPassesLoaded;

	// Password list arrays
	std::string* passwords;
	std::string* hPasswords;

protected:
	// Calculate the hash
	virtual std::string hashMsg(std::string msg) = 0;
};

#endif // PASSLIST_H
