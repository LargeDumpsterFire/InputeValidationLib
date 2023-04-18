#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <string>
using std::string;

//
int getIntInput(string msg);
int universalIntegerValidationWithLimits(int smallNmb, int bigNmb, string msg);
//
bool validateDoubleInput(double& input, string msg);
double universalDoubleValidation(string msg);
//
//int randomNumberGenerator(int small, int big);
int randomNumberGeneratorExample(int small, int big);
//
bool isAlphabetString(const string& str);
string stringInputValidation(string msg);
//
#endif
