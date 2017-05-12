#include "address.h"

Address::Address()
{
    address= "";
    city = "";
    state = "";
    zip = 0;
}

Address::Address(std::string a, std::string c, std::string s, int z){
    address = a;
    city = c;
    state = s;
    zip = z;
}

bool Address::is_cal() const{
    return (state == "CA");
}

std::string Address::getAddress() const{
    return address;
}

void Address::setAddress(const std::string &value){
    address = value;
}

std::string Address::getCity() const{
    return city;
}

void Address::setCity(const std::string &value){
    city = value;
}

std::string Address::getState() const{
    return state;
}

void Address::setState(const std::string &value){
    state = value;
}

int Address::getZip() const{
    return zip;
}

void Address::setZip(int value){
    zip = value;
}

void Address::operator=(const Address& a){
    address = a.address;
    city = a.city;
    state = a.state;
    zip = a.zip;
}

ostream& operator <<(ostream& out, const Address& d){
    out<<d.address<<endl;
    out<<d.city<<", "<<d.state<<" "<<d.zip;
    return out;
}
