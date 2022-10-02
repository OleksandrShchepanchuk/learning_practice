
#ifndef ABONENT_ENERGY_H
#define ABONENT_ENERGY_H

#include <iostream>
#include "abonent.h"
#include <string>
#include <ctime>



class Abonent_energy: public Abonent
{
    private:
        double start_data;
        double end_data;
    public:
        Abonent_energy(std::string name,
                        std::string surname,
                        bool arrears_,
                        double rate_,
                        std::string address_,
                        std::tm date_of_reg_,
                        std::tm date_of_last_check_,
                        std::tm *all_dates_,
                        int k_days_,
                        double start_data_,
                        double end_data_);
        Abonent_energy();   
        virtual ~Abonent_energy();
        void set_start_data(double start_data_);
        double get_start_data();
        void set_end_data(double end_data_);
        double get_end_data();
        double get_total_price();
        void print(std::ostream& f);
        void readFromFile(std::istream& in);
};


#endif