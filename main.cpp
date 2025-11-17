#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next_node = nullptr;

        while(curr != nullptr){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        return prev;
    }
};

ListNode* createList(const int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << (current->next != nullptr ? " -> " : "");
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Solution solution;
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* originalHead = createList(arr, n);
    std::cout << "Original List: ";
    printList(originalHead);

    ListNode* reversedHead = solution.reverseList(originalHead);
    
    std::cout << "Reversed List: ";
    printList(reversedHead);

    deleteList(reversedHead);

    return 0;
}