#include <iostream>
using namespace std;

#include "words.h"

int main(){
	char str1[100];
	char str2[100];
	cout << "What do you want to reverse?" << endl;
	cin >> str1;
	reverse(str1,str2);
	cout << "Reversed it now is: " << str2 << endl;
	const char* one = "this and that";
	const char* two = "This, and That";
	bool condition = compare(one, two);
	if(condition)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	char sentence[100] = "Madam, I Adam";
	bool pal = palindrome(sentence);
	cout << "Is sentence a palindrome? ";
	if(pal)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	char st1[100] = "Wiliam Shakespeare";
	char st2[100] = "I am a weakish speller!";
	bool con2 = anagram(st1,st2);
	cout << "Is One is anagram of Two? ";
	if(con2)
		cout << "True" << endl;
	else
		cout << "False" << endl;
return 0;
}


