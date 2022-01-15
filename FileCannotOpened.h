//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_FILECANNOTOPENED_H
#define KURSOVAY_FILECANNOTOPENED_H
#pragma once
#include <exception>
class FileNotOpen : public std::exception
{
public:
    FileNotOpen() : reason("Could not open file...") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason; // ! const
};
#endif //KURSOVAY_FILECANNOTOPENED_H
