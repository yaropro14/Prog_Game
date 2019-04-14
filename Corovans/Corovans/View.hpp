//
//  View.hpp
//  Proj_Game
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef View_hpp
#define View_hpp


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Map&Objects.hpp"
#include "Game.hpp"
#include "Keypressable.hpp"


class View
{
public:
    View();
    ~View();
    
    static View * inst;
    static View * Get();
    
    Keypressable * onkey_delegater;
    void setonkey(Keypressable * key)
    {
        onkey_delegater = key;
    }
    
    void set_model(Game * g) {
        game = g;
    }
    
    void Run();
    void Draw();
    void Sizeofwin();
    
    void DrawBackground();
    
    void CharacterPainter(sf::Sprite s, Coord c, int h);
    void CamelPainter(Coord c, L_R_Dir d);
    void ObjectPainter(Object o);
    
    sf::RenderWindow window;
    int x_size, y_size;
    
    int elem_size;
    
private:
    Map * map;
    Game * game;
    int square_size;
    int x_squares, y_squares;
};


#endif /* View_hpp */
