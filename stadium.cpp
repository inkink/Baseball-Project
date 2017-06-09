#include "stadium.h"

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The constructor creates a stadium with all of the info
 * of its location, team, and stadium type
 * *******************************************************/
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
    souvenirs.reserve(50);
}

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * team    - team name
 * stadium - stadium name
 * a       - address
 * date    - opening date
 * phone   - phone number
 * cap     - capacity
 * l       - league
 * g       - grass
 *
 * POST-CONDITIONS
 * The constructor creates a stadium with all of the info
 * of its location, team, and stadium type
 * *******************************************************/
Stadium::Stadium(string team, string stadium, string a, string s,
                 string phone, Date date, int cap, bool l, bool g){
    teamName = team;
    stadiumName = stadium;
    address =a;
    openDate =date;
    phoneNum = phone;
    capacity =cap;
    grass = g;
    state = s;
    league = l;
    souvenirs.reserve(50);
    addSouvenir("Baseball cap", 25.99);
    addSouvenir("Baseball bat", 35.35);
    addSouvenir("Team pennant", 12.99);
    addSouvenir("Autographed baseball", 19.99);
}

/***********************************************************
 * FUNCTION getTeamName O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the team name
 * *******************************************************/
string Stadium::getTeamName(){
    return teamName;
}

/***********************************************************
 * FUNCTION getAddress O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the stadium address
 * *******************************************************/
string Stadium::getAddress(){
    return address;
}

/***********************************************************
 * FUNCTION getOpenDate O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the date opened
 * *******************************************************/
Date Stadium::getOpenDate(){
    return openDate;
}

/***********************************************************
 * FUNCTION getPhoneNum O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the phone number
 * *******************************************************/
string Stadium::getPhoneNum()
{
    return phoneNum;
}

/***********************************************************
 * FUNCTION getCapacity O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the capacity of the stadium
 * *******************************************************/
int Stadium::getCapacity(){
    return capacity;
}

/***********************************************************
 * FUNCTION setTeam O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * team - new team name
 *
 * POST-CONDITIONS
 * The function will assign a new team name
 * *******************************************************/
void Stadium::setTeam(string team){
    teamName = team;
}

/***********************************************************
 * FUNCTION setAddress O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * address - new address
 *
 * POST-CONDITIONS
 * The function will assign a new address
 * *******************************************************/
void Stadium::setAddress(string address){
    this->address = address;
}

/***********************************************************
 * FUNCTION setOpenDate O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * date - new date
 *
 * POST-CONDITIONS
 * The function will assign a new open date
 * *******************************************************/
void Stadium::setOpenDate(Date date){
    openDate = date;
}

/***********************************************************
 * FUNCTION setCapacity O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * cap - new capacity
 *
 * POST-CONDITIONS
 * The function will assign a new max capacity for the stadium
 * *******************************************************/
void Stadium::setCapacity(int cap){
    capacity = cap;
}

/***********************************************************
 * FUNCTION operator== O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * two - stadium to check
 *
 * POST-CONDITIONS
 * The function will return true if equal team names
 * *******************************************************/
bool Stadium::operator==(Stadium two){
    return(teamName==two.teamName);
}

/***********************************************************
 * FUNCTION operator> O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * two - stadium to check
 *
 * POST-CONDITIONS
 * The function will return true if greater team name
 * *******************************************************/
bool Stadium::operator>(Stadium two){
    return(teamName>two.teamName);
}

/***********************************************************
 * FUNCTION operator< O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * two - stadium to check
 *
 * POST-CONDITIONS
 * The function will return true if less team name
 * *******************************************************/
bool Stadium::operator<(Stadium two){
    return(teamName<two.teamName);
}

/***********************************************************
 * FUNCTION operator>= O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * two - stadium to check
 *
 * POST-CONDITIONS
 * The function will return true if greater than or equal
 * team name
 * *******************************************************/
bool Stadium::operator>=(Stadium two){
    return(teamName>=two.teamName);
}

/***********************************************************
 * FUNCTION operator<= O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * two - stadium to check
 *
 * POST-CONDITIONS
 * The function will return true if less than or equal
 * team name
 * *******************************************************/
bool Stadium::operator<=(Stadium two){
    return(teamName<=two.teamName);
}

/***********************************************************
 * FUNCTION getState O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the state of stadium
 * *******************************************************/
string Stadium::getState() const
{
    return state;
}

/***********************************************************
 * FUNCTION setState O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new state
 *
 * POST-CONDITIONS
 * The function will assign the stadium a new state
 * *******************************************************/
void Stadium::setState(const string &value)
{
    state = value;
}

/***********************************************************
 * FUNCTION getLeague O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the league of stadium
 * *******************************************************/
bool Stadium::getLeague() const
{
    return league;
}

/***********************************************************
 * FUNCTION setLeague O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new league
 *
 * POST-CONDITIONS
 * The function will assign the stadium a new league
 * *******************************************************/
void Stadium::setLeague(bool value)
{
    league = value;
}

/***********************************************************
 * FUNCTION getGrass O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the grass of stadium
 * *******************************************************/
bool Stadium::getGrass() const
{
    return grass;
}

/***********************************************************
 * FUNCTION setGrass O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new grass
 *
 * POST-CONDITIONS
 * The function will assign the stadium a new grass value
 * *******************************************************/
void Stadium::setGrass(bool value)
{
    grass = value;
}

/***********************************************************
 * FUNCTION getStadiumName O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the name of stadium
 * *******************************************************/
string Stadium::getStadiumName() const
{
    return stadiumName;
}

/***********************************************************
 * FUNCTION setStadiumName O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new state
 *
 * POST-CONDITIONS
 * The function will assign the stadium a new name
 * *******************************************************/
void Stadium::setStadiumName(const string &value)
{
    stadiumName = value;
}

/***********************************************************
 * FUNCTION addSouvenir O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * name - name of new souvenir
 * cost - cost of new souvenir
 *
 * POST-CONDITIONS
 * The function will add the new souvenir to the stadium
 * *******************************************************/
void Stadium::addSouvenir(string name, double cost)
{
    Souvenir newItem(stadiumName, name, cost);
    souvenirs.push_back(newItem);
}

/***********************************************************
 * FUNCTION removeSouvenir O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * itemName - souvenir to remove
 *
 * POST-CONDITIONS
 * The function will remove the souvenir from the stadium
 * *******************************************************/
void Stadium::removeSouvenir(string itemName)
{
    for(int i=0; i<souvenirs.size(); i++)
    {
        if(souvenirs[i].getItem() == itemName)
        {
            souvenirs.erase(souvenirs.begin()+i);
        }
    }
}

/***********************************************************
 * FUNCTION modifySouvenir O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * itemName - name of souvenir
 * name     - new name
 * cost     - new cost
 *
 * POST-CONDITIONS
 * The function will return the modify the name and cost
 * of a souvenir
 * *******************************************************/
void Stadium::modifySouvenir(string itemName, string name, double cost)
{
    for(int i=0; i<souvenirs.size(); i++)
    {
        if(souvenirs[i].getItem() == itemName)
        {
            souvenirs[i].setItem(name);
            souvenirs[i].setPrice(cost);
        }
    }
}

/***********************************************************
 * FUNCTION findSouvenir O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * s - souvenir to find
 *
 * POST-CONDITIONS
 * The function will return if the souvenir exists
 * *******************************************************/
bool Stadium::findSouvenir(string s)
{
    for(int i=0; i<souvenirs.size(); i++)
    {
        if(souvenirs[i].getItem() == s)
            return true;
    }
    return false;
}

/***********************************************************
 * FUNCTION getSouvenir O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * s - souvenir to get
 *
 * POST-CONDITIONS
 * The function will return souvenir from the stadium
 * *******************************************************/
Souvenir Stadium::getSouvenir(string s)
{
    for(int i=0; i<souvenirs.size(); i++)
    {
        if(souvenirs[i].getItem() == s)
            return souvenirs[i];
    }
    return souvenirs[0];
}

/***********************************************************
 * FUNCTION displaySouvenir O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the string to be displayed
 * in the gui for souvenirs
 * *******************************************************/
string Stadium::displaySouvenir()
{
    string result = "";
    for(int i=0; i<souvenirs.size(); i++)
    {
        result += "- " + souvenirs[i].getOriginName() + ", "
                + souvenirs[i].getItem() + ", $"
                + std::to_string(souvenirs[i].getPrice()) + "\n";
    }
    return result;
}

/***********************************************************
 * FUNCTION operator<< O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * out - output stream
 * one - stadium to output
 *
 * POST-CONDITIONS
 * The function will return the output of the stadium to
 * be displayed
 * *******************************************************/
ostream& operator<<(ostream& out, const Stadium& one){
    out<<one.teamName<<endl;
    return out;
}
