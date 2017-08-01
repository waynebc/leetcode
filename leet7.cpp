class Solution{
	public:
		int reverse(int x){
			
			bool neg=x<0?true:false;

			x=x>=0?x:-x;
			long long b=0;
			int tmp=0;
			while(x){
				b=b*10+x%10;
				x=x/10;
			}
			b=neg?-b:b;
			if(b<numeric_limits<int>::min()||
					b>numeric_limits<int>::max())
				b=0;
			return b;
		}
}

