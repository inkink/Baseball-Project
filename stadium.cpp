#include "stadium.h"

Stadium::Stadium()
{
    openDate = Date();
    teamName = "none";
    stadiumName = "none";
    state = "na";
    phoneNum = "000-000-0000";
    address = "none";
    capacity =0;
    league = 0;
    grass = 0;

}
Stadium::Stadium(string team, string stadium, string a, string s,
                 string phone, Date date, int cap, bool l, bool g){
    teamName = team;
    stadiumName = stadium;
    address =a;
    openDate =date;
    phoneNum = phone;
    capacity =cap;
    grass = g;
    league = l;
    state = s;
}

string Stadium::getTeamName(){
    return teamName;
}

string Stadium::getAddress(){
    return address;
}

Date Stadium::getOpenDate(){
    return openDate;
}

int Stadium::getCapacity(){
    return capacity;
}

void Stadium::setTeam(string team){
    teamName = team;
}

void Stadium::setAddress(string address){
    this->address = address;
}

void Stadium::setOpenDate(Date date){
    openDate = date;
}

void Stadium::setCapacity(int cap){
    capacity = cap;
}

bool Stadium::operator==(Stadium two){
    return(teamName==two.teamName);
}

bool Stadium::operator>(Stadium two){
    return(teamName>two.teamName);
}

bool Stadium::operator<(Stadium two){
    return(teamName<two.teamName);
}

bool Stadium::operator>=(Stadium two){
    return(teamName>=two.teamName);
}

bool Stadium::operator<=(Stadium two){
    return(teamName<=two.teamName);
}

string Stadium::getState() const
{
    return state;
}

void Stadium::setState(const string &value)
{
    state = value;
}

bool Stadium::getLeague() const
{
    return league;
}

void Stadium::setLeague(bool value)
{
    league = value;
}

bool Stadium::getGrass() const
{
    return grass;
}

void Stadium::setGrass(bool value)
{
    grass = value;
}

string Stadium::getStadiumName() const
{
    return stadiumName;
}

void Stadium::setStadiumName(const string &value)
{
    stadiumName = value;
}

ostream& operator<<(ostream& out, const Stadium& one){
    out<<one.teamName<<endl;
    //    out<<one.address<<endl;
    //    out<<one.phoneNum<<endl;
//    out<<one.openDate<<endl;
//    out<<one.capacity<<endl;
    return out;
}
