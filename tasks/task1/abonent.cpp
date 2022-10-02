#include "abonent.h"
#include <iostream>
#include <ctime>
#include <fstream>

const int VALUE = 1000;
std::tm Date(int year, int month, int day)
{
    std::tm tm = {0};
    tm.tm_year = year - 1900; // years count from 1900
    tm.tm_mon = month - 1;    // months count from January=0
    tm.tm_mday = day;         // days count from 1
    return tm;
}




Abonent::Abonent(   std::string name,
                    std::string surname,
                    bool arrears_,
                    double rate_,
                    std::string address_,
                    std::tm date_of_reg_,
                    std::tm date_of_last_check_,
                    std::tm *all_dates_,
                    int k_days_
                ) 
{
    all_dates = new std::tm[VALUE];
    arrears             = arrears_;
    rate                = rate_;
    address             = address_;
    date_of_reg         = date_of_reg_;
    date_of_last_check  = date_of_last_check_;
    k_days = k_days_;
    standard = 3;

    for (int i = 0; i < k_days; i ++)
    {
        all_dates[i] = all_dates_[i];
    }
}

Abonent::Abonent()
{
    std::string name = "";
    std::string surname = "";
    bool arrears_ = 0;
    double rate_ = 0;
    std::string address_ = "";
    std::tm date_of_reg_ = Date(0,0,0);
    std::tm date_of_last_check_ = Date(0,0,0); 
    standard = 3;
    all_dates = new std::tm[VALUE];
    k_days = 0; 

};

Abonent::Abonent(const Abonent& other)
{
    this->address = other.address;
    this->arrears = other.arrears;
    this->date_of_last_check = other.date_of_last_check;
    this->rate = other.rate;
    this->k_days = other.k_days;
    this->all_dates = new std::tm[VALUE];
    this->date_of_reg = other.date_of_reg;
    for (int i = 0; i < this->k_days; i++)
    {
        this->all_dates[i] = other.all_dates[i];
    }
}

Abonent::~Abonent()
{
    delete[] this->all_dates;
}

void Abonent::set_name(std::string name_) {
    name = name_;
}


void Abonent::set_surname(std::string surname_) {
    surname = surname_;
}


void Abonent::set_address(std::string address_) {
    address = address_;
}


void Abonent::set_date_of_reg(int day, int month, int year) {
    date_of_reg = Date(day, month, year);
}


void Abonent::set_date_of_last_check(int year, int month, int day) {
    date_of_last_check = Date(year, month, day);
}

void Abonent::set_all_dates(std::tm* all_dates_, int k_days_)
{
    delete[] all_dates;
    all_dates = new std::tm[VALUE];
    k_days = k_days_;
    for (int i = 0; i < k_days; i++)
    {
        all_dates[i] = all_dates_[i];
    }
}

void Abonent::set_rate(double rate_)
{
    rate = rate_;
}

void Abonent::set_standard(int standard_)
{
    standard = standard_;
}


void Abonent::set_arrears(bool arrears_)
{
    arrears = arrears_;
}


std::string Abonent::get_name()
{
    return name;
}

std::string Abonent::get_surname()
{
    return surname;
}

std::string Abonent::get_address()
{
    return address;
}

std::tm Abonent::get_date_of_reg()
{
    return date_of_reg;
}

std::tm Abonent::get_date_of_last_check()
{
    return date_of_last_check;
}

double Abonent::get_rate()
{
    return rate;
}

int Abonent::get_standard()
{
    return standard;
}

std::tm *Abonent::get_all_dates()
{
    std::tm *array_to_return = new std::tm[VALUE];
    for (int i =0; i < k_days; i++)
    {
        array_to_return[i] = all_dates[i];    
    }
    return array_to_return;
    // return all_dates;
}

bool Abonent::get_arrears()
{
    return arrears;
}

int Abonent::service_costs()
{
    if (this->is_overdue())
    {
        return rate*3;
    }
    else {
        return rate;
    }
}

bool Abonent::is_overdue()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now= std::localtime(&t);
    time_t time1 = mktime(now);
    time_t time2 = mktime(&date_of_last_check);
    const int seconds_per_day = 60*60*24;
    const int seconds_per_year = 31556926;
    double portable_difference = std::difftime(time1, time2) / seconds_per_year;
    if (portable_difference > standard)
    {
        return 1;
    }
    else return 0;
}

int Abonent::term_to_check()
{
    std::time_t t = std::time(0);
    time_t time2 = mktime(&date_of_last_check);
    const int seconds_per_day = 60*60*24;
    std::tm* now= std::localtime(&t);
    time_t time1 = mktime(now);
    double seconds = (time2 + (31556926 * 3) - time1)/seconds_per_day;
    return seconds;
}





void Abonent::print(std::ostream& f)
{
    f << "name: " << name << " " << surname << std::endl;
    f << "arrears " << arrears << std::endl;
    f << "rate " << rate << std::endl;
    f << "address " << address << std::endl;
    f << "date of registration " << date_of_reg.tm_mday<<" " <<date_of_reg.tm_mon + 1 << " " << date_of_reg.tm_year + 1900 << std::endl;
    f << "date of last check " << date_of_last_check.tm_mday << " " <<date_of_last_check.tm_mon + 1 << " " << date_of_last_check.tm_year + 1900 << std::endl;
    f << "all checks" << std::endl;
    for (int i = 0; i < k_days; i++)
    {
        f << all_dates[i].tm_mday << " " <<all_dates[i].tm_mon + 1 << " " << all_dates[i].tm_year + 1900 << std::endl;
    }
}

void Abonent::readFromFile(std::istream& in) 
{

        std::string name;
        std::string surname;
        bool arrears_;
        double rate_;
        std::string address_;
        in >> name >> surname >> arrears_ >> rate_ >> address_;
        if (!name.length()) {
            return;
        }
        this->set_surname(surname);
        this->set_arrears(arrears_);
        this->set_address(address_);
        this->set_rate(rate_);

        int day1,day2,day3;
        int month1,month2,month3;
        int year1,year2, year3;
        in >> year1>> month1 >> day1;
        in >> year2 >> month2 >> day2;
        std::tm *all_dates_;
        all_dates_ = new tm[100];
        int k_days_;
        in >> k_days_;
        for (int i = 0; i < k_days_; i++)
        {
            in >> year3 >> month3 >> day3;
            all_dates_[i] = Date(year3, month3, day3);
        }

        this->set_name(name);

        this->set_date_of_reg(year1,month1,day1);
        this->set_date_of_last_check(year2,month2,day2);
        this->set_all_dates(all_dates_, k_days_);
}
