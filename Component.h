//
//  Component.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__Component__
#define __OODesign_Lab1Deliverable__Component__

#include <iostream>
#include <vector>
//abstract base class
#include "PricingVisitor.h"

namespace cp
{

    class Component
    {
    private:
        std::string name;
        double value;
        std::vector<cp::Component *> cvec;
    
    public:
        enum {STOCK, BOND, MM, ACCOUNT, PORTFOLIO} type;
        void virtual addComponent(cp::Component *) = 0;
        void virtual deleteComponent(cp::Component *) = 0;
        double virtual getCurrentValue() = 0;
        void virtual printList();
        double virtual acceptVisitor(PricingVisitor* ) = 0;
        std::string getName();
        void setName(std::string);
        void setValue(double);
        double getValue();
        virtual std::vector<cp::Component *>* getList();

    };

}



#endif /* defined(__OODesign_Lab1Deliverable__Component__) */
