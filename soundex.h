void encode(const char* surname, char soundex[5]);

int encrypt(int surname_index, const char* surname);

bool compare(const char* one, const char* two);

bool check(const char* one, const char* two, int index);

int count(const char* surname, const char* sentence);
