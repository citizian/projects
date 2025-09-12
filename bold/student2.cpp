#include "studenti.h"
using std::string;
using std::ostream;
using std::istream;
using std::endl;

double Student::Average() const {
    if (ArrayDb::size() > 0) {
        return ArrayDb::sum() / ArrayDb::size();
    } else {
        return 0.0; // Avoid division by zero
    }
}

const string& Student::Name() const {
    return (const string&) *this; // Cast to const string
}

double& Student::operator[](int i) {
    return ArrayDb::operator[](i); // Access the valarray element
}

double Student::operator[](int i) const {
    return ArrayDb::operator[](i); // Access the valarray element
}

ostream& Student::arr_out(ostream& os) const {
    int i;
    int lim = ArrayDb::size();
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4) {
                os << endl; // New line every 5 elements
            }
        }
        if (i % 5 != 0) {
            os << endl; // Ensure a new line at the end
        }
    } else {
        os << "Empty array.";
    }
    return os;
}

istream & operator>>(istream & is, Student & stu) {
    is >> (string &)stu;
    return is;
}
istream & getline(istream & is, Student & stu) {
    getline(is, (string &)stu);
    return is;
}
ostream & operator<<(ostream & os, const Student & stu) {
    os << "Scores for " << (const string &)stu << ":\n";
    stu.arr_out(os);
    return os;
}