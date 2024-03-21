#include <iostream>
#include <string>

int main() {

    std::string date = "2011-03-01";
    size_t first_hphen = date.find('-');
    size_t last_hphen = date.rfind('-');

    if (first_hphen != std::string::npos && last_hphen != std::string::npos) {
        std::string str_year = date.substr(0, first_hphen);
        std::string str_month = date.substr(first_hphen + 1, last_hphen - first_hphen - 1);
        std::string str_day = date.substr(last_hphen + 1);

        std::cout << "year: [" << str_year << "] ";
        std::cout << "month: [" << str_month << "] ";
        std::cout << "day: [" << str_day << "]\n";
    } else {
        std::cout << "Invalid date format\n";
    }
}