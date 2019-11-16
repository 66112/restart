/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) return head;
		ListNode* before_head = new ListNode(-1);
		ListNode* after_head = new ListNode(-1);
		ListNode* before = before_head, *after = after_head;
		while (head){
			if (head->val < x){
				before->next = head;
				before = before->next;
			}
			else{
				after->next = head;
				after = after->next;
			}
			head = head->next;
		}
		after->next = NULL;
		before->next = after_head->next;
		return before_head->next;
	}
};