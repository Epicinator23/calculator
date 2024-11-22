#include "MenuData.h"

MenuData::MenuData() : size(0) {
}

void MenuData::addFunction(FunctionType function, const string& description) {
	functions.push_back(function);
	descriptions.push_back(description);
	size++;
}

const vector<FunctionType>& MenuData::getFunctions() const {
	return functions;
}

FunctionType MenuData::getFunction(const int& id) {
	if (isValid(id)) {
		return functions[id];
	} else {
		return 0;
	}
}

const string& MenuData::getDescription(const int& id) {
	if (isValid(id)) {
		return descriptions[id];
	} else {
		static std::string empty = "";
		return empty;
	}
}

const int& MenuData::getSize() const {
	return size;
}

const bool MenuData::isValid(const int& choice) {
	if (choice >= 0 && choice < size) {
		return true;
	} else {
		return false;
	}
}