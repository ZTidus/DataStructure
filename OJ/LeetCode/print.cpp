// print
// printVector
void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}
// printLinkedList
void printLinkedList(ListNode* head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
// inorder
private:
    void inorder(TreeNode* root, unordered_set<int>& st)
    {
        if (!root) return;
        inorder(root->left, st);
        st.insert(root->val);
        inorder(root->right, st);
    }
};

