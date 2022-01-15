
#include <iostream>
#include <string>
#include "Dictionary.h"
#include <windows.h>
#include <locale>
#include <io.h>
#include <fcntl.h>

void test(Dictionary &dictionary) {
    while (true) {
        std::cout << "enter the name of operation\n"
                     "1-delete\n"
                     "2-insert\n"
                     "3-search\n"
                     "4-print\n"
                     "in case of another name the test ends\n";
        std::string operation;
        std::cin >> operation;
        if (operation == "delete") {
            std::cout << "enter input data\n";
            std::string input_data;
            cin >> input_data;
            dictionary.delete_element(input_data);
        }
        else if (operation=="search"){
            std::cout << "enter input data\n";
            std::string input_data;
            cin >> input_data;
            std::vector<std::string> vector = dictionary[input_data];
            for (int i = 0; i < vector.size(); ++i) {
                std::cout <<vector[i]<< "\n";
            }
        }
        else if(operation == "insert"){
            std::cout << "enter input data\n";
            std::string input_data;
            cin >> input_data;
            vector<string> values;
            std::string key = "";
            dictionary.checkInput(input_data);
            int i = 0;
            for (; input_data[i] != ' '; ++i) {
                key += input_data[i];
            }
            i++;
            std::string value_temp;
            for (; i < input_data.size(); ++i) {
                if (input_data[i] != ' ')
                    value_temp += input_data[i];
                else {
                    values.push_back(value_temp);
                    value_temp = "";
                }
            }
            values.push_back(value_temp);
            for (int j = 0; j < values.size(); ++j) {
                dictionary.insert_element(key, values[j]);
            }
        }
        else if(operation == "print"){
            dictionary.printDictionary();
        }
        else
            break;
    }
}

using namespace std;


int main() {
    setlocale(LC_ALL, "ru-RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Dictionary dict;
    std::string filename = "C:\\Users\\user.v2.0\\CLionProjects\\kursovay\\input.txt";
    dict.writeFromFile(filename);
    test(dict);
    dict.printDictionary();
    //std::cout << "AFTER DELETE AND INSERTION\n";
    //dict.delete_element("helloy");
    //dict.insert_element("swim" , "плыть");
    //dict.printDictionary();

}
