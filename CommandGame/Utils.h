#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toLower(const string& str) {
	string lowerStr = str;
	for (int i = 0; i < str.length(); ++i) {
		lowerStr[i] = tolower(str[i]);
	}
	return lowerStr;
}


vector<string> split(const string& s, const string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;
    string stringCopy = s;

    while ((pos = stringCopy.find(delimiter)) != string::npos) {
        token = stringCopy.substr(0, pos);
        tokens.push_back(token);
        stringCopy.erase(0, pos + delimiter.length());
    }
    tokens.push_back(stringCopy);

    return tokens;
}



