#include <algorithm>
#include <vector>

#include "Intl.h"

istream& read_hw(istream& in, std::vector<double>& hw);

istream& Intl::read(istream& in) {
    Core::read_common(in); 
    in >> toeic;           
    read_hw(in, homework); 
    return in;
}

double Intl::grade() const {
    double base_grade = Core::grade();
    return (base_grade + (toeic / 100.0)) / 2.0;
}