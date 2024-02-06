#include "Teherauto.h"
void Teherauto::PrintData() {
	std::cout << this->nev << " - Teherautó" << std::endl;
	std::cout << "Tulajdonos: " << this->tulaj << std::endl;
	std::cout << "Gyartas eve: " << this->gyartas_ev << std::endl;
	std::cout << "Kilometerallas: " << this->maxkm << " km" << std::endl;
	std::cout << "Osszeskiadas: " << this->osszkiadas << " Ft" << std::endl;
	std::cout << "Sulya: " << this->suly << " kg" << std::endl;
	std::cout << "Rogzitett adatok:" << std::endl;
	this->PrintDetails();
}

std::string Teherauto::GetJarmuTipus() {
	return "Teherauto";
}
void Teherauto::WriteToFileHead(std::ofstream& o) {
	Jarmu::WriteToFileHead(o, "t");
	o << suly << std::endl;
	Jarmu::WriteToFileData(o);
}