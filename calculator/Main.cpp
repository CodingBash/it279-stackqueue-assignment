
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int curResult = 0;

StackNS::Stack stack = StackNS::Stack();

void add(int numIn)
{
	curResult += numIn;
}

void subtract(int numIn)
{
	curResult -= numIn;
}

void multiply(int numIn)
{
	curResult = curResult * numIn;
}

void divide(int numIn)
{
	curResult = curResult / numIn;
}

void modDiv(int numIn)
{
	curResult = curResult / numIn;
}



int main()
{
	
	//Create stack to do operations when operand and number is sent in
	
	auto createStackData = [](int one, int two, char c) -> StackNS::NodeStackData 
	{
		StackNS::NodeStackData data = StackNS::NodeStackData();
		//int one is the number sent in by the user
		data.integer_one = one;
		//int two is calc value after the previous operation
		data.integer_two = two;
		//this is the operation send in that cordinates with int one
		data.character = c;
		return data;
	};
	
	stack.push(createStackData(0,0,'T'));

	StackNS::Stack undoDataStack = StackNS::Stack();
	
	StackNS::NodeStackData undoData;
	
	cout << curResult;
	
	bool redoEnabled = false;
	
	int count = 0;
	
	while(true)
	{	
	
		cout << "\n<";
		
		char inputChar;
		cin >> inputChar;
		
		if(inputChar != 'R')
		{
			redoEnabled = false;
		}
		
		int numIn;
		
		if(inputChar == 'Q')
		{
			cout << "\nGoodbye\n";
			exit(0);
		}
		if(inputChar == 'R')
		{
			if(redoEnabled == false)
			{
				cout << "No operations to redo" << endl;
				cout << curResult;
				continue;
			}
			else
			{
				undoData = undoDataStack.pop();
				inputChar = undoData.character;
				numIn = undoData.integer_one;
			}
		}
		if(inputChar == 'C')
		{	//TODO make sure that this counts as an action when using the undo command.
			stack.push(createStackData(0,curResult,inputChar));
			curResult = 0;
			cout << curResult;
			continue;
		}
		if(inputChar == 'U')
		{
			if(stack.top().character == 'T')
			{
				cout << "There is no operation to undo" << endl;
				cout << curResult;
				continue;
			}
			undoData = stack.pop();
			undoDataStack.push(undoData);
			curResult = undoData.integer_two;
			redoEnabled = true;
			cout << curResult;
			continue;
		}
		
		if(redoEnabled == false)
		{
			cin >> numIn;
		}
		
		
		switch (inputChar)
		{
			case '+':
				stack.push(createStackData(numIn,curResult,inputChar));
				add(numIn);
				cout << curResult;
				count++;
				break;
			case '-':
				stack.push(createStackData(numIn,curResult,inputChar));
				subtract(numIn);
				cout << curResult;
				count++;
				break;
				
				
			case '*':
				stack.push(createStackData(numIn,curResult,inputChar));
				multiply(numIn);
				cout << curResult;
				count++;
				break;
			case '/':
				if((abs(curResult) > abs(numIn)))
				{
					stack.push(createStackData(numIn,curResult,inputChar));
					divide(numIn);
					cout << curResult;
					count++;	
				}
				else
				{
					cout << "This opertion can not be completed" << endl;
					cout << curResult;
				}
				break;
			case '%':
				stack.push(createStackData(numIn,curResult,inputChar));
				divide(numIn);
				cout << curResult;
				count++;
				break;
			default:
				cout << "Invalid command entered";
				break;
			
		}
	
	}
	
	
	return 0;
}






