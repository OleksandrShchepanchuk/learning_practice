#include <iostream>
#include <string>

#include "abonent.h"
#include "abonent_energy.h"
#include <ctime>




Abonent_energy::Abonent_energy(std::string name,
                        std::string surname,
                        int arrears_,
                        double rate_,
                        std::string address_,
                        std::tm date_of_reg_,
                        std::tm date_of_last_check_,
                        std::tm *all_dates_,
                        int k_days_,
                        double start_data_,
                        double end_data_)
: Abonent(name, surname,  arrears_, rate_, address_, date_of_reg_,  date_of_last_check_, all_dates_, k_days_)
{
    start_data = start_data_;
    end_data = end_data_;
}

Abonent_energy::Abonent_energy(const Abonent_energy& other)
:Abonent(other)
{
    start_data = other.start_data;
    end_data = other.end_data;
}   


Abonent_energy& Abonent_energy::operator=(const Abonent_energy& other)
{
    if (this != &other)
    {
        Abonent::operator=(other);
        start_data = other.start_data;
        end_data = other.end_data;
    }
    return *this;
}

Abonent& Abonent_energy::operator=(const Abonent& other)
{
    if (const Abonent_energy *derived = dynamic_cast<const Abonent_energy *>(&other))

   {
        if (this != *&derived)
        {
            Abonent::operator=(other);
            start_data = derived->start_data;
            end_data = derived->end_data;
        }
    }
    return *this;
}

Abonent_energy::~Abonent_energy()
{
    std::cout << "\nAbonent_energy is destroyed" << std::endl;
}

Abonent_energy::Abonent_energy()
:Abonent()
{
    start_data = 0;
    end_data = 0; 
}

void Abonent_energy::set_start_data(double start_data_)
{
    start_data = start_data_;
}


void Abonent_energy::set_end_data(double end_data_)
{
    end_data = end_data_;
}

double Abonent_energy::get_end_data()
{
    return end_data;
}


double Abonent_energy::get_start_data()
{
    return start_data;
}

double Abonent_energy::get_total_price()
{
    if (end_data - start_data < 1000)
    {
        return rate*(end_data - start_data);
    }
    return rate*(end_data - start_data) *2;
}




void Abonent_energy::print(std::ostream& f)
{
    Abonent::print(f);
    if (&f == &std::cout)
    {
        f << "start_data: " << start_data << "\nend_data: " << end_data;
        std::cout << std::endl;
    }
    else {
        f << start_data << " " << end_data << " ";
    }
}
void Abonent_energy::readFromFile(std::istream& in)
{
    Abonent::readFromFile(in);
    in >> start_data >> end_data;
}   

