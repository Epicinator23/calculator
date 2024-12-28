#include "MenuData.h"

void quit(ActionData& action_data) {
	action_data.getOutStream() << "Thank you for running this program.\nContributions are encouraged via Venmo @Epicinator23\n";
	action_data.quit();
}

MenuData::MenuData() : size(1), empty("") {
	functions.push_back(&quit);
	operations.push_back("q");
	descriptions.push_back("Quits the program");
	first_words.push_back(empty);
	second_words.push_back(empty);
	final_words.push_back(empty);
}

void MenuData::addFunction(FunctionType func, const string& op, const string& desc, const string& fst, const string& snd, const string& fw) {
	functions.push_back(func);
	operations.push_back(op);
	descriptions.push_back(desc);
	first_words.push_back(fst);
	second_words.push_back(snd);
	final_words.push_back(fw);
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

const string& MenuData::getOperation(const int& id) {
	if (isValid(id)) {
		return operations[id];
	} else {
		return empty;
	}
}

const string& MenuData::getDescription(const int& id) {
	if (isValid(id)) {
		return descriptions[id];
	} else {
		return empty;
	}
}

const string& MenuData::getFirstWord(const int& id) {
	if (isValid(id)) {
		return first_words[id];
	} else {
		return empty;
	}
}

const string& MenuData::getSecondWord(const int& id) {
	if (isValid(id)) {
		return second_words[id];
	} else {
		return empty;
	}
}

const string& MenuData::getFinalWord(const int& id) {
	if (isValid(id)) {
		return final_words[id];
	} else {
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