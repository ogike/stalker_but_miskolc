#pragma once

#include <string>

class Item
{
public:
	int price;
	int weight;
	bool is_owned;
	std::string name;

	Item() : price(0), weight(0), is_owned(false), name("unnamed item") {}
	Item(int price, int weight, std::string name) : price(price), weight(weight), name(name), is_owned(false) {}

	virtual bool isHealing() const { return false; }
};

class HealingItem : public Item
{
public:
	float healAmount;
	int woundRemoveChance;

	HealingItem(): healAmount(50), woundRemoveChance(50), Item(100, 1, "Bandage") {}
	
	HealingItem(int healAmount, float woundRemChance, int price, int weight, std::string name):
		healAmount(healAmount), woundRemoveChance(woundRemChance), Item(100, 1, "Bandage") {}

	bool isHealing() const override { return true; }
};
