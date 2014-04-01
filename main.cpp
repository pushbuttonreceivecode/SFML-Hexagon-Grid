#include <SFML/Graphics.hpp>
#include <hexgrid.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600,32), "Hexgrid Example", sf::Style::Default);

    nasic::hexgrid grid(window, nasic::hexgrid::hexStyle::translucent);
    sf::Event e;
    bool running = true;
    while(running)
    {
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
            window.clear();
            window.draw(grid);
            window.display();
    }
    return 0;
}
