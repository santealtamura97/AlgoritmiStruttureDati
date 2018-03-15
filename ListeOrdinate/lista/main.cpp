#include <iostream>
#include <string>
#include <stdlib.h>
#include "list_vector.h"
#include "linear_list.h"

#define DIM_LISTA 10

using namespace std;

int main(){
    List_vector<string> list1,list2;

    string x;

	/* inserting three elements into the list list1 */
	x = "ciao";
  list1.insert(x, list1.begin());
	x = "lala";
  list1.insert(x, list1.begin());
	x = "alto";
  list1.insert(x, list1.begin());
	x = "pupu";
  list1.insert(x, list1.begin());

	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */
	list2 = list1;
	/* visualizing the list list2 */
	cout << "After list2=list1, list2="; cout << list2;

	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

	/* erasing the first element from the list list2 */
	list2.erase(list2.begin());
	/* visualizing the list list2 */
	cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;

    if(list1.palindrome()==true)
        cout<<"La lista e' palindroma"<< endl;
    else
        cout<<"La lista non e' palindroma"<<endl;
    list1.reverse();
    cout << "list1 after reverse=" ; cout << list1;

    cout<<"list1 size=";cout<<list1.size();
    cout<<"\n"<<endl;
    system("pause");
    return 0;
}
