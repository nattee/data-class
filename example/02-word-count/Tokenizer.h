#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Tokenizer
{
public:
    Tokenizer(string fileName) {
        fin.open(fileName.c_str());
        token = NULL;
        if (fin.is_open()) {
            if (getline(fin,line)) {
                token = strtok( (char*)line.c_str(), delims );
            }
        }
    }
    string next() {
        string s = token;
        token = strtok( NULL, delims );
        while (token == NULL) {
            if (getline(fin,line)) {
                token = strtok( (char*)line.c_str(), delims );
            } else {
                break;
            }
        }
        return s;
    }
    bool hasNext() {
        return token != NULL;
    }
    void close() {
        fin.close();
    }
    static const char *delims;

private:
    char *token;
    ifstream fin;
    string line;

};

const char *Tokenizer::delims = " \"\'[](){},.!@#$%^&|~-=<>?;:+-*_/\\\n";


#endif // TOKENIZER_H
