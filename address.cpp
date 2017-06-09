#include "address.h"

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The constructor creates address to store address, city,
 * state, and zipcode
 * *******************************************************/
Address::Address()
{
    address= "";
    city = "";
    state = "";
    zip = 0;
}

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * a - address
 * c - city
 * s - state
 * z - zipcode
 *
 * POST-CONDITIONS
 * The constructor creates address to store address, city,
 * state, and zipcode
 * *******************************************************/
Address::Address(std::string a, std::string c, std::string s, int z){
    address = a;
    city = c;
    state = s;
    zip = z;
}

/***********************************************************
 * FUNCTION is_cal O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return if address is in california
 * *******************************************************/
bool Address::is_cal() const{
    return (state == "CA");
}

/***********************************************************
 * FUNCTION getAddress O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the address string
 * *******************************************************/
std::string Address::getAddress() const{
    return address;
}

/***********************************************************
 * FUNCTION setAddress O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new address
 *
 * POST-CONDITIONS
 * The function will assign a new address string to value
 * *******************************************************/
void Address::setAddress(const std::string &value){
    address = value;
}

/***********************************************************
 * FUNCTION getCity O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return city
 * *******************************************************/
std::string Address::getCity() const{
    return city;
}

/***********************************************************
 * FUNCTION setCity O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new city
 *
 * POST-CONDITIONS
 * The function will assign a new city to the address
 * *******************************************************/
void Address::setCity(const std::string &value){
    city = value;
}

/***********************************************************
 * FUNCTION getState O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the state of the address
 * *******************************************************/
std::string Address::getState() const{
    return state;
}

/***********************************************************
 * FUNCTION setState O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * value - new state
 *
 * POST-CONDITIONS
 * The function will return the state of the address
 * *******************************************************/
void Address::setState(const std::string &value){
    state = value;
}

/***********************************************************
 * FUNCTION getZip O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the zipcode
 * *******************************************************/
int Address::getZip() const{
    return zip;
}

/***********************************************************
 * FUNCTION setZip O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will assign a new zipcode to the address
 * *******************************************************/
void Address::setZip(int value){
    zip = value;
}

/***********************************************************
 * FUNCTION operator== O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * a - other address to check
 *
 * POST-CONDITIONS
 * The function will return true if the address, city, state
 * and zip equals a's values
 * *******************************************************/
void Address::operator=(const Address& a){
    address = a.address;
    city = a.city;
    state = a.state;
    zip = a.zip;
}

/***********************************************************
 * FUNCTION operator<< O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * out - output stream
 * d   - address to be outputted
 *
 * POST-CONDITIONS
 * The function will return an ostream of the desired
 * output when displayed
 * *******************************************************/
ostream& operator <<(ostream& out, const Address& d){
    out<<d.address<<endl;
    out<<d.city<<", "<<d.state<<" "<<d.zip;
    return out;
}
