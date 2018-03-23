#include <iostream>
#include "correct.h"
using namespace std;

int main(){
	cout << "$$$$ Helper functions $$$$$" << endl << endl;
	char binary[9];
	ascii_to_binary('A', binary);
	cout<<"The ASCII code of A is "<<int('A')<<" which in binary is "<<binary<<endl;
	cout << endl;

	cout << "$$$$$ Question 1 $$$$$ " << endl << endl;
	char encoded[512], text[32];
	text_to_binary("Art", encoded);
	cout<<"Art encoded as binary is: " << encoded << endl << endl;
	binary_to_text("010000010111001001110100",text);
	cout<<"00....100 decoded in text is: "<<text<<endl<<endl;

	cout << "$$$$$ Question 2 $$$$$ " << endl << endl;
	char correct[512];
	add_error_correction("01000001",correct);
	cout<<"01000001 correction bits are: " << correct << endl;

	cout << "$$$$$ Question 3 $$$$$ " << endl << endl;
	char decoded[512];
	decode("1001110",decoded);
	cout << "1001110 decoded is: " << decoded << endl;
	return 0;
}
