/*
 * This file is part of Passcrack, a password cracker.
 * Copyright (C) 2020   fantoro
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

#include "md5.h"
#include <openssl/md5.h>
#include <string>

std::string Md5List::hashMsg(std::string msg){
	unsigned char res[MD5_DIGEST_LENGTH];
	MD5((unsigned char*)msg.c_str(),msg.size(),res);
	std::stringstream sstream;
	for(int i=0;i<MD5_DIGEST_LENGTH;i++){
		sstream << std::hex << std::setfill('0') << std::setw(2) << (int)res[i] << std::dec;
	}
	return sstream.str();
}

Md5List::Md5List(std::string passwords[], size_t arrSize)
		: Passlist::Passlist(passwords, arrSize) {}
