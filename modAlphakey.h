#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class modAlphakey
{
private:
    int key1; // кол-во столбцов
public:
    modAlphakey()=delete; // запрет конструктора без параметров
    modAlphakey(const int& key) :key1(key) {};
    std::string encrypt(const std::string& open_text); // зашифрование
    std::string decrypt(const std::string& cipher_text); // расшифрование
};