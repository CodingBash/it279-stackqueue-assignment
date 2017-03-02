#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Queue.h"
using namespace std;
using namespace QueueNS;



int stringToInt(string);
int determineArrivalTime(int,int);
int serviceTime(int);
void arrivalMessage(int,int);
void departureMessage(int,int);
int determineMaxWaitTime(int,int,int);

int main(){
	int dayLength =720;
	int maxWait = 0;
	int maxLine = 0;
	int currentTime = 0;
	int customerIntervals = 0;
	Queue queue = Queue();// queue for customers
	auto createQueueData =[](int customerNumber, int arrivalTime) -> NodeQueueData {
		NodeQueueData data = NodeQueueData();
		data.customerNumber = customerNumber;
		data.arrivalTime = arrivalTime;
		return data;
	};
	
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
	while(currentTime<=dayLength)
	{
		
		if(currentTime ==arrivalTime)
		{
			arrivalTime = determineArrivalTime(currentTime, customerIntervals);
			arrivalMessage(customerNumber,currentTime);
			if(queue.size() == 0)
			{
				serviceTimeValue = currentTime + serviceTime(customerIntervals);
				queue.queue(createQueueData(customerNumber,currentTime));
			}
			else
			{

				queue.queue(createQueueData(customerNumber,currentTime)); //Customer added to line				
			}
			customerNumber++;
			if((queue.size()-1) >maxLine)
			{
				maxLine = queue.size() -1;
			}
			//cout<<maxLine<<"\t";	//for debugging
		}
		
		if(currentTime == serviceTimeValue)
		{
			NodeQueueData temp = queue.dequeue();
			departureMessage(temp.customerNumber,currentTime);
			if(queue.size() != 0)
			{
				serviceTimeValue = currentTime + serviceTime(customerIntervals);
				maxWait = determineMaxWaitTime(temp.arrivalTime,currentTime,maxWait);
			}
			else
				serviceTimeValue = -1;
		}
		//cout <<"\t"<<maxLine <<"\t"<<serviceTimeValue <<"\t" <<currentTime;		
		//cout<<"\n";       //used during debugging		
		currentTime++;
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

int determineMaxWaitTime(int customerArrival, int customerServiceTime, int maxWait)
{
	if((customerServiceTime - customerArrival)>maxWait)
		maxWait= customerServiceTime - customerArrival;
	return maxWait;
}
