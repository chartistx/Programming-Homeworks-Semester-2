// H_3.cpp 
//H3. "Dots teksta fails. Saskaitīt tekstā vārdus (garumā vismaz 2)
//pēc to pirmajiem diviem burtiem, nešķirojot reģistru(""ab"", ""ac"", ""ad"" utt.).
//Programmai statistika pa vārdu garumiem jāsaliek tabulā,
//kas realizēta kā vārdnīca(STL map).Programmas rezultātā iegūt failu,
//kas katrai tekstā sastopamajai 2 burtu virknei(ar ko sākas vārds)
//izdrukāts pārstāvēto vārdu skaits(piemēram, ab 7, ac 3, ad 5 utt.).
//Par vārdu tiek uzskatīta latīņu alfabēta burtu virkne."

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    fstream fin("input.txt", ios::in);
    string word;
    map<string, int>count;
    string letters;
    while (fin >> word) {
        letters = "";
        letters += word[0];
        letters += word[1];
        count[letters]++;
      
    }
    for (auto it = count.begin(); it != count.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}


// INPUT - aab acc abb add aaj nnn mmm nn bbb aaass dasdas sadas da as dss as da sdas sda as as ddasda
// EXPECTED OUTPUT -    aa 3, ab 1, ac 1, ad 1, as 4, bb 1, da 3, dd 1, ds 1, mm 1, nn 2, sa 1, sd 2
// OUTPUT -             aa 3, ab 1, ac 1, ad 1, as 4, bb 1, da 3, dd 1, ds 1, mm 1, nn 2, sa 1, sd 2