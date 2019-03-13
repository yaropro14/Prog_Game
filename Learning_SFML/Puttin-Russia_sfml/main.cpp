#include <SFML/Graphics.hpp>

int main()
{
    // Image
    sf::Image putin;
    putin.loadFromFile("/Users/yaroslav/Desktop/Proga/Learning_SFML/Learning_SFML/Images/vladimir-putin.png");
    
    sf::Image Russia;
    Russia.loadFromFile("/Users/yaroslav/Desktop/Proga/Learning_SFML/Learning_SFML/Images/Russia.png");
    
    
    sf::Texture putinTexture;
    putinTexture.loadFromFile("/Users/yaroslav/Desktop/Proga/Learning_SFML/Learning_SFML/Images/vladimir-putin.png");
    
    sf::Texture textureRussia;
    textureRussia.loadFromFile("/Users/yaroslav/Desktop/Proga/Learning_SFML/Learning_SFML/Images/Russia.png");
    
    sf::Sprite sprite;
    sf::Vector2u size = textureRussia.getSize();
    
    sf::RenderWindow app(sf::VideoMode(size.x, size.y), "RUSSIA PURIN");
    
    sprite.setTexture(textureRussia);
    sprite.setOrigin(0, 0);
    
    sf::Sprite putinsprite;
    putinsprite.setTexture(putinTexture);
    sf::Vector2u putinSize = textureRussia.getSize();
    putinsprite.setPosition(putinSize.x, putinSize.y);
    
    float a = 1, b = 1;
    
    float x = 20, y = 1;
    
    /**   Circle
    sf::CircleShape shape(250.f);
    shape.setFillColor(sf::Color::Cyan);
    */
    while (app.isOpen())
    {
        // проверяем события (нажатие кнопки, закрытие окна и т.д.)
        sf::Event event;
       while (app.pollEvent(event))
       {
            // если событие "закрытие окна":
            if (event.type == sf::Event::Closed)
                // закрываем окно
                app.close();
       }
        
        // очищаем экран и заливаем его цветом
        app.clear();
        
        putinsprite.setPosition(x, y);
        
        if(x == size.x - 550)
            a = -1;
        if(x == 0)
            a = 1;
        
        if(y == size.y - 590)
            b = -1;
        if(y == 0)
            b = 1;
        
        x += a;
        y += b;
        
        
        app.draw(sprite);
        
        
        app.draw(putinsprite);
        
        
        // отображаем на экран
        app.display();
    }
    
    return 0;
}
