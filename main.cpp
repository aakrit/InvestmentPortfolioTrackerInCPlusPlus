//
//  main.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include <iostream>
#include <string>
#include "PortfolioManager.h"

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Welcome to creating your financial portfolio process" << endl;
    cout << "Each portfolio can have one or more portfolios and one or more accounts, and in each account you can buy Stocks, Bonds, and or MoneyMarket." << endl << endl;
    
    //I will have my portfolio manager do everything and have not created any Gui since the assignment said we didn't to implement one
    
    PortfolioManager::createAndInspectEntirePortfolio();
    
    
    cout << endl << endl;
    cout << "This concludes the Program!" << endl;

    return 0;
}

