#include "stadium.h"

Stadium::Stadium()
{
//    Date temp;
    TeamName ="";
    PhoneNum = "(000)000-0000";
    Capacity =0;
}
Stadium::Stadium(string team, Address a, string phone, Date date, int cap ){
    TeamName =team;
    address =a;
    OpenDate =date;
    PhoneNum = phone;
    Capacity =cap;
}

string Stadium::getTeamName(){
    return TeamName;
}

Address Stadium::getAddress(){
    return address;
}

Date Stadium::getOpenDate(){
    return OpenDate;
}

int Stadium::getCapacity(){
    return Capacity;
}

void Stadium::setTeam(string team){
    TeamName = team;
}

void Stadium::setAddress(Address address){
    this->address = address;
}

void Stadium::setOpenDate(Date date){
    OpenDate = date;
}

void Stadium::setCapacity(int cap){
    Capacity = cap;
}

bool Stadium::operator==(Stadium two){
    return(TeamName==two.TeamName);
}

bool Stadium::operator>(Stadium two){
    return(TeamName>two.TeamName);
}

bool Stadium::operator<(Stadium two){
    return(TeamName<two.TeamName);
}

bool Stadium::operator>=(Stadium two){
    return(TeamName>=two.TeamName);
}

bool Stadium::operator<=(Stadium two){
    return(TeamName<=two.TeamName);
}

ostream& operator<<(ostream& out, const Stadium& one){
    out<<one.TeamName<<endl;
    out<<one.address<<endl;
    out<<one.PhoneNum<<endl;
    out<<one.OpenDate<<endl;
    out<<one.Capacity<<endl;
    return out;
}
