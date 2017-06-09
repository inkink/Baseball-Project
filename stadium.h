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
    Stadium();                                                      //constructor
    Stadium(string team, string stadium, string a, string s,
            string phone, Date date, int cap, bool l, bool g);      //param constructor
    string getTeamName();                                           //return team name
    string getAddress();                                            //return stadium address
    Date getOpenDate();                                             //return date opened
    string getPhoneNum();                                           //return phone num
    int getCapacity();                                              //return capacity
    void setTeam(string team);                                      //assign new team
    void setAddress(string address);                                //assign new address
    void setOpenDate(Date date);                                    //assign new open date
    void setPhoneNum(string num);                                   //assign new phone num
    void setCapacity(int cap);                                      //assign new capacity
    bool operator==(Stadium two);                                   //overloaded==
    bool operator>(Stadium two);                                    //overloaded>
    bool operator<(Stadium two);                                    //overloaded<
    bool operator>=(Stadium two);                                   //overloaded>=
    bool operator<=(Stadium two);                                   //overloaded<=
    friend ostream& operator<<(ostream& out, const Stadium& one);   //overloaded<<
    string getState() const;                                        //return state
    void setState(const string &value);                             //assign new state
    bool getLeague() const;                                         //return league
    void setLeague(bool value);                                     //assign new league
    bool getGrass() const;                                          //return if grass
    void setGrass(bool value);                                      //assign if grass
    string getStadiumName() const;                                  //return stadium name
    void setStadiumName(const string &value);                       //assign new stadium name
    void addSouvenir(string name, double cost);                     //add souvenir to shop
    void removeSouvenir(string itemName);                           //remove souvenir from shop
    void modifySouvenir(string itemName, string name, double cost); //change souvenir info
    bool findSouvenir(string s);                                    //check if souvenir exists
    Souvenir getSouvenir(string s);                                 //return souvenir
    string displaySouvenir();                                       //display souvenir info

private:
    string teamName;                                                //team name
    string stadiumName;                                             //stadium name
    string address;                                                 //address
    string state;                                                   //state located
    Date openDate;                                                  //date opened
    string phoneNum;                                                //phone number
    int capacity;                                                   //max capacity
    bool league;                                                    //national = 0 , american = 1
    bool grass;                                                     //if grass field
    vector<Souvenir> souvenirs;                                     //list of souvenirs
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
