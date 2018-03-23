void ascii_to_binary(char ch, char* binary);

char binary_to_ascii(const char* binary);

void text_to_binary(const char* string, char* binary);

void binary_to_text(const char* binary, char* string);

void add_error_correction(const char* data, char* corrected);

char parity(char d1, char d2, char d3);

char parity(char d1, char d2, char d3, char d4);

void decode(const char* received, char* decode);

void flip(int i, char& b1, char& b2, char& b3, char& b4, char& b5, char& b6, char& b7);

char reverse(char ch);
