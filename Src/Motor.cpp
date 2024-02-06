#include "Motor.h"
void Motor::PrintData() {
	std::cout << this->nev << " - Motor" << std::endl;
	std::cout << "Tulajdonos: " << this->tulaj << std::endl;
	std::cout << "Gyartas eve: " << this->gyartas_ev << std::endl;
	std::cout << "Kilometerallas: " << this->maxkm << " km" << std::endl;
	std::cout << "Osszeskiadas: " << this->osszkiadas << " Ft" << std::endl;
	std::cout << "Kobcenti: " << this->kobcenti << " cm3" << std::endl;
	std::cout << "Rogzitett adatok:" << std::endl;
	this->PrintDetails();
}

std::string Motor::GetJarmuTipus() {
	return "Motor";
}

void Motor::WriteToFileHead(std::ofstream& o) {
	Jarmu::WriteToFileHead(o, "m");
	o << kobcenti << std::endl;
	Jarmu::WriteToFileData(o);
}