

// GG – STL list un saistītais saraksts ar izņēmumsituāciju apstrādi un vienībtestēšanu**.

// * atrisināt uzdevumu G divos veidos:
//   a) izmantojot dinamiskas datu struktūras (saistīto sarakstu vtml.),
//   b) izmantojot STL::list konteineru.

// ** tas pats uzdevums, kas G, bet tā risinājums (a) jāpapildina ar divām lietām:

//   1) vismaz viena no datu pārbaudēm jārealizē, izmantojot izņēmumsituāciju
//  apstrādes (exception handling) mehānismu,

//   2) vismaz viena funkcija (vēlams, galvenā) ir jānotestē,
//  izmantojot vienībtestēšanu, kur attiecīgā funkcija būtu jāpārbauda 
//  uz vismaz trīs dažādiem nosacījumiem;
//      šim nolūkam, kā minimums, ir nepieciešams:
// 	      (1) šo funkciju iznest ārā citā failā (nekā funkcija main),
// 	      (2) izveidot otru projektu speciāli šīs funkcijās testēšanai 
// (tātad, kopā būs divi projekti, parastais, kas izmantos funkciju, otrais, kas testēs).

// Papildus norāde: šādam vienībtestēšanas projektam daļēji atbilst iepriekšējā
//  semestra pēdējais laboratorijas darbs (ar klasēm) ar cieti iekodētu main funkciju.

//ONE WAY LINKED LIST

//G8.Uzrakstīt funkciju, kas apgriež sarakstu otrādi.
//Darbības laikā nedrīkst tikt izmantoti papildus elementi,
//kas dublētu visu esošā saraksta informāciju.Darbība jāveic,
//pārkabinot saites, nevis pārkopējot elementu vērtības.
#include <iostream>
//#include <list>
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



bool test1_push_back() {
	elem* first = NULL;//pirma listes elem pointeris
	elem* last;//pedeja listes elem pointeris
	string parbaude[] = { "a", "c", "b","d"};
	int izmers = sizeof(parbaude)/sizeof(string);
	push_back(first, last, "a");
	push_back(first, last, "b");
	push_back(first, last, "c");
	push_back(first, last, "d");

	int count = 0;//lai parbauditu garumu
	try {
		elem* i = first;
		while (i != NULL) {
			if (parbaude[count] != i->num)throw(0);
			i = i->next;
			count++;
		}
		if (count != izmers)throw(0);
		rem(first);
		return true;
	}
	catch (int c) {
		rem(first);
		return false;
	}

}

bool test2_push_back() {
	elem* first = NULL;//pirma listes elem pointeris
	elem* last;//pedeja listes elem pointeris
	string parbaude[] = { "0", "1", "c", "d" };
	int izmers = sizeof(parbaude) / sizeof(string);
	push_back(first, last, "0");
	push_back(first, last, "1");
	push_back(first, last, "c");
	push_back(first, last, "d");

	int count = 0;//lai parbauditu garumu
	try {
		elem* i = first;
		while (i != NULL) {
			if (parbaude[count] != i->num)throw(0);
			i = i->next;
			count++;
		}
		if (count != izmers)throw(0);
		rem(first);
		return true;
	}
	catch (int c) {
		rem(first);
		return false;
	}

}



bool test1_apgriezt_otradi() {
	bool check = true;

	elem* first = NULL;//pirma listes elem pointeris
	elem* last;//pedeja listes elem pointeris
	string parbaude[] = { "1" };
	int izmers = sizeof(parbaude) / sizeof(string);
	push_back(first, last, "1");
	apgriezt_otradi(first, last);

	int count = 0;//lai parbauditu garumu

	elem* i = first;
	while (i != NULL) {
		if (parbaude[count] != i->num) {
			check = false;
			break;
		}
		i = i->next;
		count++;
	}
	if (count != izmers)check = false;

	rem(first);
	return check;
}

bool test2_apgriezt_otradi() {
	bool check = true;

	elem* first = NULL;//pirma listes elem pointeris
	elem* last;//pedeja listes elem pointeris
	string parbaude[] = { "1", "1" };
	int izmers = sizeof(parbaude) / sizeof(string);
	push_back(first, last, "0");
	push_back(first, last, "1");
	apgriezt_otradi(first, last);

	int count = 0;//lai parbauditu garumu

	elem* i = first;
	while (i != NULL) {
		if (parbaude[count] != i->num) {
			check = false;
			break;
		}
		i = i->next;
		count++;
	}
	if (count != izmers)check = false;

	rem(first);
	return check;
}

bool test3_apgriezt_otradi() {
	bool check = true;

	elem* first = NULL;//pirma listes elem pointeris
	elem* last;//pedeja listes elem pointeris
	string parbaude[] = { "d", "c", "1", "0" };
	push_back(first, last, "0");
	push_back(first, last, "1");
	push_back(first, last, "d");
	apgriezt_otradi(first, last);

	int count = 0;//lai parbauditu garumu

	elem* i = first;
	while (i != NULL) {
		if (parbaude[count] != i->num) {
			check = false;
			break;
		}
		i = i->next;
		count++;
	}
	if (count != 4)check = false;

	rem(first);
	return check;
}









int main()
{
	cout << "PUSH BACK TEST1: " << (test1_push_back() ? "OK" : "FAILED") << endl;
	cout << "PUSH BACK TEST2: " << (test2_push_back() ? "OK" : "FAILED") << endl;

	cout << "APGRIEZT OTRADI TEST1: " << (test1_apgriezt_otradi() ? "OK" : "FAILED") << endl;
	cout << "APGRIEZT OTRADI TEST2: " << (test2_apgriezt_otradi() ? "OK" : "FAILED") << endl;
	cout << "APGRIEZT OTRADI TEST3: " << (test3_apgriezt_otradi() ? "OK" : "FAILED") << endl;

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



