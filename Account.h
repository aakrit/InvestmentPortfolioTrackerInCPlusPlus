//
//  Account.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__Account__
#define __OODesign_Lab1Deliverable__Account__

#include <iostream>
#include <vector>
#include <algorithm>
#include "Component.h"

class bond::Bond;
class mm::MoneyMarket;
class PricingVisitor;
class stock::Stock;

class Account: public cp::Component
{
    std::vector<cp::Component *> AccountList;
    double sum = 0;
public:
    
    Account(std::string);
    ~Account();
    void virtual addComponent(Component *);
    void virtual deleteComponent(Component *);
    double virtual getCurrentValue();
    double virtual acceptVisitor(PricingVisitor* );
    void virtual printList();
    virtual std::vector<cp::Component *>* getList();
    void setSum(double);
};



#endif /* defined(__OODesign_Lab1Deliverable__Account__) */
