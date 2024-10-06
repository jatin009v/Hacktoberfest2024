1. Kth Largest Element in an Array using Min-Heap
Problem: Given an array of integers, find the Kth largest element in the array.

Algorithm:
Create a min-heap of size K.
Iterate through each element of the array:
If the heap has less than K elements, add the element to the heap.
Otherwise, if the element is larger than the smallest element in the heap (root), remove the smallest element from the heap and add the current element.
After iterating through all elements, the root of the heap will be the Kth largest element.
Code (C++):
cpp
Copy code
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Create a min-heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        
        // Maintain size of heap to k
        if (minHeap.size() > k) {
            minHeap.pop(); // Pop smallest element
        }
    }
    
    // The root of the min heap is the Kth largest element
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << "Kth largest element is " << findKthLargest(nums, k) << endl;
    return 0;
}
Time Complexity:
O(N log K) where N is the number of elements in the array, because inserting and removing from the heap takes log K time.


2. Merge K Sorted Lists using Min-Heap
Problem: Given K sorted linked lists, merge them into one sorted list.

Algorithm:
Create a min-heap to keep track of the first node of each list.
Extract the smallest element from the heap and add it to the result list.
Insert the next node of the extracted element into the heap.
Repeat the process until all the lists are merged.
Code (C++):
cpp
Copy code
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for the min-heap
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Min-heap (priority queue)
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    // Push the head of each list into the heap
    for (auto list : lists) {
        if (list) minHeap.push(list);
    }

    // Create a dummy node to help with result list creation
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Extract the minimum element from the heap, add it to the result list
    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();
        current->next = smallest;
        current = current->next;

        // If there's a next node in the list, push it into the heap
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}

int main() {
    // Example usage
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};
    ListNode* result = mergeKLists(lists);

    // Output the merged list
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
Time Complexity:
O(N log K) where N is the total number of elements across all lists, and K is the number of linked lists.
