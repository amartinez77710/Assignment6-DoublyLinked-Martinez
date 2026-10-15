#include <iostream>
#include <cmath>
#include <random>
#include "coordinate.h"
void add_coordinate(Coordinate *list_end, float x, float y);
//void forward_display(Coordinate *list_beginning);
//void backward_display(Coordinate *list_end);
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

	//Allocating Coordinate nodes
	for(int i = 1; i <= input; i++){
		Coordinate *node = new Coordinate;
		node->x = dist(gen);   //Number generator. Range -50 to 50
		node->y = dist(gen);
		node->coord_id = i;
		node->next = nullptr;
		node->previous = nullptr;
		if(head == nullptr)
			node = head;

	}

	return 0;
}





