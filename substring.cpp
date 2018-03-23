bool is_prefix(const char* a, const char* b, int &i){
	char sentinel = '\0';
	char whitespace = ' ';
	int start_pos = 0;
	while((a[start_pos]!=sentinel)&&((b[i]!=sentinel)||(b[i]!=whitespace))){
		if(a[start_pos]!=b[i]){
			return false;
		}
		i++;
		start_pos++;
	}
	return true;
}


int substring_position(const char* a, const char* b){
	char sentinel = '\0';
	char whitespace = ' ';
	int j = 0;
	while(b[j]!=sentinel){
		if(j==0){
			int i = j;
			if(is_prefix(a,b,i)){
				if((b[i]==sentinel)||(b[i]==whitespace)){
					return j;
				}
			}
		}
		else if(b[j]==whitespace){
			int i = j+1;
			if(is_prefix(a,b,i)){
				if((b[i]==sentinel)||(b[i]==whitespace)){
					return j+1;
				}
			}
		}
	j++;
	}
	return -1;
}
