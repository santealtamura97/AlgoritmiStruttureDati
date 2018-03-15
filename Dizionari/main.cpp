#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "dictionary.h"
#include "list_vector.h"
#include<string>

using namespace std;

int main()
{
    /*string c="bello";
    string a="bella";
    hash<string> p;
    cout<<p(c);
    cout<<"\n";
    cout<<p(a);*/

    //creiamo il dizionario
     hash_table<string,int> dizionario(4);
     mypair<string,int> coppia;
     coppia.first="ciao";
     coppia.second=56;
     dizionario.insert(coppia);
     coppia.first="ragno";
     coppia.second=1234;
     dizionario.insert(coppia);
     coppia.first="alto";
     coppia.second=234;
     dizionario.insert(coppia);
     cout<<"The position of elements with key 'ciao' is: "<<dizionario.search("ciao");
     cout<<"\nThe position of elements with key 'ragno' is: "<<dizionario.search("ragno");
     cout<<"\nThe position of elements with key 'alto' is: "<<dizionario.search("alto");
     if(dizionario.containsValue(1234))
        cout<<"\nTrovata\n";
     else
        cout<<"\nNon trovata";
     cout<<"\nvalori:";
     int *valori=dizionario.value();
     for(int i=0;i<dizionario.returnDsize();i++){
        cout<<"\n "<<valori[i];
     }
     cout<<"\nchiavi:";
     string* chiavi=dizionario.keys();
     for(int i=0;i<dizionario.returnDsize();i++)
        cout<<"\n "<<chiavi[i];

     dizionario.resize();
     cout<<"\nThe position of elements with key 'ciao' is: "<<dizionario.search("ciao");
     cout<<"\nThe position of elements with key 'ragno' is: "<<dizionario.search("ragno");
     cout<<"\nThe position of elements with key 'alto' is: "<<dizionario.search("alto");
     cout<<"\nThe new divisor is: "<<dizionario.returnDivisor();

     hash_table<int,int> dizionario1(4);
     mypair<int,int> coppia1;
     coppia1.first=23;
     coppia1.second=11;
     dizionario1.insert(coppia1);



    return 0;
}
