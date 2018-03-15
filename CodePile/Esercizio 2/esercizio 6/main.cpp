#include <iostream>
#include <stdlib.h>
#include "funzioni.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Coda<char> c;
    List_vector<char> infissa(10);
    char var='3';
    infissa.insert(var,1);
    var='+';
    infissa.insert(var,2);
    var='5';
    infissa.insert(var,3);
    var='*';
    infissa.insert(var,4);
    var='(';
    infissa.insert(var,5);
    var='5';
    infissa.insert(var,6);
    var='-';
    infissa.insert(var,7);
    var='2';
    infissa.insert(var,8);
    var=')';
    infissa.insert(var,9);

    converti(infissa,c);


    system("pause");
    return 0;
}
