#include "Auto.h"


std::string Auto::GetJarmuTipus() {
	return "Auto";
}

void Auto::PrintData() {
	std::cout << this->nev << " - Auto - " << this->tipus << std::endl;
	std::cout << "Tulajdonos: " << this->tulaj << std::endl;
	std::cout << "Gyartas eve: " << this->gyartas_ev << std::endl;
	std::cout << "Kilometerallas: " << this->maxkm << " km" << std::endl;
	std::cout << "Osszeskiadas: " << this->osszkiadas << " Ft" << std::endl;
	std::cout << "Utasok maximalis szama: " << this->utasszam << " db" << std::endl;
	std::cout << "Rogzitett adatok:" << std::endl;
	this->PrintDetails();
}
void Auto::WriteToFileHead(std::ofstream& o) {
	Jarmu::WriteToFileHead(o, "a");
	o << tipus << std::endl;
	o << utasszam << std::endl;
	Jarmu::WriteToFileData(o);
}