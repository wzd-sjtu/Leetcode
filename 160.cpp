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
    ListNode* A;
    ListNode* B;

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // old classic thingking
        A = headA;
        B = headB;

        while(headA != NULL && headB != NULL) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        if(headA == NULL) {
            headA = B;    
        }
        else {
            headB = A;
        }

        while(headA != NULL && headB != NULL) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        if(headA == NULL) {
            headA = B;    
        }
        else {
            headB = A;
        }

        while(headA != NULL && headB != NULL) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};