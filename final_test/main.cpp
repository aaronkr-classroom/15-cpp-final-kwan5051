#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>

#include "Core.h"
#include "Intl.h"
#include "Vec.h"
#include "Student_info.h"
#include "median.h"
#include "Grad.h"

using namespace std;

int main() {
    vector<Core*> students;
    Core* record;
    char ch;
    string::size_type maxlen = 0;

    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else if (ch == 'G')
            record = new Grad;
        else if (ch == 'I') 
            record = new Intl;
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        record->read(cin);
        maxlen = max(maxlen, record->getName().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_ptrs);

    for (vector<Core*>::size_type i = 0; i != students.size(); i++) {
        if (dynamic_cast<Intl*>(students[i])) {
            cout << "(I) ";
        }
        else if (dynamic_cast<Grad*>(students[i])) {
            cout << "(G) ";
        }
        else {
            cout << "(U) ";
        }

        cout << students[i]->getName()
            << string(maxlen + 1 - students[i]->getName().size(), ' ');

        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what() << endl;
        }

        delete students[i];
    }

    return 0;
}