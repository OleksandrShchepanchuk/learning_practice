#include <iostream>
#include "abonent.h"
#include "abonent_energy.h"
#include "abonent_water.h"
#include "Service.h"
#include <string>
#include <ctime>

void Service::delete_customer(int index)
{
    if (dynamic_cast<Abonent_energy*>(customers[index])) energy_q--;
    else if (dynamic_cast<Abonent_water*>( customers[index])) water_q--;
    delete customers[index];
    for (int i = index; i < q-1; i++)
    {
        customers[i] = customers[i+1];
    }
    q--;
    customers[q] = NULL;  
}

int Service::get_water_quantity()
{
    return  water_q;
}
int Service::get_energy_quantity()
{
    return energy_q;
}

void Service::dealocate()
{
    for (int i = 0; i < q; i++)
    {
        delete customers[i];
    }
    delete[] customers;
}


void Service::allocate_specific_memory(Abonent*& first,  Abonent*& second)
{
        if (dynamic_cast<Abonent_energy*>(second)) first = new Abonent_energy;
        else if (dynamic_cast<Abonent_water*>( second)) first = new Abonent_water;
        else first = new Abonent;
}


void Service::increase_max()
{
    MAXq *=2;
    Abonent **new_arr = new Abonent*[MAXq];
    for (int i = 0; i < q; i++)
    {
        allocate_specific_memory(new_arr[i], customers[i]);
        *new_arr[i] = *customers[i];
    }
    dealocate();
    customers = new Abonent*[MAXq];
    for (int i  = 0; i < q; i++)
    {
        allocate_specific_memory(customers[i], new_arr[i]);
        *customers[i] = *new_arr[i];
    }
    
}

Service::Service()
{
    name = "";
    customers = new Abonent*[MAXq];
    q  = 0; 
    MAXq = 100;
    water_q = 0;
    energy_q = 0;
}


Service::Service(std::string name_, Abonent ** customers_, int q_)
{
    name = name_;
    customers = new Abonent*[MAXq];
    MAXq = 100;
    water_q = 0;
    energy_q = 0;
    while (q_ > MAXq) {
       MAXq *= 2;
    }
    q = q_;
    for (int i = 0; i < q; i++)
    {
        allocate_specific_memory(customers[i], customers_[i]);
        *customers[i] = *customers_[i];
    }

}

Service::Service(const Service& other)
{
    name = other.name;
    customers = new Abonent*[MAXq];
    q = other.q;
    water_q = other.water_q;
    energy_q = other.energy_q;
    for (int i = 0; i < q; i++)
    {
        allocate_specific_memory(customers[i], other.customers[i]);
        *customers[i] = *other.customers[i];
    }
    MAXq = other.MAXq;
}  


Service::~Service()
{
    delete[] customers;
}


void Service::set_name(std::string name_)
{
    name = name_;
}      

void Service::set_customers(Abonent** customers_, int q_)
{
    delete[] customers;
    while (q_ > MAXq) {
       MAXq *=2;
    }
    customers = new Abonent*[MAXq];
    q = q_;
    for (int i = 0; i < q; i++)
    {
        allocate_specific_memory(customers[i], customers_[i]);
        *customers[i] = *customers_[i];
    }
}      

std::string Service::get_name()
{
    return name;
}    

Abonent** Service::get_customers()
{
    Abonent** array_to_return = new Abonent*[MAXq];
    for (int i = 0; i < q; i++)
    {
        allocate_specific_memory(array_to_return[i], customers[i]);
        *array_to_return[i] =  *customers[i];
    }
    return array_to_return;
}


int Service::get_quantity()
{
    return q;
}


void Service::print(std::ostream& os, bool choice)
{
    os << name << "\n";
    for (int i = 0; i < q;  i++)
    {
        if (dynamic_cast<Abonent_energy*>(customers[i])) os << 2 << " ";
        else if (dynamic_cast<Abonent_water*>( customers[i])) os << 3 << " ";
        else os << 1 << " ";
        if (!choice)
        {
            customers[i]->print(os);
        }
        else
        {
            os << customers[i]->get_name() << " " << customers[i]->get_surname() << " "<< customers[i]->get_address() << "\n";
        } 
        os << "\n";
    }
}


void Service::read(std::istream& is)
{
    Abonent **customers_new;
    int choice = 1;
    for (int i = 0; i < q; i++)
    {
        delete customers[i];
    }
    delete[] customers;
    q = 0;
    customers = new Abonent*[MAXq];
    is >> name;
    while(42)
    {
        if (q+2 > MAXq)
        {
            increase_max();
        }
        is >> choice;

        if (!choice) break;
        switch (choice)
        {
        case 1:
            customers[q] = new Abonent;
            break;
        case 2:
            customers[q] = new Abonent_energy;
            /* code */
            break;
        case 3:
            customers[q] = new Abonent_water;
            /* code */
            break;
        }
        customers[q]->readFromFile(is);
        // std::cout  << *customers[q];
        if (!customers[q]->get_name().length()) break;
        // if (!address) break;
        q++;
    }
}




bool Service::delete_abonent(std::string address)
{
    bool deleted = 0;
    for (int i = 0; i < q; i ++)
    {
        if (customers[i]->get_address() == address)
        {
            delete_customer(i);
            deleted = 1;
            i--;
        }
    }
    return deleted;
}


void Service::add_abonent(Abonent* abonent)
{
    // abonent->print(std::cout);
    allocate_specific_memory(customers[q], abonent);
    *customers[q] = *abonent;

    q++;
}



void Service::print_with_both_services(std::ostream& os)
{
    Abonent ** water_customers = get_water_customers();
    Abonent ** energy_customers = get_energy_customers();

    for (int i = 0; i < water_q; i++)
    {
        for (int j = 0; j < energy_q; j++)
        {
            if (water_customers[i]->get_address() == energy_customers[j]->get_address())
            {
                water_customers[i]->Abonent::print(os); 
            }
        }
    }
    water_customers = NULL;
    energy_customers  = NULL;
}

Abonent ** Service::get_water_customers()
{
    Abonent ** water_customers = new Abonent*[MAXq];
    int count = 0;
    for (int i = 0; i < q; i++)
    {
        if (dynamic_cast<Abonent_water*> (customers[i]))
        {
            water_customers[count] = new Abonent_water;
            *water_customers[count] = *customers[i];
            count ++;
        }
    }
    water_q = count;
    return  water_customers;
}


Abonent ** Service::get_energy_customers()
{
    Abonent ** energy_customers = new Abonent*[MAXq];
    int count = 0;
    for (int i = 0; i < q; i++)
    {
        if (dynamic_cast<Abonent_energy*> (customers[i]))
        {
            // std::cout << q << " ";
            energy_customers[count] = new Abonent_energy;
            *energy_customers[count] = *customers[i];
            count ++;
        }
    }
    energy_q = count;
    return  energy_customers;
}



void Service::check_equipment(std::ostream& os)
{   

        std::time_t t = std::time(0);
        std::tm* now= std::localtime(&t);
        int month = now->tm_mon;
        for (int i = 0; i < q; i++)
        {
            std::time_t month_of_check = t + customers[i]->term_to_check()*86400;
            if (localtime(&month_of_check)->tm_mon- month == 0 && localtime(&month_of_check)-> tm_year - customers[i]->get_date_of_last_check().tm_year == 3)
            {
                customers[i]->print(os);
            }
        }
}


double Service::total()
{
    double sum =0;
    for (int i = 0; i < q; i++)
    {
        sum += customers[i]->get_total_price() + customers[i]->get_arrears();
    }
    return sum;
}




Abonent * Service::get_max_debtor()
{       
        Abonent *max = customers[0];
        for (int i = 0; i < q-1; i++)
        {
            if (max->get_arrears() < customers[i+1]->get_arrears())
            {
                max = customers[i+1];
            }
        }
        return max;
}


void Service::sort_array(std::string parametr)
{
    for (int i = 0; i < q-1; i++)
    {
        for (int j = 0; j < q - i - 1; j ++)
        {
            if (compare(customers[j],customers[j+1], parametr))
            {
                std::swap(customers[j],customers[j+1]);
            }
        }
    }
    
}

bool Service::compare(Abonent *& abonent, Abonent *& abonent2, std::string parametr)
{
    if (parametr == "name") return abonent->get_name() > abonent2->get_name();
    if (parametr == "surname") return abonent->get_surname() > abonent2->get_surname();
    if (parametr == "address") return abonent->get_address() > abonent2->get_address();
    if (parametr == "arrears") return abonent->get_arrears() > abonent2->get_arrears();
    if (parametr == "date_of_reg")
    {
        tm b = abonent2->get_date_of_reg();
        tm a = abonent->get_date_of_reg();

        return mktime(&a) > mktime(&b);
    } 
    if (parametr == "date_of_last_check") {
        tm b = abonent2->get_date_of_last_check();
        tm a = abonent->get_date_of_last_check();
        return mktime(&a) > mktime(&b);
    }
    if (parametr == "rate") return abonent->get_rate() > abonent2->get_rate();
    if (parametr == "k_days") return abonent->get_k_days() > abonent2->get_k_days();
    return 0;
}