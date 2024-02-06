#include "Jarmu.h"

void Jarmu::AddAdat(std::string kiadas, int osszeg, int kmallas, std::string megjegyzes) {
	
	if (osszeg < 0)
		throw std::out_of_range("Az osszegnek legalabb 0-nak kell lennie!");
	if (kmallas < 0)
		throw std::out_of_range("Az kilometerallasnak legalabb 0-nak kell lennie!");
	
	Adat* n = new Adat;
	n->kiadas = kiadas;
	n->kmallas = kmallas;
	n->megjegyzes = megjegyzes;
	n->osszeg = osszeg;
	n->next = this->adatok;
	this->adatok = n;
	this->osszkiadas += osszeg;
	this->maxkm = kmallas;
	this->adatszam++;
}

void Jarmu::RemoveAdat(int indx) {
	if (this->adatszam == 0)
		throw std::out_of_range("Meg nincs adat felveve!");
	else if (indx < 0)
		throw std::out_of_range("A sorszamnak legalabb 1-nek kell lennie!");
	else if (indx >= this->adatszam) 
		throw std::out_of_range("A sorszamnak kisebbnek kell lennie mint " + std::to_string(this->adatszam + 1) + "!");


	int curr_index = 0;
	Adat* q = 0;
	Adat* p = this->adatok;
	while (indx != curr_index)  //torolni kivant elemhez tekerunk p-vel
	{
		q = p;
		p = p->next;
		curr_index++;
	}
	if (q == 0) //első elemet töröljük
		this->adatok = p->next;
	else
		q->next = p->next;
	this->osszkiadas -= p->osszeg;
	if (this->adatszam == 1)
		this->maxkm = 0;
	else if (this->maxkm == p->kmallas) {
		this->maxkm = this->adatok->kmallas;
	}
	delete p;
	this->adatszam--;
}

void Jarmu::PrintDetails() {
	Adat* p = this->adatok;
	int ind = 1;
	if (p == 0) {
		std::cout << "\tMeg nincs rogzitett adat!" << std::endl;;
	}
	else {
		while (p != 0)
		{
			std::cout << "\t" << ind << ". " << p->kiadas << " \t " << p->kmallas << " km \t " << p->osszeg << " Ft \t " << p->megjegyzes << std::endl;
			p = p->next;
			ind++;
		}
	}
	
}
void Jarmu::WriteToFileHead(std::ofstream& o, std::string type) {
	o << type << std::endl;
	o << tulaj << std::endl;
	o << gyartas_ev << std::endl;
	o << nev << std::endl;
}
void Jarmu::WriteToFileData(std::ofstream& o) {
    //legvégére megyek, egyel bejjebb teszed,kiirom index-1
	o << adatszam << std::endl;
	int curr_ind = adatszam;
	while (curr_ind != 0)
	{
		Adat* p = adatok;
		for (int i = 0; i < curr_ind - 1; i++)
		{
			p = p->next;
		}
		curr_ind--;
		o << p->kiadas << std::endl;
		o << p->osszeg << std::endl;
		o << p->kmallas << std::endl;
		o << p->megjegyzes << std::endl;
	}
}