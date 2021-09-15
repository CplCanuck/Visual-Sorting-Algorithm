#include <SFML/Graphics.hpp>

int main()
{
    /**Window**/
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML works!");
    window.setFramerateLimit(144);



    /**Macro Variables**/
    float screenWidth = window.getSize().x;
    float screenHeight = window.getSize().y;



    /**Game Objects**/
    //bars
    int numOfBars = 100;
    float barWidths = screenWidth/numOfBars;
    float barHeightMultiplier = screenHeight/numOfBars;
    
    //declare bars[]
    sf::RectangleShape bars[numOfBars];

    //defining bars[]
    for(int i = 0; i < numOfBars; i++){
        bars[i].setFillColor(sf::Color::White);
        bars[i].setSize(sf::Vector2f(barWidths, (i + 1) * barHeightMultiplier));
        bars[i].setPosition(sf::Vector2f(i * barWidths, screenHeight - ((i + 1) * barHeightMultiplier)));
    }



    /**Program**/
    while (window.isOpen())
    {
        //Event polling
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch(ev.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
            }
        }

        //Update

        //Render
        window.clear();

        for(int i = 0; i < numOfBars; i++){
            window.draw(bars[i]);
        }

        window.display();
    }

    return 0;
}