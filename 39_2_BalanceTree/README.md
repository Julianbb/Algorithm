### 题目:<br>
求是否是平衡二叉树(二叉树的任意一个结点的左右子书的深度相差不超过１)<br>


### 解法：<br>
采用后序遍历，每遍历一个节点的时候,我们已经遍历了它的左右子树。遍历每个结点的时候记录它的深度(某一节点的深度等于它到叶子节点的路径长度),这样我们就可以一遍遍历，一边判断每个结点是不是平衡的。