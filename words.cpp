#include <cctype>
#include <iostream>
using namespace std;

void reverse(char str1[100], char str2[100]){
	int index_of_sentinel = 0;
	char sentinel = '\0';
	while(str1[index_of_sentinel] != sentinel){
		index_of_sentinel++;
	}
	str2[index_of_sentinel] = sentinel;
	for(int i = 0; i < index_of_sentinel; i++){
		str2[index_of_sentinel - i - 1] = str1[i];
	}
}

bool compare(const char* one, const char* two){
	int index_one = 0;
	int index_two = 0;
	char sentinel = '\0';
	while(!isalpha(one[index_one])){
		index_one++;
	}
	while(!isalpha(two[index_two])){
		index_two++;
	}
	if((one[0]==sentinel)&&(two[0]==sentinel)){
		return true;
	}
	char upper_one = toupper(one[index_one]);
	char upper_two = toupper(two[index_two]);
	if(upper_one==upper_two){
		index_one++;
		index_two++;
		char copy_one[100];
		char copy_two[100];
		int index_copy_one = 0;
		int index_copy_two = 0;
		while(one[index_one-1]!=sentinel){
			copy_one[index_copy_one] = one[index_one];
			index_copy_one++;
			index_one++;
		}
		while(two[index_two-1]!=sentinel){
			copy_two[index_copy_two] = two[index_two];
			index_copy_two++;
			index_two++;
		}
		compare(copy_one,copy_two);
	}
	else{
		return false;
	}
}

bool palindrome(char sentence[100]){
	char sentence_two[100];
	reverse(sentence, sentence_two);
	return compare(sentence,sentence_two);
}

int search(char ch, char str[100]){
	int count = 0;
	int index = 0;
	char sentinel = '\0';
	while(str[index] != sentinel){
		if(ch == toupper(str[index]))
			count++;
		index++;
	}
	return count;
}
		
bool anagram(char str1[100], char str2[100]){
	int count_chars_one = 0;
	int count_chars_two = 0;
	int index_one = 0;
	int index_two = 0;
	char sentinel = '\0';
	while(str1[index_one] != sentinel){
		if(isalpha(str1[index_one]))
			count_chars_one++;
			index_one++;
	}
	while(str2[index_two] != sentinel){
		if(isalpha(str2[index_two]))
			count_chars_two++;
			index_two++;
	}
	if(count_chars_one!=count_chars_two)
		return false;
	index_one = 0;
	index_two = 0;
	int number1 = 0;
	int number2 = 0;
	char ch;
	while((str1[index_one])!=sentinel){
		ch = str1[index_one];
		number1 = search(toupper(ch), str1);
		number2 = search(toupper(ch), str2);
		if(number1!=number2)
			return false;
		index_one++;
		while(!isalpha(str1[index_one])&&(str1[index_one]!=sentinel))
			index_one++;
	}
	return true;
}
		
































	







