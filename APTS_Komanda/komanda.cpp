// komanda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include <unordered_map>
#include <map>
using namespace std;

struct team {
    int lvl=-1;
    string pers1;
    string pers2;
    //pers(string p1, string p2) { pers1 = p1; pers2 = p2; };
};
struct lvl {
    string pers1;
    string pers2;
    //pers(string p1, string p2) { pers1 = p1; pers2 = p2; };
};

int main()
{
    //fstream fin("post_in.txt", ios::in);//.in Participant Woman Man
    //fstream fout("post_out.txt", ios::out);//.out
    fstream fin("team.in", ios::in);//.in Participant Woman Man
    fstream fout("team.out", ios::out);//.out

    map<string, team> komanda;
    map<int, lvl> level;
    string line;
    string key;
    team kom;
    int count = 0;
    string first;
    while (getline(fin, line,' ')) {

        if(true) {
            key = line;
            if (key != "0") {
                getline(fin, line, ' ');
                komanda[key].pers1 = line;

                getline(fin, line);
                komanda[key].pers2 = line;

            }
            

        }
    }

    bool checkk;
    for (auto it = komanda.begin(); it != komanda.end(); ++it) {
        checkk = true;
        for (auto it2 = komanda.begin(); it2 != komanda.end(); ++it2) {
            if (it->first == it2->second.pers1 || it->first == it2->second.pers2) {
                checkk = false;
                break;
            }
        }

        if (checkk) {
            it->second.lvl = 0;
            first = it->first;
            break;

        }
        
    }
    level[0].pers1 = " "+komanda[first].pers1+" " + komanda[first].pers2;
    bool check = true;
    string l_keys1;
    int lc = 0;
    istringstream iss;
    string temp;
    int ccount = 0;
    while(true) {
        l_keys1 = level[lc].pers1;
        if (l_keys1 == "")break;
        ccount++;
        lc++;
        iss.clear();
        iss.str(l_keys1);
        while (iss>>temp) {
            
            if (komanda[temp].pers1 != "0")level[lc].pers1 += " " + komanda[temp].pers1;
            if (komanda[temp].pers2 != "0")level[lc].pers1 += " " + komanda[temp].pers2;
        }
        check = false;

    }

    for (int i = lc - 1; i >= 0; --i) {
        fout <<i+1<<":"<< level[i].pers1 << endl;
    }
    fout << 0 << ": " << first << endl;
    fout.close();
    fin.close();
}
