#ifndef STADIUM_H
#define STADIUM_H
#include "iostream"
#include "date.h"
#include "address.h"
using namespace std;

class Stadium
{
public:
    Stadium();

    Stadium(string team, Address a, string phone, Date date, int cap);
    std::string getTeamName();
    Address getAddress();
    Date getOpenDate();
    std::string getPhoneNum();
    int getCapacity();
    void setTeam(string team);
    void setAddress(Address address);
    void setOpenDate(Date date);
    void setPhoneNum(string num);
  
    void setCapacity(int cap);
    bool operator==(Stadium two);
    bool operator>(Stadium two);
    bool operator<(Stadium two);
    bool operator>=(Stadium two);
    bool operator<=(Stadium two);
    friend ostream& operator<<(ostream& out, const Stadium& one);

private:

    std::string TeamName;
    std::string Address;
    std::string OpenDate;
    std::string PhoneNum;
    int Capacity;
};

#endif // STADIUM_H
