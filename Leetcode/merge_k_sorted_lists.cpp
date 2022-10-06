/*
    Anmol Bansal - Ace117MC
    Link to Problem - https://leetcode.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*> >, greater<pair<int,ListNode*> > > pq;
        for(auto i: lists) {
            if (i) pq.push({i->val, i});
        }
        
        ListNode *head = NULL;
        if(pq.size()) {
            head = pq.top().second;
            pq.pop();
        }
        if(head and head->next) {
            pq.push({head->next->val, head->next});
            head->next = NULL;
        }
        ListNode *it = head;
        while(pq.size()) {
            pair<int,ListNode*> t = pq.top();
            pq.pop();
            it->next = t.second;
            it=it->next;
            if(it->next) pq.push({it->next->val, it->next});
            it->next = NULL;
        }
        return head;
    }
};
