#include<iostream>
#include<vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        if (lists.size() == 1) {
            return lists[0];
        }
        
        std::vector<ListNode*> newList;

        int i = 0;

        while(i + 1 < lists.size())
        {
            if (lists[i] == nullptr) {
                i++;
                continue;
            }

            newList.emplace_back(mergeTwoLists(lists[i], lists[i + 1]));
            i += 2;
        }

        if (lists.size() & 1) {
            newList.emplace_back(lists[lists.size() - 1]);
        }

        return mergeKLists(newList);
    }

    ListNode* mergeTwoLists(ListNode* &first, ListNode* &second) 
    {
        if (second && first->val > second->val) {
            std::swap(first, second);
        }

        if (first->next == nullptr && second == nullptr) {
            return first;
        }

        if (first->next == nullptr && second != nullptr) {
            first->next = second;
            return first;
        }

        if (first->next != nullptr && second == nullptr) {
            return first;
        }

        if (first->next->val > second->val) {
            first->next = mergeTwoLists(second, first->next);
        }
        else {
            first->next = mergeTwoLists(first->next, second);
        }

        return first;
    }
};

void print(ListNode* node) {
    if (node == nullptr) {
        return;
    }

    std::cout << node->val << " ";
    print(node->next);
}

int main() {
    std::vector<ListNode*>nodes;
  /*nodes.push_back(new ListNode(1, new ListNode(2, new ListNode(5))));
    nodes.push_back(new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(9)))));
    nodes.push_back(new ListNode(4, new ListNode(8)));*/
    nodes.push_back(new ListNode(1));
    nodes.push_back(new ListNode(0));
    Solution s;
    ListNode* node = s.mergeKLists(nodes);
    print(node);
}