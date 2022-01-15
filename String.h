//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_STRING_H
#define KURSOVAY_STRING_H

#include <iostream>
class String
{
public:
    String();
    String(const char* str);
    ~String();
    String& operator=(const String& other);
    String(const String& other);
    friend std::istream& operator>> (std::istream& in, String& string);
    friend std::ostream& operator<<(std::ostream& out, const String& string);
    bool operator== (const String& otherString);
    int getLength() ;
    char& operator[](const int index);
private:
    char* str_;
    int length_;
};



#endif //KURSOVAY_STRING_H
