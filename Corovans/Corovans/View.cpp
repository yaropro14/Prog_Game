//
//  View.cpp
//  Proj_Game
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <stdio.h>

using namespace std::placeholders;

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Map&Objects.hpp"
#include "Game.hpp"


#include "View.hpp"


static void Sizechange(int y);


View::View()
{
    //printf("create\n");
    //printf("create\n");
    square_size = 70;
    window.create(sf::VideoMode(3360, 2100), "Corovans", sf::Style::Fullscreen);
    Sizeofwin();
    
    map = Map::Get();
    game = Game::Get();
    
    elem_size = 100 * square_size / map->map_size;
    //camel = new Camel();
    
}


void View::Run()
{
    Draw();
    
    while (window.isOpen())
    {
        // проверить все события окна, которые были вызваны с последней итерации цикла
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "запрос закрытия" событие: мы закрываем окно
            
            if(event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::KeyPressed)
            {
                onkey_delegater->onkey();
            }
            
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {game->camels[0];}
        }
        //printf("1\n");
        Draw();
        window.display();
    }
}


static void Sizechange(int y)
{
    View * v = View::Get();
    v->Sizeofwin();
    printf("setsize\n");
    v->window.setSize(sf::Vector2u(v->x_size, v->y_size));
    v->Draw();
}


void View::Sizeofwin()
{
    sf::Vector2u size = window.getSize();
    
    x_size = (size.x / square_size) * square_size;
    y_size = (size.y / square_size) * square_size;
    
    x_squares = x_size / square_size;
    y_squares = y_size / square_size;
}


View * View::inst;

View * View::Get()
{
    if(inst != nullptr)    return inst;
    
    inst = new View;
    return inst;
}


void View::Draw()
{
    window.clear();
    DrawBackground();
    
    game->CamelPaint(std::bind(&::View::CamelPainter, this, _1, _2));
    game->CharacterPaint(std::bind(&View::CharacterPainter, this, _1, _2, _3));
    game->ObjectsPaint(std::bind(&View::ObjectPainter, this, _1));
    return;
}


void View::DrawBackground()
{
    for(int i = 0; i < y_squares; i ++) //y_squares
        for(int j = 0; j < x_squares; j ++) {
            if(map->map[i * 2][j * 2] == 's') {
                map->stone.setPosition(j * square_size, i * square_size);
                window.draw(map->stone);
            }
            else {
            map->sand.setPosition(j * square_size, i * square_size);
            window.draw(map->sand);
            }
        }
    //map->palm.setPosition(700, 700);
   //map->pyramid.setPosition(200, 900);
   // window.draw(map->palm);
   // window.draw(map->pyramid);
}


void View::CharacterPainter(sf::Sprite s, Coord c, int h)
{
    Coord n;
    n.first = c.first * elem_size;
    n.second = c.second * elem_size - h;
    //printf("x = %d, y = %d\n", c.first * elem_size, c.second);
    //int i = 0;
    //scanf("%d", &i);
    s.setPosition(n.first, n.second);
    window.draw(s);
}


void View::CamelPainter(Coord c, L_R_Dir d)
{
    //camel->camel.setPosition(c.first * suare_size, c.second * suare_size);
   // camel->camel.setTextureRect(sf::IntRect(10, 0, 260, 210));
    //camel->camel.move(10, 0);
   // window.draw(camel->camel);
}


void View::ObjectPainter(Object o)
{
    o.sprite.setPosition(o.body.back().first, o.body.back().second);
    window.draw(o.sprite);
}


View::~View()
{
}
