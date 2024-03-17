/*******************************************

//F16.Dots teksta fails, kurā atrodas sintaktiski pareizs
//C++ programmas teksts.Saskaitīt, cik salīdzināšanas operatoru
//(== , != , <= , >= ) satur dotā programma.Drīkst uzskatīt,
//ka programmas tekstā nav komentāru un ka attiecīgie simboli
//neparādīsies teksta literāļos.

// autors pienem ka teksta ievaditais kods ir sintaktiski korekts un veiksmigi kompilejas
// tiek pienemts ka teksta ievaditais kods nesatu char virknes("tekst" formata) kas satur !=<> simbolus
// tiek pienemts ka teksta ievaditais kods ir vismaz 2 simbolu gars
Programma izveidota: 2023/04/03

*******************************************/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int check;
    do {
        fstream f("textinput.txt", ios::in);
        string s;//uzglabas teksta rindu
        int count = 0;
        char prev, cur;//uzglabas iteracijas ieprieksejo un esošo esošas iteracias stirng elementu


        while (getline(f, s)) {
        //cout << s << endl;
            prev = s[0];
            for (int i = 1; i < s.length(); ++i) {
                cur = s[i];
                if (cur=='=' && (prev == '!' || prev == '=' || prev == '<' || prev == '>'))
                    count++;
                prev = cur;
            }
        }

        cout << "programma ir "<<count<<" salidzinasanas operatori" << endl;
        
        
        f.close();
        cout << "Vai turpinat (1) vai beigt (0)?\n";
        cin >> check;
    } while (check);
    
}

//TESTA PLANS

// TEKSTS "== dassd != =! == <= => >= =< " gaititais rez: 5 , rezultats 5
// TEKSTS "if(1>=2 || 3<=3 ||4==4||1!=0){};" gaiditais rez: 4 , rezutats 4