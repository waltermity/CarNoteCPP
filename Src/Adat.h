#pragma once
#include <string>
#include "memtrace.h"
struct Adat
{
	std::string kiadas;
	int osszeg;
	int kmallas;
	std::string megjegyzes;
	Adat* next;
};
