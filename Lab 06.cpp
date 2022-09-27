#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	string background = "images1/backgrounds/prague.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {

			//creates the reference green color that we will be getting rid of 
			Color GreenRef(32, 214 , 23, 255);

			//gets the pixel color from the foreground and background
			Color Yoda = foregroundImage.getPixel(x, y);
			Color Prague = backgroundImage.getPixel(x, y);

			//if statement that checks if the pixel from foreground is equal to the ref green color
			if (Yoda == GreenRef) {
				//if yes, it replaces the pixel color with the background pixle color 
				foregroundImage.setPixel(x, y, Prague);
			}
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}