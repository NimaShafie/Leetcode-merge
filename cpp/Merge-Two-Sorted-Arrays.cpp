// https://leetcode.com/problems/merge-two-sorted-lists/
// 21. Merge Two Sorted Lists

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* combLinkedList;
		ListNode* head;
		bool l1Empty = false, l2Empty = false;		// these will be used to mark if the LL's are empty or not (if empty, we won't search)
		combLinkedList = new ListNode();
		head = combLinkedList;
		head->next = combLinkedList;
		combLinkedList->next = nullptr;

		if (l1 == nullptr) return l2;		// base case, to make sure at least one LL has data in it
		if (l2 == nullptr) return l1;
		
		// we will be examining both sorted linked lists here, we need to combine them together in a sorted order

		while ((!l1Empty || !l2Empty)) {	// while at least one of the LL's have data in them, continue the while loop

			if ((!l1Empty) && (l1->val) <= (l2->val)) {	// if the data value of l1 > l2, then we're going to insert that node into return LL
				combLinkedList->val = l1->val;
				cout << combLinkedList->val << endl;
				combLinkedList->next = l1->next;
				//combLinkedList = combLinkedList->next;
				if ((l1->next) != nullptr) l1 = l1->next;
				else {
					l1Empty = true;
					l1->val = 101;		// the limit is val >= 100, so when we switch to 101, we signal an end
				}
			}
			// need to ensure that l2 is not nullptr, if it is, then we won't be adding anymore nodes and can skip this portion
			else if (!l2Empty) {		
				combLinkedList->val = l2->val;	// else the LL gets l2's val
				cout << combLinkedList->val << endl;
				combLinkedList->next = l2->next;
				//combLinkedList = combLinkedList->next;
				if ((l2->next) != nullptr) l2 = l2->next;
				else {
					l2Empty = true;
					l2->val = 101;		// the limit is val >= 100, so when we switch to 101, we signal an end
				}
			}
		}
		cout << "Displaying the linked list from function\n";
		while (head->next != nullptr) {
			cout << head->val << endl;
			head = head->next;
		}
		return head;
	}
};

int main()
{
	ListNode* l1;
	ListNode* l12;

	ListNode* l2;


	l1 = new ListNode(0);
	l12 = new ListNode(4, nullptr);

	l1->next = l12;

	l2 = new ListNode(3, nullptr);

	Solution sol;
	ListNode* combLinkedList = sol.mergeTwoLists(l1, l2);
	combLinkedList = new ListNode();

	cout << "Displaying the final linked list now\n";
	while (combLinkedList->next != nullptr) {
		cout << combLinkedList->val << endl;
		combLinkedList = combLinkedList->next;
	}

	return 0;
}