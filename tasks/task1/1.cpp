#include "abonent.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;
void readFromFile(Abonent *arr, istream& in, int& size);

int main() {
    // Abonent abonent2;
    // Abonent abonent1 = abonent2;
    // // cout << "Hellow world" << endl;
    // abonent2.set_date_of_last_check(2020, 9, 18);
    ifstream f("in.txt");
    // cout << abonent2.term_to_check() << endl;;
    // abonent1.readFromFile(f);
    // abonent1.print();
    // // abonent2.print();
    // // abonent1.print();
    int size = 0;
    std::tm * dates = new std::tm[100] {Date(2020, 8, 2), Date(2021,8, 2)};
    Abonent a("name", "surname", 0, 0, "address", Date(2020,8, 2), Date(2021,8, 2), dates, 2);
    a.get_all_dates()[0] = Date(2010,2,6);
    cout << a.get_all_dates()[0].tm_year + 1900 << endl;
    cout << dates[0].tm_year + 1900 << endl;

    Abonent * abonent = new Abonent[100];
    readFromFile(abonent, f, size);
    for (int i = 0; i < size; i++)
    {
        abonent[i].print(cout);
    }
    f.close();
    // ofstream a("out.txt");
    for (int i = 0; i < size; i++)
    {
        // abonent[i].print(a);
    }
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
    return 0;
}

void readFromFile(Abonent *arr, istream& in, int& size) {
    while (!in.eof()) {
        arr[size].readFromFile(in);
        if (!arr[size].get_name().length())
        {
            break;
        }
        size++;
    }
}


