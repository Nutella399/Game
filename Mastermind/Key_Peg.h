#pragma once
#include <vector>
#include <iostream>

class Key_Peg{

private: 
	float x_coor = 180;
	float x_coor_const = 180;
	float y_coor = 520;

public:
	Key_Peg();
	~Key_Peg();
	void pushBackKey(std::vector<char> pin_colors); 

	//FIX THIS
	std::vector<char> key_pin_colors;
	std::vector<float> key_pin_x_coordinates;
	std::vector<float> key_pin_y_coordinates;

	friend class Guess_Peg; 
};

