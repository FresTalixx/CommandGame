#pragma once
#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

class Key : public Item {
	private:
		string doorName;
public:
	Key(const string& name, const string& description, const string& door)
		{
			itemName = name;
			itemDescription = description;
			doorName = door;
		}

		void use() override
		{
			// Implementation for using the key
			// For example, unlocking the door
			cout << "You use the " << itemName << " to unlock the " << doorName << "." << endl;
		}
};
