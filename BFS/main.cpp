/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-12 20:56
#   Describe      : 广度优先算法, 入口->出口最短路径

    0 0 1 0
    0 0 0 0
    0 0 1 0
    0 1 0 0 
    0 0 0 1

0: 可走， 1: 障碍物  入口: (0,0)   出口: (3,2) , 答案: 7



总结：步骤 
1. 
2. 
3. 
4.
# ====================================================*/



#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


int dir[4][2] = {
		  {0,1}, // 
		  {1,0}, // 
		  {0,-1},// 
		  {-1,0} // 
		 };


struct node 
{
    int x; 
    int y;
    int step;
};


int BFS(int* map, int* book, int rows, int cols, vector<node>& array, int end_x, int end_y)
{

    int step = 0;
    int index = 0;

    // 遍历
    while(index != array.size())
    {
	node tmp;
	for(int i=0; i<4; i++)
	{
	    tmp.x = (array[index]).x + dir[i][0];
	    tmp.y = (array[index]).y + dir[i][1];
	    tmp.step = 1 + array[index].step;


	    if(tmp.x == end_x && tmp.y == end_y)
		return tmp.step;
	    
	    if(tmp.x>=0 && tmp.y>=0 && tmp.x < rows && tmp.y < cols && *(map+tmp.x*cols+tmp.y) == 0)
	    {
		if(*(book+tmp.x*cols+tmp.y) == 0 )
		{
		    array.push_back(tmp);
		    *(book+tmp.x*cols+tmp.y) = 1;
		}
	    }
	}

	index++;
    }

    return -1;
}


int main(void)
{
    vector<node> array;
    int ROW = 5;
    int COL = 4;
    int map[ROW][COL] = {{0,0,1,0},{0,0,0,0},{0,0,1,0},{0,1,0,0},{0,0,0,1}}; // 地图
    int book[ROW][COL];
    memset(book, 0, sizeof(book));

    // 1. 初始化   
    node start;
    start.x = 0;
    start.y = 0;
    start.step = 0;
    array.push_back(start);
    book[start.x][start.y] = 1;
    
    int result = BFS(*map, *book, ROW, COL, array, 3, 2);
    if(result == 7)
	cout << "pass" << endl;
    else
	cout << "failed" << endl;

    return 0;
}


