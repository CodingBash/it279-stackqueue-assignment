
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

//This is the varible that willl be updated every time the user enters in a command
int curResult = 0;

//Stack used to keep track of all the input and the results of the input
StackNS::Stack stack = StackNS::Stack();

//Simple operations included here to avoid clutter in main method.
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
	
	//The stack starts with these values. It also does not allow the user to use undo on this node
	stack.push(createStackData(0,0,'T'));
	
	//stack that is used to keep track of the nodes that have been popped by undp
	StackNS::Stack undoDataStack = StackNS::Stack();
	
	//Node data to keep track of the node poped off during undo operations
	StackNS::NodeStackData undoData;
	
	cout << curResult;
	
	
	//Keeps track of the number of undo operations in a row.
	//If something other than an undo or redo is entered, the int is reset
	int numRedo = 0;
	bool isRedo = false;
	
	while(true)
	{	
	
		cout << "\n<";
		
		char inputChar;
		cin >> inputChar;
		
		//this checks to see if a redo operation is a possibility
		if(inputChar != 'R' && inputChar != 'U')
		{
			numRedo = 0;
			isRedo = false;
		}
		
		int numIn;
		
		//Quit functionality
		if(inputChar == 'Q')
		{
			cout << "\nGoodbye\n";
			exit(0);
		}
		
		//Redo functionality
		if(inputChar == 'R')
		{
			//if there havent been any Undo operations, there cant't be any redos.
			if(numRedo == 0)
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
				numRedo--;
				isRedo = true;
			}
		}
		
		//Clear functionality
		if(inputChar == 'C')
		{
			stack.push(createStackData(0,curResult,inputChar));
			curResult = 0;
			cout << curResult;
			continue;
		}
		
		//Undo functionality
		if(inputChar == 'U')
		{	//Can not Undo the initial node
			if(stack.top().character == 'T')
			{
				cout << "There is no operation to undo" << endl;
				cout << curResult;
				continue;
			}
			//Pop the node, revert to previous total, store node in case of undo
			undoData = stack.pop();
			undoDataStack.push(undoData);
			curResult = undoData.integer_two;
			numRedo++;
			cout << curResult;
			continue;
		}
		
		//If it is not a Redo, there should be an int input from the user if the code reaches this point
		if(isRedo == false)
		{
			cin >> numIn;
		}
		
		//Switch case depending on the operation that is sent in by the user
		switch (inputChar)
		{
			case '+':
				stack.push(createStackData(numIn,curResult,inputChar));
				add(numIn);
				cout << curResult;
				break;
			case '-':
				stack.push(createStackData(numIn,curResult,inputChar));
				subtract(numIn);
				cout << curResult;
				break;
				
				
			case '*':
				stack.push(createStackData(numIn,curResult,inputChar));
				multiply(numIn);
				cout << curResult;
				break;
			case '/':
				if((abs(curResult) > abs(numIn)))
				{
					stack.push(createStackData(numIn,curResult,inputChar));
					divide(numIn);
					cout << curResult;	
				}
				else
				{	//Check to make sure that the operation is doable
					cout << "This opertion can not be completed" << endl;
					cout << curResult;
				}
				break;
			case '%':
				stack.push(createStackData(numIn,curResult,inputChar));
				divide(numIn);
				cout << curResult;
				break;
			default:
				cout << "Invalid command entered";
				break;
			
		}
	
	}
	
	
	return 0;
}






