#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Inventory {
private:
	vector<string> items;

public:
	Inventory() : items() {}

	void addItem(const string& item) {
		items.push_back(item);
	}

	vector<string> getItems() const {
		return items;
	}

	void deleteItem(const string& item) {
		auto it = find(items.begin(), items.end(), item);
		if (it != items.end()) {
			items.erase(it);
		}
	}

	bool hasItem(const string& item) const {
		return find(items.begin(), items.end(), item) != items.end();
	}

};
