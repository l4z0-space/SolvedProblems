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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<long long > first,second;
    
        while(l1 != NULL ){
            first.push_back(l1->val);
            l1 = l1->next;
            
        }
        while(l2 != NULL ){
            second.push_back(l2->val);
            l2 = l2->next;
        }
    
       
         vector<int> rs;
        
        int sz = min(first.size(),second.size());
        int rem = 0;
        
        for(int i=0;i<sz;i++){
            int toADD= ((first[i]+second[i]+rem));
            rs.push_back(toADD%10);
            rem = toADD/10;
                    
        }
        
        //remainging digits;
        if(first.size()>sz){
            for(int i=sz;i<first.size();i++){
                int toADD = first[i]+rem;
                rs.push_back(toADD%10);
                rem= toADD/10;
            }
        }
        if(second.size()>sz){
            for(int i=sz;i<second.size();i++){
                int toADD = second[i]+rem;
                rs.push_back(toADD%10);
                rem= toADD/10;
            }
        }
        if(rem!=0)rs.push_back(rem);
        ListNode *toReturn = new ListNode(rs[0]);
        ListNode *temp = toReturn;
        for(int i = 1;i<rs.size();i++){
            temp->next = new ListNode(rs[i]);
            temp = temp->next;
        
        }
        return toReturn;
    }
};