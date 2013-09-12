//
//  PortfolioManager.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "PortfolioManager.h"
#include "Stock.h"
#include "Bond.h"
#include "MoneyMarket.h"

using namespace std;

PortfolioManager* PortfolioManager::instance = NULL;

PortfolioManager::PortfolioManager()
{
    std::cout << "We have created a PortfolioManager for you" << std::endl;
}

PortfolioManager* PortfolioManager::makePortfolioManager()
{
    if(instance == NULL)
    {
        instance = new PortfolioManager();
    }
    else
    {
        std::cout << "Error: cannot create more than one instrance of this class";
    }
    return instance;
}

PortfolioManager::~PortfolioManager()
{
    std::cout << "Exiting the ProtfolioManager" << std::endl;
}

Portfolio* PortfolioManager::buildPortfolio(std::string name)
{
    Portfolio* p1 = new Portfolio(name);
    return p1;
}
Account* PortfolioManager::buildAccount(std::string name)
{
    Account* a1 = new Account(name);
    return a1;
}
PricingVisitor* PortfolioManager::createPricingVisitor()
{
    PricingVisitor* pv1 = new PricingVisitor();
    return pv1;
}
PortfolioIterator* PortfolioManager::buildPortfolioIterator()
{

    PortfolioIterator* pv1 = new PortfolioIterator();

    return pv1;
}
void PortfolioManager::createAndInspectEntirePortfolio()
{
    //creating some stocks
    cp::Component* s1 = new stock::Stock("APPL", 500, 1000000);
    cp::Component* s2 = new stock::Stock("GOOG", 800, 1000000);
    cp::Component* s3 = new stock::Stock("MSFT", 40, 1000000);
    cp::Component* s4 = new stock::Stock("YHOO", 25, 10000000);
    
    //creating some money markets
    cp::Component* m1 = new mm::MoneyMarket("mm1", 100);
    cp::Component* m2 = new mm::MoneyMarket("mm2", 150);
    cp::Component* m3 = new mm::MoneyMarket("mm3", 300);
    
    //creating some bonds
    cp::Component* b1 = new bond::Bond("bond1", 30);
    cp::Component* b2 = new bond::Bond("bond2", 40);
    cp::Component* b3 = new bond::Bond("bond3", 50);
    cp::Component* b4 = new bond::Bond("bond4", 10);
    cp::Component* b5 = new bond::Bond("bond5", 20);
    
    PortfolioManager* pm = PortfolioManager::makePortfolioManager();
    cout << "Now lets use the PortfolioManager to build your portfolio " << endl;
    cp::Component* p1 = pm->buildPortfolio("InitialPortfolio");
    //PL.push_back(dynamic_cast<Portfolio*>(p1));
    cout << "Lets create 2 Portfolios and 2 Accounts in your initial Portfolio " << endl << endl;
    cp::Component* p2 = pm->buildPortfolio("Portfolio2");
    //PL.push_back(dynamic_cast<Portfolio*>(p2));
    p1->addComponent(p2);
    cp::Component* p3 = pm->buildPortfolio("Portfolio3");
    //PL.push_back(dynamic_cast<Portfolio*>(p3));
    p1->addComponent(p3);
    cp::Component* a1 = pm->buildAccount("Account1");
    //AL.push_back(dynamic_cast<Account*>(a1));
    p1->addComponent(a1);
    cp::Component* a2 = pm->buildAccount("Account2");
    p1->addComponent(a2);
    
    cout << endl;
    cout << "Lets add some Stocks and Bonds to Account1 " << endl;
    a1->addComponent(s1);
    a1->addComponent(s2);
    a1->addComponent(s3);
    a1->addComponent(b1);
    a1->addComponent(b2);
    cout << endl;
    a1->printList();
    cout << endl;

    cout << "Lets add a Stock, Bond, and MoneyMarket to Account2 " << endl;
    a2->addComponent(s4);
    a2->addComponent(b3);
    a2->addComponent(m1);
    cout << endl;
    a2->printList();
    cout << endl;
    cout << "Lets add two new Accounts in Portfolio 2" << endl;
    cp::Component* a3 = pm->buildAccount("Account3");
    p2->addComponent(a3);
    cp::Component* a4 = pm->buildAccount("Account4");
    p2->addComponent(a4);
    cout << endl;
    p2->printList();
    cout << endl;
    cout << "Lets add some Bonds and MoneyMarket to Account3" << endl;
    a3->addComponent(m2);
    a3->addComponent(m3);
    a3->addComponent(b4);
    a3->addComponent(b5);
    cout << endl;
    a3->printList();
    cout << endl;
    cout << "Lets add some MoneyMarket, Bonds, and Stocks to Account4" << endl;
    a4->addComponent(s1);
    a4->addComponent(b3);
    a4->addComponent(b2);
    a4->addComponent(s4);
    a4->addComponent(m3);
    cout << endl;
    a4->printList();
    cout << endl;
    cout << "Now that your portfolio is created, we can Visit it to get the value in each Portfolio and Account via a PricingIterator and PricingVisitor" << endl;
    cout << endl;
    PricingVisitor* PV = pm->createPricingVisitor();

    p1->printList();
    cout << "The Total value of " << p1->getName() << " is $" << p1->acceptVisitor(PV);
    cout << endl << endl;
    p2->printList();
    cout << "The Total value of " << p2->getName() << " is $" << p2->acceptVisitor(PV);
    cout << endl << endl;
    p3->printList();
    cout << "The Total value of " << p3->getName() << " is $" << p3->acceptVisitor(PV);
    cout << endl << endl;
    
    a1->printList();
    cout << "The Total value of " << a1->getName() << " is $" << a1->acceptVisitor(PV);
    cout << endl << endl;
    a2->printList();
    cout << "The Total value of " << a2->getName() << " is $" << a2->acceptVisitor(PV);
    cout << endl << endl;
    a3->printList();
    cout << "The Total value of " << a3->getName() << " is $" << a3->acceptVisitor(PV);
    cout << endl << endl;
    a4->printList();
    cout << "The Total value of " << a4->getName() << " is $" << a4->acceptVisitor(PV);
    cout << endl << endl;
    
    cout << "Let remove Portfolio3 and Account 2 from InitialPortfolio" <<endl;
    cout << "Currently ";
    p1->printList();
    cout << "And has value: $" << p1->acceptVisitor(PV) ;
    cout << endl <<endl;
    p1->deleteComponent(p3);
    p1->deleteComponent(a2);
    cout << endl;
    cout << "After Removing the items ";
    p1->printList();
    cout << "Lets get the value of " << p1->getName() << " after this deletion: $";
    cout << p1->acceptVisitor(PV) << endl << endl;
    
    cout << "Lets remove a stock, bond, and a monneymarket from Account4" <<endl;
    cout << "Currently ";
    a4->printList();
    cout << "And has value: $" << a4->acceptVisitor(PV) ;
    cout << endl << endl;
    a4->deleteComponent(s1);
    a4->deleteComponent(b2);
    a4->deleteComponent(m3);
    cout << endl;
    cout << "After Removing the items ";
    a4->printList();
    cout << "Lets get the value of " << a4->getName() << " after this deletion: $";
    cout << a4->acceptVisitor(PV) << endl << endl;
    
    
    
    cout << "After calling the Pricing Visitor once on a portfolio to recursively determine its value, we store that value so we don't have to recalculate it for short time periods. The value of the InitialPortfolio is: $"<< p1->getCurrentValue() << endl;
    cout << "After calling the Pricing Visitor once on an Account to recursively determine its value, we store that value so we don't have to recalculate it for short time periods. The value of Account4 is: $"<<a4->getCurrentValue() << endl;

}





