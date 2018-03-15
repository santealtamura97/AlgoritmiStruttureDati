#include "ordered_list.h"
#include <iostream>
#include<string>
#include<stdlib.h>

using namespace std;


int main(){
    Ordered_list<string> list1,list2;
    string x,y;
    x="ragno";
    list1.insert_in_order(x);
    x="cane";
    list1.insert_in_order(x);
    cout<<"List1=";cout<<list1;
    system("pause");
    x="alto";
    list1.insert_in_order(x);
     cout<<"List1=";cout<<list1;
    system("pause");
    x="dolce";
    list1.insert_in_order(x);

    cout<<"List1=";cout<<list1;
    system("pause");

    x="bello";
    list1.insert_in_order(x);
     cout<<"List1=";cout<<list1;
    system("pause");
     x="zorro";
     list1.insert_in_order(x);
      cout<<"List1=";cout<<list1;
  x="piscio";
     list1.insert_in_order(x);
      cout<<"List1=";cout<<list1;
      x="adiuu";
     list1.insert_in_order(x);
      cout<<"List1=";cout<<list1;

      y="gatto";
      list2.insert_in_order(y);
      y="pisello";
      list2.insert_in_order(y);
    cout<<"List2=";cout<<list2;

    list1.merge(list2);
    cout<<"List1=";cout<<list1;

    list1.erase(list1.search("dolce"));
    cout<<"List1=";cout<<list1;
    system("pause");
    return 0;
}

