//
// Created by user.v2.0 on 28.05.2021.
//

#include "String.h"
#include <iostream>
#include <cstring>

int LEMGTH = 100; // максимальная длинна поля
String::String()
{
    //str_ = '\0';
    length_ = 0;
}
String::String(const char* str)
{
    length_ = strlen(str);
    this->str_ = new char[length_ + 1];
    for (int i = 0; i < length_; i++)
    {
        this->str_[i] = str[i];
    }
    this->str_[length_] = '\0';
}
String::String(const String& other)
{
    length_ = strlen(other.str_);
    this->str_ = new char[length_ + 1];
    for (int i = 0; i < length_; i++)
    {
        this->str_[i] = other.str_[i];
    }
    this->str_[length_] = '\0';
}
String& String::operator=(const String& other)
{
    if (this->str_ != nullptr)
    {
        delete[] str_;
    }
    length_ = strlen(other.str_);
    this->str_ = new char[length_ + 1];
    for (int i = 0; i < length_; i++)
    {
        this->str_[i] = other.str_[i];
    }
    this->str_[length_] = '\0';
    return *this;
}
std::istream& operator>>(std::istream& in, String& string)
{
    string.str_ = new char[LEMGTH];
    in.get(string.str_[0]);
    if ((string.str_[0] == ' ') || (string.str_[0] == '\n'))
    {
        string.str_[1] = '\0';
        return in;
    }
    for (int i = 1; i < LEMGTH; i++)
    {
        in.get(string.str_[i]);
        if ((string.str_[i] != ' ') && (string.str_[i] != ',') &&
            (string.str_[i] != '.') && (string.str_[i] != '!') &&
            (string.str_[i] != '?') && (string.str_[i] != '-') &&
            (string.str_[i] != '\n'))
            continue;
        else
        {
            string.str_[i] = '\0';
            break;
        }
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const String& string)
{
    out << string.str_;
    return out;
}
bool String::operator==(const String& otherString)
{
    for (int i = 0; i < length_; i++)
    {
        if (this->str_[i] != otherString.str_[i])
        {
            return false;
        }
    }
    return true;
}
char& String::operator[] (const int index)
{
    return str_[index];
}
String::~String()
{
    delete[] this->str_;
}

int String::getLength() {
    return length_;
}
