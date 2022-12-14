#include <iostream>
#include <string>

#include "abonent.h"
#include "abonent_energy.h"
#include "abonent_water.h"
#include <ctime>


Abonent_water::Abonent_water(std::string name,
                        std::string surname,
                        int arrears_,
                        double rate_,
                        std::string address_,
                        std::tm date_of_reg_,
                        std::tm date_of_last_check_,
                        std::tm *all_dates_,
                        int k_days_,
                        double cubes_)
: Abonent(name, surname,  arrears_, rate_, address_, date_of_reg_,  date_of_last_check_, all_dates_, k_days_)
{
    cubes = cubes_;
}
Abonent_water::Abonent_water(const Abonent_water& other)
: Abonent(other)
{
    cubes = other.cubes;

}

Abonent_water& Abonent_water::operator=(const Abonent_water& other)
{
    if (this != &other)
    {
        Abonent::operator=(other);
        cubes = other.cubes;
    }
    return *this;
}

Abonent& Abonent_water::operator=(const Abonent& other)
{
    if (const Abonent_water *derived = dynamic_cast<const Abonent_water *>(&other))
    {

        if (this != *&derived)
        {
            Abonent::operator=(other);
            cubes = derived->cubes;
        }
    }
    return *this;
}



Abonent_water::Abonent_water()
: Abonent()
{
    cubes = 0;
}

Abonent_water::~Abonent_water()
{
}

void Abonent_water::set_cubes(double cubes_)
{
    cubes = cubes_;
}
double Abonent_water::get_cubes()
{
    return cubes;
}
double Abonent_water::get_total_price()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now= std::localtime(&t);
    if (now->tm_mon <= 4 || now->tm_mon >=7 )
    {
        return rate*cubes*2;
    }
    return rate*cubes/2;
}

void Abonent_water::print(std::ostream& f)
{
    Abonent::print(f);
    if (&f == &std::cout)
    {
        f << "cubes: " << cubes << "\n";
        std::cout << std::endl;
    }
    else {
        f << cubes;
    }
}
void Abonent_water::readFromFile(std::istream& in)
{
    Abonent::readFromFile(in);
    in >> cubes;
}   





