#include "pch.h"
#include "Key_Peg.h"


Key_Peg::Key_Peg(){	 
}


Key_Peg::~Key_Peg(){
}

void Key_Peg::pushBackKey(std::vector<char> pin_colors) {
	
	std::vector<char>::iterator eit = pin_colors.end() - 4;
	bool matchs[4] = { false, false, false, false };

	for (int i = 0; i < 4; i++) {
		if (pin_colors.at(i) == *eit) {
			key_pin_colors.push_back('K');
			key_pin_x_coordinates.push_back(x_coor);
			key_pin_y_coordinates.push_back(y_coor);
			x_coor += 20;
			matchs[i] = true;
		}
		eit++;
	}

	eit = pin_colors.end() - 4;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matchs[i]) {
				break;
			}
			else if (pin_colors.at(i) == *eit) {
				key_pin_colors.push_back('W');
				key_pin_x_coordinates.push_back(x_coor);
				key_pin_y_coordinates.push_back(y_coor);
				x_coor += 20;
				matchs[i] = true;
			}
			eit++;
		}
		eit = pin_colors.end() - 4;
	}

	for (int i = 0; i < 4; i++) {
		if (matchs[i] == false) {
			key_pin_colors.push_back('N');
			key_pin_x_coordinates.push_back(0);
			key_pin_y_coordinates.push_back(0);

		}
	}
}