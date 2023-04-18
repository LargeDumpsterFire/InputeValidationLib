
// InputValidationV1.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "inputValLib.h"

// TODO: This is an example of a library function
void fnInputValidationV1()
{
}
#include <iostream> // header in standard library

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::invalid_argument;
using std::out_of_range;


/***********************************************************/

int universalIntegerValidationWithLimits(int smallNmb, int bigNmb, string msg)
{
	// Declare userInput variable
	int userInput;

	// Print message with smallNmb and bigNmb
	cout << msg << smallNmb << " and " << bigNmb << endl;

	// Set validInput to false
	bool validInput = false;

	// While validInput is false
	while (!validInput) {

		// If userInput is between smallNmb and bigNmb
		if (cin >> userInput && userInput >= smallNmb && userInput <= bigNmb) {

			// Set validInput to true
			validInput = true;
		}
		else {

			// Print error message
			cout << "Invalid input. Please enter an integer." << endl;
			cout << "Please input a number between " << smallNmb << " and " << bigNmb << "\n";

			// Clear cin and ignore any input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');


		}

	}

	// Return userInput
	return userInput;
}

int getIntInput(string msg) {

	// Declare input variable
	int input;

	// Set validInput to false
	bool validInput = false;

	// While validInput is false
	while (!validInput) {

		// Print message
		cout << msg;

		// If input is an integer
		if (cin >> input) {

			// Set validInput to true
			validInput = true;
		}
		else {

			// Clear cin and ignore any input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// Print error message
			cout << "Invalid input. Please enter an integer." << endl;
		}
	}

	// Return input
	return input;
}
/***********************************************************/
//This function is used to validate user input of a double value. It takes in a double reference and a string message as parameters. It then reads the user input from
// the console and attempts to convert it to a double. If the conversion is successful, it checks if there are any extra characters after the number. If there are,
// it returns false. Otherwise, it returns true.
bool validateDoubleInput(double& input, string msg) {
	string line;

	getline(cin, line);
	if (line.empty()) {
		return false;  // Empty input
	}
	size_t pos;
	try {
		// The stod() function is used to convert a string to a double. It takes two arguments: the string to be converted and a pointer to an integer that will be set to the position of the first character that could not be converted. The function returns the converted double value.
		input = stod(line, &pos);
	}
	catch (const invalid_argument& ex) {
		return false;  // Not a double
	}
	catch (const out_of_range& ex) {
		return false;  // Out of range
	}
	if (pos != line.size()) {
		return false;  // Extra characters after the number
	}
	return true;  // Valid input
}
double universalDoubleValidation(string msg) {
	//asks user to enter a number from the msg passed to the function
	double userInput;
	cout << msg;
	//cin.ignore has to be used either in the main or in this function because it will take any characters in the cin buffer and use it as an input. i think that is why it needs to be used in the main or in this function

	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// receives user input 
	bool validInput = false;
	while (!validInput) {

		if (validateDoubleInput(userInput, msg)) { // checks if user input is valid
			validInput = true; // if valid, sets validInput to true
			//cout << "Valid input: " << userInput << endl;
			//break;
		}
		else { // if user input is not valid
			cin.clear(); // clears cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores any characters in cin
			cout << "Invalid input. Please try again." << endl; // prints error message
		}
	}
	return userInput; // returns user input
}
/***********************************************************/
bool isAlphabetString(const string& str) {
	// Iterate through each character in the string
	for (char c : str) {
		// Check if the character is not an alphabet character
		if (!isalpha(c)) {
			// If not, return false
			return false;
		}
	}
	// If all characters are alphabet characters, return true
	return true;
}
//This function takes a string as an argument and returns a string. It will prompt the user for input and validate that the input is a string containing only letters of the alphabet. 
string stringInputValidation(string msg) {
	string userInput; //Declare a string to store the user input
	bool validInput = false; //Declare a boolean to track if the user input is valid

	//Loop until valid input is entered
	while (!validInput) {
		cout << msg << endl; //Print the message passed as an argument
		getline(cin, userInput); //Get the user input
		if (isAlphabetString(userInput)) { //Check if the user input is a string containing only letters of the alphabet
			validInput = true; //If it is, set validInput to true
		}
		else { //If it is not,
			cout << "Invalid input. Please enter a string containing only letters of the alphabet. "; //Print an error message
		}
	}
	return userInput; //Return the user input
}
/***********************************************************/
/*
it's important to note that the rand() function generates pseudo-random numbers,
which means the sequence of numbers generated by the function is deterministic and depends on the initial seed value.
Therefore, you should always seed the random number generator with a value that changes with each run of the program,
for example, the current time, to ensure that the sequence of random numbers generated is different each time the program runs.
You can do this using srand() function before calling rand() function.
see below this function for an example of how to use it
*/

int randomNumberGenerator(int small, int big) {

	int randomNumber;
	randomNumber = rand() % (big - small + 1) + small;
	return randomNumber;

}

int randomNumberGeneratorExample(int small, int big) {
	int randomNumber;
	srand(time(0));
	randomNumber = rand() % (100 - 1 + 1) + 1;
	cout << randomNumber << "\n";
	return randomNumber;
}


