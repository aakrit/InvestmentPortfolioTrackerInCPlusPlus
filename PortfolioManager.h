//
//  PortfolioManager.h
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __OODesign_Lab1Deliverable__PortfolioManager__
#define __OODesign_Lab1Deliverable__PortfolioManager__

#include <iostream>
#include "Portfolio.h"
#include "PricingVisitor.h"
#include "PortfolioIterator.h"
#include <vector>

class bond::Bond;
class stock::Stock;
class mm::MoneyMarket;

// this will be implemented as a SingleTon Class

class PortfolioManager
{
    static PortfolioManager* instance;
    PortfolioManager();
    
    //I would ideally store Portfolios and Accounts objects in vectors to iterate on but don't have time to implement this without errors
    static std::vector<Portfolio*> PL;
    static std::vector<Account*> AL;

    
public:
    static PortfolioManager* makePortfolioManager();
    ~PortfolioManager();
    Portfolio* buildPortfolio(std::string name);
    Account* buildAccount(std::string name);
    PricingVisitor* createPricingVisitor();
    PortfolioIterator* buildPortfolioIterator();
    static void createAndInspectEntirePortfolio();
};




#endif /* defined(__OODesign_Lab1Deliverable__PortfolioManager__) */
