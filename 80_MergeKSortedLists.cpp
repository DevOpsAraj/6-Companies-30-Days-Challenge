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
class Solution
{
public:
    ListNode *mergeTwolists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwolists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwolists(list1, list2->next);
            return list2;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;

        ListNode *temp = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            temp = mergeTwolists(temp, lists[i]);
        }
        return temp;
    }
};