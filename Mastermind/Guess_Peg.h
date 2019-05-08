#pragma once
#include <iostream>
#include "Key_Peg.h"

class Guess_Peg{
private: 
	float secret_y_coor = 120; 

public:
	Guess_Peg();
	~Guess_Peg();

	int pushBackCode(int game_counter, Key_Peg &kp);
	void makeCode(Key_Peg &kp);

	//FIX THIS
	std::vector<char> pin_colors;
	std::vector<float> pin_x_coordinates;
	std::vector<float> pin_y_coordinates;
};

