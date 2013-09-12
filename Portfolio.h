//
//  Portfolio.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__Portfolio__
#define __OODesign_Lab1Deliverable__Portfolio__

#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "Account.h"
#include "PricingVisitor.h"

class Portfolio: public cp::Component
{
    std::vector<cp::Component *> PortfolioList;
    double sum = 0;
public:

    Portfolio(std::string);
    ~Portfolio();
    void virtual addComponent(Component *);
    void virtual deleteComponent(Component *);
    double virtual getCurrentValue();
    double virtual acceptVisitor(PricingVisitor* );
    //std::string getName();
    void virtual printList();
    virtual std::vector<Component *>* getList();
    void setSum(double);
};

#endif /* defined(__OODesign_Lab1Deliverable__Portfolio__) */
