#include <iostream>
#include "Main.h"
#include "Tesztek.h"

int main()
{

	Jarmuvek* jarmuvek = 0;
	int jdb = 0;
	
	Start(&jarmuvek, &jdb);
	while(MainMenu(&jarmuvek, &jdb));
	Stop(jarmuvek, jdb);

	while (jarmuvek != 0)
	{
		DelJarmu(&jarmuvek, &jdb, 0);
	}
    mytests();
    return 0;
}
//fomenu,--@param lista&jarmudarabszam
bool MainMenu(Jarmuvek** a, int* db) {
	system("CLS");
	std::cout << "============================================" << std::endl;
	std::cout << "                  CAR NOTE                  " << std::endl;
	std::cout << "============================================" << std::endl;
	Jarmuvek* p = (*a);
	if (p == 0) {
		std::cout << "Nincs meg jarmu a listaban!" << std::endl;
	}

	int i = 1;
	while (p != 0)
	{
		std::cout << "\t" << i << ". " << p->jamru->GetNev() << std::endl;
		p = p->next;
		i++;
	}
	std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;
	std::cout << "(sorszam) Jarmu kivalasztas" << std::endl;
	std::cout << "(h) Jarmu hozzaadasa" << std::endl;
	std::cout << "(t) Jarmu eltavolitasa" << std::endl;
	std::cout << "(k) Kilepes" << std::endl;
	std::cout << "Valasztott menu: ";

	std::string inp;
	std::getline(std::cin, inp);

	if (inp == "h")
		while (AddJarmuMenu(a, db));
	else if (inp == "t")
		while(DelJarmuMenu(a, db));
	else if (inp == "k")
		return false;
	else {
		int b;
		try
		{
			b = std::stoi(inp);
		}
		catch (const std::exception&)
		{
			std::cout << "Nem megfelelo menupont! Add meg ujra!" << std::endl;
			return PETCon(false);
		}
		if ((*db) == 0) {
			std::cout << "Nincs meg jarmu a listaban igy sorszam nem adhato meg! Vegyel fel elobb jarmuvet!" << std::endl;
			return PETCon(false);
		}
		else if (b < 1 || b > (*db)) {
			std::cout << "Ez a sorszam nem letezik! (1-" << (*db) << ")" << std::endl;
			return PETCon(false);
		}
		Jarmuvek* p = (*a);
		int i = 1;
		while (i != b) {
			p = p->next;
			i++;
		}
		while(JarmuMenu(&p->jamru));
	}
	return true;
}
//(Press enter to continue)
bool PETCon(bool res) {
	std::cout << "Nyomd le az entert a folytatashoz!";
	std::cin.ignore();
	return res;
}
//jarmutorles menu-- @param lista&jarmu dbszam
bool DelJarmuMenu(Jarmuvek** a, int* db) {
	if ((*db) == 0) {
		std::cout << "Nincs meg jarmu a listaban igy sorszam nem adhato meg! Vegyel fel elobb jarmuvet!" << std::endl;
		return PETCon(false);
	}
	std::cout << "Adj meg a torolni kivant jarmu sorszamat! ('v' - vissza)" << std::endl;

	std::string inp;
	std::getline(std::cin, inp);
	if (inp == "v")
		return false;
	int b;
	try
	{
		b = std::stoi(inp);
	}
	catch (const std::exception&)
	{
		std::cout << "Szam megadasa szukseges a torleshez!" << std::endl;
		return PETCon(true);
	}
	if (b < 1 || b >(*db)) {
		std::cout << "Ez a sorszam nem letezik! (1-" << (*db) << ")" << std::endl;
		return PETCon(true);
	}
	DelJarmu(a, db, b - 1);
	return false;
}
//jarmu tenyleges torlese-- @param lista & jarmu dbszam & torolni kivant jarmu indexe
void DelJarmu(Jarmuvek** a, int* db, int ind) {
	Jarmuvek* p = (*a);
	Jarmuvek* q = 0;
	int i = 0;
	while (i != ind)
	{
		q = p;
		p = p->next;
		i++;
	}

	if (q == 0)
		(*a) = p->next;
	else
		q->next = p->next;
	delete p->jamru;
	delete p;
	(*db)--;
}
//auto hozzadasa menu-- @param lista & jarmu db szam
bool AddJarmuMenu(Jarmuvek** a, int* db) {
	std::string inp;
	do {
		std::cout << "Add meg a jarmu tipusat!" << std::endl;
		std::cout << "\t(a) Auto" << std::endl;
		std::cout << "\t(t) Teherauto" << std::endl;
		std::cout << "\t(m) Motor" << std::endl;
		std::cout << "\t(v) Vissza" << std::endl;

		inp = Readtext("Valasztott menupont: ");
		if (inp == "v")
			return false;
		else if (inp != "a" && inp != "t" && inp != "m")
			std::cout << "Nincs ilyen menupont!" << std::endl;
		else
			break;
	} while (true);
	
	std::cout << "=========================" << std::endl;
	std::string tnev = Readtext("Tulajdonos neve: ");

	int gyev = ReadNbr("Jarmu gyartasanak eve: ");
	
	std::string jnev = Readtext("Jarmu neve: ");

	Jarmu* j = 0;
	if (inp == "a") {
		std::string at = Readtext("Auto tipusa: ");

		j = new Auto(tnev, gyev, jnev, ReadNbr("Utasok maximalis szama: "), at);
	}
	else if (inp == "m") {
		j = new Motor(tnev, gyev, jnev, ReadNbr("Motor kobcenti szama: "));
	}
	else {
		j = new Teherauto(tnev, gyev, jnev, ReadNbr("Teherauto sulya: "));
	}
	(*db)++;
	Jarmuvek* jm = new Jarmuvek();
	jm->next = (*a);
	jm->jamru = j;
	(*a) = jm;
	return false;
}

//beolvas egy szamot--ha nem szam-->szol hogy szam kell//addig nem enged tovabb
int ReadNbr(std::string title) {
	std::string inp2;
	do
	{
		std::cout << title;
		std::getline(std::cin, inp2);
		try
		{
			return std::stoi(inp2);
		}
		catch (const std::exception&)
		{
			std::cout << "Szam megadasa kotelezo!" << std::endl;
		}
	} while (true);
}
//kiirja a @param string-et es szoveget beolvas (pl.menuben)
std::string Readtext(std::string title) {
	std::cout << title;
	std::string inp;
	std::getline(std::cin, inp);
	return inp;
}
//fomenubol id beirva ide kerul, adatok listazasa, felvitt rekordot listazasa--@param lista
bool JarmuMenu(Jarmu** a) {
	system("CLS");
	(*a)->PrintData();
	std::cout << "============================" << std::endl;
	std::cout << "\t(h) Adat rogzitese" << std::endl;
	std::cout << "\t(t) Adat torles" << std::endl;
	std::cout << "\t(v) Vissza" << std::endl;
	std::string inp = Readtext("Valasztott menupont: ");
	if (inp == "v")
		return false;
	else if (inp == "h") {
		do
		{
			std::string kiadas = Readtext("Kiadas ideje: ");
			int osszeg = ReadNbr("Fizetett osszeg: ");
			int kmallas = ReadNbr("Kilometer allas: ");
			std::string megjegyzes = Readtext("Megjegyzes: ");
			try
			{
				(*a)->AddAdat(kiadas, osszeg, kmallas, megjegyzes);
				break;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
			}
		} while (true);
	}
	else if (inp == "t") {
		do
		{
			std::string ind = Readtext("Adj meg egy sorszamot (vissza - v): ");
			if (ind == "v")
				break;
			int inp = 0;
			try
			{
				inp = std::stoi(ind);
				try
				{
					(*a)->RemoveAdat(inp - 1);
					break;
				}
				catch (const std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			catch (const std::exception&)
			{
				std::cout << "Szam megadasa kotelezo!" << std::endl;
			}
		} while (true);
	}
	else {
		std::cout << "Ilyen menupont nem letezik! Add meg ujra!" << std::endl;
		return PETCon(true);
	}
	return true;
}
//beolv fajlbol
void Start(Jarmuvek** a, int* db)
{
	std::ifstream f("./data.txt"); //beolv f-be
	if (!f.good()) { // ha nem l�tezik a file akkor sim�n l�trehozzuk
		std::ofstream o("./data.txt");
		o.close();
		return;
	}
	std::string line;   //line-ba olvassuk adatokat soronkent
	std::getline(f, line);
	(*db) = std::stoi(line);


	Jarmuvek* p = 0; //legutolso hozzafuzott elem
	Jarmuvek* q = 0; //utolsoelotti hozaadott elem
    //bet�lt�si szekvencia
	for (int i = 0; i < (*db); i++)
	{
		p = new Jarmuvek();
		std::getline(f, line);

		std::string tnev;   //tulajnev
		std::getline(f, tnev);

		std::string gyevs;  //gyartasievstring
		std::getline(f, gyevs);
		int gyev = std::stoi(gyevs); //gyartasi ev

		std::string jnev;   //jarmunev
		std::getline(f, jnev);

		Jarmu* j = 0;
		if (line == "a") {
			std::string at;
			std::getline(f, at);

			std::string uss;
			std::getline(f, uss);
			int us = std::stoi(uss);

			j = new Auto(tnev, gyev, jnev, us, at);
		}
		else if (line == "m") { //motor
			std::string kcs;
			std::getline(f, kcs);
			int kc = std::stoi(kcs);
			j = new Motor(tnev, gyev, jnev, kc);
		}
		else {  //teheratuo
			std::string ss;
			std::getline(f, ss);
			int s = std::stoi(ss);
			j = new Teherauto(tnev, gyev, jnev, s);
		}
		p->jamru = j; //lista elem�be bet�ltj�k
		std::getline(f, line);
		int ad = std::stoi(line); //adatsz�m beolv.
		for (int i = 0; i < ad; i++)
		{
			std::string ks; //kiadas
			std::getline(f, ks);

			std::string os; //osszeg string
			std::getline(f, os);
			int o = std::stoi(os); //osszeg

			std::string kms; //km string
			std::getline(f, kms);
			int km = std::stoi(kms);//km

			std::string mj; //megjegyzes
			std::getline(f, mj);
			p->jamru->AddAdat(ks, o, km, mj); //hozz�adjuk az adatot a jarmuhoz
		}
        //lista pointerek �ll�t�sa
		if (i == 0) { //*a eredeti lista amit mainben letrehoztunk,
			(*a) = p; // eleje=vege
			q = p; //
		}
		else {
			q->next = p;
			q = p;
			p = p->next;
		}
		
	}

	f.close();
}

void Stop(Jarmuvek* a, int db) {
	std::ofstream o("./data.txt");
	o << db << std::endl;
	Jarmuvek* p = a;
	for (int i = 0; i < db; i++)
	{
		p->jamru->WriteToFileHead(o);
		p = p->next;
	}
	o.close();
}