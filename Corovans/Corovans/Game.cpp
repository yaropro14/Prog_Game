//
//  Game.cpp
//  Corovans
//
//  Created by Yaroslav on 01/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//


#include <time.h>


#include <random>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <list>



#include "Game.hpp"
#include "View.hpp"
#include "AI.hpp"


const int N_PYR = 2;
const int N_GRE = 4;
const int N_SCE = 4;
const int N_TRE = 4;
const int N_STO = 8;
const int N_SNA = 4;


Game::Game()
{
    map = new Map();
}


void Game::CreateField()
{
    int n = N_PYR;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int dx = 0, dy = 0;
            dx += (X_SIZE / n) * i;
            dy += (Y_SIZE / n) * j;
            
            Coord c = GetCoordForObject(n, dx, dy);
            if(c == Coord(0, 0)) break;
            
            Object * pyr = new Pyramid(c);
            AddObject(pyr);
        }
    
    n = N_SNA;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int dx = 0, dy = 0;
            dx += (X_SIZE / n) * i;
            dy += (Y_SIZE / n) * j;
            
            Coord c = GetCoordForObject(n, dx, dy);
            if(c == Coord(0, 0)) break;
            
            Snake * s = new Snake(c);
            SnakeAI * sai = new SnakeAI(s);
        }
    
    
    n = N_GRE;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int dx = 0, dy = 0;
            dx += (X_SIZE / n) * i;
            dy += (Y_SIZE / n) * j;
            
            Coord c = GetCoordForObject(n, dx, dy);
            if(c == Coord(0, 0)) break;
            
            Object * gre = new Greenery(c);
            AddObject(gre);
        }
    
    n = N_SCE;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int dx = 0, dy = 0;
            dx += (X_SIZE / n) * i;
            dy += (Y_SIZE / n) * j;
            
            Coord c = GetCoordForObject(n, dx, dy);
            if(c == Coord(0, 0)) break;
            
            Object * sce = new Scelet(c);
            AddObject(sce);
        }
    
    n = N_TRE;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int dx = 0, dy = 0;
            dx += (X_SIZE / n) * i;
            dy += (Y_SIZE / n) * j;
            
            Coord c = GetCoordForObject(n, dx, dy);
            if(c == Coord(0, 0)) break;
            
            Object * tree = new Tree(c);
            AddObject(tree);
        }
    
    n = N_STO;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int dx = 0, dy = 0;
            dx += (X_SIZE / n) * i;
            dy += (Y_SIZE / n) * j;
            
            Coord c = GetCoordForObject(n, dx, dy);
            if(c == Coord(0, 0)) break;
            
            Object * sto = new Stone(c);
            AddObject(sto);
        }
}


void Game::NewLife()
{
    Coord c;
    
    c = GetCoordForObject(1, 0, 0);
        
//    printf("%d %d \n", c.first, c.second);
    Object * life = new Life(c);
    objects.push_back(life);
    
    struct timespec t;
    t = {30, 0};
    View::Get()->SetOnTimer(t, std::bind(&Game::NewLife, this));
}


void Game::SnakePaint(Object * o, SnakePainter p)
{
    p(o->type, o->position, o->z_size, o);
}


void Game::ObjectsPaint(Object * o, ObjectPainter p)
{
        p(o->type, o->position, o->z_size, o);
}

void Game::AddObject(Object * o)
{
    objects.push_back(o);
}

Game * Game::inst;

Game * Game::Get()
{
    if(inst != nullptr)    return Game::inst;
    Game::inst = new Game;
    return Game::inst;
}


Coord Game::GetCoordForObject(int n, int dx, int dy)
{
    for(auto i = 0; i < 20; i ++)
    {
        int y, x;
        x = rand() % (X_SIZE / n) + dx;
        y = rand() % (Y_SIZE / n) + dy;

        Coord a;
        a.first = x;
        a.second = y;
        int a_x = 600;
        int a_y = 600;
        
        for(auto o : Game::Get()->objects)
        {
            Coord b;
            b.first = o->position.first + o->figure.position.first;
            b.second = o->position.second + o->figure.position.second;
            int b_x = o->figure.x;
            int b_y = o->figure.y;
            
            if(Check(a, b, a_x, a_y, b_x, b_y)) a = Coord(0, 0);
        }
        
        auto o = character;
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        
        if(Check(a, b, a_x, a_y, b_x, b_y)) a = Coord(0, 0);
        
        if(a.first < 70 || a.second < 400 || a.first > X_SIZE - 420 || a.second > Y_SIZE - 70)
            a = Coord(0, 0);
        
        if (a != Coord(0, 0))
            return a;
    }
    
    return Coord(0, 0);
}


bool Game::CheckPlace(Coord c, int radius)
{
    for(const auto o : objects)
    {
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        if(Check(c, o->position, radius, radius, b_x, b_y)) return false;
    }
    
    for(auto o : corovan->camels)
    {
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        if(Check(c, o->position, radius, radius, b_x, b_y)) return false;
    }
    
    auto o = character;
    int b_x = o->figure.x;
    int b_y = o->figure.y;
    if(Check(c, o->position, radius, radius, b_x, b_y)) return false;
    
    if(c.first <= 0 || c.first >= X_SIZE)    return false;
    if(c.second <= 0 || c.second >= Y_SIZE)   return false;
    
    return true;
}


bool Game::OnSkreen(int x, int y)
{
    int x1 = character->position.first;
    int y1 = character-> position.second;
    
    int sx = View::Get()->x_cells / 2;
    int sy = View::Get()->y_cells / 2;
    
    if(x > x1 - sx && x < x1 + sx)
        if(y > y1 - sy && y < y1 + sy)
            return true;
    
    return false;
}


void Game::Move()
{
    if(corovan->camels.size() == 0)
    {
        delete corovan;
        corovan = nullptr;
        corovan = new Corovan();
    }
    
    for(auto ai : snake_Ai_deligater){
        int x = ai->snake->position.first;
        int y = ai->snake->position.second;
        ai->OnMove();
        ai->snake->Move();
    }
    
    if(character->hurm) character->Hurm();
    
    corovan->Move();
    
    struct timespec t;
    t = {0, 100000000};
    View::Get()->SetOnTimer(t, std::bind(&Game::Move, this));
}


void Game::MapPaint(MapPainter p, Coord c)
{
    for(int y  = 0; y < Y_SIZE; y += map->size_in_cell) {
        if(y + map->size_in_cell >= c.second)
            for(int x = 0; x < X_SIZE; x += map->size_in_cell){
                if(x + map->size_in_cell >= c.first) {
                    if(y == 0 || x == 0)
                        p(map->stone, Coord(x, y));
                    else if(y >= Y_SIZE - 75 || x >= X_SIZE - 70)
                        p(map->stone, Coord(x, y));
                    else
                        p(map->sand, Coord(x, y));;
                }
        }
    }
}


Game::~Game()
{
}


Alive::Alive()
{
    lifes = 20;
}


Alive::~Alive()
{
}

LeftRightDirection::LeftRightDirection()
{
}


LeftRightDirection::~LeftRightDirection()
{
}


Character::Character()
{
    z_size = 182 / CELL_SIZE;
    x_size = 70 / CELL_SIZE;
    y_size = 10 / CELL_SIZE;
    
    go = false;
    hurm = false;
    hurm_dir = NO;
    
    lifes = NUM_LIFES;
    brilliants = 0;
    hit = false;
    rob = false;
    
    position = Coord(300, 300);
    
    dir = ST_BACK;
    step = 1;
    speed = 10;
    
    type = CHARACTER;
    
    Game * g =  Game::Get();
    
//    position.first = g->map->size_in_cell;
//    position.second = g->map->size_in_cell + z_size;
    
    figure.position.first = 0;
    figure.position.second = 0;
    
    figure.x = x_size;
    figure.y = y_size;
    
    struct timespec t;
    t = {0, 75000000};
    View::Get()->SetOnTimer(t, std::bind(&Character::Move, this));
}


bool Character::SetDirection(Dir d)
{
    dir = d;
    if(go == true) return false;
    go = true;
    return true;
}

bool Check(Coord a, Coord b, int a_x, int a_y, int b_x, int b_y)
{
    if(b.first <= a.first + a_x && a.first + a_x <= b.first + b_x)
    {
        if(b.second >= a.second - a_y && b.second - b_y <= a.second - a_y) return true;
        if(b.second >= a.second && b.second - b_y <= a.second) return true;
        if(b.second - b_y <= a.second && b.second - b_y >= a.second - a_y) return true;
    }
    
    if(a.first <= b.first + b_x && b.first + b_x <= a.first + a_x)
    {
        if(b.second >= a.second - a_y && b.second - b_y <= a.second - a_y) return true;
        if(b.second - b_y >= a.second && b.second - b_y <= a.second - a_y) return true;
        if(b.second - b_y <= a.second && b.second - b_y >= a.second - a_y) return true;
    }
    
    return false;
}


SPRITE_TYPE Character::CheckPosition(Coord c)
{
    Coord a;
    a.first = c.first + figure.position.first;
    a.second = c.second + figure.position.second;
    int a_x = figure.x;
    int a_y = figure.y;
    
    Game * g = Game::Get();
    
    Object * ofd;
    
    for(auto o : g->objects)
    {
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        
        if(Check(a, b, a_x, a_y, b_x, b_y))
        {
            if(o->type == LIFE) {
                
                if (lifes <= 65 )lifes = (lifes + 5);
                
                
                ofd = o;
                g->objects.remove(o);
                return CHARACTER;
            }
            
            if(o->type == BRILLIANT)
            {
                brilliants ++;
                g->objects.remove(o);
                return BRILLIANT;
            }
            
            return o->type;
        }
    }
    
    
    for(auto camel : g->corovan->camels)
    {
        Camel * o = camel;
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        if(Check(a, b, a_x, a_y, b_x, b_y)) {
            if(rob)    o->full --;
            
            if(o->full == 0)
            {
                if(rand() % 2)
                {
                    Object * b = new Brilliant(Coord(o->position.first + 100, o->position.second + 100));
                    g->objects.push_back(b);
//                    hit = false;
                }
                g->corovan->camels.remove(o);
                return CHARACTER;
            }
            return o->type;
        }
    }
    
    for(auto s : g->snake_Ai_deligater)
    {
        Snake * o = s->snake;
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        if(Check(a, b, a_x, a_y, b_x, b_y)) {
            if(hit && step == 1)    o->lifes --;
            
            if(o->lifes == 0 && o->type == SNAKE)
            {
                g->snake_Ai_deligater.remove(s);
                Snake * snake = new Snake();
                Snake * s = new Snake();
                SnakeAI * sai = new SnakeAI(s);
            }
            
            return o->type;
        }
    }
    
    if(a.first < 70 || a.first + a_x > X_SIZE - 70) return BORDER;
    if(a.second < 100 || a.second + a_y > Y_SIZE - 70) return BORDER;
    
    return CHARACTER;
}


void Character::Move()
{
    struct timespec t;
    t = {0, 75000000};
    View::Get()->SetOnTimer(t, std::bind(&Character::Move, this));
    
    if(go == false) return;
    
    SPRITE_TYPE s;
    
    switch (dir) {
        case FORWARD:
            s = CheckPosition(ChangePosition(position, 0, -speed));
            if(s != CHARACTER) {
                if(s == GREENERY)
                {
                    Game::Get()->sounds->PlaySounds(HIT);
                    speed = 50;
                    lifes -= 5;
                    position =ChangePosition(position, 0, speed);
                }
                break;
            }
            else position = ChangePosition(position, 0, -speed);
            step ++;
            step = step % 8;
            dir = FORWARD;
            break;
            
        case BACK:
            s = CheckPosition(ChangePosition(position, 0, speed));
            if(s != CHARACTER) {
                if(s == GREENERY)
                {
                    Game::Get()->sounds->PlaySounds(HIT);
                    speed = 50;
                    lifes -= 5;
                    position = ChangePosition(position, 0, -speed);
                }
                break;
            }
            else position = ChangePosition(position, 0, speed);
            step ++;
            step = step % 8;
            dir = BACK;
            break;
            
        case LEFT:
            s = CheckPosition(ChangePosition(position, -speed, 0));
            if(s != CHARACTER) {
                if(s == GREENERY)
                {
                    Game::Get()->sounds->PlaySounds(HIT);
                    speed = 50;
                    lifes -= 5;
                    position =ChangePosition(position, speed, 0);
                }
                break;
            }
            else position = ChangePosition(position, -speed, 0);
            step ++;
            step = step % 8;
            dir = LEFT;
            break;
            
        case RIGHT:
            s = CheckPosition(ChangePosition(position, speed, 0));
            if(s != CHARACTER) {
                if(s == GREENERY)
                {
                    Game::Get()->sounds->PlaySounds(HIT);
                    speed = 50;
                    lifes -= 5;
                    position = ChangePosition(position, -speed, 0);
                }
                break;
            }
            else position = ChangePosition(position, speed, 0);
            step ++;
            step = step % 9;
            if(step == 0)   step++;
            dir = RIGHT;
            break;
            
        default:
            break;
            
    }
    
    if(step == 1 || step == 5) Game::Get()->sounds->PlaySounds(STEP);
    
    if(hit) step ++;
    if(!hit)    speed = 10;
    if(step > 3) hit = false;
    
    if(rob) step ++;
    if(step > 3) rob = false;
    
    go = false;
    
}


void Character::Hurm()
{
    hurm = false;
    speed = 50;
    lifes -= 2;
    
    switch (hurm_dir) {
        case BACK:
            if(CheckPosition(ChangePosition(position, 0, speed)) == CHARACTER)
                position = ChangePosition(position, 0, speed);
            break;
            
        case FORWARD:
            if(CheckPosition(ChangePosition(position, 0, -speed)) == CHARACTER)
                position = ChangePosition(position, 0, -speed);
            break;
            
        case LEFT:
            if(CheckPosition(ChangePosition(position, -speed, 0)) == CHARACTER)
                position = ChangePosition(position, -speed, 0);
            break;
            
        case RIGHT:
            if(CheckPosition(ChangePosition(position, speed, 0)) == CHARACTER)
                position = ChangePosition(position, speed, 0);
            break;
            
        default:
            break;
    }
    
    speed = 10;
}


Coord ChangePosition(Coord position, int x, int y)
{
    position.first += x;
    position.second += y;
    
    return position;
}


Character::~Character()
{
}


Corovan::Corovan():LeftRightDirection()
{
    L_R_Dir di[2] = {L, R};
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(di, di + 2, g);
    
    d = di[0];
    
    figure.position = Coord(5, -10);
    figure.x = 900;
    figure.y = 100;
    
    int x = di[0] == L ? X_SIZE - 10 : 0; //  -figure.x;
    int y;
    
    while(1)
    {
        y = rand() % Y_SIZE;
        
        if(y > 500)
            if(CheckYPosition(y, figure.y))
                break;
    }
    
    position = Coord(x, y);
    
    //step = 0;
    
    int max = rand() % 5 + 1;
    
    for (int i = 0; i < max; i++) {
        x = position.first + i * 170;
        y = position.second + 60 * ((i + 1) % 2) + i;
        camels.push_back(new Camel(Coord(x, y), d));
    }
    
    step = 0;
    for(auto camel : camels)
    {
        camel->SetDirection(d);
        camel->step = step;
        step = rand() % 42;
    }
}


void Corovan::Move()
{
    for(auto camel : camels)
    {
        Coord n;
        n = (d == L ? ChangePosition(camel->position, -10, 0) : ChangePosition(camel->position, 10, 0));
    
        if(camel->CheckPosition(n) == HEROE) {
            return;
        }
    }
    
    for(auto camel : camels)
    {
        int x;
        x = (d == L ? camel->position.first + camel->figure.x : camel->position.first);
        
        if(d == L)
            if(x <= 0)
            {
                camels.remove(camel);
                break;
            }
        
        if(d == R)
            if(x >= X_SIZE)
            {
                camels.remove(camel);
                break;
            }
            
    }
        
    for(auto camel : camels)
        camel->Move();
}


bool Corovan::CheckYPosition(int y, int y_size)
{
    Coord a;
    a.first = 0;
    a.second = y;
    int a_x = X_SIZE;
    int a_y = y_size;
    
    for(auto o : Game::Get()->objects)
    {
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        
        if(Check(a, b, a_x, a_y, b_x, b_y) && o->type != BRILLIANT)   return false;
    }
    
    if(y < 300 || y > Y_SIZE - 70) return false;
    
    if(y < figure.y) return false;
    
    return true;
}


Corovan::~Corovan()
{
}


Camel::Camel(Coord c, L_R_Dir dir)
{
    z_size = 210 / CELL_SIZE;
    x_size = 270 / CELL_SIZE;
    y_size = 90 / CELL_SIZE;
    
    //std::list <Coord> position;
    
    d = dir;
    step = 0;
    full = 20;
    
    Game * g =  Game::Get();
    
    position.first = c.first;
    position.second = c.second;
    
    figure.position.first = 0;
    figure.position.second = 20;
    
    figure.x = 270;
    figure.y = 40;
    
    type = CAMEL;
}


void Camel::Move()
{  
    Coord n;
    n = (d == L ? ChangePosition(position, -10, 0) : ChangePosition(position, 10, 0));

    
    step ++;
    step %= 42;
    
    if(step == 0 && d == R)   step++;
    
    if(step >= 20 && step <= 25) return;
    if(step >= 40 || step <= 1) return;
    
    position = n;
}


OBJ Camel::CheckPosition(Coord c)
{
    Coord a;
    a.first = c.first + figure.position.first;
    a.second = c.second + figure.position.second;
    int a_x = figure.x;
    int a_y = figure.y;
    
    Character * o = Game::Get()->character;
    
    Coord b;
    b.first = o->position.first + o->figure.position.first;
    b.second = o->position.second + o->figure.position.second;
    int b_x = o->figure.x;
    int b_y = o->figure.y;
    
    if(Check(a, b, a_x, a_y, b_x, b_y))   return HEROE;
    
    return FREE;
}


Camel::Camel()
{
}


Camel::~Camel()
{
}


Snake::Snake()
{
    z_size = 100 / CELL_SIZE;
    x_size = 79 / CELL_SIZE;
    y_size = 50 / CELL_SIZE;
    
    Dir d[4] = {LEFT, RIGHT, BACK, FORWARD};
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(d, d + 2, g);
    
    dir = d[0];
    
    figure.position = Coord(0, -10);
    figure.x = 60;
    figure.y = 50;
    
    speed = 10;
    bite = false;
    
    lifes = 5;

    int x, y;
    
    while(1)
    {
        y = rand() % Y_SIZE;
        x = rand() % X_SIZE;
        
        if(y > 500)
            if(CheckPosition(Coord(x, y)) == SNAKE)
                break;
    }
    
    position = Coord(x, y);

    
    type = SNAKE;
}

Snake::Snake(Coord c)
{
    z_size = 100 / CELL_SIZE;
    x_size = 79 / CELL_SIZE;
    y_size = 50 / CELL_SIZE;
    
    Dir d[4] = {LEFT, RIGHT, BACK, FORWARD};
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(d, d + 2, g);
    
    dir = d[0];
    
    figure.position = Coord(0, -10);
    figure.x = 60;
    figure.y = 50;
    
    speed = 15;
    lifes = 5;
    bite = false;
    
    position = c;
    
    type = SNAKE;
}

SPRITE_TYPE Snake::CheckPosition(Coord c)
{
    Coord a;
    a.first = c.first + figure.position.first;
    a.second = c.second + figure.position.second;
    int a_x = figure.x;
    int a_y = figure.y;
    
    Game * g = Game::Get();
    
    for(auto o : g->objects)
    {
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        
        if(Check(a, b, a_x, a_y, b_x, b_y))   return o->type;
    }
    
    for(auto camel : g->corovan->camels)
    {
        Object * o = camel;
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        if(Check(a, b, a_x, a_y, b_x, b_y))   return o->type;
    }
    
    
    for(auto ai : g->snake_Ai_deligater)
    {
        Object * o = ai->snake;
        Coord b;
        b.first = o->position.first + o->figure.position.first;
        b.second = o->position.second + o->figure.position.second;
        int b_x = o->figure.x;
        int b_y = o->figure.y;
        if(this != o)
            if(Check(a, b, a_x, a_y, b_x, b_y))   return GREENERY;
    }
    
    auto o = g->character;
    Coord b;
    b.first = o->position.first + o->figure.position.first;
    b.second = o->position.second + o->figure.position.second;
    int b_x = o->figure.x;
    int b_y = o->figure.y;
    if(Check(a, b, a_x, a_y, b_x, b_y))   return o->type;
    
    if(a.first < 70 || a.first + a_x > X_SIZE - 70) return BORDER;
    if(a.second < 100 || a.second + a_y > Y_SIZE - 70) return BORDER;
    
    return SNAKE;
}


Coord Snake::NextPosition()
{
    int x = position.first;
    int y = position.second;
    
    switch (dir) {
        case FORWARD:
            return Coord(x, y - speed);
            
        case BACK:
            return Coord(x, y + speed);
            
        case RIGHT:
            return Coord(x + speed, y);
            
        case LEFT:
            return Coord(x - speed, y);
            
        case ST_FORWARD:
            dir = FORWARD;
            return position;
            
        case ST_BACK:
            dir = BACK;
            return position;
            
        case ST_RIGHT:
            dir = RIGHT;
            return position;
            
        case ST_LEFT:
            dir = LEFT;
            return position;
            
        default:
            return position;
            break;
    }
}


void Snake::Move()
{
    if(bite && !Game::Get()->character->hit)
    {
        Game::Get()->sounds->PlaySounds(HIT);
        Dir d;
        switch (dir) {
            case ST_BACK:
                d = BACK;
                break;
                
            case ST_FORWARD:
                d = FORWARD;
                break;
                
            case ST_LEFT:
                d = LEFT;
                break;
                
            case ST_RIGHT:
                d = RIGHT;
                break;
                
            default:
                break;
        }
        Game::Get()->character->hurm = true;
        Game::Get()->character->hurm_dir = d;
        bite = false;
    }
    position = NextPosition();
    step ++;
    step %= 6;
}

Snake::~Snake()
{
    
}


Map::Map()
{
    x_size = X_SIZE;
    y_size = Y_SIZE;
    
    background.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Bacground.png");
    sand.setTexture(background);
    sand.setTextureRect(sf::IntRect(0, 0, 70, 70));
    
    stone.setTexture(background);
    stone.setTextureRect(sf::IntRect(70, 0, 70, 70));
    
    sf::Vector2u size = background.getSize();
    
    size_in_cell = size.y / CELL_SIZE;//View::Get()->cell_size;
}

Map::~Map()
{
}
