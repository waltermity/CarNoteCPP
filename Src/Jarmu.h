#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Adat.h"
#include <exception>
#include "memtrace.h"
class Jarmu
{
private:
	Adat* adatok;
	int adatszam=0;
protected:
	std::string tulaj;
	int gyartas_ev;
	std::string nev;
	int maxkm=0;
	int osszkiadas=0;
	void PrintDetails();
	void WriteToFileData(std::ofstream& o); //felvitt rekordok kiiras
	void WriteToFileHead(std::ofstream& o, std::string type); //tnev,gyev,jnev,tipus kiirasa
public:
	Jarmu(std::string t, int g, std::string n) : tulaj(t), gyartas_ev(g), nev(n)
	{
		adatok = 0;
	}
	virtual ~Jarmu()
	{
		while (this->adatszam!=0)
		{
			this->RemoveAdat(0);
		}
	}
	std::string GetNev() const { return nev; }
	int Getmaxkm() { return maxkm; }
	int GetOsszkiadas() { return osszkiadas; }
	virtual std::string GetJarmuTipus() = 0;
	void AddAdat(std::string kiadas, int osszeg, int kmallas, std::string megjegyzes);
	void RemoveAdat(int indx);
	virtual void PrintData() = 0;
	virtual void WriteToFileHead(std::ofstream& o) = 0; //jarmuspecifikus kiiras
};