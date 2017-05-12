#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include "iostream"
using namespace std;

class Address
{
public:
    Address();
    Address(std::string a, std::string c, std::string s, int z);

    bool is_cal() const;

    std::string getAddress() const;
    void setAddress(const std::string &value);

    std::string getCity() const;
    void setCity(const std::string &value);

    std::string getState() const;
    void setState(const std::string &value);

    int getZip() const;
    void setZip(int value);

    void operator=(const Address& a);
    friend ostream& operator <<(ostream& out, const Address& d);

private:
    std::string address;
    std::string city;
    std::string state;
    int zip;

};

#endif // ADDRESS_H
