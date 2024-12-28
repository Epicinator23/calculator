#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "ActionData.h"		// using namespace std;
#include "MenuData.h"

// calculations.cpp
void quit(ActionData& action_data);
void doMath(MenuData& menu_data, ActionData& action_data);

void add(ActionData& action_data);
void subtract(ActionData& action_data);
void multiply(ActionData& action_data);
void divide(ActionData& action_data);

void addMatrices(ActionData& action_data);
void subtractMatrices(ActionData& action_data);
void multiplyMatrices(ActionData& action_data);
void divideMatrices(ActionData& action_data);



//	user_io.cpp
string getString(ActionData& action_data, const string& prompt);
int getInteger(ActionData& action_data, const string& prompt);
double getDouble(ActionData& action_data, const string& prompt);
void presentOptions(MenuData& menu_data, ActionData& action_data);
int getChoice(MenuData& menu_data, ActionData& action_data);
Matrix getMatrix(ActionData& action_data, string& prompt);


#endif
