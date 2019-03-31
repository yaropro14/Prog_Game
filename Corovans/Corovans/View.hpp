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


class View
{
public:
    View();
    ~View();
    static View * inst;
    static View * Get();
    void Run();
    void Draw();
    void DrawBackground();
    void Sizeofwin();
    sf::RenderWindow window;
    int x_size, y_size;
    private:
    int x_squares, y_squares;
};


#endif /* View_hpp */
