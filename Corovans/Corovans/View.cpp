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
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Map&Objects.hpp"


#include "View.hpp"


static void Sizechange(int y);


View::View()
{
    //printf("create\n");
    //printf("create\n");
    window.create(sf::VideoMode(2160, 1350), "Corovans");
    Sizeofwin();
    struct sigaction sa = {0};
    sa.sa_handler = Sizechange;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGWINCH, &sa, 0);
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
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Draw();
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
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    x_size = 2160;// (size.ws_col / 60) * 60;
    y_size = 1350;// (size.ws_row / 60) * 60;
    
    x_squares = x_size / 60;
    y_squares = y_size / 60;
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
    return;
}

void View::DrawBackground()
{
    sf::Texture sand_texture;
    sand_texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Sand.png");
    sf::Sprite sand;
    sand.setTexture(sand_texture);
    sand.setOrigin(0, 0);
    Map * m = Map::Get();
    //int x = m->x_size - x_squares;
    //int y = m->y_size - y_squares;
    //printf("x = %d, y = %d\n", x_squares, y_squares);
    //for(int i = 0; y < y + y_squares; y ++, i++)
    //for(int j = 0; x < x + x_squares; x ++, j++) {
    for(int i = 0; i < y_squares; i++)
    for(int j = 0; j <x_squares; j++) {
        //printf("x = %d, y = %d\n", x, y);
        int c = 0;
        //scanf("%d", &c);

        sand.setPosition(j * 60, i * 60);

        window.draw(sand);
        window.display();
 
    }
    
}



View::~View()
{
}
