//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_DICTIONARY_H
#define KURSOVAY_DICTIONARY_H

#include <ostream>
#include "HashTable.h"

class Dictionary : Hashtable {
public:
    Dictionary(std::size_t capacity = 20) {
        try {
            this->capacity = capacity;
            size = 0;
            arr = new vector<HashNode>[capacity];
            // Инициализируем все элементы массива как NULL
            for (int i = 0; i < capacity; i++)
                arr[i] = vector<HashNode>();
        }
        catch (...) {
            throw new WrongSize;
        }
    }

    void printDictionary();

    void insert_element(std::string key, std::string value);

    vector<string> operator[](std::string key) { return get(key); }

    bool delete_element(std::string key);

    int getHashCode(std::string key) { return hashCode(key); }

    void writeFromFile(std::string);

    void checkInput(std::string temp);

private:

    void checkKey(std::string key);

    void checkValues(vector<string> values);
};


#endif //KURSOVAY_DICTIONARY_H
