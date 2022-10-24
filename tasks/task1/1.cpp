#include "abonent.h"
#include "abonent_energy.h"
#include "abonent_water.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Service.h"

using namespace std;
void readFromFile(Abonent *arr, istream& in, int& size);
Abonent *find_in_range(Abonent A, Abonent B, Abonent *array, int k, int &count);
void insertionSort(Abonent *arr, int n);
void print_array(Abonent* arr, int k, ostream& os);


int main() {
    // Abonent abonent2;
    // Abonent abonent1 = abonent2;
    // // cout << "Hellow world" << endl;
    // abonent2.set_date_of_last_check(2020, 9, 18);
    // ifstream f("in.txt");
    // cout << abonent2.term_to_check() << endl;;
    // abonent1.readFromFile(f);
    // abonent1.print();
    // // abonent2.print();
    // // abonent1.print();
    // int size = 0;
    std::tm * dates = new std::tm[100] {Date(2020, 8, 2), Date(2021,8, 2)};
    // Abonent a("name", "surname", 0, 0, "address", Date(2020,8, 2), Date(2021,8, 2), dates, 2);
    // a.get_all_dates()[0] = Date(2010,2,6);
    // cout << a.get_all_dates()[0].tm_year + 1900 << endl;
    // cout << dates[0].tm_year + 1900 << endl;

    // Abonent * abonent = new Abonent[100];
    // readFromFile(abonent, f, size);
    // for (int i = 0; i < size; i++)
    // {
    //     abonent[i].print(cout);
    // }
    // f.close();
    // ofstream a("out.txt");
    // for (int i = 0; i < size; i++)
    // {
        // abonent[i].print(a);
    // }
    // a.close();
    // int b = 1;
    // while(b) 
    // {

    //     cin >> b;
    //     switch (b)
    //     {
    //     case 1: {
    //         for (int i = 0; i < size; i++) {
    //             abonent[i].print();
    //             cout << "term_to_check: " << abonent[i].term_to_check() << endl << endl;
    //         }
    //     }
    //         break;
    //     case 2: {
    //         for (int i = 0; i < size; i++) {
    //             abonent[i].print();
    //             cout << "service_costs: " << abonent[i].service_costs() << endl << endl;
    //         }
    //         break;
    //     }
    //     case 3: {
    //         for (int i = 0; i < size; i++) {
    //             abonent[i].print();
    //             cout << "is_overdue: " << abonent[i].is_overdue() << endl << endl;
    //         }
    //         break;
    //     }
    //         cout << "Chose an option: ";
    //     case 0: {
    //         cout << "End" << endl;
    //     }
    //         break;
    //     }
    // }
    // Abonent_energy user_energy("name", "surname", 2, 2, "address", Date(2020,8, 2), Date(2021,8, 2), dates, 2,1000,1200);
    // Abonent_water user_water("name", "surname", 2, 2, "address", Date(2020,8, 2), Date(2021,8, 2), dates, 2,200);
    // Abonent* user;
    // Abonent user1("name", "surname", 2, 2, "address", Date(2020,8, 2), Date(2021,8, 2), dates, 2);
    // user = &user_energy;
    // user->print(cout);
    // Abonent_energy *user_energy;
    // cout << user_energy.get_total_price() << endl;
    // // cout << user->get_total_price() << endl;
    // cout << endl;
    // cout << *user;
    // // name surname 0 3 address1 2020 8 2 2 2 2021 2 2 8 2021 2 7 2020 1000 1300
    // cin >> *user;
    // cout << *user;
    // cout << endl;
    // cout << endl;
    // cout << "+------" << endl;
    // cout << user_energy;
    // cout << "+------" << endl;
    // cout << user_water;



// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /*Abonent test_for_addition("name", "surname", 2, 10, "address", Date(2005,8, 2), Date(2005,8, 2), dates,2);
    Abonent test_for_addition1("name", "surname", 2, 5, "address", Date(2016,8, 2), Date(2016,8, 2), dates,2);
    Abonent test_for_addition2;
    test_for_addition2 = (test_for_addition + test_for_addition1);
    */
    // cout << (test_for_addition < test_for_addition1) << endl;
    // cout << (test_for_addition > test_for_addition1) << endl;
    /*cout << string(test_for_addition);
    Abonent *arr = new Abonent[100];
    Abonent *arr2 = new Abonent[100];
    int size = 0;
    ifstream f("in.txt");
    readFromFile(arr, f, size);
    f.close();
    ofstream a("out_array.txt");
    ofstream b("out_array_sorted.txt");
    */
    // print_array(arr, size, a);
    // insertionSort(arr, size);
    // print_array(arr, siz e,b);
    // a.close();
    // b.close();
    // int count = 0;
    // arr2 = find_in_range(test_for_addition, test_for_addition1, arr, size, count);
    // print_array(arr2, count, cout);
    // cout << test_for_addition1 << endl << endl;
    // test_for_addition2 = test_for_addition1++;
    // cout << test_for_addition1 << " 2 "<< test_for_addition2 << endl << endl;
    // test_for_addition2 = ++test_for_addition1;
    // cout << test_for_addition1 << " 2 "<< test_for_addition2 << endl << endl;
    // test_for_addition1 = test_for_addition2 = test_for_addition;
    // cout << test_for_addition1 << " 2 "<< test_for_addition2 << endl << endl;
    Service service;
    ifstream f("out_array.txt");
    ofstream a ("out.txt");
    // cout << "aaaaaaaa" << endl;
    Abonent *test_for_add_f = new Abonent_water("name", "surname", 1000, 5, "address10", Date(2016,8, 2), Date(2019, 10, 23), dates,2, 200);


    // test_for_add_f->print(cout);
    service.read(f);
    service.delete_abonent("address7");
    service.delete_abonent("address1");
    service.add_abonent(test_for_add_f);
    // service.print_with_both_services(a);
    service.sort_array("date_of_last_check");
    service.print(a);
    // service.check_equipment(cout);
    a.close();
    f.close();
    // service.get_max_debtor()->print(cout);

    cout << service.total() << endl;
    
    delete test_for_add_f;

    return 0;
}





void readFromFile(Abonent *arr, istream& in, int& size) {
    while (true) {
        arr[size].readFromFile(in);
        if (!arr[size].get_name().length())
        {
            break;
        }
        size++;
    }
}


Abonent *find_in_range(Abonent A, Abonent B, Abonent *array, int k, int &count)
{
    Abonent *result = new Abonent[k+1];
    for (int i = 0; i < k; i++)
    {
        // cout << i << endl;
        if (array[i] > A && array[i] < B)
        {
        
            result[count] = array[i];
            count ++;
        }
    }
    return result;
}

void insertionSort(Abonent *arr, int n) 
{ 
    int i, j;
    Abonent key; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void print_array(Abonent* arr, int k, ostream& os)
{
    for (int i = 0; i < k; i++)
    {
        os << arr[i];
    }
}