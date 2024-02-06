#pragma once
#include "Jarmu.h"
#include "memtrace.h"
class Motor : public Jarmu {
private:
	int kobcenti;
public:
	Motor(std::string tu, int g, std::string n, int k) : Jarmu(tu, g, n), kobcenti(k) {}
	~Motor(){}
    void PrintData() override;
	std::string GetJarmuTipus() override;
	void WriteToFileHead(std::ofstream& o) override;
};