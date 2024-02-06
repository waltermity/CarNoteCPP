#pragma once
#include "Jarmu.h"
#include "memtrace.h"

class Auto : public Jarmu {
private:
	int utasszam;
	std::string tipus;
public:
    Auto(std::string tu, int g, std::string n, int u, std::string ti) : Jarmu(tu, g, n), utasszam(u), tipus(ti) {}
    void PrintData() override;
	std::string GetJarmuTipus() override;
	void WriteToFileHead(std::ofstream& o) override;
};