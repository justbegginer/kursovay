//
// Created by user.v2.0 on 28.05.2021.
//

#ifndef KURSOVAY_HASHTABLE_H
#define KURSOVAY_HASHTABLE_H

#include <iostream>
#include "Exceptions.h"
#include<bits/stdc++.h>
#include "String.h"


using namespace std;

const int ALPHABET_SIZE = 53;
// шаблон для универсального типа

// Hashnode class
class HashNode {

public:

    vector<string> values;
    std::string key;
    HashNode *next_node = nullptr;

    HashNode() {

    }

    // Конструктор hashnode
    HashNode(std::string key, std::string value) {
        this->values.push_back(value);

        this->key = key;
    }

    HashNode(std::string key, vector<string> values) {
        for (int i = 0; i < values.size(); ++i) {
            this->values.push_back(values[i]);
        }
        this->key = key;
    }

    void sort(){
        for (int i = 1; i < values.size(); ++i) {
            for (int j = 0; j < values[i-1].size() && j < values[i].size(); ++j) {
                if (values[i-1][j] > values[i][j]){
                    std::swap(values[i-1] , values[i]);
                    i = 0;
                    break;
                }
                else if(values[i-1][j] < values[i][j])
                    break;
            }
        }
    }

};

// шаблон для универсального типа
// Наш собственный класс Hashmap
class Hashtable {
private:
    std::size_t collision_number = 1;
protected:
    vector<HashNode> *arr;
    int capacity;
    int size;
    vector<int> indexes_of_exist;

    // Реализует хеш-функцию для поиска индекса
    // для ключа
    int hashCode(std::string key) const {
        unsigned long hash = 0;
        unsigned long pPow = 1; // P_pow
        for (size_t i = 0; key[i] != '\0'; ++i) {
            hash += (key[i] - 'a' + 1) * pPow;
            pPow *= ALPHABET_SIZE; // примерный размер алфавита
        }
        return (hash & 0x7fffffff) % capacity;
    }

    // Функция для удаления пары ключ-значение
    bool deleteNode(std::string key) {

        if (!arr[hashCode(key)].empty()) {
            for (int i = 0; i < arr[hashCode(key)].size(); ++i) {
                if (arr[hashCode(key)][i].key == key) {
                    vector<HashNode> new_vector(0);
                    for (int j = 0; j < arr[hashCode(key)].size(); ++j) {
                        if (key != arr[hashCode(key)][j].key) {
                            new_vector.push_back(arr[hashCode(key)][j]);
                            arr[hashCode(key)].pop_back();
                        }
                    }
                    arr[hashCode(key)] = new_vector;

                    if (arr[hashCode(key)].empty()) {
                        vector<int> temp_vector;
                        for (int j = 0; j < indexes_of_exist.size(); ++j) {
                            if (indexes_of_exist[j] != hashCode(key))
                                temp_vector.push_back(indexes_of_exist[j]);
                        }
                        indexes_of_exist.clear();
                        for (int j = 0; j < temp_vector.size(); ++j) {
                            indexes_of_exist.push_back(temp_vector[j]);
                        }

                    }
                    return true;
                }
            }
            return false;
        } else
            return false;
    }
    // Возвращаем текущий размер

    int sizeofMap() {
        return size;
    }

    // Возвращаем true если размер равен 0
    bool isEmpty() {
        return size == 0;
    }

    vector<string> get(std::string key) {

        if (arr[hashCode(key)].size() != 0) {
            for (int i = 0; i < arr[hashCode(key)].size(); i++) {
                if (key == arr[hashCode(key)][i].key) {
                    return arr[hashCode(key)][i].values;
                }
            }
            std::cout << "there is no such element in this table\n";
            throw exception();
        } else {
            std::cout << "there is no such element in this table\n";
            throw exception();
        }
    }

    void IsNeedExpand() {
        if (collision_number * pow(size,collision_number)/4 >= capacity){
            //std::cout << "EXPAND\n";
            expand();
        }
    }

    void expand() {

        vector<HashNode> *copy_array = new vector<HashNode>[capacity];
        for (int i = 0; i < capacity; ++i) {
            copy_array[i] = vector<HashNode>();
            for (int j = 0; j < arr[i].size(); ++j) {
                copy_array[i].push_back(arr[i][j]);
                //std::cout << arr[i][j].key << "\n";
            }
        }
        capacity *= 8;
        arr = new vector<HashNode>[capacity];
        collision_number = 1;
        size = 0;
        vector<int> indexes_of_exist_copy;

        for (int i = 0; i < indexes_of_exist.size(); ++i) {
            indexes_of_exist_copy.push_back(indexes_of_exist[i]);
        }
        while (!indexes_of_exist.empty()){
            indexes_of_exist.pop_back();
        }
        for (int i = 0; i < indexes_of_exist_copy.size(); ++i) {
            for (int j = 0; j < copy_array[indexes_of_exist_copy[i]].size(); ++j) {
                //std::cout << copy_array[indexes_of_exist[i]][j].key<<"\n";
                for (int k = 0; k < copy_array[indexes_of_exist_copy[i]][j].values.size(); ++k) {

                    this->insert(copy_array[indexes_of_exist_copy[i]][j].key,copy_array[indexes_of_exist_copy[i]][j].values[k]);
                }
            }
        }


    }

    void insert(std::string key, std::string value) {
        if (arr[hashCode(key)].empty()) {
            arr[hashCode(key)] = *new vector<HashNode>;
            arr[hashCode(key)].push_back(HashNode(key, value));
            indexes_of_exist.push_back(hashCode(key));
            arr[hashCode(key)][0].sort();
            size++;
        } else {
            for (int i = 0; i < arr[hashCode(key)].size(); ++i) {
                if (arr[hashCode(key)][i].key == key) {
                    arr[hashCode(key)][i].values.push_back(value);
                    arr[hashCode(key)][i].sort();
                    return;
                }
            }
            //indexes_of_exist.push_back(hashCode(key));
            size++;
            arr[hashCode(key)].push_back(HashNode(key, value));
            collision_number++;
            //std::cout << collision_number << "\n";
            IsNeedExpand();
        }
    }


public:
    Hashtable(std::size_t base_size = 20) {
        // Начальная емкость хеш-массива
        try {
            capacity = base_size;
            size = 0;
            arr = reinterpret_cast<vector<struct HashNode> *>(new vector<Hashtable>[base_size]);
            // Инициализируем все элементы массива как NULL
            for (int i = 0; i < capacity; i++)
                arr[i] = vector<HashNode>();
        }
        catch (...) {
            throw new WrongSize;
        }
    }
};


#endif //KURSOVAY_HASHTABLE_H
