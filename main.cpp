#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

int main()
{
    /**Window**/
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Bubble Sort");
    window.setFramerateLimit(144);



    /**Game Objects**/
    //variables
    float screenWidth = window.getSize().x;
    float screenHeight = window.getSize().y;

    unsigned seed = time(NULL); //initialize the random seed
    auto rng = std::default_random_engine(seed);

    int maxSwaps = 3000;
    int swaps = 0;
    int current = 0;
    bool isSolved = false;

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

        //Update and Render
        if(current < bars.size() - 1 && swaps < maxSwaps){
            for(int j = current+1; j < bars.size(); j++){
                if(bars[current].getSize().y > bars[j].getSize().y){
                    //Swap
                     std::iter_swap(bars.begin()+current, bars.begin()+j);

                    //Render
                    window.clear();

                    for(int i = 0; i < numOfBars; i++){
                        bars[i].setPosition(sf::Vector2f(i * barWidths, screenHeight - bars[i].getSize().y));
                        window.draw(bars[i]);
                    }

                    window.display();
                    
                    swaps++;
                }
            }
            bars[current].setFillColor(sf::Color::Green);
            if(current == bars.size() - 3){
                bars[current + 1].setFillColor(sf::Color::Green);
                bars[current + 2].setFillColor(sf::Color::Green);
            }
            current++;
        }
    }

    return 0;
}