#include <iostream>
using namespace std;

int main(){

    int fence_count;
    int piano_width;
    
    cin>>fence_count;
    cin>>piano_width;
    
    int *fence = new int[fence_count];

    for(int i=0;i<fence_count;i++){
        cin>>fence[i];
    }

    if(fence_count<piano_width){
    
        cout<<0<<endl;
        return -1;
    }
    
    int sum = 0;
    for(int i=0;i<piano_width;i++){
        sum += fence[i];
    }
    
	int begin = 0;
    int end = piano_width;
    
    int min = sum;
    int min_pos = 0;

    while(end < fence_count){
        
        sum = sum - fence[begin] + fence[end];
        begin++; //begin from here
        end++;	//end from here -1
        if(min > sum){
            min = sum;
            min_pos = begin;
        }
        
    }

    cout<<min_pos+1<<endl; //the index is count from 1

}
