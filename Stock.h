//
//  Stock.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__Stock__
#define __OODesign_Lab1Deliverable__Stock__

#include <iostream>
#include <string>
#include <vector>
#include "Component.h"
#include "PricingVisitor.h"
namespace stock
{
    //The stock class is a LEAF component of the composite pattern
    class Stock: public cp::Component
    {
        double maxshares;
        std::vector<Stock* > Stocklist;
    public:
        Stock(std::string, double, double);
        ~Stock();
        
        void virtual addComponent(Component *);
        void virtual deleteComponent(Component *);
        double virtual acceptVisitor(PricingVisitor* );
        double virtual getCurrentValue();
        void setPrice(double);

    };
    
}

#endif /* defined(__OODesign_Lab1Deliverable__Stock__) */

