//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_WRONGKEY_H
#define KURSOVAY_WRONGKEY_H
#pragma once
#include <exception>
class WrongKey : public std::exception
{
public:
    WrongKey() : reason("Wrong key") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};

#endif //KURSOVAY_WRONGKEY_H
