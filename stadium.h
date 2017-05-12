#ifndef STADIUM_H
#define STADIUM_H
#include "iostream"

class Stadium
{
public:
    Stadium();
    Stadium(std::string team="", std::string address="", std::string date="", int cap=0);
    std::string getTeamName();
    std::string getAddress();
    std::string getOpenDate();
    int getCapacity();
    void setTeam(std::string team);
    void setAddress(std::string address);
    void setOpenDate(std::string date);
    void setCapacity(int cap);
private:
    std::string TeamName;
    std::string Address;
    std::string OpenDate;
    int Capacity;
};

#endif // STADIUM_H
