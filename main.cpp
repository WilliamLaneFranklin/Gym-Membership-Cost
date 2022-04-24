#include <iostream>
#include <iomanip>


using namespace std;


//Function prototypes
void welcomeMessage();
void displayPrices();
void optionsMenu();
char readCharOption(char char1, char char2);
int readIntOption(int int1, int int2);
void getInput(char &club, int &months, int &sessions);
void calculateTotals(char club, int months, int sessions, double &membership, double &training);
void displayTotals(int months, int sessions, double membership, double training);
void endingMessage();


//Constants
double const SPORTS_CLUB = 20.00;
double const ULTRA_SPORTS = 30.00;
double const SESSION_COST = 10.00;


int main(){
	cout << fixed << setprecision(2) << endl;
	welcomeMessage();
	displayPrices();

	double membershipCost = 0.00;
	double trainingCost = 0.00;
	char clubType = '\0';
	int numMonths = 0;
	int numSessions = 0;
	char userOption = '\0';

	do {
		optionsMenu();
		userOption = readCharOption('C', 'Q');
		if (userOption == 'C'){
			getInput(clubType, numMonths, numSessions);
			calculateTotals(clubType, numMonths, numSessions, membershipCost, trainingCost);
			displayTotals(numMonths, numSessions, membershipCost, trainingCost);
	}
	}
	while (userOption != 'Q');
	endingMessage();
	return 0;
}


void welcomeMessage(){
	cout << "Welcome to my fitClub program!" << endl;
}


void displayPrices(){
	cout << '\n' << "The cost to become a member of the fitClub center is as follows:" << endl;
	cout << '\n' << " -The membership fee per month for Sports Club is $20.00" << endl;
	cout << " -The membership fee per month for Ultra Sports Club is $30.00" << endl;
	cout << " -If membership is bought and paid for 12 or more months, the discount is 10% off membership cost" << endl;
	cout << " -Personal training sessions are $10.00 per session." << endl;
	cout << " -If more than five personal training sessions are bought and paid for, the discount on each sessions is 20%" << endl;
}


void optionsMenu(){
	cout << '\n' << "Please pick one of the following options:" << endl;
	cout << '\n' << "(C/c) Calculate membership costs." << endl;
	cout << "(Q/q) Quit this program." << '\n' << endl; 
}


char readCharOption(char char1, char char2){
	char userOption = '\0';
	cout << ">> ";
	cin >> userOption;
	userOption = toupper(userOption);
	while (userOption != char1 && userOption != char2){
		cin.clear();
		cin.ignore(50, '\n');
		cout << "Invalid option! Try again!! " << endl;
		cout << ">> ";
		cin >> userOption;
		userOption = toupper(userOption);
	}
	return userOption;
}


int readIntOption(int int1, int int2){
	int userOption = 0;
	cout << ">> "; 
	cin >> userOption;
	while (!cin || (userOption < int1 || userOption > int2)){
		cin.clear();
		cin.ignore(50, '\n');
		cout << "Invalid number! Please try again!!" << endl;
		cout << ">> ";
		cin >> userOption;
		}
	return userOption;
}

 
void getInput(char &club, int &months, int &sessions){
	cout << "Would you prefer (S)ports or (U)ltra Sports Club? " << endl;
	club = readCharOption('S', 'U');
	cout << "How many months of membership would you like? The maximum contract is 24 months. " << endl;
	months = readIntOption(1, 24);
	cout << "How many personal training sesions would you like? " << endl;
	sessions = readIntOption(0, 200);
}


void calculateTotals(char club, int months, int sessions, double &membership, double &training){
	if (club == 'S'){
		if (months >= 12){
			membership = (SPORTS_CLUB * months) - (SPORTS_CLUB * months * .10);
		}
		else if (months < 12){
			membership = (SPORTS_CLUB * months);
		}
	}
	else if (club == 'U'){
		if (months >= 12){
			membership = (ULTRA_SPORTS * months) - (ULTRA_SPORTS * months * .10);
		}
		else if (months < 12){
			membership = (ULTRA_SPORTS * months);
		}
	}
	if (sessions > 5){
		training = (SESSION_COST * sessions) - (SESSION_COST * sessions  * .20);
	}
	else if (sessions >= 5){
		training = (SESSION_COST * sessions);
	}
}


void displayTotals(int months, int sessions, double membership, double training){
	if (months >= 12){
		cout << '\n' << "Your membership cost after the 10% off is: $" << membership << endl;
	}
	else if (months < 12){
		cout << "Your membership cost is: $" << membership << endl;
	}
	cout << "Your personal training cost for " << sessions << " sessions is: $" << training << endl;
	cout << "Your total membership cost is: $" << membership + training << endl;
}

 
void endingMessage(){
	cout << '\n' << "Thank you for checking out my fitClub center!! Come back and be fit!" << endl; 
}
