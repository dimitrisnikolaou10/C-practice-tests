#include <iostream>
using namespace std;

#include "substring.h"

int main(){
	int result = substring_position("exercise","this is a simple exercise");
	cout << "The result is: " << result << endl;
	return 0;
}
