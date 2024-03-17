
#include <iostream>
#include <fstream>
using namespace std;

struct elem {//vienvirziena listes elementa izveide
    char* pilseta;// = new char[100];
    elem* next;
    elem() { pilseta = NULL;  next = NULL; };
};

void push_back(elem*& first, elem*& last, char* n) {//jauna elementa pievienosana listei
    elem* p = new elem();

    if (first == NULL) {
        first = p;
        last = p;
    }
    else {
        last = first;
        first = p;
        first->next = last;
        //last->next = p;
        //last = p;
        //if (p->next == NULL)cout << 111<<endl;
    }
    p->pilseta = n; 
}

void rem(elem*& first) {//listes izdzesana
    elem* p = first;
    
    while (p) {
        first = first->next;
        delete p->pilseta;
        delete p;
        
        p = first;
    }
}

int main() {

    elem* f[26];//pointer to first element for each letter
    elem* l[26];//pointer to last element for each letter
    for (int i = 0; i < 26; i++) { f[i] = NULL; l[i] = NULL; }//initialization for all pointers    
    fstream fin("post.in", ios::in);
    int count = 0;
    int temp;//holder for array shift
    char* rd = new char[20];
    while (fin.getline(rd, 100, ' ')) {
        if (rd[0] > 90) {
            temp = rd[0] - 97;
            //cout << reader << " " << reader[0] <<" "<<temp<< endl;// << temp;
            push_back(f[temp], l[temp], rd);
            
        }
        else {
            temp = rd[0] - 65;
            //cout <<reader << " " << reader[0] << " " << temp<< endl;// << temp;
            push_back(f[temp], l[temp], rd);
        }
        rd= new char[20];
        count++;

    }
    //izdrukat otra faila
    fstream fout("post.out", ios::out);
    if (count == 0) {
        fout << "nothing";
    }
    else {
        count = 0;
        for (int i = 0; i < 26; i++) {
            //count = 0;
            elem* p = f[i];
            if (p!=NULL &&count==0){
                fout << p->pilseta;
                p = p->next;
                count++;
            }
            while (p) {
                fout <<" "<< p->pilseta;
                p = p->next;
            }
        }
    }
    for (int i = 0; i < 26; i++) { rem(f[i]); }
    delete rd;
    fout.close();
    fin.close();
}
