#include "modAlphakey.h"
#include <stdexcept>

using namespace std;

std::string modAlphakey::encrypt(const std::string& open_text) {
    if (open_text.empty()) {
        throw invalid_argument("Input text cannot be empty.");
    }
    if (key1 <= 0) {
        throw invalid_argument("Key must be greater than 0.");
    }

    string tabl = open_text;
    int dl = open_text.length();
    if (key1 > dl) {
        throw invalid_argument("Key cannot be greater than the text length.");
    }

    int nstrok = (dl - 1) / key1 + 1;
    int x = 0;

    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            int index = i + key1 * j;
            if (index - 1 < dl) {
                tabl[x] = open_text[index - 1];
                x++;
            }
        }
    }
    return tabl;
}

std::string modAlphakey::decrypt(const std::string& cipher_text) {
    if (cipher_text.empty()) {
        throw invalid_argument("Cipher text cannot be empty.");
    }
    if (key1 <= 0) {
        throw invalid_argument("Key must be greater than 0.");
    }

    string tabl = cipher_text;
    int dl = cipher_text.length();
    if (key1 > dl) {
        throw invalid_argument("Key cannot be greater than the text length.");
    }

    int nstrok = (dl - 1) / key1 + 1;
    int x = 0;

    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            int index = i + key1 * j;
            if (index - 1 < dl) {
                tabl[index - 1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}

