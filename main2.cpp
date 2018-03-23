#include <iostream>
using namespace std;

#include "soundex.h"

int main(){
	char surname[100];
	cout << "Please provide a surname" << endl;
	cin >> surname;
	char soundex[5];
	encode(surname, soundex); 
	cout << "The sound of the surname is: " << soundex << endl;
	const char* s1 = "Jackson";
	const char* s2 = "Fkll";
	char sound1[5];
	encode(s1,sound1);
	char sound2[5];
	encode(s2,sound2);
	if(compare(sound1,sound2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	int c = 0;
	c = count(s1,"Kljngkjl, Johnson, Jollon and Babe.");
	cout << "The number of same words is: " << c << endl;
return 0;
}


