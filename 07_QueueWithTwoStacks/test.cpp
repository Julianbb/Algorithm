#include "QueueWith2Stacks.hpp"

	
void Test(char actual, char expected)
{
    if(actual == expected)
	cout << "Test passed" << endl;
    else
	cout << "Test failed" << endl;
}


int main(int argc, char** argv)
{
    CQueue<char> qqueue;

    qqueue.appendTail('a');
    qqueue.appendTail('b');
    qqueue.appendTail('c');

    

    char head = qqueue.deleteHead();
    Test(head, 'a');

    head = qqueue.deleteHead();
    Test(head, 'b');

    qqueue.appendTail('d');
    head = qqueue.deleteHead();
    Test(head, 'c');

    qqueue.appendTail('e');
    head = qqueue.deleteHead();
    Test(head, 'd');

    head = qqueue.deleteHead();
    Test(head, 'e');

    return 0;
}
