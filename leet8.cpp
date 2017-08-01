#include<iostream>
#include<limits>
using namespace std;
class Solution{
	public:
		int myAtoi(string str){
			int i=0;
			long long res=0,sign=1;
			while(str[i]==' '||str[i]=='\t'||
					str[i]=='\n'||str[i]=='\r'){
				i++;
			}
			if((str[i]<'0' || str[i]>'9')&&
					(str[i]!='+' && str[i]!='-'))
				return 0;
			if(str[i]=='+'||str[i]=='-'){
				if(str[i]=='+')sign=sign;
				else sign=-sign;
				i++;
			}
			while(str[i]>='0' && str[i]<='9'){
				res=res*10+(str[i]-'0');
				i++;
				if(res>(long long)numeric_limits<int>::max()){
					break;
				}
			}
			res=res*sign;
			if(res>(long long)numeric_limits<int>::max())
				res=numeric_limits<int>::max();
			if(res<(long long)numeric_limits<int>::min())
				res=numeric_limits<int>::min();
			return res;
		}
};

int main(){
	string str="";
	cin>>str;
	Solution s;
	int res=s.myAtoi(str);
	cout<<res<<endl;
	return 0;
}

