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
