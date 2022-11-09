#include<bits/stdc++.h>

using namespace std;

void genHammingCode(int siz){

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
   cout<<"\nData size is : "<<dataSize<<endl;
   
    int arr[dataSize];

    /* Storing bits in queue */
   queue<int>bits;
   cout<<"Enter bit by bits :\n";
   for(int i=1;i<=siz;i++){
    int bit;cin>>bit;
    bits.push(bit);
   }

   /*Generating hamming code */

   for(int i=1;i<=dataSize;i++){
    if( (i & (i-1)) ){
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
cout<<"Modified code with parity bit : \n"<<endl;
  for(int i=1;i<=dataSize;i++){
    // cout<<i<<" "<<endl;
    cout<<arr[i]<<" ";
   }
   cout<<endl;  

}

int main(){
    int siz;
    cout<<"\nEnter the number of bit you want to send data ? ";
    cin>>siz;
    genHammingCode(siz);            

    
}
