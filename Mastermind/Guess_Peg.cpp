#include "pch.h"
#include "Guess_Peg.h"


Guess_Peg::Guess_Peg(){
 
}


Guess_Peg::~Guess_Peg(){
}

int Guess_Peg::pushBackCode(int game_counter, Key_Peg &kp) {
	int static counter = 0; 
	if (counter >= 4) {
		kp.pushBackKey(pin_colors);
		kp.y_coor -= 40;
		kp.x_coor = kp.x_coor_const;
		counter = 0;
		game_counter++; 
	}
	else {
		char choice;
		std::cin >> choice;
		pin_x_coordinates.push_back(kp.x_coor);
		pin_y_coordinates.push_back(kp.y_coor);
		kp.x_coor += 20;
		switch (choice) {
		case 'Y':
			pin_colors.push_back('Y');
			break;
		case 'T':
			pin_colors.push_back('T');
			break;
		case 'R':
			pin_colors.push_back('R');
			break;
		case 'P':
			pin_colors.push_back('P');
			break;
		case 'O':
			pin_colors.push_back('O');
			break;
		case 'B':
			pin_colors.push_back('B');
			break;
		}
		counter++;
	}
	return game_counter;
}

void Guess_Peg::makeCode(Key_Peg &kp) {
	for (int i = 0; i < 4; i++) {
		char choice;
		std::cin >> choice;
		pin_x_coordinates.push_back(kp.x_coor);
		pin_y_coordinates.push_back(secret_y_coor);
		kp.x_coor += 20;
		switch (choice) {
		case 'Y':
			pin_colors.push_back('Y');
			break;
		case 'T':
			pin_colors.push_back('T');
			break;
		case 'R':
			pin_colors.push_back('R');
			break;
		case 'P':
			pin_colors.push_back('P');
			break;
		case 'O':
			pin_colors.push_back('O');
			break;
		case 'B':
			pin_colors.push_back('B');
			break;
		}
	}

	kp.x_coor = kp.x_coor_const;
}