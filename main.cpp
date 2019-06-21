/*
 * This file is part of Passcrack, an MD5 password cracker.
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
 * along with Passcrack. If not, see <https://www.gnu.org/licenses/>
*/

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>
#include "classes/passlist.h"
#include "classes/cracker.h"

std::string *passwords, result;
size_t passwordsSize;

int main(int argc, char* argv[]){
	if(argc < 3) {
		std::cout << std::endl
			  << " ==== [ " << argv[0] << " help ] ==== " << std::endl
			  << " Usage:\n " << argv[0] << " [MD5HASH] [PASSWORD1... [PASSWORDN]]\n " << argv[0] << " [MD5HASH] [DICTIONARYFILE]" << std::endl << std::endl
			  << " Examples:\n " << argv[0] << " e10adc3949ba59abbe56e057f20f883e 1234 4321 123 321 1337 123456 test password password1 password2 password3 password123 password123321\n " << argv[0] << " e10adc3949ba59abbe56e057f20f883e ./passwords.txt" << std::endl
			  << "\n Passcrack   Copyright (C) 2019   fantoro" << std::endl
			  << " This program comes with ABSOLUTELY NO WARRANTY; This is free" << std::endl
			  << " software, and you are welcome to redistribute it under certain" << std::endl
			  << " conditions; refer to the GNU General Public License 3 included" << std::endl
			  << " with your copy of this software for details, if you haven't" << std::endl
			  << " received a copy of the GNU General Public License 3 with your" << std::endl
			  << " copy of this software, see <https://www.gnu.org/licenses/>" << std::endl;
		return 1;
	}
	bool argPws = true;
	int fd = open(argv[2],O_RDONLY);
	if(fd!=-1){
		struct stat fdstat;
		int fstato = fstat(fd,&fdstat);
		close(fd);
		if(fstato!=-1){
			argPws = false;
			std::fstream filestream1;
			filestream1.open(argv[2],std::fstream::in);
			passwordsSize = 0;
			while(std::getline(filestream1,result)){
				passwordsSize++;
			}
			passwords = new std::string[passwordsSize];
			std::fstream filestream;
			filestream.open(argv[2],std::fstream::in);
			for(int i = 0; (size_t)i < passwordsSize; i++){
				std::getline(filestream,result);
				passwords[i] = result;
			}
		}
	}
	if(argPws){
		passwordsSize = argc-1;
		passwords = new std::string[passwordsSize];
		for(int i=2; i < argc; i++){
			passwords[i-2] = argv[i];
		}
	}
	Cracker cracker(argv[1]);
	Passlist pwlist(passwords, passwordsSize);
	delete [] passwords;
	pwlist.preHash();
	cracker.setDictionaryPtr(&pwlist);
	bool success = cracker.crack(&result);
	if(!success){
		std::cout << "Couldn't find a matching password with the provided dictionary" << std::endl;
		return 1;
	}
	std::cout << "Found a matching password: \"" << result << "\"" << std::endl;
	return 0;
}
