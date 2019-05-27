//
//  View.hpp
//  Proj_Game
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include <poll.h>
#include <time.h>

#ifndef View_hpp
#define View_hpp


#include <variant>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Keypressable.hpp"
#include "Tree.hpp"
#include "Storage.hpp"
//#include "Sound.hpp"


using movable = std::function<void()>;
using timeoutable = std::function<void()>;


class SnakeAI;


class View
{
public:
    View();
    ~View();
    
    static View * inst;
    static View * Get();
    
    Keypressable * onkey_delegater;
    std::list <std::pair < long, movable>> ontime_deligater;
    
    
    long min_game_time;
    
    void SetOnKey(Keypressable * key)
    {
        onkey_delegater = key;
    }
    
    
    void SetOnTimer(struct timespec timeout, movable t)
    {
        std::pair <long , movable> n;
        
        n.first = timeout.tv_nsec / 1000000 + timeout.tv_sec * 1000;
        n.second = t;
        
        ontime_deligater.push_back(n);
    }
    
    void set_model(Game * g) {
        game = g;
    }
    
    void Run();
    void Draw();
    void DrawSistemCharacteristics();
    void DrawLevel(Node * tree);
    void Sizeofwin();
    void SetScreenPosition();
    bool GetKey(long time);
    
    void SnakePainter(SPRITE_TYPE type, Coord c, int h, Object * o);
    void MapPainter(sf::Sprite & sprite, Coord c);
    void ObjectPainter(SPRITE_TYPE type, Coord c, int h, Object * o);
    void CharacterPainter(Character * c, sf::Sprite sprite);
    
    Storage * storage;
    
    sf::RenderWindow window;
    int x_size, y_size;
    
    //int elem_size;
    
    int cell_size;
    int x_cells, y_cells;
    Coord screen_position;
    
private:
    Map * map;
    Game * game;
};


#endif /* View_hpp */
