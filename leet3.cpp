class Solution {
	public:
		 int lengthOfLongestSubstring(string s) {
			 map<char,int> posMap;
			 int start=0,end=1;
			 int maxLen=1;
			 posMap[s[0]]=0;
			 for(;end<s.size();end++){
				 if(posMap.find(s[end])!=posMap.end()){
					 int len=end-start;
					 maxLen=maxLen>len?maxLen:len;
					 start=posMap[s[end]]+1;
				 }
				 posMap[s[end]]=end;
			 }
			 return maxLen;
		 }
};

