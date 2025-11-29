#pragma once
#include <string>

class Action {
protected:
	std::string description;
public:
	Action() = default;
	Action(const std::string& desc) : description(desc) {}

	std::string getDescription() const {
		return description;
	}

	virtual void execute(std::string& returnMessage) {}

	virtual void setDescription(const std::string& desc) {
		description = desc;
	}

	virtual ~Action() = default;

};