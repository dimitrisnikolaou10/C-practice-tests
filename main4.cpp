#include <iostream>
#include <fstream>
using namespace std;

#include "braille.h"

int main(){
	int size;
	char braille[512];
	braille[0] = '\0';
	for(int i = 1; i < 512; i++){
		braille[i] = '.';
	}
	cout << endl;
	cout << "Question 1" << endl;

	size = encode_character('t',braille);
	cout << "The character 't' encoded in braillle is '" << braille << "' (";
	cout << size << " characters)" << endl;

	braille[0] = '\0';
	for(int i = 1; i < 512; i++){
		braille[i] = '.';
	}

	size = encode_character('Z',braille);
	cout << "The character 'Z' encoded in braillle is '" << braille << "' (";
	cout << size << " characters)" << endl;

	braille[0] = '\0';
	for(int i = 0; i < 512; i++){
		braille[i] = '.';
	}

	size = encode_character('5',braille);
	cout << "The character '5' encoded in braillle is '" << braille << "' (";
	cout << size << " characters)" << endl;

	braille[0] = '\0';
	for(int i = 0; i < 512; i++){
		braille[i] = '.';
	}

	size = encode_character('.',braille);
	cout << "The character '.' encoded in braillle is '" << braille << "' (";
	cout << size << " characters)" << endl;

	braille[0] = '\0';
	for(int i = 0; i < 512; i++){
		braille[i] = '.';
	}
/*
	cout << endl;
	cout << endl;
	cout << "Question 2" << endl;

	char string[512] = "Hello";	
	encode(string,braille);
	cout << "The string Hello in braille is " << endl << braille << endl;
*/
//	encode("S-Club7?",braille);
//	cout << "The string S-Club7? in braille is " << endl << braille << endl;

return 0;
}
