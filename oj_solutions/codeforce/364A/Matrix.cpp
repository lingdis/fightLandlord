nclude <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	    
	    int sum;
		    string str;
			    
			    cin>>sum;
				    cin>>str;
					    
					    int len = str.size();
						    int *numbers = new int[len];
							    
							    for(int i=0;i<len;i++){
									        numbers[i] = str[i] - '0';
											    }
								    
								    vector<int> values;
									    queue<int> current;

										    
										    for(int i=len-1;i>=0;i--){
												        
												        current.push(0);
														        int sizeTemp = current.size();
																        for(int j=0;j<sizeTemp;j++){
																			            int temp = current.front();
																						            current.pop();
																									            temp = temp + numbers[i];
																												            values.push_back(temp);
																															            current.push(temp);
																																		        }
																		    }
											    

											    sort(values.begin(),values.end());
												    
												    for(int i=0;i<values.size();i++){
														        cout<<values[i]<<" ";
																    }
													    cout<<endl;
														    
														    auto high = upper_bound(values.begin(), values.end(), sum);
															    int upper_len = values.end() - high;
																    
																    for(int i=0;i<upper_len;i++){
																		        values.pop_back();
																				    }
																	    
																	    cout<<values.size()<<endl;
																		    cout<<values[values.size()-1]<<endl;
																			    
																			    int sqrtRoot = sqrt(sum);
																				    auto low = lower_bound(values.begin(), values.end(), sqrtRoot);
																					    
																					    cout<<"low: "<<*low<<endl;
																						    
																						    int lowerIndex = low - values.begin();
																							    int counts = 0;
																								    for(int i=0;i<lowerIndex;i++){
																										        
																										        while(i!=0 && values[i] == values[i-1]){
																													            i++;
																																        }
																												        
																												        if(sum % values[i] == 0){
																															            int another = sum / values[i];      
																																		            auto bounds = equal_range(low, high, another);
																																					            //low = bounds.second;
																																					            high = bounds.first;
																																								            if(bounds.first == bounds.second){
																																												                continue; 
																																																            }else{
																																																				                cout<<*bounds.first<<" "<<*bounds.second<<endl;
																																																								                counts += (bounds.second - bounds.first);
																																																												            }
																																											        }
																														        
																														    }
																									    
																									    if(sqrtRoot * sqrtRoot == sum){
																											        auto bounds = equal_range(low, values.end(), sqrtRoot);
																													    }
																										     
																										     cout<<counts<<endl;   
																											     
}
