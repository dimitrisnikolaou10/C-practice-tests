#include <iostream>
using namespace std;

char encrypt(int surname_index, const char* surname){
	char ch = surname[surname_index];
	if((ch=='b')||(ch=='f')||(ch=='p')||(ch=='v'))
		return '1';
	else if((ch=='c')||(ch=='g')||(ch=='j')||(ch=='k'||(ch=='q')||(ch=='s')||(ch=='x')||(ch=='z')))
		return '2';
	else if((ch=='d')||(ch=='t'))
		return '3';
	else if((ch=='l'))
		return '4';
	else if((ch=='m')||(ch=='n'))
		return '5';
	else if((ch=='r'))
		return '6';
	else
		return '0';
}

void encode(const char* surname, char soundex[5]){
	char sentinel = '\0';
	soundex[0] = surname[0];
	soundex[4] = sentinel;
	int soundex_index = 1;
	while(soundex_index < 4){
		soundex[soundex_index] = '0';
		soundex_index++;
	}
	soundex_index = 1;
	int surname_index = 1;
	char code = '0';
	char previous_code = '1';
	while((surname[surname_index]!=sentinel)&&(soundex[soundex_index]!=sentinel)){
		code = encrypt(surname_index, surname);
		if((code!='0')&&(code!=previous_code)){
			soundex[soundex_index] = code;
			soundex_index++;
			previous_code = code;
		}
		surname_index++;
	}
}		

bool check(const char* one, const char* two, int index){
	if(one[index]==two[index]){
		index++;
		if(index < 4)
			check(one, two, index);
		else 
			return true;
	}
	else
		return false;
}

bool compare(const char* one, const char* two){
	return check(one, two, 0);
}

int count(const char* surname, const char* sentence){
	char soundex[5];
	encode(surname, soundex);
	int start_index = 0;
	int finish_index = 0;
	char comma = ',';
	char whitespace = ' ';
	char period = '.';
	char sentinel = '\0';
	int count = 0;
	while(sentence[finish_index]!=period){
		while(isalpha(sentence[finish_index])){
			finish_index++;
		}
		char name[100];
		int index = 0;
		for(int i = start_index; i < finish_index; i++){
			name[index] = sentence[i];
			index++;
		}
		name[index] = sentinel;
		char soundex_other[5];
		encode(name, soundex_other);
		if(compare(soundex, soundex_other))
			count++;
		if(sentence[finish_index]==whitespace){
			start_index = finish_index + 5;
			finish_index = start_index;
		}
		else if(sentence[finish_index]!=period){
			start_index = finish_index + 2;
			finish_index = start_index;
		}
		else if(sentence[finish_index]==period){
			return count;
		}
	}
}





	




















