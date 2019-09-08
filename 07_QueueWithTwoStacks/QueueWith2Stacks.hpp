#include <stack>
#include <exception>
#include <iostream>
#include <stdexcept>

using namespace std;



template <typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};


template<typename T>
CQueue<T>::CQueue(void)
{


}


template<typename T>
CQueue<T>::~CQueue(void)
{


    
}


template<typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
    if(stack2.size() > 0)
    {
	T tmp = stack2.top();
	stack2.pop();
	return tmp;
    }
    else
    {
	while(stack1.size()>0)
	{
	    T tmp = stack1.top();
	    stack2.push(tmp);
	    stack1.pop();
	}

	T tmp = stack2.top();
	stack2.pop();
	return tmp;
    }
}
	






















// template<typename T>
// void CQueue<T>::appendTail(const T& node)
// {
//     stack1.push(node);
// }



// template<typename T>
// T CQueue<T>::deleteHead()
// {

//     if(stack2.empty())
//     {
//         if(stack1.empty())
//         {
//             std::logic_error ex("queue is empty");
//             throw new exception(ex);
//         }
//         while(stack1.size())
//         {
//             T midValue = stack1.top();
//             stack2.push(midValue);
//             stack1.pop();
//         }

//     }
//         T tmp = stack2.top();
//         stack2.pop();
//         return tmp;

// }
