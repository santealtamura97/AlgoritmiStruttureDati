#include <iostream>
#include <cstdlib>
#include "list_vector.h"

using namespace std;

int main()
{
    List_vector<int> list1, list2;
	int x;

	/* inserting three elements into the list list1 */
	x = 1;
  list1.insert(x, list1.begin());
	x = 2;
  list1.insert(x, list1.begin());
	x = 3;
  list1.insert(x, list1.begin());
	x = 4;
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
	/*if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;
			*/
    if(list1 != list2)
        cout <<"list1 diversa da list2"<< endl;
    else
        cout <<"list1 uguale a list2"<<endl;

    cout<<"Tra la posizione 1 e la posizione 4 ci sono numero di elementi:";cout<<list1.num_elements(1,4);

    list1.exchange(2,4);
    cout<<"\nlist1 after exchange element in pos 2 with element in pos 4";cout<<list1;

    list1.move_min_max();
    cout<<"\nlist1 after move min in first positon and max in last position";cout<<list1;

    list1.insertionSort();
    cout<<"\nlist1 after insertionSort";cout<<list1;

    list1.clear();
    /* visualizing the list list1 */
	cout << "\nlist1 after clear=" ; cout << list1;

    system("EXIT SUCCESS");
    return 0;
}
