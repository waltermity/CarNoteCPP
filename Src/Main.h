#pragma once
#include "Jarmu.h"
#include "Auto.h"
#include "Motor.h"
#include "Teherauto.h"
#include <fstream>
#include "memtrace.h"
//láncolt lista strukrúrája
struct Jarmuvek
{
	Jarmu* jamru;
	Jarmuvek* next;
};

bool MainMenu(Jarmuvek** a, int* db);
bool JarmuMenu(Jarmu** a);
bool AddJarmuMenu(Jarmuvek** a, int* db);
bool DelJarmuMenu(Jarmuvek** a, int* db);
void DelJarmu(Jarmuvek** a, int* db, int ind);
bool PETCon(bool res);
int ReadNbr(std::string title);
std::string Readtext(std::string title);
void Start(Jarmuvek** a, int* db);
void Stop(Jarmuvek* a, int db);