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


class Node
{
public:
    std::list <Object *> val;       // value
    
    struct Node * left;      // left child
    struct Node * right;     // right child
    struct Node * parent;    // parent
    
    Node();
    ~Node();
    
    Node * AddNode(Node * node, Node * parent, Object * val);
};


#endif /* Tree_hpp */
