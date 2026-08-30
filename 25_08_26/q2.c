// Q2) LeetCode  problem number 237.

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}