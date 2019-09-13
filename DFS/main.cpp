/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-12 20:14
#   Describe      : 深度优先算法, 解决数字全排列的问题
#
# ====================================================*/

#include <iostream>
using namespace std;



int number = 4; // 1-4 的扑克全排列
int a[4], book[4];





// 做标记==的步骤 都是套路，记住, 标**号的是容易出错的地方
void DFS(int step)
{
    if(step == 4) // =======================边界，说明1-4都已经排好
    {
	for(int i=0; i<number; i++)
	{
	    cout << a[i] << " " ;
	}
	cout << endl;
	return; //************************************
    }

    //=================== 尝试每种可能
    for(int i=1; i<=number; i++)    // 此时站在 step 的盒子面前， 应该放哪张， 按照1.2.3顺序一一尝试 
    {
	if(book[i] == 0) // 证明 i 扑克牌还能用
	{
	    a[step] = i; //将 i 扑克放入第step的盒子里
	    book[i] = 1; // 标志 i 已经用了


	    // 第step 个放好了， 接下来 第step+1
	    DFS(step+1); // ===============================进行下一步
	    book[i] = 0; // 一定将扑克收回才能进行下一次尝试 // **********************************收回
	}
    }

    return;
}







int main(void)
{
    DFS(0);


    return 0;
}

