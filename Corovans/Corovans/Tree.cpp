//
//  Tree.cpp
//  Corovans
//
//  Created by Yaroslav on 17/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Tree.hpp"


Node::Node():
val(0), left(nullptr), right(nullptr), parent(nullptr)
{
}


Node::~Node()
{
    if(left != nullptr)
        left->~Node();
    if (right != nullptr)
        right->~Node();
}


Node * Node::AddNode(Node * node, Node * parent, Var_t value)
{
    if (node == nullptr)
    {
        node = new Node();
        node->val.push_back(value);
        node->left = nullptr;
        node->right = nullptr;
        node->parent = parent;
        return node;
    }
    
    else
    {
        Coord c = GetCoord(value);
        Coord valc = GetCoord(val.front());
        
        if (c.second == valc.second)
            val.push_back(value);
        
        if (c.second < valc.second)
            node->left = AddNode(node->left, node, value);
        
        else if (c.second > valc.second)
            node->right = AddNode(node->right, node, value);
        
    }
    
    return node;
}


template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

Coord GetCoord(Var_t x)
{
    return std::visit(overloaded {
        [](Character * arg) { return arg->position;},
        [](Object * arg) { return arg->position;},
    }, x);
}
