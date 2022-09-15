
#ifndef ABONENT_ABONENT_H
#define ABONENT_ABONENT_H

#include "date.h"
#include <iostream>
#include <string>





class Abonent {
    private:
        std::string name, surname, address;
        Date date_of_reg, date_of_last_check;
        Date *all_dates;
        int size;
        bool arrears;
        double rate;
        int standard = 3;
    public:
        Abonent();
        Abonent(    bool arrears_,
                    double rate_,
                    std::string address,
                    Date date_of_reg_,
                    Date date_of_last_check_,
                    Date *all_dates_
                );
        Abonent(const Abonent& other);

        void set_name(std::string name_) {
            name = name_;
        }
        void set_surname(std::string surname_) {
            surname = surname_;
        }
        void set_address(std::string address_) {
            address = address_;
        }
        void set_date_of_reg(int day, int month, int year) {
            date_of_reg = Date(day, month, year);
        }
        void set_date_of_last_check(int day, int month, int year) {
            date_of_reg = Date(day, month, year);
        }

        int service_costs(){
            // return rate ? if 
        }
};  

#endif