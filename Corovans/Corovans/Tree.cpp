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


Node * Node::AddNode(Node * node, Node * parent, Object * value)
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
        Coord c = node->val.front()->position;;
        Coord valc = value->position;
        
        if (c.second == valc.second)
            val.push_back(value);
        
        if (c.second < valc.second)
            node->left = AddNode(node->left, node, value);
        
        else if (c.second > valc.second)
            node->right = AddNode(node->right, node, value);
        
    }
    
    return node;
}
