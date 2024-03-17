

//STD LIST

//G8.Uzrakstīt funkciju, kas apgriež sarakstu otrādi.
//Darbības laikā nedrīkst tikt izmantoti papildus elementi,
//kas dublētu visu esošā saraksta informāciju.Darbība jāveic,
//pārkabinot saites, nevis pārkopējot elementu vērtības.

#include <iostream>
#include <list>
using namespace std;

void apgriezt_otradi(list<string>& liste) {//apgriz sarakstu otradi
	cout << "\n ievadita liste: " << endl;
	//izvade
	for (auto i: liste) {
		cout << i << " ";
	}

	string val1, val2;//uzglabas vertibas kas jasamaina vietam
	auto first = liste.begin();
	auto last = liste.rbegin();

	while(first != last.base()) {//gadijuma kad liste ir nepara sk elem, parbauda vai esam centraa
		//piefikse
		val1 = *first;
		val2 = *last;
		//samaina vertibas vietam
		*first = val2;
		*last = val1;
		//parbida iteratorus uz centru
		++first;
		if (first == last.base())return;//gadijuma ja liste ir para sk elementu , parbauda vai esam centraa
		++last;
	}
}

int main()
{
	list<string> ievade;

	//ievade
	string read_input="j";
	string temp;
	while (read_input=="j") {
		cout << "ievadiet elementu: \n ";
		cin >> temp;
		cout << "\nvai turpinat ievadi(j/n)" << endl;
		cin >> read_input;
		ievade.push_back(temp);
	}

	apgriezt_otradi(ievade);

	//izvadit rezultatu
	cout<<"\n liste pec apgriesanas: "<<endl;
	for (auto i: ievade) {
		cout << i << " ";
	}

	ievade.clear();
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
//		1 2				|	2 1						|									|
//--------------------------------------------------------------------------------------|

