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
#include "passlist.h"
#include <iostream>

Passlist::Passlist(){
	this->preHashed = false;
	this->passesLoaded = false;
}
Passlist::Passlist(std::string passwords[], size_t arrSize){
	this->prevPassesLoaded = false;
	this->prevPreHashed = false;
	this->setPasswords(passwords, arrSize);
}
Passlist::~Passlist(){
	if(this->prevPassesLoaded){
		delete[] this->passwords;
	}
	if(this->prevPreHashed){
		delete[] this->hPasswords;
	}
}
void Passlist::setPasswords(std::string pws[], size_t arrSize){
	if(arrSize<=0){
		throw 1;
	}
	if(this->prevPassesLoaded){
		delete[] this->passwords;
	}
	this->passwords = new std::string[arrSize];
	for(int i=0;((size_t)i < arrSize); i++){
		this->passwords[i] = pws[i];
	}
	this->pwsArrSize = arrSize;
	this->passesLoaded = true;
	this->prevPassesLoaded = true;
	this->preHashed = false;
}
std::string* Passlist::getPasswords(){
	if(passesLoaded == false){
		throw 1;
	}
	return this->passwords;
}
std::string* Passlist::getHashedPasswords(bool preHash){
	if(preHash == false && this->preHashed == false){
		throw 1;
	}
	if(preHash == true && this->preHashed == false){
		this->preHash();
	}
	return this->hPasswords;
}

void Passlist::preHash(){
	if(this->passesLoaded == false) throw 1;
	if(this->preHashed) return;
	if(this->prevPreHashed){
		delete[] this->hPasswords;
	}
	this->hPasswords = new std::string[this->pwsArrSize];
	this->prevPreHashed = true;
	for(int i = 0; (size_t)i < pwsArrSize; i++){
		(this->hPasswords)[i] = hashMsg((this->passwords)[i]);
	}
	this->preHashed = true;
}
