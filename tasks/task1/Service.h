
#ifndef SERVICE_SERVICE_H
#define SERVICE_SERVICE_H

#include <iostream>
#include "abonent.h"
#include <string>
#include <ctime>



class Service
{
    private:
        std::string name;
        Abonent ** customers;
        int q;
        int MAXq;
        int water_q;
        int energy_q;
        void delete_customer(int index);
        void increase_max();
        void dealocate();
        void allocate_specific_memory(Abonent*& first,  Abonent*& second);
        bool compare(Abonent*& abonent, Abonent*& abonent2, std::string parametr = "name");
    public:
        Service();        
        Service(std::string name_, Abonent ** customers_, int q_);        
        Service(const Service& other);  
        ~Service();  


        void set_name(std::string name_);      
        void set_customers(Abonent** customers_, int q_);

        std::string get_name();      
        Abonent** get_customers();
        int get_quantity();
        int get_water_quantity();
        int get_energy_quantity();
        
        //methods
        //
        Abonent ** get_water_customers();
        Abonent ** get_energy_customers();
        //
        //print and input

        void print(std::ostream& os, bool choice = 0);
        void read(std::istream& is);
        void print_with_both_services(std::ostream& os);
        void check_equipment(std::ostream& os);

        // delete and add 

        bool delete_abonent(std::string address);
        void add_abonent(Abonent* abonent);

        //
        double total();
        Abonent * get_max_debtor();
        
        //sorting
        void sort_array(std::string parametr = "name");
};


#endif