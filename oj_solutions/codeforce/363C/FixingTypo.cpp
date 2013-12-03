#include <iostream>
using namespace std;

int main(){
	
	string str;
	cin>>str;
	
	int len=str.size();

	if(len == 0){
		return -1;
	}

	string new_str(len,0);
	new_str[0] = str[0];
	int pos = 1;
	bool repeat = false;
	for(int i=1;i<len;i++){
		if(str[i] == str[i-1]){
			if(repeat){
				continue;
			}else{
				new_str[pos] = str[i];
				pos++;
				repeat = true;
			}
		}else{
		
			new_str[pos] = str[i];
			pos++;
			repeat = false;
		}
	}
	
	string result(pos,0);
	bool isTypo = false;
	int begin = 0;
	int result_pos=0;
	while(begin<pos){

		if(!isTypo){
			
			if(begin == pos -1){
				result[result_pos] = new_str[begin];
				break;
			}else{
				
				result[result_pos] = new_str[begin];
				result_pos++;
				
			
				if(new_str[begin] == new_str[begin+1]){
					isTypo = true;
					result[result_pos] = new_str[begin+1];
					result_pos++;
					begin = begin + 2;
				}else{
					begin++;
				}

			}

		}else{
		
			if(begin == pos-1){
				result[result_pos] = new_str[begin];
				break;
			}else{
				
				result[result_pos] = new_str[begin];
				result_pos++;
				
				if(new_str[begin] == new_str[begin+1]){
					result_pos++;
					begin = begin + 2;
				}else{
					begin++;
				}

				isTypo = false;
			}

		}

	}
	
	result.resize(begin+1);

	cout<<str<<endl;
	cout<<new_str<<endl;
	cout<<result<<endl;
}

