#pragma once

#include <stack>
#include <assert.h>

template<typename T> 
class StackWithMin
{
public:
    StackWithMin(){}
    ~StackWithMin(){}


    void pop();
    void push(T data);
    T min()const;

private:
    std::stack<T> Data;
    std::stack<T> Min;
};




template<typename T> 
void StackWithMin<T>::pop()
{
    assert(Data.size() > 0 && Min.size() > 0);
    Data.pop();
    Min.pop();
}



template<typename T> 
void StackWithMin<T>::push(T data)
{
    if(Data.size()==0 && Min.size()==0)
    {
	Data.push(data);
	Min.push(data);
    }
    else
    {
	Data.push(data);
	if(data < Min.top())
	{
	    Min.push(data);
	}
	else
	{
	    Min.push(Min.top());
	}
    }
}



template<typename T> 
T StackWithMin<T>::min()const
{
    return Min.top();
}





























// template<typename T>
// class StackWithMin
// {
// public:
//     StackWithMin(){}
//     ~StackWithMin(){}


//     T& Top();
//     const T& top() const;

//     void push(const T& value);
//     void pop();

//     const T& min() const;

//     bool empty() const;
//     int size() const;


// private:
//     std::stack<T> m_data;
//     std::stack<T> m_min;
// };


// template<typename T>
// void StackWithMin<T>::push(const T& value)
// {
//     m_data.push(value);
//     if(m_min.size() == 0 || value < m_min.top())
//         m_min.push(value);
//     else
//         m_min.push(m_min.top());
// }


// template <typename T>
// void StackWithMin<T>::pop()
// {
//     assert(m_data.size() > 0 && m_min.size() > 0);
//     m_data.pop();
//     m_min.pop();
// }



// template <typename T>
// const T& StackWithMin<T>::min() const
// {
//     assert(m_data.size() > 0 && m_min.size() > 0);
//     return m_min.top();
// }




// template <typename T>
// T& StackWithMin<T>::Top()
// {
//     return m_data.top();
// }



// template <typename T>
// const T& StackWithMin<T>::top() const
// {
//     return m_data.top();
// }



// template <typename T>
// bool StackWithMin<T>::empty() const
// {
//     return m_data.empty();
// }



// template <typename T>
// int StackWithMin<T>::size() const
// {
//     return m_data.size();
// }
