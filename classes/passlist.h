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

	// Calculate the MD5 hash
	std::string md5Hash(std::string msg);
};

#endif // PASSLIST_H
