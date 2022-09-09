#include "abonent.h"
#include "date.h"








Abonent::Abonent(   bool arrears_,
                    double rate_,
                    std::string address_,
                    Date date_of_reg_,
                    Date date_of_last_check_,
                    Date all_dates_
                ) 
            {
                arrears             = arrears_;
                rate                = rate_;
                address             = address_;
                date_of_reg         = date_of_reg_;
                date_of_last_check  = date_of_last_check_;
            }