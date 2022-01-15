//
// Created by user.v2.0 on 28.05.2021.
//

#include "Dictionary.h"


void Dictionary::printDictionary() {
    std::cout << "PRINT DICTIONARY\n";
    for (int i = 0; i < indexes_of_exist.size(); ++i) {
        for (int j = 0; j < arr[indexes_of_exist[i]].size(); ++j) {
            std::cout << arr[indexes_of_exist[i]][j].key << ":";
            for (int k = 0; k < arr[indexes_of_exist[i]][j].values.size(); ++k) {
                std::cout << arr[indexes_of_exist[i]][j].values[k] << " ";
            }
            std::cout << std::endl;
        }
    }
}


void Dictionary::insert_element(std::string key, std::string value) {
    checkKey(key);
    std::vector<string> vector;
    vector.push_back(value);
    checkValues(vector);
    insert(key, value);
}

bool Dictionary::delete_element(std::string key) {
    checkKey(key);
    return deleteNode(key);
}


void Dictionary::writeFromFile(std::string name) {
    try {
        std::fstream in;
        in.open(name);
        std::string temp;
        getline(in, temp);
        while (temp != "\0") {
            vector<string> values;
            std::string key = "";
            checkInput(temp);
            int i = 0;
            for (; temp[i] != ' '; ++i) {
                key += temp[i];
            }
            i++;
            std::string value_temp;
            for (; i < temp.size(); ++i) {
                if (temp[i] != ' ')
                    value_temp += temp[i];
                else {
                    values.push_back(value_temp);
                    value_temp = "";
                }
            }
            values.push_back(value_temp);
            for (int j = 0; j < values.size(); ++j) {
                insert_element(key, values[j]);
            }
            getline(in, temp);
        }
    }
    catch (WrongValues e) {
        throw new WrongValues;
    }
    catch (WrongKey e) {
        throw new WrongKey;
    }
    catch (NoSign e) {
        throw new NoSign;
    }
}

void Dictionary::checkInput(std::string temp) {
    int counter = 0;
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] != ' ')
            counter++;
    }
    if (counter == 0) {
        std::cout << "Given only a key\n";
        throw exception();
    }
}

void Dictionary::checkKey(std::string key) {
    if (key.size() == 0) {
        std::cout << "Empty key\n";
        throw new WrongKey;
    }
    if ((key[0] >= 'a' && key[0] <= 'z') || (key[0] >= 'A' && key[0] <= 'Z')) {
    } else {
        std::cout << "wrong key\n";
        throw new WrongKey;
    }
    for (int i = 1; i < key.size(); ++i) {
        if (!(key[i] >= 'a' && key[i] <= 'z') && key[i] != '-') {
            std::cout << "wrong key\n";
            throw new WrongKey;
        }

    }
}

void Dictionary::checkValues(vector<string> values) {

    for (int i = 0; i < values.size(); ++i) {
        if (values[i].size() == 0) {
            std::cout << "Empty value\n";
            throw new WrongValues;
        }
        //std::cout << int('ß') <<"\n";
        if (!(values[i][0] >= -64 && values[i][0] <= -1)) {
            std::cout << "Wrong values\n";
            throw new WrongValues;
        }
        for (int j = 1; j < values[i].size(); ++j) {
            //std::cout << int (values[i][j]) << "\n";
            if (!(values[i][j] >= -32 && values[i][j] <= -1) && (values[i][j] != '-')) {
                std::cout << "Wrong values\n";
                throw new WrongValues;
            }
        }
    }
}
