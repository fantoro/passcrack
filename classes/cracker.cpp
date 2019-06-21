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
