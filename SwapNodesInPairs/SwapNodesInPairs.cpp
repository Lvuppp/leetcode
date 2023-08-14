#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        if (head->next) {
            ListNode* tmp = head->next->next;
            head->next->next = head;
            head = head->next;
            head->next->next->next = swapPairs(tmp);
        }

        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    Solution s;
    s.swapPairs(head);
}