#include "../library/lib.h"
#include "menu.h"
using namespace sf;
RenderWindow window(VideoMode(800, 500), "NIM-Game");

int main()
{
    int x, y;
    Vector2i mousexy;
    srand(time(NULL));

    Image backIM;
    backIM.loadFromFile("../src/images/wood.png");
    Texture backTX;
    backTX.loadFromImage(backIM);
    Sprite backSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);

    Image icon;
    if(!icon.loadFromFile("../src/images/icon.png")){
        return 1;
    }

    Font font;
    font.loadFromFile("../src/font/16872.ttf");
    Text text, t1, t2, t3, t4;
    text.setFont(font);

    t1.setFont(font);
    t2.setFont(font);
    t3.setFont(font);
    t4.setFont(font);

    text.setString(L"Играть");
    t1.setString(L"НИМ");
    t2.setString(L"Рекорды");
    t3.setString(L"Правила");
    t4.setString(L"Выход");

    text.setCharacterSize(60);
    t1.setCharacterSize(100);
    t2.setCharacterSize(60);
    t3.setCharacterSize(60);
    t4.setCharacterSize(60);

    text.setFillColor(Color::White);
    t1.setFillColor(Color::White);
    t2.setFillColor(Color::White);
    t3.setFillColor(Color::White);
    t4.setFillColor(Color::White);    

    text.setPosition(250, 180);
    t1.setPosition(250, 20);
    t2.setPosition(250, 260);
    t3.setPosition(250, 340);
    t4.setPosition(250, 420);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
		
    		t1.setFillColor(Color::White);
   	 	t2.setFillColor(Color::White);
    		t3.setFillColor(Color::White);
    		t4.setFillColor(Color::White); 

                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 255 && x < 463 && y > 198 && y < 242) {
                    t1.setFillColor(Color::Green);
		    difficulty();
                    break;
                }
                if (x > 252 && x < 487 && y > 277 && y < 330) {
                    t2.setFillColor(Color::Green);
		    recordsmenu();
                    break;
                }
                if (x > 254 && x < 474 && y > 353 && y < 410) {
                    t3.setFillColor(Color::Green);
		    manual();
                    break;
                }
                if (x > 249 && x < 424 && y > 437 && y < 484) {
                    t4.setFillColor(Color::Green);
		    window.close();
                }
            }
        }
	
	window.setIcon(62, 55, icon.getPixelsPtr());
        window.clear();
        window.draw(backSP);
        window.draw(text);
        window.draw(t1);
        window.draw(t2);
        window.draw(t3);
        window.draw(t4);
        window.display();
    }
    return 0;
}
