//#pragma once
//#include <string>
//#include "Item.h"
//
//
//class Passkey4Digit : public Item {
//private:
//	std::string correctCode;
//	bool isUsed = false;
//public:
//	Passkey4Digit(const std::string& name, const std::string& desc, const std::string& code)
//		: Item(name, desc), correctCode(code) {
//		itemID = "passkey4digit";
//	}
//
//	void setCode(const std::string& code) {
//		correctCode = code;
//	}
//
//	string getCode() const {
//		return correctCode;
//	}
//
//	void setUsed(bool used) {
//		isUsed = used;
//	}
//
//	bool getIsUsed() const {
//		return isUsed;
//	}
//
//	void use(std::string& returnMessage) override {
//		std::string inputCode;
//		std::cout << "Enter the 4-digit code: ";
//		std::cin >> inputCode;
//		if (inputCode == correctCode) {
//			isUsed = true;
//			returnMessage = "The passkey accepted the code. It can now be used to unlock the door.";
//		} else {
//			returnMessage = "Incorrect code. The passkey remains unused.";
//		}
//	}
//};
