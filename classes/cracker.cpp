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
#include "cracker.h"
#include "passlist.h"

Cracker::Cracker(){
	this->hashLoaded = false;
	this->pwlistLoaded = false;
}
Cracker::Cracker(std::string hash){
	this->hashtc = hash;
	this->hashLoaded =  true;
	this->pwlistLoaded = false;
}
Cracker::Cracker(Passlist *plist){
	this->pwlist = plist;
	this->pwlistLoaded = true;
	this->hashLoaded = false;
}
Cracker::Cracker(std::string hash, Passlist *plist){
	this->hashtc = hash;
	this->hashLoaded = true;
	this->pwlist = plist;
	this->pwlistLoaded = true;
}

void Cracker::setHashToCrack(std::string hash){
	this->hashtc = hash;
	this->hashLoaded = true;
}
void Cracker::setDictionaryPtr(Passlist *plist){
	this->pwlist = plist;
	this->pwlistLoaded = true;
}

std::string Cracker::getHashToCrack(){
	return this->hashtc;
}
Passlist* Cracker::getDictionaryPtr(){
	return this->pwlist;
}

bool Cracker::crack(std::string *result){
	if(pwlistLoaded==false){ return false; }
	if(hashLoaded==false) { return false; }
	if(pwlist->passesLoaded==false) { return false; }
	if(pwlist->preHashed==false) { return false; }
	std::string* pwords = pwlist->getPasswords();
	std::string* hPwords = pwlist->getHashedPasswords(true);
	for(int i=0;(size_t) i < pwlist->pwsArrSize;i++){
		if(this->hashtc == hPwords[i]){
			*result = pwords[i];
			return true;
		}
	}
	return false;
}
