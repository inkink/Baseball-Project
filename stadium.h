#ifndef STADIUM_H
#define STADIUM_H
#include <vector>
#include <algorithm>
#include "iostream"
#include "date.h"
#include "souvenir.h"
using namespace std;


class Stadium
{
public:
    Stadium();
    Stadium(string team, string stadium, string a, string s,
            string phone, Date date, int cap, bool l, bool g);
    string getTeamName();
    string getAddress();
    Date getOpenDate();
    string getPhoneNum();
    int getCapacity();
    void setTeam(string team);
    void setAddress(string address);
    void setOpenDate(Date date);
    void setPhoneNum(string num);
    void setCapacity(int cap);
    bool operator==(Stadium two);
    bool operator>(Stadium two);
    bool operator<(Stadium two);
    bool operator>=(Stadium two);
    bool operator<=(Stadium two);
    friend ostream& operator<<(ostream& out, const Stadium& one);

    string getState() const;
    void setState(const string &value);

    bool getLeague() const;
    void setLeague(bool value);

    bool getGrass() const;
    void setGrass(bool value);

    string getStadiumName() const;
    void setStadiumName(const string &value);

    void addSouvenir(string name, double cost);
    void removeSouvenir(string itemName);
    void modifySouvenir(string itemName, string name, double cost);
    bool findSouvenir(string s);
    Souvenir getSouvenir(string s);
    string displaySouvenir();

private:
    string teamName;
    string stadiumName;
    string address;
    string state;
    Date openDate;
    string phoneNum;
    int capacity;
    bool league; //national = 0 , american = 1
    bool grass;
    vector<Souvenir> souvenirs;
};

struct StadiumNameComparator
{
    bool operator()(Stadium s1, Stadium s2)
    {
        return s1.getStadiumName() < s2.getStadiumName();
    }
};

struct TeamNameComparator
{
    bool operator()(Stadium s1, Stadium s2)
    {
        return s1.getTeamName() < s2.getTeamName();
    }
};

struct StadiumDateComparator
{
    bool operator()(Stadium s1, Stadium s2)
    {
        return s1.getOpenDate() < s2.getOpenDate();
    }
};

#endif // STADIUM_H
