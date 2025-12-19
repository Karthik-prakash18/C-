#include <iostream>
using namespace std;
// Run command g++ LL(filename).cpp -o main
// ./main.exe
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
        // TC - 0(n)
        // SC - 0(1)
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    // TC - O(l1+l2)
    // SC - O(1)
    if(list1 == NULL){
        return list2;
    }

    if(list2 == NULL){
        return list1;
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* ans = dummy;

    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            ans->next = list1;
            list1 = list1->next;
        } else{
            ans->next = list2;
            list2 = list2->next;
        }
        ans = ans->next;
    }

    if(list1!=NULL){
        ans->next = list1;
    }

    if(list2!=NULL){
        ans->next = list2;
    }

    ListNode* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

bool hasCycle(ListNode *head) {
    // TC - O(n)
    // SC - O(1)
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }

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
    // int arr[] = {1, 2, 3, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // ListNode* originalHead = createList(arr, n);
    // std::cout << "Original List: ";
    // printList(originalHead);

    // ListNode* reversedHead = solution.reverseList(originalHead);
    
    std::cout << "Reversed List: ";
    // printList(reversedHead);
    // deleteList(reversedHead);

    // int l1[] = {1, 2, 3};
    // int n1 = sizeof(l1) / sizeof(l1[0]);

    // int l2[] = {1, 3, 4, 6}; 
    // int n2 = sizeof(l2) / sizeof(l2[0]);

    // ListNode* list1 = createList(l1, n1);
    // ListNode* list2 = createList(l2, n2);

    // printList(mergeTwoLists(list1, list2));

    int c[] = {1, 2, 3, 4};
    ListNode* cycleList = createList(c, 4);

    // create cycle: tail -> node with value 2
    // cycleList->next->next->next->next = cycleList->next;

    cout << "Has Cycle: " << (hasCycle(cycleList) ? "true" : "false") << endl;

    return 0;
}