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
    string getTeamName();
    Address getAddress();
    Date getOpenDate();
    string getPhoneNum();
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
    string teamName;
    Address address;
    Date openDate;
    string phoneNum;
    int capacity;
};

#endif // STADIUM_H
