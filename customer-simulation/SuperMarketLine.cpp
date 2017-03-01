#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <queue>
using namespace std;



int stringToInt(string);
int determineArrivalTime(int,int);
int serviceTime(int);
void arrivalMessage(int,int);
void departureMessage(int,int);

int main(){
	int dayLength =60;
	int maxWait = 0;
	int maxLine = 0;
	int currentTime = 0;
	int customerIntervals = 0;
	queue<int> customerLine;// queue for customers
	
	while(customerIntervals<1)
	{
		string sequence;
		cout<< "Enter Maximum difference in Customer Arrival: ";
		cin >> sequence;
		customerIntervals = stringToInt(sequence);
		if(customerIntervals>=1 && customerIntervals <=dayLength);
		else if(customerIntervals <1)
			cout << "Customers must arrive at least 1 minute apart. Try again\n";
		else if(customerIntervals >dayLength)
		{
			cout << "Interval Range for Customers is too large. Try again\n";
			customerIntervals = 0;
		}
	}
	customerIntervals = customerIntervals -1;
	int customerNumber=1;
	int arrivalTime = determineArrivalTime(currentTime,customerIntervals);
	int serviceTimeValue = -1;
	int currentCustomer = customerNumber;
	int savedWaitTime=-1;
	int savedCustomer=-1;
	while(currentTime<=dayLength)
	{
		
		if(currentTime ==arrivalTime)
		{
			arrivalTime = determineArrivalTime(currentTime, customerIntervals);
			arrivalMessage(customerNumber,currentTime);
			if(customerLine.empty())
			{
				serviceTimeValue = currentTime + serviceTime(customerIntervals);
				customerLine.push(customerNumber);
				currentCustomer= customerLine.front(); //No line so Customer Service begins
				savedCustomer = -1;//Reset saved values
				savedWaitTime = -1;
			}
			else
			{
				customerLine.push(customerNumber); //Customer added to line
				if(savedCustomer==-1)
				{
					savedCustomer = customerNumber;
					savedWaitTime = 0;
				}
				
			}
			customerNumber++;
			if((customerLine.size()-1) >maxLine)
			{
				maxLine = customerLine.size() -1;
			}
			//cout<<maxLine<<"\t";	//for debugging
		}
		
		if(currentTime == serviceTimeValue)
		{
			departureMessage(currentCustomer,currentTime);
			if(customerLine.size() != 1)
			{
				serviceTimeValue = currentTime + serviceTime(customerIntervals);
			}
			else
				serviceTimeValue = -1;
			customerLine.pop();
			currentCustomer = customerLine.front();
			if(currentCustomer == savedCustomer)
			{
				if(savedWaitTime> maxWait)
					maxWait = savedWaitTime;
				savedWaitTime = -1; //reset values
				savedCustomer =-1;
			}
			
		}
		//cout << savedWaitTime <<"\t"<<maxLine <<"\t"<<serviceTimeValue <<"\t" <<currentTime;		
		//cout<<"\n";       //used during debugging
		currentTime++;
		if(savedWaitTime != -1)
			savedWaitTime++;
		
	}	
	

	cout<< "Max Line Size was "<<maxLine <<" Customer";
	if(maxLine !=1)
		cout<<"s";
	cout<< " long\n";
	cout<< "Max Wait Time was "<<maxWait<< " minute";
	if(maxWait !=1)
		cout<<"s";
	cout<<" long\n\n";
	
	return 0;
}

int stringToInt(string sequence)
{
 int returnable=0;
 for(int i = 0; i<sequence.size();++i)
    {
	if(sequence.size()!=0)
	{
		stringstream convert(sequence);
		if( !(convert >> returnable))
			returnable =0;
	}
    }
 return returnable;
}


int serviceTime(int customerIntervals)
{
	return (rand() % customerIntervals) +1;
}

int determineArrivalTime(int currentTime, int customerIntervals)
{
	return currentTime + serviceTime(customerIntervals);
}

void arrivalMessage(int customerNumber,int customerTime)
{
	cout <<"Customer "<<customerNumber <<" arrived at "<< customerTime <<"\n";
}

void departureMessage(int customerNumber, int customerTime)
{
	cout <<"Customer "<<customerNumber <<" left at "<< customerTime <<"\n";
}
