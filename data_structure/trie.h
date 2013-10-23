

class Trie{

	int count;
	char val;
	Trie* tries[26];
	
	int toLowerCase(char c){
		if(c >= 'a' && c<= 'z'){
			return c-'a';
		}

		if(c >= 'A' && c<= 'Z'){
			return c-'A';
		}

		return -1;
	}

public:

	Trie(char var){
		this->val = val;
		this->count = 0;
	}
	
	void insert(char* str){
		

		if(*str == '\0'){
			return;
		}	
		
		this->count++;
		
		int currentVal = toLowerCase(*str);
		if(currentVal < 0){
			
			//throw exception;
			return;
		}
		
		
		if(tries[currentVal] == null){
			
			tries[currentVal] = new Trie(currentVal+'a');
		}else{
			
		}

		tries[currentVal].insert(str++);
	}

	int lookup(char* str){
		
		if(*str == '\0'){
			return count;
		}		

		int currentVal = toLowerCase(*str);
		if(currentVal < 0){
			// throw Exception;
			return 0;
		}

		if(tries[currentVal] == null){
			return 0;
		}

		return tries[currentVal].lookup(str++);
	}

}



