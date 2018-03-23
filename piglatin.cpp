#include <cctype>
#include <iostream>
using namespace std;

bool is_vowel(char ch, int position, int length){
	char sentinel = '\0';
	const char* all_vowels = "aeiouy";
	const char* some_vowels = "aeiou";
	bool first = position == 0;
	bool last = position == length - 1;
	if(first||last){
		int index = 0;
		while(some_vowels[index]!=sentinel){
			if(some_vowels[index] == ch){
				return true;
			}
		index++;
		}
	}
	else{
		int index = 0;
		while(all_vowels[index]!=sentinel){
			if(all_vowels[index] == ch){
				return true;
			}
		index++;
		}
	}
	return false;
}
	
		

int find_first_vowel(const char* word){
	char sentinel = '\0';
	int length = 0;
	while(word[length] != sentinel){
		length++;
	}
	for(int i = 0; i < length; i++){
		if(is_vowel(word[i], i, length)){
			return i;
		}
	}
	return -1;
}

void translate_word(const char* english, char piglatin[512]){
	char sentinel = '\0';
	int length = 0;
	while(english[length] != sentinel){
		length++;
	}
	int vowel_position = find_first_vowel(english);
	if((vowel_position == -1)){
		int index = 0;
		while(english[index] != sentinel){
			piglatin[index] = english[index];
			index++;
		}
		if(isdigit(english[0])){
			piglatin[index] = sentinel;
		}
		else{
			piglatin[index] = 'a';
			piglatin[index+1] = 'y';
			piglatin[index+2] = sentinel;
		}
		return;
	}
	if(vowel_position == 0){
		int index = 0;
		while(english[index] != sentinel){
			piglatin[index] = english[index];
			index++;
		}
		piglatin[index] = 'w';
		piglatin[index+1] = 'a';
		piglatin[index+2] = 'y';
		piglatin[index+3] = sentinel;
		return;
	}
	if(vowel_position > 0){
		if(isdigit(english[0])){
			int index = 0;
			while(english[index] != sentinel){
				piglatin[index] = english[index];
				index++;
			}
			piglatin[index] = sentinel;
			return;
		}
		bool upper = isupper(english[0]);
		int move_by = vowel_position;
		int index;
		for(index = 0; index < length; index++){
			if(index<move_by){
				piglatin[length-move_by+index] = english[index];
			}
			else{
				piglatin[index-move_by] = english[index];
			}
		}
		piglatin[index] = 'a';
		piglatin[index+1] = 'y';
		piglatin[index+2] = sentinel;
		if(upper){
			piglatin[0] = toupper(piglatin[0]);
			piglatin[length-move_by] = tolower(piglatin[length-move_by]);
		}
		return;
	}
}

void translate_stream(const char* input, char output[512]){
	char sentinel = '\0';
	char whitespace = ' ';
	if(input[0] == sentinel){
		return;
	}
	char copy_input[512];
	int index = 0;
	while(input[index]!=sentinel){
		copy_input[index] = input[index];
		index++;
	}
	copy_input[index] = sentinel;
	char copy_output[512];
	int word_end = 0;
	while((copy_input[word_end]!=whitespace)&&(copy_input[word_end]!=sentinel)){
		word_end++;
	}
	char word[512];
	for(int i = 0; i < word_end; i++){
		word[i] = copy_input[i];
	}
	word[word_end] = sentinel;
	char pigword[512];
	translate_word(word,pigword);
	index = 0;
	while(pigword[index]!=sentinel){
		copy_output[index] = pigword[index];
		index++;
	}
	
}



