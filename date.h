#ifndef DATE_H
#define DATE_H
#include "string"
#include <iostream>

using namespace std;

class Date
{
public:
    Date();                                                     //default constructor
    Date(int m, int d, int y);                                  //param constructor
    int getMonth() const;                                       //return month
    void setMonth(int value);                                   //assign new month
    int getYear() const;                                        //return year
    void setYear(int value);                                    //assign new year
    int getDay() const;                                         //return day
    void setDay(int value);                                     //assign new day
    std::string getString() const;                              //return string form
    void operator=(const Date& date);                           //overloaded =
    bool operator<=(const Date& other) const;                   //overloaded <=
    bool operator>=(const Date& other) const;                   //overloaded >=
    bool operator<(const Date& other) const;                    //overloaded <
    bool operator>(const Date& other) const;                    //overloaded >
    bool operator==(const Date& other) const;                   //overloaded ==
    bool operator!=(const Date& other) const;                   //overloaded !=
    friend ostream& operator <<(ostream& out, const Date& d);   //overloaded <<
private:
    int month;                                                  //month num
    int day;                                                    //day num
    int year;                                                   //year num
};

#endif // DATE_H
