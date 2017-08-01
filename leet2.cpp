/*
 * Definition for singly-linked list.
 */
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
	public:
		ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
			ListNode* lp=new ListNode(-1);
			ListNode* l3=lp;
			int carry=0;
			while(l1!=NULL || l2!=NULL){
			    
				l3->next=new ListNode(0);
				l3=l3->next;
				
				if(l1==NULL){
					l3->val=(l2->val+carry)%10;
					carry=(l2->val+carry)/10;
					l2=l2->next;
				}else if(l2==NULL){
					l3->val=(l1->val+carry)%10;
					carry=(l1->val+carry)/10;
					l1=l1->next;
				}else{
					l3->val=(l1->val+l2->val+carry)%10;
					carry=(l1->val+l2->val+carry)/10;
					l1=l1->next;
					l2=l2->next;
				}
			}
			if(carry){
			    l3->next=new ListNode(carry);
			}
			return lp->next;
		}
};





