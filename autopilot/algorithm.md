---
title: coding
categories: CAT
tags: TAG
date: 2021-05-07
---

- [螺旋数组](#螺旋数组)
- [旋转矩阵](#旋转矩阵)
- [重建二叉树](#重建二叉树)
- [二叉树的下一个节点](#二叉树的下一个节点)
- [用两个栈实现队列](#用两个栈实现队列)
- [矩阵中的路径](#矩阵中的路径)
- [二进制中1的个数](#二进制中1的个数)
- [数值的整数次方](#数值的整数次方)
- [树的子结构](#树的子结构)
- [二叉树的镜像](#二叉树的镜像)
- [对称的二叉树](#对称的二叉树)
- [包含min函数的栈](#包含min函数的栈)
- [栈的压入、弹出序列](#栈的压入、弹出序列)
- [二叉搜索树的后序遍历序列](#二叉搜索树的后序遍历序列)
- [二叉树中和为某一值的路径](#二叉树中和为某一值的路径)
- [最长不含重复字符的子字符串](#最长不含重复字符的子字符串)
- [丑数](#丑数)


#### 螺旋数组

1. 遍历过的地方做标记
2. 根据步进做换向：

> di=0, dj=1 | di,dj=dj,-di(右转向，-90旋转矩阵)

```python
def spiralMatrix(nums):
    i=0
    j=0
    di=0
    dj=1
    rows=len(nums)
    cols=len(nums[0])
    for _ in range(rows*cols):
        print("{} ".format(nums[i][j]), end="")
        nums[i][j]=None
        next=nums[(i+di)%rows][(j+dj)%cols]
        if next is None:
            di,dj=dj,-di
        i += di
        j += dj
    
    print()
```

#### 旋转矩阵

#### 重建二叉树

输入某二叉树的前序遍历和中序遍历的结果(不包含重复数字)，请重建出该二叉树

解析： 前序遍历第一位为根节点，这样就可以在中序遍历中找到根节点的索引。而在中序遍历的跟节点索引之前的是左边区域的中序遍历结果，之后的是右边区域的遍历结果。根据两片区域的长度顺序在前序遍历的数组中取值就可以得到相对应的前序遍历结果，如此便可以递归进行。

```c++
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0 || pre.size()!=vin.size()){
            return nullptr;
        }
        
        TreeNode *head=new TreeNode(pre[0]);
        
        // find index
        vector<int>::iterator index_iter=find(vin.begin(),vin.end(),pre[0]);
        int index=index_iter-vin.begin();

        vector<int> vin_l(vin.begin(),index_iter);
        vector<int> vin_r(index_iter+1,vin.end());
        vector<int> pre_l(pre.begin()+1,pre.begin()+1+index);
        vector<int> pre_r(pre.begin()+1+index,pre.end());
        
        head->left=reConstructBinaryTree(pre_l,vin_l);
        head->right=reConstructBinaryTree(pre_r,vin_r);
        
        return head;
    }
};

// 优化， 增加索引参数，减少数组拷贝
class Solution {
public:
    TreeNode* recursion(vector<int>& preorder,int pre_l,int pre_r,vector<int>& inorder,int in_l,int in_r)
    {
        if(pre_l > pre_r) return nullptr;
        if(pre_l == pre_r) return new TreeNode(preorder[pre_l]);
        
        int rt_val = preorder[pre_l];
        auto it = find(inorder.begin()+in_l,inorder.begin()+in_r+1,rt_val);
        
        int left = it - (inorder.begin() + in_l);
        
        TreeNode* root = new TreeNode(rt_val);
        root->left = recursion(preorder,pre_l + 1,pre_l + left,inorder,in_l,in_l + left - 1);
        root->right = recursion(preorder,pre_l + left + 1,pre_r,inorder,in_l + left + 1,in_r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursion(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
```



#### 二叉树的下一个节点

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

```c++
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode==nullptr){
            return nullptr;
        }
        
        // 有右节点则在右节点中找
        if(pNode->right !=nullptr){
            pNode=pNode->right;
            while(pNode->left !=nullptr){
                pNode=pNode->left;
            }
            return pNode;
        }
        
        // 没有右节点则在父节点中找
        // 分两种情况：
        //    若当前为左节点，返回父节点
        //    若当前为右节点，则更新当前为父节点，循环
        while(pNode->next !=nullptr){
            TreeLinkNode *tmp=pNode;
            pNode=pNode->next;
            if(tmp==pNode->left){
                return pNode;
            }
        }
        
        return nullptr;
    }
};
```

#### 用两个栈实现队列

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

```c++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(! stack2.empty()){
            int res=stack2.top();
            stack2.pop();
            return res;
        }
        
        while(! stack1.empty()){
            int res=stack1.top();
            stack1.pop();
            stack2.push(res);
        }
        
        if(! stack2.empty()){
            int res=stack2.top();
            stack2.pop();
            return res;
        }else{
            return -1;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

#### 矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 

示例：

> IN: [[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcced"
> OUT: true

解析: 一开始想到用BFS，但是通过率只有70%。原因是BFS同时对所有路径进行遍历，路径之间相互有干扰。所以正确的做法是回溯遍历，一条一条地走，走不通的需要回退，保持地图原样。

```c++
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==word[0]){
                    if(bfsBack(matrix,word,i,j,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool bfsBack(vector<vector<char> >& matrix, string word,int x,int y,int start){
        if(start == word.size()){
            return true;
        }
       
        int m=matrix.size();
        int n=matrix[0].size();
        char tmp=matrix[x][y];
        matrix[x][y]='0';
        
        vector<pair<int,int> > nums={{x-1,y},
                                     {x+1,y},
                                     {x,y-1},
                                     {x,y+1}};
        for(auto num:nums){
            int x=num.first;
            int y=num.second;
            if(x>=0 &&x<m && y>=0 && y<n && matrix[x][y]==word[start]){
                if(bfsBack(matrix,word,x,y,start+1)){
                    return true;
                }
            }
        }
        matrix[x][y]=tmp;

        return false;
    }
};
```

#### 剪绳子

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

思路：

1. 个人思路： 比较分割成[2,n/2+1]哪次分隔最大，每次分割按最均匀分割
2. 动态规划: dp[n]是n的最大乘积

```c++
//m2 dp[i]=max(j*dp[i-j],j*(i-j)), for j in [2,i-2]
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(max(4,n+1),0);
        dp[2]=1;
        dp[3]=2;

        if(n<4){
            return dp[n];
        }
        
        for(int i=4;i<n+1;i++){
            for(int j=2;j<=i-2;j++){
                dp[i]=max(dp[i],j*dp[i-j]);
                dp[i]=max(dp[i],j*(i-j));
            }
        }

        return dp[n];
    }

};


// m1 
class Solution {
public:
    int cuttingRope(int n) {
        int num=n/2+1;
        int max_n=0;
        vector<int> res(num-1);
        for(int i=1;i<num;i++){
            res[i-1]=getMax(n,i+1);
            max_n=max(max_n,res[i-1]);
        }
        return max_n;

    }
    int getMax(int n, int split){
        int m=n/split;
        int yu=n%split;
        vector<int> tmp(split,m);
        for(int i=0;i<yu;i++){
            tmp[i] +=1;
        }

        int res=1;
        for(int i=0;i<tmp.size();i++){
            res *=tmp[i];
        }
        return res;
    }
};

```

#### 二进制中1的个数

请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。


```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n>0){
            res +=(n&1);
            n >>=1;
        }
        return res;
        
    }
};
```

#### 数值的整数次方

实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

```c++
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==-1) return 1/x;
        if(n&1) return myPow(x*x,n>>1)*x;
        else return myPow(x*x,n>>1);


    }
};
```

#### 正则表达式匹配  

根据pattern的第二个字符是不是'*'字符，将情况分为两类。

pattern的下一个字符为'*'字符，即*(pattern+1)=='*'，此时又分为两种情况：
如果当前字符匹配，即 *str==*pattern或者*str=='.' && *pattern!='\0'，根据'*'表示的含义划分为三种：
当前字符出现0次：等价于判断str和pattern+2是否匹配。
当前字符出现1次：等价于判断str+1和pattern+2是否匹配。
当前字符出现1次以上：等价于判断str+1和pattern是否匹配。
如果当前字符不匹配，此时'*'只能表示当前字符出现0次。等价于判断str和pattern+2是否匹配。
pattern的下一个字符不为'*'字符，即*(pattern+1)!='*'，这时逻辑比较简单：
如果当前字符匹配，即 *str==*pattern或者*str=='.' && *pattern!='\0'，此时等价于判断str+1和pattern+1是否匹配。
如果当前字符不匹配，直接返回false即可。

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        return matchHelp(s,p,0,0);
    }

    bool matchHelp(string s,string p,int si,int pi){
        if(si==s.size() && pi>=p.size()){
            return true;
        }
        if(si<s.size() && pi>=p.size()){
            return false;
        }

        

        //1. p next is not *
        if((pi<p.size()-1 && p[pi+1]!='*')|| pi==p.size()-1){
            if(si==s.size()){
                return false;
            }
            if(s[si]==p[pi] || p[pi]=='.'){
                return matchHelp(s,p,si+1,pi+1);
            }else{
                return false;
            }
        }

        //2. p next is *
        if(s[si]==p[pi] || p[pi]=='.'){
            if(si==s.size()){
                return matchHelp(s,p,si,pi+2);
            }
            return matchHelp(s,p,si,pi+2) || matchHelp(s,p,si+1,pi);
        }else{
            return matchHelp(s,p,si,pi+2);
        }

    }
};
```

#### 调整数组顺序使奇数位于偶数前面  

> In: [1,2,3,4]
> Out: [1,3,2,4]

```c++
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            while(l<r && isOdd(nums[l])){
                l++;
            }
            while(l<r && !isOdd(nums[r])){
                r--;
            }
            if(l<r){
                int tmp=nums[l];
                nums[l]=nums[r];
                nums[r]=tmp;
                l++;
            }
        }
        return nums;

    }
    bool isOdd(int num){
        return num%2==1;
    }
};
```

#### 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

解析：遍历二叉树，查看是否存在一个节点，使得从当前节点开始的子树与B重合。

注意点：

1. 遍历的方式，可以参考前序中序后序，即`recurCheck(A,B) || isSubStructure(A->left,B) ||isSubStructure(A->right, B);`这里面三个函数是不一样的。
2. 对当前节点判断是否相同
    - b为空，说明已经匹配完毕，return true
    - a为空，说明b还有没匹配， return false
    - 值不等，false
    - 递归判断左右子节点



```c++
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B==nullptr){
            return false;
        }
        // 遍历节点
        return recurCheck(A,B) || isSubStructure(A->left,B) ||isSubStructure(A->right, B);

    }

    // 对当前节点判断是否相同
    bool recurCheck(TreeNode*a, TreeNode *b){
        if(b==nullptr){
            return true;
        }
        if(a==nullptr){
            return false;
        }

        if(a->val !=b->val){
            return false;
        }

        return recurCheck(a->left,b->left) && recurCheck(a->right,b->right);

    }
};
```

#### 二叉树的镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像

```
例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9

镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }

        TreeNode *tmp=root->left;
        root->left=mirrorTree(root->right);
        root->right=mirrorTree(tmp);
        return root;
    }
};
```

#### 对称的二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

```
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
```

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }

        return helpFunc(root->left,root->right);

    }

    bool helpFunc(TreeNode* t1,TreeNode* t2){
        if(t1==nullptr && t2==nullptr){
            return true;
        }
        if(t1==nullptr || t2==nullptr){
            return false;
        }

        if(t1->val==t2->val){
            return helpFunc(t1->left, t2->right) && helpFunc(t1->right,t2->left);
        }
        return false;
    }
};
```


#### 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

解析: 使用两个栈。其中一个栈正常地存储数据linguine栈push保存当前值对应的最小值

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        sa.push(x);
        if(sb.empty() || x<sb.top()){
            sb.push(x);
        }else{
            sb.push(sb.top());
        }
    }
    
    void pop() {
        sa.pop();
        sb.pop();
    }
    
    int top() {
        return sa.top();
    }
    
    int min() {
        return sb.top();
    }

private:
    stack<int> sa;
    stack<int> sb;
};

```

#### 栈的压入、弹出序列  

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1;
        int p1=0;
        int p2=0;
        for(int i =0;i<pushed.size();i++){
            s1.push(pushed[i]);
            while(!s1.empty() && p2<popped.size() && s1.top()==popped[p2]){
                s1.pop();
                p2++;
            }
        }
        return s1.empty();
    }
};
```

#### 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

```c++
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyHelp(postorder,0, postorder.size()-1);

    }

    bool verifyHelp(vector<int>& nums, int l, int r){
        if(r-l <1){
            return true;
        }

        int head=nums[r];
        int lr=l;
        while(lr<r && nums[lr]<head){
            lr++;
        }


        // validatity check
        for(int i=lr;i<r;i++){
            if(nums[i] <head){
                return false;
            }
        }

        return verifyHelp(nums,l,lr-1) && verifyHelp(nums,lr,r-1);

    }
};
```

#### 二叉树中和为某一值的路径

输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

```c++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root==nullptr){
            return vector<vector<int>>();
        }

        return helpFunc(root,target,0);
    }

    vector<vector<int> > helpFunc(TreeNode* root,int target, int depth){
        vector<vector<int> > rr;
        if(root->left==nullptr && root->right==nullptr){
            if(root->val!=target){
                return rr;
            }
            vector<int> res(depth+1,0);
            res[depth]=target;
            rr.push_back(res);
            return rr;
        }

        if(root->left !=nullptr){
            vector<vector<int> > r1=helpFunc(root->left,target-(root->val),depth+1);
            for(auto r11:r1){
                r11[depth]=root->val;
                rr.push_back(r11);
            }
        }
        if(root->right !=nullptr){
            vector<vector<int> > r2=helpFunc(root->right,target-(root->val),depth+1);
            for(auto r22:r2){
                r22[depth]=root->val;
                rr.push_back(r22);
            }
        }
        return rr;
    }
};
```

#### 最长不含重复字符的子字符串

解析: 维护一小段不重复的窗口

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int l=0;
        int r=0;
        int res=1;
        while(r<s.size()-1){
            int index=-1;
            for(int i=l;i<=r;i++){
                if(s[r+1]==s[i]){
                    index=i;
                }
            }

            if(index<0){
                r++;
                res=max(res,r-l+1);
            }else{
                l=index+1;
                r++;
            }
        }

        return res;

    }
};
```

#### 丑数

我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

```
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n,1);
        int a=0;
        int b=0;
        int c=0;

        int index=1;
        while(index<n){
            res[index]=min(res[a]*2,min(res[b]*3,res[c]*5));
            if(res[index]==res[a]*2) a++;
            if(res[index]==res[b]*3) b++;
            if(res[index]==res[c]*5) c++;
            index++;
        }

        return res[n-1];
    }
};
```

#### 数组中的逆序对

归并

```c++
class Solution {
public:
    int count=0;
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        mergeSort(nums,0,nums.size()-1);
        return count;

    }

    vector<int> mergeSort(vector<int>& nums,int l,int r){
        if(l==r){
            return vector<int>(1,nums[l]);
        }

        int mid=(l+r)/2;
        vector<int> nl=mergeSort(nums,l,mid);
        vector<int> nr=mergeSort(nums,mid+1,r);

        int m=r-l+1;
        vector<int> res(m,0);

        l=0;
        r=0;
        m=0;
        while(l<nl.size() && r<nr.size()){
            if(nl[l]<=nr[r]){
                res[m++]=nl[l++];
            }
            else{
                res[m++]=nr[r++];
                // 表示从i开始的数与nr[r]相比都是一次逆序数
                count +=nl.size()-l;
            }
        }
        while(l<nl.size()){
            res[m++]=nl[l++];
        }

        while(r<nr.size()){
            res[m++]=nr[r++];
        }
        return res;
    }
};
```


