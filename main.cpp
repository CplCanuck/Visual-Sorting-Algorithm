#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

int main()
{
    /**Window**/
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML works!");
    window.setFramerateLimit(144);



    /**Macro Variables**/
    float screenWidth = window.getSize().x;
    float screenHeight = window.getSize().y;

    unsigned seed = time(NULL); //initialize the random seed
    auto rng = std::default_random_engine(seed);



    /**Game Objects**/
    //bars
    int numOfBars = 100;
    float barWidths = screenWidth/numOfBars;
    float barHeightMultiplier = screenHeight/numOfBars;
    
    //declare bars[]
    std::vector<sf::RectangleShape> bars;

    //defining bars[]
    for(int i = 0; i < numOfBars; i++){
        sf::RectangleShape tempBar(sf::Vector2f(barWidths, (i + 1) * barHeightMultiplier));
        bars.push_back(tempBar);
    }

    //randomize into bars[]
    std::shuffle(bars.begin(), bars.end(), rng);

    for(int i = 0; i < bars.size(); i++){
        bars[i].setPosition(sf::Vector2f(i * barWidths, screenHeight - bars[i].getSize().y));
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