#include "pch.h"
#include "Guess_Peg.h"
#include <SFML/Graphics.hpp>

bool gameNotWon(Key_Peg kp) {
	bool answer = true; 
	int black_counter = 0; 
	if (kp.key_pin_colors.size() >= 4) {
		int index = kp.key_pin_colors.size() - 1;
		for (int i = 0; i < 4; i++) { 
			if (kp.key_pin_colors.at(index) == 'K') {
				black_counter++;
			}
			index--;
		}
		if (black_counter == 4) {
			answer = false;
		}
	}
	
	return answer; 
}

int main(){ 
		
	bool displayOnce = true; 
	bool displaySecretCode = false; 
	int num_vertBox = 40, num_horzBox = 20;
	float size = 20;
	float w = size * num_horzBox;  
	float h = size * num_vertBox;  
	int game_counter = 0; 
	int counter = 0;

	Guess_Peg gp = Guess_Peg(); 
	Key_Peg kp = Key_Peg(); 

	gp.makeCode(kp);
	
	sf::RenderWindow window(sf::VideoMode(w, h), "Mastermind");

	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;
	t1.loadFromFile("images/yellow.png");
	t2.loadFromFile("images/teal.png");
	t3.loadFromFile("images/red.png");
	t4.loadFromFile("images/purple.png");
	t5.loadFromFile("images/orange.png");
	t6.loadFromFile("images/blue.png");
	t7.loadFromFile("images/brown.png");
	t8.loadFromFile("images/black.png");
	t9.loadFromFile("images/white.png");

	sf::Sprite yellow(t1);
	sf::Sprite teal(t2);
	sf::Sprite red(t3);
	sf::Sprite purple(t4);
	sf::Sprite orange(t5);
	sf::Sprite blue(t6);
	sf::Sprite brown(t7);
	sf::Sprite black(t8);
	sf::Sprite white(t9);
	

	while (window.isOpen()){
		
		sf::Event e;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();   

		for (int i = 0; i < num_horzBox; i++)
		{
			for (int j = 0; j < num_vertBox; j++)
			{
				brown.setPosition(i*size, j*size);
				window.draw(brown);
			}
		}

		float x = 0; 
		float y = 0; 

		for (float i = 0; i < gp.pin_colors.size(); i++) {
			if (i < 4 && !displaySecretCode) {
				continue; 
			}
			x = gp.pin_x_coordinates.at(i);
			y = gp.pin_y_coordinates.at(i);
			switch (gp.pin_colors.at(i)) {
			case 'Y':
				yellow.setPosition(x, y); 
				window.draw(yellow); 
				break;
			case 'T':
				teal.setPosition(x, y);
				window.draw(teal);
				break;
			case 'R':
				red.setPosition(x, y);
				window.draw(red);
				break;
			case 'P':
				purple.setPosition(x, y);
				window.draw(purple);
				break;
			case 'O':
				orange.setPosition(x, y);
				window.draw(orange);
				break;
			case 'B':
				blue.setPosition(x, y);
				window.draw(blue);
				break;
			case 'K':
				black.setPosition(x, y);
				window.draw(black);
				break;
			}
		}

		for (float i = 0; i < kp.key_pin_colors.size(); i++) {
			x = kp.key_pin_x_coordinates.at(i);
			y = kp.key_pin_y_coordinates.at(i);
			switch (kp.key_pin_colors.at(i)) {
			case 'W':
				white.setPosition(x, y);
				window.draw(white);
				break;
			case 'K':
				black.setPosition(x, y);
				window.draw(black);
				break;
			}
		}

		yellow.setPosition(30, 30);
		window.draw(yellow);
		teal.setPosition(50, 30);
		window.draw(teal);
		red.setPosition(70, 30);
		window.draw(red);
		purple.setPosition(90, 30);
		window.draw(purple);
		orange.setPosition(110, 30);
		window.draw(orange);
		blue.setPosition(130, 30);
		window.draw(blue);

		window.display();
		
		if (game_counter < 10 && gameNotWon(kp)) {
			game_counter = gp.pushBackCode(game_counter, kp);
		}else if (game_counter == 10 && displayOnce) {
			std::cout << "You ran out of guesses.";
			displayOnce = false; 
			displaySecretCode = true;
		}else if(!gameNotWon(kp) &&  displayOnce){
			std::cout << "That is the code, you win";
			displayOnce = false;
			displaySecretCode = true;
		}
	}
	return 0;
}