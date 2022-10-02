
#ifndef ABONENT_ABONENT_H
#define ABONENT_ABONENT_H

#include <iostream>
#include <string>
#include <ctime>

std::tm Date(int year, int month, int day);


class Abonent {
    protected:
        std::string name, surname, address;
        std::tm date_of_reg, date_of_last_check;
        std::tm *all_dates;
        int k_days;
        int size;
        double rate;
        int standard;
        bool arrears;
    public:
        Abonent();
        Abonent(    std::string name,
                    std::string surname,
                    bool arrears_,
                    double rate_,
                    std::string address_,
                    std::tm date_of_reg_,
                    std::tm date_of_last_check_,
                    std::tm *all_dates_,
                    int k_days_
                );
        Abonent(const Abonent& other);
        virtual ~Abonent();


        void set_name(std::string name_);
        void set_surname(std::string surname_);
        void set_address(std::string address_);
        void set_date_of_reg(int day, int month, int year);
        void set_date_of_last_check(int day, int month, int year);
        void set_all_dates(std::tm* all_dates_, int k_days_);
        void set_rate(double rate_);
        void set_standard(int standard_);
        void set_arrears(bool arrears_);

        std::string get_name();
        std::string get_surname();
        std::string get_address();
        std::tm get_date_of_reg();
        std::tm get_date_of_last_check();
        std::tm* get_all_dates();
        double get_rate();
        int get_standard();
        bool get_arrears();
        
        virtual int service_costs();
        virtual bool is_overdue();
        virtual int term_to_check();

        virtual void print(std::ostream& f);
        virtual void readFromFile(std::istream& in);
};  

#endif