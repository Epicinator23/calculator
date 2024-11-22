#ifndef MENU_DATA_H
#define MENU_DATA_H

#include <string>
#include <vector>
#include <map>

#include "ActionData.h"		// using namespace std;

typedef void (*FunctionType)(ActionData& action_data);

class MenuData {
private:
	vector<FunctionType> functions;
	vector<string> descriptions;
	int size;

public:
	MenuData();

	void addFunction(FunctionType function, const string& description);
	const vector<FunctionType>& getFunctions() const;
	FunctionType getFunction(const int& id);
	const string& getDescription(const int& id);
	const int& getSize() const;
	const bool isValid(const int& choice);
};

#endif