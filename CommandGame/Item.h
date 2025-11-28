#pragma once

#include <string>

using namespace std;

class Item {
protected:
	string itemName;
	string itemDescription;
	string itemID;
public:
	Item() {
		itemName = "";
		itemDescription = "";
	}

	Item(const string& name, const string& desc) {
		itemName = name;
		itemDescription = desc;
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

	string getItemID() {
		return itemID;
	}

	void setItemID(const string& itemID) {
		this->itemID = itemID;
	}

	virtual void use(string& returnMessage) {};

	virtual void examine(string& returnMessage) {
		returnMessage = itemDescription;
	}

	virtual void onPlayerLeave() {};
};