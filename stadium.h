#ifndef STADIUM_H
#define STADIUM_H
#include "iostream"

class Stadium
{
public:
//    Stadium();
    Stadium(string team="", string address="", string date="", int cap=0);
    string getTeamName();
    string getAddress();
    string getOpenDate();
    int getCapacity();
    void setTeam(string team);
    void setAddress(string address);
    void setOpenDate(string date);
    void setCapacity(int cap);
private:
    string TeamName;
    string Address;
    string OpenDate;
    int Capacity;
};

#endif // STADIUM_H
