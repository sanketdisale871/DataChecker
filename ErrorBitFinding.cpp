
#include<bits/stdc++.h>

using namespace std;


int main(){
    int DataBit;

    cout<<"\n\nHow many bits do you want to enter ?  : ";
    cin>>DataBit;
    
    int sizee = DataBit;
    int userBit[sizee];
    for(int i=1;i<=sizee;i++){
        cin>>userBit[i];
    }
    stack<int>bitNoError;

    int pBit = 3;
        // int pBit = 1;
    while(pBit>=1){
        vector<int>v;

        int d = pBit-1;
        for(int i=1;i<=sizee;i++){

            if( (i & (1<<(d))) != 0){  // pBit th set asel tar vector madhye tak
                v.push_back(userBit[i]);
            }

        }
        int one_cnt = count(v.begin(),v.end(),1);
    

        // cout<<"One count for "<<pBit<<"is "<<one_cnt<<endl;

        if(one_cnt % 2 != 0){
           int num = (1<<d);
            userBit[num] = 1;  // even parity ke liye change
            bitNoError.push(1);
        }
        else{
            bitNoError.push(0);
        }
        pBit--;
    }

    /* Calculating error bit  number */
    int ans = 0;
    int i =0;
    while(!bitNoError.empty()){
      int num = (1<<i);
      if(bitNoError.top()){
        ans += num;
        i++;
      }
      else{
        i++;
      }
      bitNoError.pop();
    }
   cout<<"\nError Bit is : "<<ans;

    return 0;
}
