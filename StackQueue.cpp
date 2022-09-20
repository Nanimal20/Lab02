// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;




//ArrayBasedStack Implementations
int ArrayBasedStack::peek() const{
	if (this->isEmpty())
	{
		throw "ADT is empty";
	}
	else
	{
		return stack_values[stack_count - 1];
	}
}

bool ArrayBasedStack::isEmpty() const{

	return (stack_count == 0);
}

bool ArrayBasedStack::push(const int & val){
	
	if (stack_count >= stack_size){
		return false;
	}
	stack_values[stack_count] = val;
	stack_count = stack_count + 1;
	return true;
}

bool ArrayBasedStack::pop(){
	
	if(stack_count == 0){
		return false;
	}
	stack_values[stack_count] = 0;
	stack_count = stack_count - 1;
	return true;
}

string ArrayBasedStack::toString()const{
	std::string str = "";
	for (int i = 0; i < stack_count; i++){
		str = str + std::to_string(stack_values[i]);
		if (i != stack_count - 1){
			str = str +" ";
		}
	}
	return str;
}

int * ArrayBasedStack::getArray() const {
	
	return stack_values;
} 

int ArrayBasedStack::getCount() const{
	
	return stack_count;
}
ArrayBasedStack::ArrayBasedStack(){

	int size = 1000;
	stack_size = size;
	stack_values = new int[size];
	stack_count = 0;
}
ArrayBasedStack::~ArrayBasedStack(){

	stack_values = NULL;
	delete stack_values;
}





//ArrayBasedQueue Implementations
string ArrayBasedQueue::peekFront() const{
	if (this->isEmpty())
	{
		throw "ADT is empty";
	}
	else
	{
		return queue_values[0];
	}
}

bool ArrayBasedQueue::isEmpty() const{
	
	return (queue_count ==0);
}

bool ArrayBasedQueue::enQueue(const std::string &val){
	
	if (queue_count == queue_size){
		return false;
	}
	queue_values[queue_count++] = val;
	return true;
}

bool ArrayBasedQueue::deQueue(){
	if (queue_count == 0){
		return false;
	}
	for (int i = 0; i < queue_count - 1; i++){
		queue_values[i] = queue_values[i + 1];
	}
	for (int i = queue_count; i < queue_size; i++){
		queue_values[i] = "";
	}
	queue_count--;
	return true;
}

string ArrayBasedQueue::toString()const{
	std::string str = "";
	for (int i = 0; i < queue_count; i++){
		str += queue_values[i];
		if (i != queue_count - 1){
			str += " ";
		}
	}
	return str;
}

ArrayBasedQueue::ArrayBasedQueue(){
	
	int size = 1000;
	queue_size = size;
	queue_values = new std::string[size];
	queue_count = 0;
}

ArrayBasedQueue::~ArrayBasedQueue(){
	
	queue_values = NULL;
	delete queue_values;
}

std::string * ArrayBasedQueue::getArray() const{
	return queue_values;
}

int ArrayBasedQueue::getCount() const{
	return queue_count;
}


