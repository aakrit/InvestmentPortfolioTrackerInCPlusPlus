//
//  PricingVisitor.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "PricingVisitor.h"
#include "Portfolio.h"
#include "Account.h"
#include "Bond.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "PortfolioIterator.h"
#include "Component.h"

double PricingVisitor::visitComponent(cp::Component* c)
{
    if(c->type == cp::Component::STOCK )
        return visitComponent(dynamic_cast<stock::Stock*>(c));
    else if (c->type == cp::Component::BOND)
        return visitComponent(dynamic_cast<bond::Bond*>(c));
    else if (c->type == cp::Component::MM)
        return visitComponent(dynamic_cast<mm::MoneyMarket* >(c));
    else if (c->type == cp::Component::ACCOUNT)
        return visitComponent(dynamic_cast<Account* >(c));
    else
        return visitComponent(dynamic_cast<Portfolio* >(c));
}

double PricingVisitor::visitComponent(stock::Stock* sc)
{
    return sc->getValue();
}
double PricingVisitor::visitComponent(mm::MoneyMarket* sc)
{
    return sc->getValue();
}
double PricingVisitor::visitComponent(bond::Bond* sc)
{
    return sc->getValue();
}
double PricingVisitor::visitComponent(Portfolio* sc)
{
    //create an Iterator
    //iterate through the PortfolioList
    //as long as the list is not emply recursively call visitComponent passing in the ith element in the PortfolioList and keep adding the sum and return it
    double totalvalue = 0;
    PortfolioIterator* PI = new PortfolioIterator();
    if(!(PI->isNotEmpty(sc)))
    {
        return 0.0;
    }
    while ((PI->isNotEmpty(sc)))
    {
        totalvalue = visitComponent(PI->first(sc));
        while(!(PI->isDone(sc)))
        {
            totalvalue += visitComponent(PI->next(sc));
        }
        sc->setSum(totalvalue);
        return totalvalue;
    }
}
double PricingVisitor::visitComponent(Account* sc)
{
    double totalvalue = 0;
    PortfolioIterator* PI = new PortfolioIterator();
    totalvalue = visitComponent(PI->first(sc));
    while(!(PI->isDone(sc)))
    {
        totalvalue += visitComponent(PI->next(sc));
    }
    sc->setSum(totalvalue);
    return totalvalue;
    
    //create an Iterator
    //iterate through the AccountList
    //as long as the list is not emply recursively call visitComponent passing in the ith element in the AccountList and return the sum
    
}
