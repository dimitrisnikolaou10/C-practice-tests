#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define BINARY_LENGTH 8
#define CORRECTION_LENGTH 7
#define CORRECTION_DATA_LENGTH 4

//helper functions
void ascii_to_binary(char ch, char* binary){
	for(int n = 128; n ; n>>=1)
		*binary++ = (ch & n) ? '1' : '0';
	*binary = '\0';
}

char binary_to_ascii(const char* binary){
	int ch = 0;
	for(int n = 0, slide = 128; n < 8; n++, slide>>=1){
		if(binary[n] == '1')
			ch = ch | slide;
	}
	return ch;
}

//own functions here
void text_to_binary(const char* string, char* binary){
	char sentinel = '\0';
	if(*string == sentinel){
		*binary = sentinel;
		return;
	}
	ascii_to_binary(*string, binary);
	text_to_binary(string+1,binary+BINARY_LENGTH);
}

void binary_to_text(const char* binary, char* string){
	char sentinel = '\0';
	if(*binary == sentinel){
		*string = sentinel;
		return;
	}
	*string = binary_to_ascii(binary);
	binary_to_text(binary+BINARY_LENGTH, string+1);
}

char parity(char d1, char d2, char d3){
	int one = d1 - 48;
	int two = d2 - 48;
	int three = d3 - 48;
	int sum = one+two+three;
	if (sum%2 == 0)
		return '0';
	else
		return '1';
}

char parity(char d1, char d2, char d3, char d4){
	int one = d1 - 48;
	int two = d2 - 48;
	int three = d3 - 48;
	int four = d4 - 48;
	int sum = one+two+three+four;
	if (sum%2 == 0)
		return '0';
	else
		return '1';
}

void add_error_correction(const char* data, char* corrected){
	char sentinel = '\0';
	char d1,d2,d3,d4,c1,c2,c3;
	if(*data == sentinel){
		*corrected = sentinel;
		return;
	}
	d1 = *(data+0);
	d2 = *(data+1);
	d3 = *(data+2);
	d4 = *(data+3);
	c1 = parity(d1,d2,d4);
	c2 = parity(d1,d3,d4);
	c3 = parity(d2,d3,d4);
	*(corrected+0) = c1;
	*(corrected+1) = c2;
	*(corrected+2) = d1;
	*(corrected+3) = c3;
	*(corrected+4) = d2;
	*(corrected+5) = d3;
	*(corrected+6) = d4;
	add_error_correction(data+CORRECTION_DATA_LENGTH, corrected+CORRECTION_LENGTH);
}

char reverse(char ch){
	if(ch=='0')
		return '1';
	else
		return '0';
}

void flip(int i, char& b1, char& b2, char& b3, char& b4, char& b5, char& b6, char& b7){
	switch(i){
	case 1: b1 = reverse(b1);
		break;  
	case 2: b2 = reverse(b2);
		break;  
	case 3: b3 = reverse(b3);
		break;  
	case 4: b4 = reverse(b4);
		break;  
	case 5: b5 = reverse(b5);
		break;  
	case 6: b6 = reverse(b6);
		break;  
	case 7: b7 = reverse(b7);
		break;  
	}
}
	
void decode(const char* received, char* decoded){
	char sentinel = '\0';
	char b1,b2,b3,b4,b5,b6,b7,p1,p2,p3;
	b1 = *(received+0); 
	b2 = *(received+1); 
	b3 = *(received+2); 
	b4 = *(received+3); 
	b5 = *(received+4); 
	b6 = *(received+5); 
	b7 = *(received+6); 
	p1 = parity(b4,b5,b6,b7);
	p2 = parity(b2,b3,b6,b7);
	p3 = parity(b1,b3,b5,b7);
	int pone, ptwo, pthree;
	pone = p1 - 48;
	ptwo = p2 - 48;
	pthree = p3 - 48;
	int sum = pone+ptwo+pthree;
	if(sum==0){
		*(decoded+0) = b3;
		*(decoded+1) = b5;
		*(decoded+2) = b6;
		*(decoded+3) = b7;
		*(decoded+4) = sentinel;
		return;
	}
	int flag[3] = {pone,ptwo,pthree};
	int incorrect_digit_index = flag[0]*4 + flag[1]*2 + flag[2]*1;
	flip(incorrect_digit_index, b1, b2, b3, b4, b5, b6, b7); 
	*(decoded+0) = b3;
	*(decoded+1) = b5;
	*(decoded+2) = b6;
	*(decoded+3) = b7;
	*(decoded+4) = sentinel;
}	

