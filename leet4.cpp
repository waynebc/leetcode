class Solution {
	public:
	    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int len1=nums1.size();
			int len2=nums2.size();
			if(len1>len2){
				findMedianSortedArrays(nums2,nums1);
			}else{
				int start=0,end=len1-1;
				int i=(start+end)/2;
				int j=(len1+len2)/2-i;

				while(start!=end){
					if((i==(n-1) || nums1[i]>=nums2[j]) && 
							(i==0 || nums1[i-1]<=nums2[j+1])){
						break;
					}else if(i>0 && nums1[i-1]>nums2[j+1]){
						end=i-1;
					}else if(i<(n-1) && nums1[i]<nums2[j]){
						start=i+1;
					}
				}
				int isOdd=(len1+len2)%2;
				double med=0;
				if(isOdd){
					med=nums1[i-1]>nums2[j]?nums1[i-1]:nums2[j];
				}else{
					int l=nums1[i-1]>nums2[j]?nums1[i-1]:nums2[j];
					int r=nums[i]<nums2[j+1]?nums[i]:nums2[j+1];
					med=(l+r)/2.0;
				}
				return med;
			}
		}
};
