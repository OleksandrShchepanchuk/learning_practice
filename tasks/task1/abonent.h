
#ifndef ABONENT_ABONENT_H
#define ABONENT_ABONENT_H

#include "date.h"
#include <iostream>
#include <string>





class Abonent {
    std::string name, surname, address;
    Date date_of_reg, date_of_last_check;
    Date all_dates[10000];
    bool arrears;
    double rate;
    int standard = 3;
    public:
        Abonent(    bool arrears_,
                    double rate_,
                    std::string address,
                    Date date_of_reg_,
                    Date date_of_last_check_,
                    Date all_dates_
                );
        int service_costs(){
            // return rate ? if 
        }
};

#endif