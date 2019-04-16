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

#include "Game.hpp"
#include "View.hpp"


static void Sizechange(int y);


View::View()
{
    cell_size = CELL_SIZE;
    
    window.create(sf::VideoMode(3360, 2100), "Corovans", sf::Style::Fullscreen);
    Sizeofwin();
    screen_position = Coord(0, 0);

    game = Game::Get();
    map = game->map;
}


void View::Run()
{
    Draw();
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        sf::Event event;
        
        
        
        while (window.pollEvent(event))
        {
            // "запрос закрытия" событие: мы закрываем окно
            
            if(event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::KeyPressed) {
                onkey_delegater->onkey();
            }
            
            if(sf::Event::Resized)    game->character->speed = 10;
            
            /*else {
                game->character->SetDirection(NO);
            }*/
            
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {game->camels[0];}
        }
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
    
    x_size = (size.x / cell_size) * cell_size;
    y_size = (size.y / cell_size) * cell_size;
    
    x_cells = x_size / cell_size;
    y_cells = y_size / cell_size;
}


void View::SetScreenPosition()
{
    Coord p = game->character->position;
    Coord a = screen_position;
    
    screen_position.first = p.first - x_cells / 2;
    screen_position.second = p.second - y_cells / 2;
    
    if(screen_position.first + x_cells >= X_SIZE)   screen_position.first = a.first;
    if(screen_position.second >= Y_SIZE - y_cells)  screen_position.second = a.second;
    
    if(screen_position.first < 0)   screen_position.first = 0;
    if(screen_position.second < 0)   screen_position.second = 0;
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
    
    SetScreenPosition();
    
    game->MapPaint(std::bind(&::View::MapPainter, this, _1, _2), screen_position);
    //game->CamelPaint(std::bind(&::View::CamelPainter, this, _1, _2));
    game->CharacterPaint(std::bind(&View::ObjectPainter, this, _1, _2, _3));
    for(auto s : game->objects)
        game->ObjectsPaint(s, std::bind(&View::ObjectPainter, this, _1, _2, _3));
    return;
}


void View::MapPainter(sf::Sprite & sprite, Coord c)
{
    sprite.setPosition((c.first - screen_position.first) * CELL_SIZE, (c.second - screen_position.second) * CELL_SIZE);
    window.draw(sprite);
}


void View::CamelPainter(Coord c, L_R_Dir d)
{
    //camel->camel.setPosition(c.first * suare_size, c.second * suare_size);
   // camel->camel.setTextureRect(sf::IntRect(10, 0, 260, 210));
    //camel->camel.move(10, 0);
   // window.draw(camel->camel);
}


void View::ObjectPainter(sf::Sprite & s, Coord c, int h)
{
    Coord n;
    n.first = (c.first - screen_position.first) * CELL_SIZE;
    n.second = (c.second - screen_position.second - h) * CELL_SIZE;
    
    s.setPosition(n.first, n.second);
    window.draw(s);
}


View::~View()
{
}
