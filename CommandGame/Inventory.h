#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Item.h"

using namespace std;

class Inventory {
private:
	vector<Item*> items;

public:
	Inventory() : items() {}

	void addItem(Item* item) {
		items.push_back(item);
	}

	const vector<Item*>& getItems() const {
		return items;
	}

	void deleteItem(const Item* item) {
		auto it = find(items.begin(), items.end(), item);
		if (it != items.end()) {
			items.erase(it);
		}
	}

	bool hasItem(const Item* item) const {
		return find(items.begin(), items.end(), item) != items.end();
	}

};
