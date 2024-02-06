#pragma once
#include "Jarmu.h"
#include "memtrace.h"

class Teherauto : public Jarmu {
private:
	int suly;
public:
	Teherauto(std::string tu, int g, std::string n, int s) : Jarmu(tu, g, n), suly(s) {}
	~Teherauto(){}
    void PrintData() override;
	std::string GetJarmuTipus() override;
	void WriteToFileHead(std::ofstream& o) override;
};