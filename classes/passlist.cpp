#include "passlist.h"
#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>

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

std::string Passlist::md5Hash(std::string msg){
	unsigned char res[MD5_DIGEST_LENGTH];
	MD5((unsigned char*)msg.c_str(),msg.size(),res);
	std::stringstream sstream;
	for(int i=0;i<MD5_DIGEST_LENGTH;i++){
		sstream << std::hex << std::setfill('0') << std::setw(2) << (int)res[i] << std::dec;
	}
	return sstream.str();
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
		(this->hPasswords)[i] = md5Hash((this->passwords)[i]);
	}
	this->preHashed = true;
}
