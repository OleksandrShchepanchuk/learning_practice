
#ifndef ABONENT_WATER_H
#define ABONENT_WATER_H

#include <iostream>
#include "abonent.h"
#include <string>
#include <ctime>


class Abonent_water: public  Abonent
{
    private:
        double cubes;
    public:
        Abonent_water(std::string name,
                        std::string surname,
                        int arrears_,
                        double rate_,
                        std::string address_,
                        std::tm date_of_reg_,
                        std::tm date_of_last_check_,
                        std::tm *all_dates_,
                        int k_days_,
                        double cubes);
        Abonent_water();
        Abonent& operator=(const Abonent& other);
        Abonent_water(const Abonent_water& other);
        Abonent_water& operator=(const Abonent_water& other);
        virtual ~Abonent_water();
        void set_cubes(double cubes_);
        double get_cubes();
        double get_total_price();
        void print(std::ostream& f);
        void readFromFile(std::istream& in);
};


#endif