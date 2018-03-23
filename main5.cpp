#include <iostream>
#include <cctype>
using namespace std;

#include "piglatin.h"

int main(){
	cout << endl;
	cout << "##### Question 1 #####" << endl;
	
	int vowel = find_first_vowel("prn");
	cout << "Vowel at: " << vowel << endl;

	
	cout << endl;
	cout << "##### Question 2 #####" << endl;

	char piglatin[512];
	translate_word("Prune",piglatin);
	cout << "prune transalted is: " << piglatin <<  endl;
	
	cout << endl;
	cout << "##### Question 3 #####" << endl;

	char output[512];
	translate_stream("Prune", output);
	cout << "prune transalted is: " << output <<  endl;

return 0;
}
