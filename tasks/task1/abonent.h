
#ifndef ABONENT_ABONENT_H
#define ABONENT_ABONENT_H

#include <iostream>
#include <string>
#include <ctime>

std::tm Date(int year, int month, int day);

const int VALUE = 1000;

class Abonent {
    protected:
        std::string name, surname, address;
        std::tm date_of_reg, date_of_last_check;
        std::tm *all_dates;
        int k_days;
        int size;
        double rate;
        int standard;
        int arrears;
        std::string date_to_string(std::tm);
    public:
        Abonent();
        Abonent(    std::string name,
                    std::string surname,
                    int arrears_,
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
        void set_arrears(int arrears_);

        std::string get_name() const;
        std::string get_surname() const;
        std::string get_address() const;
        std::tm get_date_of_reg() const;
        std::tm get_date_of_last_check() const;
        std::tm* get_all_dates() const;
        double get_rate() const;
        int get_standard() const;
        int get_arrears() const;
        int get_k_days() const;

        
        
        virtual int service_costs();
        virtual bool is_overdue();
        virtual int term_to_check();

        virtual double get_total_price();
        virtual void print(std::ostream& f);
        virtual void readFromFile(std::istream& in);

        friend std::ostream& operator << (std::ostream& os, Abonent& A);
        friend std::istream& operator >> (std::istream& is, Abonent& A);

        friend Abonent operator + (Abonent& abonent, Abonent& abonent1);
        friend Abonent operator - (Abonent& abonent, Abonent& abonent1);

        friend bool operator < (Abonent& abonent, Abonent& abonent1);
        friend bool operator > (Abonent& abonent, Abonent& abonent1);
        friend bool operator == (Abonent& abonent, Abonent& abonent1);
        friend bool operator != (Abonent& abonent, Abonent& abonent1);
        operator std::string();
        Abonent operator++();
        Abonent operator++(int);
        virtual Abonent& operator=(const Abonent& other);
};  

#endif