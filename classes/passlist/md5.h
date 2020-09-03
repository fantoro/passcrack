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
#ifndef MD5_H
#define MD5_H

#include "../passlist.h"
#include <string>
#include <sstream>
#include <iomanip>

class Md5List: public Passlist {
public:
		Md5List(std::string passwords[], size_t arrSize);
private:
		std::string hashMsg(std::string msg);
};

#endif
