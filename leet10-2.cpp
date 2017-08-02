#include<iostream>
using namespace std;

class Solution{
	public:
		bool isMatch(string s,string p){
			int slen=s.size(),plen=p.size();
			bool dp[slen+1][plen+1];
			dp[0][0]=true;
			for(int i=1;i<slen+1;i++){
				dp[i][0]=false;
			}
            for(int j=0;j<plen;j++){
                if(p[j]!='*'){
                    dp[0][j+1]=false;
                }else{
                    dp[0][j+1]=dp[0][j] || dp[0][j-1];
                }
            }
            
			for(int i=0;i<slen;i++){
				for(int j=0;j<plen;j++){
					if(p[j]!='*'){
						dp[i+1][j+1]=dp[i][j] && (s[i]==p[j] || p[j]=='.');
					}else{
						dp[i+1][j+1]=dp[i+1][j-1] || 
							(dp[i][j+1] && (s[i]==p[j-1] || p[j-1]=='.'));
					}
				}
			}
			return dp[slen][plen];


		}
};
int main(){
	string s,p;
	cin>>s>>p;
	Solution so;
	cout<<so.isMatch(s,p);
	return 0;
}
