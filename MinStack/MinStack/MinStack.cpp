// MinStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>                                       // For standard streams
#include <stack>                                          // For stack<T> container
#include <algorithm>                                      // For remove()
#include <stdexcept>                                      // For runtime_error exception
#include <string>  

class MinStack {
public:
	std::stack<int> data;
	std::stack<int> minSt;

    MinStack() {
        // do intialization if necessary
		
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
		if(minSt.empty() == true)
		{
			data.push(number);
			minSt.push(number);
		}
		else
		{
			if(number<= minSt.top())
			{
				data.push(number);
				minSt.push(number);
			}
			else
			{
				data.push(number);
			}
		}
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
		int temp;
		temp = data.top();
		if(temp == minSt.top())
		{
			data.pop();
			minSt.pop();
		}
		else
		{
			data.pop();
		}
		return temp;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
		return minSt.top();
    }
};


 int _tmain(int argc, _TCHAR* argv[])
{
	MinStack mystack;
	mystack.push(1);
	mystack.pop();
	mystack.push(2);
	mystack.push(3);
	mystack.min();
	return 0;
}





