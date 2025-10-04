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
	vector<string> operations;
	vector<string> descriptions;
	vector<string> first_words;
	vector<string> second_words;
	vector<string> final_words;
	int size;
	const string empty;

public:
	MenuData();

	void addFunction(FunctionType func, const string& op, const string& desc, const string& fst, const string& snd, const string& fw);
	const vector<FunctionType>& getFunctions() const;
	FunctionType getFunction(const int& id);
	const string& getOperation(const int& id);
	const string& getDescription(const int& id);
	const string& getFirstWord(const int& id);
	const string& getSecondWord(const int& id);
	const string& getFinalWord(const int& id);

	const int& getSize() const;
	const bool isValid(const int& choice);
};

#endif
