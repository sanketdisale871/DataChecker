    #include<bits/stdc++.h>
    
    using namespace std;
    
    vector<string>ans;
    
    void solve(int index,string s,vector<string>&temp){
        
        int m = temp.size(),n=s.size();
        
        // Base case : if number of ip address in the vector is 4 & all string is traversed
        if(index==n && m==4){
            ans.push_back(temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3]);
            return;
        }
        
        // if either out of the index or number of ip address greater than 4 then just return
        if(index>n && m>4){
            return;
        }
        
        // looping for diff length of ip addre from current index
        
        for(int i=0;i<3;i++){
            
            // if it is possible to have ip address (i+1) length
            
            if(index+i<=n){
                
                string str = s.substr(index,i+1);
                
                // if curretn ip is valid
                
                if((i==0 and str>="0" and str<="9") or (i==1 and str>="10" and str<="99") or (i==2 and str>="100" and str<="255")){
                    
                    temp.push_back(str);
                    
                    solve(index+i+1,s,temp);
                    
                    // backtrakkng
                    temp.pop_back();
                }
            }
        }
        return;
    }
    
   void restoreIpAddresses(string s) {
        
        int index = 0;
        vector<string>temp;
        
        solve(index,s,temp);
        
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }cout<<endl;
        // return ans;
    }
    
    
    int main(){
        
        string s = "25525511135" ;
        
        restoreIpAddresses(s);
        return 0;
    }
