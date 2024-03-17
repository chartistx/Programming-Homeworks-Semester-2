
//ONE WAY LINKED LIST

//G8.Uzrakstīt funkciju, kas apgriež sarakstu otrādi.
//Darbības laikā nedrīkst tikt izmantoti papildus elementi,
//kas dublētu visu esošā saraksta informāciju.Darbība jāveic,
//pārkabinot saites, nevis pārkopējot elementu vērtības.
#include <iostream>
using namespace std;

struct elem {//vienvirziena listes elementa izveide
	string num;
	elem* next;
	elem(string n) { num = n; next = NULL; };
};

void push_back(elem*& first, elem*& last, string n) {//jauna elementa pievienosana listei
	elem* p = new elem(n);
	if (first == NULL) {
		first = last = p;
	}
	else {
		last->next = p;
		last = p;
	}
}

void rem(elem*& first) {//listes izdzesana
	elem* p = first;
	while (p) {
		first = first->next;
		delete p;
		p = first;
	}
}

void apgriezt_otradi(elem* &first, elem* &last) {//apgriz sarakstu otradi parkabinot saites
	cout << "\n ievadita liste: " << endl;
	//ievaditas liestes izvade
	elem* i = first;
	while (i != NULL) {
		cout << i->num << " ";
		i = i->next;
	}
	elem* f = first, * l = last;
	elem* it = f;
	first = l;
	last = f;
	while (f != l) {//katra loop pedejais elements liste parmainas uz pirmspedejo, ta kamer nonak lidz pirmajam elementam
		//atrast pirmspedejo
		it = f;
		while (it->next != l) {
			it = it->next;
		}

		l->next = it;//nomaina saiti uz pirmspedejo
		l = it;//last iet uz pirma elem pusi par vienu elem
	}
	f->next = NULL;// ta ka pirmais tagad ir pedejais tad pointerim jarada uz NULL
}

int main()
{
	elem* first = NULL;//pirma listes elem pointeris
	elem* last;//pedeja listes elem pointeris

	//ievade
	string read_input = "j";
	string temp;
	while (read_input == "j") {//turpinat kamer atbilde uz jautajumu = j - jā
		cout << "ievadiet elementu: \n ";
		cin >> temp;
		cout << "\nvai turpinat ievadi(j/n)" << endl;
		cin >> read_input;
		push_back(first, last, temp);
	}
	//aizutit listu uz f()
	apgriezt_otradi(first,last);

	//rezultata izvade
	cout << "\n liste pec apgriesanas: " << endl;
	elem* i = first;
	while(i!=NULL) {
		cout << i->num << " ";
		i = i->next;
	}
	//izdzest visus elementus
	rem(first);
	
	cout << "\n Parbaude vai visi elementi ir izdzesti(true/false):\n"<<(first == NULL);
}

																					
//--------------------------------------------------------------------------------------|
//		Ievade			|	Gaititais Rezulats		|	Rezultats						|
//--------------------------------------------------------------------------------------|
//		1 2 3 4 5		|	5 4 3 2 1				|	5 4 3 2 1						|	
//--------------------------------------------------------------------------------------|
//		a b c d e		|	e d c b a				|	e d c b a						|
//--------------------------------------------------------------------------------------|
//		1.2 a b 3		|	3 b a 1.2				|	3 b a 1.2						|
//--------------------------------------------------------------------------------------|
//		1				|	1						|	1								|
//--------------------------------------------------------------------------------------|
//		1 2				|	2 1						|	2 1								|
//--------------------------------------------------------------------------------------|



