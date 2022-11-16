#include<bits/stdc++.h>

using namespace std;

vector<int> genHammingCode(int siz){

    /* Input data bits from the user */
   
   
   int p=0;
    /* Finding parity bits */
   for(int i=0;i<siz;i++){
        int num = (1<<i);
        if(num>=(i+1+siz)){
            p = i;
            break;
        }
   }
    /* Actual data size */
   int dataSize = siz + p;
//    cout<<"\nData size is : "<<dataSize<<endl;
   
    int arr[dataSize];
 

    /* Storing bits in queue */
   queue<int>bits;
   cout<<"Enter bit by bits : ";
   for(int i=1;i<=siz;i++){
    int bit;cin>>bit;
    bits.push(bit);
   }

   /*Generating hamming code */

   for(int i=1;i<=dataSize;i++){
    if( (i & (i-1)) ){  // given number is not power of two
        arr[i] = bits.front();
        bits.pop();
    }
    else{
        arr[i]=0;
    }
   }


   /* Inserting Parity Bit */

    int pBit = 1;
    while(pBit<=p){
        vector<int>v;
        int d = pBit-1;
        for(int i=1;i<=dataSize;i++){

            if( (i & (1<<(d))) != 0){  // pBit th set asel tar stack madhye tak
                v.push_back(arr[i]);
            }

        }
        int one_cnt = count(v.begin(),v.end(),1);
        // int zero_cnt = count(v.begin(),v.end(),0);

        // cout<<"One count for "<<pBit<<"is "<<one_cnt<<endl;

        if(one_cnt % 2 != 0){
           int num = (1<<d);
        arr[num] = 1;  // even parity ke liye change
        }
        pBit++;
    }


//    Printing Hamming Code 
cout<<"\nSender Data : "<<endl;
  for(int i=1;i<=dataSize;i++){
    // cout<<i<<" "<<endl;
    cout<<arr[i]<<" ";
   }
   cout<<endl;  


   /* Receiver Side */ 

   srand(time(0)); 

   int toggleBit = (rand() % 10) + 1;

   if(toggleBit<=dataSize && toggleBit !=0){

        if(arr[toggleBit]==0){
            arr[toggleBit]=1;
        }else{
            arr[toggleBit]=0;
        }
   }
cout<<"\nReceiver Data : "<<endl;
  for(int i=1;i<=dataSize;i++){
    
    cout<<arr[i]<<" ";
   }
   cout<<endl;  

    vector<int>bitss;
    for(int i=1;i<=dataSize;i++){
    
    int d = arr[i];
    bitss.push_back(d);
   }
   return bitss;
}

void checkErroBit(vector<int>&bitss){

    int DataBit = bitss.size();

    // cout<<"\n\nHow many bits do you want to enter ?  : ";
    // cin>>DataBit;
    
    int sizee = DataBit;
    int userBit[sizee];
    for(int i=1;i<=sizee;i++){
        userBit[i]=bitss[i-1];
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
            // userBit[num] = 1;  // even parity ke liye change
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
   
   
   if(ans){
       cout<<"\nError Bit is : "<<ans<<endl;
       cout<<"\nCorrect Data : ";

   for(int i=1;i<=sizee;i++){
       
       if(i==ans){
           if(userBit[i]==1){
               cout<<0<<" ";
           }else{
               cout<<1<<" "; 
           }
       }
       else{
        cout<<userBit[i]<<" ";  
       }
      
   }cout<<endl;

   }
   else{
       cout<<"\nNo Error in Data. Successfully Correct Data Received."<<endl;
   }
   cout<<endl;
   

}

int main(){
    int siz;
    cout<<"\nEnter the count of bits you want to send data ? ";
    cin>>siz;
    vector<int>bits=genHammingCode(siz);   

    checkErroBit(bits);

}
