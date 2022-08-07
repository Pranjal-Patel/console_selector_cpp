#include <Windows.h>
#include <vector>
#include <conio.h>
#include <string>
#include <iostream>

#pragma once
#ifndef MENU_H

#define MENU_H
#define HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

namespace menu
{
	namespace
	{
		struct arrow_key
		{
			char up = 'H', down = 'P';
		};
	}
	int draw(std::vector<std::string> options);
}

#endif
