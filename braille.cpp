#include <iostream>
#include <cctype>
using namespace std;

void sw(char ch, char braille[512], bool condition, int si){
	int i = 0;
	if(condition){
		i = 6;
	}
	switch(ch){
		case 'a': braille[0+i+si] = '0';
			break;
		case 'b': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			break;
		case 'c': braille[0+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'd': braille[0+i+si] = '0';
			braille[3+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'e': braille[0+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'f': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'g': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'h': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'i': braille[1+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'j': braille[1+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'k': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			break;
		case 'l': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			break;
		case 'm': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'n': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'o': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'p': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 'q': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'r': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 's': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			break;
		case 't': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			break;
		case 'u': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			braille[5+i+si] = '0';
			break;
		case 'v': braille[0+i+si] = '0';
			braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[5+i+si] = '0';
			break;
		case 'w': braille[1+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			braille[5+i+si] = '0';
			break;
		case 'x': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			braille[5+i+si] = '0';
			break;
		case 'y': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			braille[3+i+si] = '0';
			braille[4+i+si] = '0';
			braille[5+i+si] = '0';
			break;
		case 'z': braille[0+i+si] = '0';
			braille[2+i+si] = '0';
			braille[4+i+si] = '0';
			braille[5+i+si] = '0';
			break;	
		case '.': braille[1+i+si] = '0';
			braille[4+i+si] = '0';
			braille[5+i+si] = '0';
			break;	
		case ',': braille[2+i+si] = '0';
			break;	
		case '!': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[4+i+si] = '0';
			break;	
		case '?': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[5+i+si] = '0';
			break;	
		case ';': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			break;	
		case '-': braille[2+i+si] = '0';
			braille[5+i+si] = '0';
			break;	
		case '(': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[4+i+si] = '0';
			braille[5+i+si] = '0';
			break;	
		case ')': braille[1+i+si] = '0';
			braille[2+i+si] = '0';
			braille[4+i+si] = '0';
			braille[5+i+si] = '0';
			break;	
	}
}

int encode_character(char ch,char braille[512]){
	char sentinel = '\0';
	bool condition = (isupper(ch)||isdigit(ch));
	if (!condition){
		braille[6] = '\0';
		sw(ch,braille,false, sentinel_index);
		return 6;
	}
	if(condition){
		braille[sentinel_index+12] = '\0';
		if(isupper(ch)){
			braille[sentinel_index+0]='.';
			braille[sentinel_index+1]='.';
			braille[sentinel_index+2]='.';
			braille[sentinel_index+3]='.';
			braille[sentinel_index+4]='.';
			braille[sentinel_index+5]='0';
			sw(tolower(ch),braille,true, sentinel_index);
		}
		else if(isdigit(ch)){
			braille[sentinel_index+0]='.';
			braille[sentinel_index+1]='.';
			braille[sentinel_index+2]='0';
			braille[sentinel_index+3]='0';
			braille[sentinel_index+4]='0';
			braille[sentinel_index+5]='0';
			char ch2;
			switch(ch){
				case '0': ch2 = 'j';
					break;
				case '1': ch2 = 'a';
					break;
				case '2': ch2 = 'b';
					break;
				case '3': ch2 = 'c';
					break;
				case '4': ch2 = 'd';
					break;
				case '5': ch2 = 'e';
					break;
				case '6': ch2 = 'f';
					break;
				case '7': ch2 = 'g';
					break;
				case '8': ch2 = 'h';
					break;
				case '9': ch2 = 'i';
					break;
			}
			sw(ch2,braille,true, sentinel_index);
		}
		return sentinel_index + 12;
	}
}

void encode(char plaintext[512],char braille[512]){
	char sentinel = '\0';
	int sentinel_index = 0;
	while(plaintext[sentinel_index]!=sentinel){
		sentinel_index++;
	}
	if(plaintext[0]==sentinel){
		return;	
	}
	else{
		encode_character(plaintext[0],braille);
		cout <<"braille: " << braille <<  endl;
		for(int i = 1; i <=sentinel_index; i++){
			plaintext[i-1]=plaintext[i];
		}
		encode(plaintext, braille);
	}
}
