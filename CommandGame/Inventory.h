#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Item.h"
#include "ActionSystem.h"

using namespace std;

class Inventory {
private:
	vector<Item*> items;

public:
	Inventory();

	void addItem(Item* item);

	const vector<Item*>& getItems() const;

	void deleteItem(const Item* item);

	bool hasItem(const Item* item) const;

	~Inventory() {
		for (auto item : items) {
			delete item;
		}
	}

};
