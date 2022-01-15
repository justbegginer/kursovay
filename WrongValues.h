//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_WRONGVALUES_H
#define KURSOVAY_WRONGVALUES_H
#pragma once
#include <exception>
class WrongValues : public std::exception
{
public:
    WrongValues() : reason("Wrong value") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};
#endif //KURSOVAY_WRONGVALUES_H
