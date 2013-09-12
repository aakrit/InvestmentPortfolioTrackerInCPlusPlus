//
//  PortfolioIterator.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "PortfolioIterator.h"


PortfolioIterator::PortfolioIterator()
{
    //std::cout << "Building Portfolio Iterator" << std::endl;
}

cp::Component* PortfolioIterator::first(cp::Component *c)
{
    return c->getList()->front();//return the pointer to the 1st component in the vector
}
bool PortfolioIterator::isNotEmpty(cp::Component *c)
{
    if(!(c->getList()->empty())) //if the list is not empty
    {
        return true;//return the pointer to the 1st component in the vector
    }
    else return false;
}

cp::Component* PortfolioIterator::currentItem(cp::Component *c)
{
    return c->getList()->at(currentLocation);//return the pointer to the current component in the vector
}
cp::Component* PortfolioIterator::next(cp::Component *c)
{
    return c->getList()->at(++currentLocation);//return the pointer to the next component in the vector
}
bool PortfolioIterator::isDone(cp::Component *c)
{
    if (currentLocation == (c->getList()->size()-1))
    {
        currentLocation = 0;
        return true;
    }
    else return false;
}