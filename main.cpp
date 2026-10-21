#include <iostream>
#include <cmath>
#include <random>
#include "coordinate.h"

void add_coordinate(Coordinate *list_end, float x, float y){
	Coordinate *newnode = new Coordinate;
	newnode->x = x;
	newnode->y = y;
	newnode->coord_id = list_end->coord_id + 1;
	newnode->next = list_end->next;
	newnode->previous = list_end;
	list_end = newnode;
}

	 
void forward_display(Coordinate *list_beginning){
//We will use a temporary node to traverse each node and print their coordinates
	Coordinate *temporary = new Coordinate;
	temporary = list_beginning;
	int counter = 1;
	std
	while(temporary != nullptr){
		std::cout << "Node: " << counter << std::endl;
		std::cout << "Coordinates: (" << temporary->x << ", " << temporary->y << ")" << std::endl;
		std::cout << "____________" << std::endl;
		temporary = temporary->next; //Points to the next node
		counter++;
	}
}




void backward_display(Coordinate *list_end){
//We will use a temporary node to traverse each node and print their coordinates
        Coordinate *temporary = new Coordinate;
        temporary = list_end;
        int counter = temporary->coord_id;
        while(temporary != nullptr){
                std::cout << "Node: " << counter << std::endl;
                std::cout << "Coordinates: (" << temporary->x << ", " << temporary->y << ")" << std::endl;
                std::cout << "____________" << std::endl;
                temporary = temporary->previous; //Points to the next node
                counter--;
        }
}
//void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete);
//int list_length(Coordinate *list_beginning);
//void closest_to(Coordinate *list_beginning, float x, float y);

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
	add_coordinate(tail, 10, 10);
	forward_display(head);
	backward_display(tail);	
	return 0;
}





