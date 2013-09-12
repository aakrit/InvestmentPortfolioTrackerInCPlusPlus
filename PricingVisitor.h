//
//  PricingVisitor.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__PricingVisitor__
#define __OODesign_Lab1Deliverable__PricingVisitor__

#include <iostream>
#include <vector>

//I need to implement the following 'forward declarations' in order for my pricing vistor to have visit access without having to run into compile time linking errors
namespace cp {
    class Component;
}
namespace stock {
    class Stock;
}
namespace mm {
    class MoneyMarket;
}
namespace bond {
    class Bond;
}
class Portfolio;
class Account;
class PortfolioIterator;


class PricingVisitor
{
    
public:
    double visitComponent(stock::Stock* );
    double visitComponent(bond::Bond* );
    double visitComponent(mm::MoneyMarket* );
    double visitComponent(Portfolio* );
    double visitComponent(Account* );
    double visitComponent(cp::Component* );
};


#endif /* defined(__OODesign_Lab1Deliverable__PricingVisitor__) */
