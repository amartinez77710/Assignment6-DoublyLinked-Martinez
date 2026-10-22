#include <iostream>
#include <cmath>
#include <random>
#include "coordinate.h"

//Changing parameter to reference of list_end
//I cannot change the tail if we are only using a local one
void add_coordinate(Coordinate *&list_end, float x, float y){
//Function to add a node to an existing linked list
//But we cant add a node to a nonexistant list
	if(list_end == nullptr){
		std::cout << "Error, no list to add to" << std::endl;
		return;
	}
	Coordinate *newnode = new Coordinate;
	newnode->x = x;
	newnode->y = y;
	newnode->coord_id = list_end->coord_id + 1;
	newnode->next = nullptr;
	newnode->previous = list_end;
	list_end->next = newnode;
	list_end = newnode; //This wouldnt be possible without reference

}

	 
void forward_display(Coordinate *list_beginning){
//We will use a temporary node to traverse each node and print their coordinates
	std::cout << "\n\nForward Traversal" << std::endl;
	Coordinate *temporary = new Coordinate;
	temporary = list_beginning;
	int counter = 1;
	while(temporary != nullptr){
		std::cout << "Node: " << counter << std::endl;
		std::cout << "Coordinates: (" << temporary->x << ", " << temporary->y << ")" << std::endl;
		std::cout << "____________" << std::endl;
		temporary = temporary->next; //Points to the next node
		counter++;
	}
	delete temporary;
}




void backward_display(Coordinate *list_end){
//We will use a temporary node to traverse each node and print their coordinates
	std::cout << "\n\nBackward Traversal" << std::endl;
        Coordinate *temporary = list_end;
        int counter = temporary->coord_id;
        while(temporary != nullptr){
                std::cout << "Node: " << counter << std::endl;
                std::cout << "Coordinates: (" << temporary->x << ", " << temporary->y << ")" << std::endl;
                std::cout << "____________" << std::endl;
                temporary = temporary->previous; //Points to the next node
                counter--;
        }
}


//Another instance where i have to change parameter
//pass by reference instead
void delete_coordinate(Coordinate *&list_beginning, int coord_id_to_delete){
//We have to find the node that matches the coord id
	Coordinate *temporary = list_beginning;
	while(temporary->coord_id != coord_id_to_delete){
		temporary = temporary->next;
	}
	std::cout <<"\n---ID FOUND---\n" << "ID: " << coord_id_to_delete << std::endl;
	//now i will link the nodes behind and after the temporary
	//BUT the head and tail have special cases
	//Head Case
	if(temporary == list_beginning){
		list_beginning = temporary->next; //moving head to the next node
		list_beginning->previous = nullptr; //establishing it as the head
		delete temporary;
		return;
	}
	//Tail Case
	if(temporary->next == nullptr){
		Coordinate *behind = temporary->previous;
		behind->next = nullptr;
		delete temporary;
		return;
	}

	//Middle Case
	Coordinate *behind = temporary->previous;
	Coordinate *after = temporary->next;

	behind->next = after;
	after->previous = behind;
	delete temporary;


}


int list_length(Coordinate *list_beginning){
	Coordinate *temporary = list_beginning;
	int counter = 0;
	while(temporary != nullptr){
		temporary = temporary->next;
		counter++;
	}
	return counter;
}

void closest_to(Coordinate *list_beginning, float x, float y){
	
	//If we have no list
	if(list_beginning == nullptr){
		return;
	}
	
	
	//Finding the amount of nodes there are
	Coordinate *temporary = list_beginning;
	int counter = 0;
	while(temporary != nullptr){
		temporary = temporary->next;
		counter++;
	}
	
	//Doing distance formula, while saving values to a vector
	temporary = list_beginning;
	std::vector<float> leastDistance;
	
	for(int i = 0; i < counter; i++){
		//Distance formula
		leastDistance.push_back(std::hypot(temporary->x - x, temporary->y - y));
		temporary = temporary->next;
	}
	
	//Assigning values and finding the smallest in the vector
	//The smallest will give me the exact node
	int point = list_beginning->coord_id;
	float closest_point = leastDistance[0];
	temporary = list_beginning->next;
	for(int i = 1; i < counter; i++){
		if(closest_point > leastDistance[i]){
			closest_point = leastDistance[i];
			point = temporary->coord_id;
		}
		temporary =  temporary->next;
	}
	temporary = list_beginning;
	while(temporary != nullptr){
		if(temporary->coord_id == point){
			std::cout << "Closest to (" << x << ", " << y << ") is (" << temporary->x << ", " << temporary->y << ")" << std::endl;
			return;
		}
		temporary = temporary->next;
	}
}


		



int main(int arguments, char *argv[]){

	//Making sure arguments is not less or more than 2
    	if (arguments != 2) {
        	std::cout << "Not valid amount of arguments, only 2" << std::endl;
        	return 1;
	}
	
	int input = std::stoi(argv[1]);

	//RANDOM generator conditions
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(-50.0f, 50.0f);
	

	//Starting the doubly linked list with a head
	Coordinate *head = nullptr;
	//Ending with tail
	Coordinate *tail = nullptr;

	//Allocating Coordinate nodes and linking them
	for(int i = 1; i <= input; i++){
		Coordinate *node = new Coordinate;
		node->x = dist(gen);   //Number generator. Range -50 to 50
		node->y = dist(gen);
		node->coord_id = i;
		node->next = nullptr;
		node->previous = nullptr;
		if(head == nullptr){
			head = node;
			tail = node;
		}
		//Setting up the link
		else{
			tail->next = node;
			node->previous = tail;
			tail = node;
		}
	}
	//FORWARD PRINT
	forward_display(head);

	//BACKWARD PRINT
	backward_display(tail);

	//Add (10,10 to list)
	std::cout << "\n\n----Adding the coordinate (10,10) to end of list----" << std::endl;
	add_coordinate(tail, 10, 10);
	forward_display(head);
	
	
	//Deleting (10,10) node
	delete_coordinate(head, input + 1);
	std::cout << "\nRemoving coordinate (10,10)!" << std::endl;
	forward_display(head);


	//Length of list
	std::cout << "\nLength of Linked List: " << list_length(head) << " Nodes" << std::endl;

	//closest to (0,0)
	closest_to(head, 0, 0);	
	
	//Free memory
	Coordinate *temporary = nullptr;
	for(int i = 0; i < input; i++){
		temporary = head;
		head = head->next;
		delete temporary;
	}

		
		
	
	return 0;
}





