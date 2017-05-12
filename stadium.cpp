#include "stadium.h"

Stadium::Stadium()
{
//    Date temp;
    teamName ="";
    phoneNum = "(000)000-0000";
    capacity =0;
}
Stadium::Stadium(string team, Address a, string phone, Date date, int cap ){
    teamName =team;
    address =a;
    openDate =date;
    phoneNum = phone;
    capacity =cap;
}

string Stadium::getTeamName(){
    return teamName;
}

Address Stadium::getAddress(){
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

void Stadium::setAddress(Address address){
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

ostream& operator<<(ostream& out, const Stadium& one){
    out<<one.teamName<<endl;
    out<<one.address<<endl;
    out<<one.phoneNum<<endl;
    out<<one.openDate<<endl;
    out<<one.capacity<<endl;
    return out;
}
