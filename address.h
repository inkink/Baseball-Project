#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include "iostream"
using namespace std;

class Address
{
public:
    Address();                                                  //default constructor
    Address(std::string a, std::string c, std::string s, int z);//param constructor
    bool is_cal() const;                                        //check if CA
    std::string getAddress() const;                             //return address
    void setAddress(const std::string &value);                  //assign new address
    std::string getCity() const;                                //return city
    void setCity(const std::string &value);                     //assign new city
    std::string getState() const;                               //return state
    void setState(const std::string &value);                    //assign new state
    int getZip() const;                                         //return zip
    void setZip(int value);                                     //assign new zip
    void operator=(const Address& a);                           //overloaded equality
    friend ostream& operator <<(ostream& out, const Address& d);//overloaded output

private:
    std::string address;                                        //holds address
    std::string city;                                           //holds city
    std::string state;                                          //holds state
    int zip;                                                    //holds zipcode

};

#endif // ADDRESS_H
