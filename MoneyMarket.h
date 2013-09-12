//
//  MoneyMarket.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__MoneyMarket__
#define __OODesign_Lab1Deliverable__MoneyMarket__

#include <iostream>
#include <ctime>
#include <cmath>
#include "Component.h"
#include "PricingVisitor.h"

namespace mm
{
    //The MoneyMarket class is a LEAF component of the composite pattern
    class MoneyMarket: public cp::Component
    {
        double interestRate;
        int years = 0;
        void updateBalane();       
        
    public:
        MoneyMarket(std::string, double);
        ~MoneyMarket();
        
        void virtual addComponent(Component *);
        void virtual deleteComponent(Component *);
        double virtual acceptVisitor(PricingVisitor* );
        double getCurrentValue();
        void setBalance(double);
        
    };
    
}
#endif /* defined(__OODesign_Lab1Deliverable__MoneyMarket__) */
