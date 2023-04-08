// 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1

//解析：首先这是一个升序的链表，题目让我建立二叉搜索树，且高度差为1，提示
//我们要分出相等的部分，即找出中间的数据，两边的节点个数是一样的
//对于这只有序地数据，一般都是递归建立的，所以我们通过快慢指针找出中间数据，其次开始建立左子树和右子树
//slow == pre 说明左面已经没有比他小的数据了
class Solution 
{
public:
  
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        struct ListNode * slow;
        struct ListNode * fast;
        struct ListNode * pre;
        slow = fast = pre = head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        struct TreeNode*root  = new TreeNode;
        root->val = slow->val;

        if(pre==slow)
        {
            root->left = nullptr;
        }else
        {
            pre->next = nullptr;//阶段中间阶段前面的数据
            root->left = sortedListToBST(head);
            pre->next = slow;
        }
        root->right = sortedListToBST(slow->next);
        return root;
    }
};