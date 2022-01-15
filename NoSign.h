//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_NOSIGN_H
#define KURSOVAY_NOSIGN_H
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

#endif //KURSOVAY_NOSIGN_H
