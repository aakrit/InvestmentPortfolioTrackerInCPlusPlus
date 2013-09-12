//
//  Bond.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__Bond__
#define __OODesign_Lab1Deliverable__Bond__

#include <iostream>
#include <ctime>
#include <cmath>
#include "Component.h"
class PricingVisitor;
namespace bond
{
    //The MoneyMarket class is a LEAF component of the composite pattern
    class Bond: public cp::Component
    {
        double interestRate;
        int years = 0;
        //        time_t years = time(NULL);
        //        struct tm *yr = localtime(&years);
        //        int year = yr->tm_year;
        
        void updateBalane();
        
    public:
        Bond(std::string, double);
        ~Bond();
        
        void virtual addComponent(Component *);
        void virtual deleteComponent(Component *);
        double virtual acceptVisitor(PricingVisitor* );
        double getCurrentValue();
        void setBalance(double);
    };
    
}



#endif /* defined(__OODesign_Lab1Deliverable__Bond__) */
