/*
树结构是非线性结构，其规定的是分支关系定义的层次结构的逻辑结构
树有且只有一个根节点，除了根节点都必定有一个前驱
当树内元素大于1时候，可以将树分为m多个小的树，成为子树

树的结点指 当前结点的数据和向下的分支路径，当前结点拥有的子树称之为结点的度，树的最大度为树的度，度为0的结点为叶子结点或者终端结点。度大于0的结点称为分支结点 内部结点为除了根节点的分支结点
结点的子树的根节点称为结点的孩子，该节点为孩子的双亲，拥有同一个双亲的结点称为兄弟，在同一层的称为堂兄弟
子孙结点是当前结点的子树的所有结点 祖先结点是当前结点到根节点路径上的所有结点

树的最大层次称为输的深度或者高度 根节点是第一层 叶子结点在最高层
如果树的左右结点是有次序的，不可交换则称为有序树否则是无序树。
森林是m个互不相交的树的集合（M>=0）
树的实际关系是一个递归关系是一个二元组Tree=(value,F) value是数据元素,F是m个子树的森林 F=(T1,T2,T3) Ti=(value,F)是当前的子树

二叉树：每个结点最多只能有2棵子树 （空树是不是二叉树？） （严格定义：或为空树，或为由一个根节点加上两颗分别称为左子树右子树的互不相交的二叉树组成）
二叉树的度最大为2 二叉树是有序树，子树严格分为左右

二叉树的特殊类型（对二叉树的编号是从上到下从左到右 根节点为1开始编号）
满二叉树:在深度内所有的结点都是满的
完全二叉树:编号的位置一一对应的树（只可能在最高层的右边缺少结点）[特点是1.叶子结点只可能出现在最高两层2.对于任意结点，如果他右分支子孙的最大层次为l，则其左分支子孙最大层次必定为l或者l+1]

二叉树的性质

1.二叉树的第i层最多有2^(i-1)个结点 (i=1时候成立，则i+1层最多有2*i个数字，所以成立)
2.二叉树i层一共最多有2^i-1个结点  用求和公式求第一个性质可以得到
3.对一个二叉树 如果他叶子结点有a个，度为2的结点有c个 则 a=c+1

总共的结点为a+b+c个
而除了根节点的都必定有个前驱，所以
结点数=各个结点的度+1 即 (a+b+c=b+2c+1) 化简得到
a=c+1

4.具有n个结点的(完全二叉树)最大深度为[log(2)n]+1 可以根据2和完全二叉树定义求得
☆5.编号的性质：
1??如果i=1，则i是根，没有双亲；如果i>1，则其双亲结点为[i/2] 其左孩子结点为2i 其右孩子结点为2i+1
2??如果2i>n，则i如果左孩子结点不是2i就是叶子结点
3??如果2i+1>n，则i如果右孩子结点不是2i+1就是叶子结点

*/

#include<stdio.h>
