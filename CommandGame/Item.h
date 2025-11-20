#pragma once

#include <string>

using namespace std;

class Item {
protected:
	string itemName;
	string itemDescription;
public:

	void setName(const string& name) {
		itemName = name;
	}

	string getName() const {
		return itemName;
	}

	void setDescription(const string& description) {
		itemDescription = description;
	}

	string getDescription() const {
		return itemDescription;
	}

	virtual void use() = 0;
};