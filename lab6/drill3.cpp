#include <iostream>

class Date {
private:
    int _d, _m, _y;
public:
    Date(int d, int m, int y) : _d(d), _m(m), _y(y) {}
    int day() { return _d; }
    int month() { return _m; }
    int year() { return _y; }
    Date add_day(int n) { Date next_day{_d + 1, _m, _y}; return next_day; }
    Date add_month(int n) { Date next_month{_d, _m + 1, _y}; return next_month; }
    Date add_year(int n) { Date next_year{_d, _m, _y + 1}; return next_year; }
    void add(int d, int m, int y) {
        _d += d;
        _m += m;
        _y += y;
        // Add logic to handle month and year rollover if needed
    }
    void print() {
        std::cout << _d << "/" << _m << "/" << _y << std::endl;
    }
};

int main() {
    Date today {19, 9, 2022};
    today.add_day(35);
    today.add_month(1);
    today.print();

    // Date tomorrow = today.add_day(1);
    // today.print();
    // tomorrow.print();
}