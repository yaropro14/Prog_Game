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


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "View.hpp"
#include "AI.hpp"
#include "Sound.hpp"


const int GOAL = 5;


using namespace std::placeholders;


static void Sizechange(int y);


View::View()
{
    cell_size = CELL_SIZE;
    
    window.create(sf::VideoMode(3360, 2100), "Corovans", sf::Style::Fullscreen);
    Sizeofwin();
    screen_position = Coord(0, 0);
    
    storage = new Storage();

    game = Game::Get();
    map = game->map;
    
    min_game_time = 25;
}


void View::Run()
{
    //Draw();
    struct pollfd arr;
    struct timespec start_time, finish_time, worktime;
    
    sf::Music music;
    music.openFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Alladin.wav");
    music.play();
    music.setLoop(true);
    sf::Sprite s = storage->ss->menu;
    
    int k = 0;
    
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        Draw();
        sf::Vector2u size = storage->ss->t_menu.getSize();
        s.setPosition((x_cells - size.x) / 2, (y_cells - size.y) / 2);
        window.draw(s);
        
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && k == 0)
            k = 1;
        
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && k == 1)
        {
            s = storage->ss->menu2;
            k = 2;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && k == 2)
            break;
        
        window.display();
    }
    
    
    music.stop();
    
    
    sf::Music musics;
    musics.openFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Backgroung.wav");
    musics.play();
    music.setLoop(true);
    
    while (window.isOpen())
    {
        sf::Event event;
        
//        sounds->PlaySounds();
        
        if(game->character->lifes <= 0)
        {
            s = storage->ss->menu4;
            break;
        }
        
        if(game->character->brilliants == GOAL)
        {
            s = storage->ss->menu3;
            break;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;
        
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        struct timespec start_time, finish_time, worktime;
        clock_gettime(CLOCK_REALTIME,  &start_time);
        bool suks = GetKey(min_game_time);
        clock_gettime(CLOCK_REALTIME,  &finish_time);
        
        worktime.tv_sec = finish_time.tv_sec - start_time.tv_sec;
        worktime.tv_nsec = finish_time.tv_nsec - start_time.tv_nsec;
        int d = (int)(worktime.tv_sec * 1000) + (int)(worktime.tv_nsec / 1000000);
        
        for(int i = 0; i < ontime_deligater.size(); i ++) {
            std::pair<long, timeoutable> a = ontime_deligater.front();
            ontime_deligater.pop_front();
            a.first -= d;
            ontime_deligater.push_back(a);
        }
        
        for(int i = 0; i < ontime_deligater.size(); i ++) {
            std::pair<long, timeoutable> a = ontime_deligater.front();
            ontime_deligater.pop_front();
            
            if(a.first <= 0) {
                a.second();
            }
            
            else ontime_deligater.push_back(a);
        }
        
        Draw();
        window.display();
        //game->character->dir = ST_BACK;
    }
    
    musics.stop();
    music.play();
    
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        Draw();
        sf::Vector2u size = storage->ss->t_menu.getSize();
        s.setPosition((x_cells - size.x) / 2, (y_cells - size.y) / 2);
        window.draw(s);
        
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            break;
        
        window.display();
    }
}


bool View::GetKey(long time)
{
    sf::Clock clock;
    sf::Time timer = sf::microseconds(1000);
    clock.restart();
    timer = clock.getElapsedTime();char c;
    
    sf::Event event;
    
    while (timer.asMicroseconds() / 1000 < time) {
        
        //        if (event.type == sf::Event::KeyPressed)
        //        {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(onkey_delegater->onkey())
            return true;
        }
        //        }
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(onkey_delegater->onkey())
            return true;
        }
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(onkey_delegater->onkey())
            return true;
        }
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(onkey_delegater->onkey())
            return true;
        }
        
        timer = clock.getElapsedTime();
    }
    
    return false;
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
    
    
    
    Node * draw_tree = nullptr;
    
    game->MapPaint(std::bind(&::View::MapPainter, this, _1, _2), screen_position);
    
    draw_tree = draw_tree->AddNode(draw_tree, nullptr, game->character);
    
    for(auto o : game->objects)//Game::Get()->objects)
        draw_tree = draw_tree->AddNode(draw_tree, nullptr, o);

    for(auto camel : game->corovan->camels)
    {
        draw_tree = draw_tree->AddNode(draw_tree, nullptr, camel);
    }
    
    for(auto ai : game->snake_Ai_deligater)
    {
        draw_tree = draw_tree->AddNode(draw_tree, nullptr, ai->snake);
    }
    
    DrawLevel(draw_tree);
    
    DrawSistemCharacteristics();
}


void View::DrawSistemCharacteristics()
{
    sf::Vector2u size = storage->ss->t_life.getSize();
    
    for(int i = 0, j = 0; i < NUM_LIFES; i += 5, j ++)
    {
        Coord n;
        sf::Sprite s;
    
        if(i < game->character->lifes)  s = storage->ss->life;
        else    s = storage->ss->b_life;
        
       
        
        n.first = x_cells - (NUM_LIFES / 5 - j) * (size.x + 5);
        n.second = 5;
        
        s.setPosition(n.first, n.second);
        window.draw(s);
    }
    
    size = storage->ss->t_wpoint.getSize();
    
    int x = x_cells - 70 - size.x * 6;
    int y = 75;
    
    int n = game->character->brilliants;
    
    sf::Sprite s;
    s = storage->ss->num;
    s.setTextureRect(sf::IntRect(60 * (n / 10), 0, 60, 60));
    s.setPosition(x, y);
    window.draw(s);
    x += 64;
    
    s.setTextureRect(sf::IntRect(60 * (n % 10), 0, 60, 60));
    s.setPosition(x, y);
    window.draw(s);
    x += 64;

    sf::Sprite sp = storage->ss->wpoint;
    sp.setPosition(x, y);
    window.draw(sp);
    x += 64;

    sf::Sprite st = storage->ss->num;
    st.setTextureRect(sf::IntRect(60 * (GOAL / 10), 0, 60, 60));
    st.setPosition(x, y);
    window.draw(st);
    x += 64;

    sf::Sprite sn = storage->ss->num;
    sn.setTextureRect(sf::IntRect(60 * (GOAL % 10), 0, 60, 60));
    sn.setPosition(x, y);
    window.draw(sn);
    x += 64;

    sf::Sprite sb = storage->ss->bril;
    sb.setPosition(x, y);
    window.draw(sb);
}


void View::DrawLevel(Node * tree)
{
    if (tree == NULL)
        return;

    DrawLevel(tree->right);
    
    for(auto o : tree->val)
    switch (o->type) {
        case CHARACTER:
            CharacterPainter(game->character, storage->GetSprite(CHARACTER, game->character));
            break;
            
        case CAMEL:
            Game::Get()->corovan->step = o->step ;
            game->ObjectsPaint(o, std::bind(&View::ObjectPainter, this, _1, _2, _3, _4));
            
        case SNAKE:
            game->SnakePaint(o, std::bind(&View::ObjectPainter, this, _1, _2, _3, _4));

        default:
            game->ObjectsPaint(o, std::bind(&View::ObjectPainter, this, _1, _2, _3, _4));
            break;
    }

    DrawLevel(tree->left);
}


void View::MapPainter(sf::Sprite & sprite, Coord c)
{
    sprite.setPosition((c.first - screen_position.first) * CELL_SIZE, (c.second - screen_position.second) * CELL_SIZE);
    window.draw(sprite);
}


void View::SnakePainter(SPRITE_TYPE type, Coord c, int h, Object * o)
{
    Coord n;
    
    sf::Sprite s = storage->GetSprite(type, o);
    
    n.first = (c.first - screen_position.first) * CELL_SIZE;
    n.second = (c.second - screen_position.second - h) * CELL_SIZE;
    
    s.setPosition(n.first, n.second);
    window.draw(s);
}


void View::ObjectPainter(SPRITE_TYPE type, Coord c, int h, Object * o)
{
    Coord n;
    
    sf::Sprite s = storage->GetSprite(type, o);
    
    n.first = (c.first - screen_position.first) * CELL_SIZE;
    n.second = (c.second - screen_position.second - h) * CELL_SIZE;
    
    s.setPosition(n.first, n.second);
    window.draw(s);
}


void View::CharacterPainter(Character * c, sf::Sprite sprite)
{
    Coord n;
    
    n.first = (c->position.first - screen_position.first) * CELL_SIZE;
    n.second = (c->position.second - screen_position.second - c->z_size) * CELL_SIZE;
    
    sprite.setPosition(n.first, n.second);
    window.draw(sprite);
}

View::~View()
{
    window.close();
}
