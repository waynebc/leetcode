class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x<10)return true;
        int y=0;
        int z=x;
        while(z>=y){
            y=y*10+z%10;
            if(y==0)
                return false;
            
            z/=10;
            if(z==y || z==y/10)
                return true;
            else if(z<10)
                return false;
        }
        return false;
    }
};


