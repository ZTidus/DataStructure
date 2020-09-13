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

// compute digits
// 计算一个整数的位数
private:
    int compute_digits(int num)
    {
        int res = 0;
        while (num > 0)
        {
            res++;
            num /= 10;
        }
        return res;
    }
