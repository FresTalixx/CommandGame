#pragma once

#include <string>

using namespace std;

class Item {
protected:
	string itemName;
	string itemDescription;
public:
	Item() {
		itemName = "";
		itemDescription = "";
	}

	Item(const string& name, const string& desc) {
		itemName = name;
		itemDescription = desc;
	}

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

	virtual void use(string& returnMessage) {};
};