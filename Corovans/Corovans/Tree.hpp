//
//  Tree.hpp
//  Corovans
//
//  Created by Yaroslav on 17/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <list>
#include <variant>

#include "Game.hpp"


using Var_t = std::variant<Character *, Object *>;


class Node
{
public:
    std::list <Var_t> val;       // value
    
    struct Node * left;      // left child
    struct Node * right;     // right child
    struct Node * parent;    // parent
    
    Node();
    ~Node();
    
    Node * AddNode(Node * node, Node * parent, Var_t val);
    //void NodePrint(Node * node);
};


Coord GetCoord(Var_t x);


#endif /* Tree_hpp */
