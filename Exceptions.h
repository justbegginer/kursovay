//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_EXCEPTIONS_H
#define KURSOVAY_EXCEPTIONS_H
#pragma once
#include <exception>
class NoSign : public std::exception
{
public:
    NoSign() : reason("error while reading from file") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};

class WrongKey : public std::exception
{
public:
    WrongKey() : reason("Wrong key") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};
class WrongSize : public std::exception
{
public:
    WrongSize() : reason("Wrong table size...") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};
class WrongValues : public std::exception
{
public:
    WrongValues() : reason("Wrong value") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};
#endif //KURSOVAY_EXCEPTIONS_H
