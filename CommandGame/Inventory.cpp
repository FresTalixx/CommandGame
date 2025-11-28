#include "Inventory.h"

Inventory::Inventory() : items() {}

void Inventory::addItem(Item* item) {
	items.push_back(item);
}

const vector<Item*>& Inventory::getItems() const {
	return items;
}

void Inventory::deleteItem(const Item* item) {
	auto it = find(items.begin(), items.end(), item);
	if (it != items.end()) {
		items.erase(it);
	}
}

bool Inventory::hasItem(const Item* item) const {
	return find(items.begin(), items.end(), item) != items.end();
}