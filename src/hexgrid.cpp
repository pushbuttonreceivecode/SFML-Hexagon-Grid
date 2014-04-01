//////////////////////////////////////
//************************************
//Not Another Space Invaders Clone
//Author: Mark Richards
//Date: 2/1/2014
//License: zlib/png
//************************************
//////////////////////////////////////

/*
Copyright (c) 2014 Mark Richards

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/

#include <hexgrid.hpp>

nasic::hexgrid::hexgrid(sf::RenderWindow& window, sf::Uint32 style, const float& scale)
{
    m_scale = scale;

    //set up background elements
    hexagon = thor::Shapes::polygon(6, 50.f, sf::Color(255,0,0,100), 2.f, sf::Color(100,0,0,100));
    hexagon.setScale(m_scale, m_scale);
    hexagon.setOrigin(hexagon.getGlobalBounds().width/2.f, hexagon.getGlobalBounds().height/2.f);

    std::vector<sf::ConvexShape>::iterator hexit;

    m_style = style;
    m_scale = scale;

    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(i % 2 == 0)
            {
                hexagon.setPosition(i * (hexagon.getGlobalBounds().width * 0.80f), j * (hexagon.getGlobalBounds().height * 1.1f));
                if(j % 2 == 0)
                {
                    switch(m_style)
                    {
                        case hexStyle::translucent:
                        {
                            hexagon.setFillColor(sf::Color(255,255,255,100));
                        }
                        break;

                        case hexStyle::colorful:
                        {
                            hexagon.setFillColor(sf::Color(0,255,0,100));
                        }
                        break;

                        case hexStyle::green:
                        {
                            hexagon.setFillColor(sf::Color(0,255,0,100));
                        }
                        break;

                        case hexStyle::cyan:
                        {
                            hexagon.setFillColor(sf::Color(0,255,255,100));
                        }
                        break;

                        default:
                            break;
                    }
                }
                else
                {
                    switch(m_style)
                    {
                        case hexStyle::translucent:
                        {
                            hexagon.setFillColor(sf::Color(255,255,255,100));
                        }
                        break;

                        case hexStyle::colorful:
                        {
                            hexagon.setFillColor(sf::Color(0,255,255,100));
                        }
                        break;

                        case hexStyle::green:
                        {
                            hexagon.setFillColor(sf::Color(0,255,0,100));
                        }
                        break;

                        case hexStyle::cyan:
                        {
                            hexagon.setFillColor(sf::Color(0,255,255,100));
                        }
                        break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                hexagon.setPosition(i * (hexagon.getGlobalBounds().width * 0.80f), j * (hexagon.getGlobalBounds().height * 1.1f) - (hexagon.getGlobalBounds().height * 0.5f));
                if(j % 2 == 0)
                {
                    switch(m_style)
                    {
                        case hexStyle::translucent:
                        {
                            hexagon.setFillColor(sf::Color(255,255,255,100));
                        }
                        break;

                        case hexStyle::colorful:
                        {
                            hexagon.setOutlineColor(sf::Color(200,20,0,255));
                            hexagon.setFillColor(sf::Color(255,55,0,100));
                        }
                        break;

                        case hexStyle::green:
                        {
                            hexagon.setFillColor(sf::Color(0,255,0,100));
                        }
                        break;

                        case hexStyle::cyan:
                        {
                            hexagon.setFillColor(sf::Color(0,255,255,100));
                        }
                        break;

                        default:
                            break;
                    }
                }
                else
                {
                    switch(m_style)
                    {
                        case hexStyle::translucent:
                        {
                            hexagon.setFillColor(sf::Color(255,255,255,100));
                        }
                        break;

                        case hexStyle::colorful:
                        {
                            hexagon.setOutlineColor(sf::Color(200,200,200,255));
                            hexagon.setFillColor(sf::Color(255,255,255,100));
                        }
                        break;

                        case hexStyle::green:
                        {
                            hexagon.setFillColor(sf::Color(0,255,0,100));
                        }
                        break;

                        case hexStyle::cyan:
                        {
                            hexagon.setFillColor(sf::Color(0,255,255,100));
                        }
                        break;

                        default:
                            break;
                    }
                }
            }
            hexagrid.push_back(hexagon);
        }
    }
}

nasic::hexgrid::~hexgrid()
{
    //dtor
}

void nasic::hexgrid::update(sf::RenderWindow& window, sf::Time dt)
{
    //updates go here...
}

void nasic::hexgrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::vector<sf::ConvexShape>::const_iterator hexit;
    for(hexit = hexagrid.begin(); hexit != hexagrid.end(); ++hexit)
    {
        target.draw(*hexit, states);
    }
}
