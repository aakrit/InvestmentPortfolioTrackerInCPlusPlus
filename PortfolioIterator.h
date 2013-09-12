//
//  PortfolioIterator.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__PortfolioIterator__
#define __OODesign_Lab1Deliverable__PortfolioIterator__

#include <iostream>
#include <vector>
#include "Component.h"
#include "Account.h"
#include "Portfolio.h"

class PortfolioIterator
{
    int currentLocation = 0; //store current iterator location
public:
    PortfolioIterator();
    ~PortfolioIterator();
    cp::Component* first(cp::Component *);
    cp::Component* next(cp::Component *);
    bool isDone(cp::Component *);
    cp::Component* currentItem(cp::Component *);
    bool isNotEmpty(cp::Component *);
};


#endif /* defined(__OODesign_Lab1Deliverable__PortfolioIterator__) */
