//
//  Account.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Account.h"
#include "PricingVisitor.h"
#include "Stock.h"
#include "MoneyMarket.h"
#include "Bond.h"


Account::Account(std::string name)
{
    type = ACCOUNT;
    setName(name);
    std::cout << "Creating new Account with name: " << name << std::endl;
}
void Account::printList()
{
    std::cout << this->getName() <<" has following Components: " << std::endl;
    for (auto& x : AccountList)
    {
        std::cout << x->getName() << " with price value $" << x->getValue();
        std::cout << std::endl;
    }
}
void Account::addComponent(cp::Component* p)
{
    std::cout << "Adding " << p->getName() << " to " << this->getName() << std::endl;
    AccountList.push_back(p);
    //std::cout << "Total items in " << this->getName() << ": " << AccountList.size(); std::cout << std::endl << std::endl;
}
void Account::deleteComponent(cp::Component* p)
{
    if(this->AccountList.empty())
    {
        std::cout << "This account is already empty!" << std::endl;
    }
    else
    {
        if(dynamic_cast<stock::Stock*>(p))
        {
            if(std::find(AccountList.begin(), AccountList.end(), p) != AccountList.end())
            {
                std::vector<cp::Component*>::iterator it = std::find(AccountList.begin(), AccountList.end(), p);
                std::cout << "Removing Stock " << p->getName() << " from " << this->getName() << std::endl;
                this->AccountList.erase(it);
            }
            else
            {
                std::cout << "This Stock is not in " << this->getName() << std::endl;
            }
        }
        else if (dynamic_cast<bond::Bond*>(p))
        {
            if(std::find(AccountList.begin(), AccountList.end(), p) != AccountList.end())
            {
                std::vector<cp::Component*>::iterator it = std::find(AccountList.begin(), AccountList.end(), p);
                std::cout << "Removing Bond " << p->getName() << " from " << this->getName() << std::endl;
                this->AccountList.erase(it);
            }
            else
            {
                std::cout << "This Bond is not in " << this->getName() << std::endl;
            }
        }
        else if (dynamic_cast<mm::MoneyMarket*>(p))
        {
            if(std::find(AccountList.begin(), AccountList.end(), p) != AccountList.end())
            {
                std::vector<cp::Component*>::iterator it = std::find(AccountList.begin(), AccountList.end(), p);
                std::cout << "Removing MoneyMarket " << p->getName() << " from " << this->getName() << std::endl;
                this->AccountList.erase(it);
            }
            else
            {
                std::cout << "This MoneyMarket is not in " << this->getName() << std::endl;
            }
        }
        else
        {
            std::cout << "ERROR: can only remove stocks, bonds, or moneymarkets" << std::endl;
        }
    }
}
double Account::acceptVisitor(PricingVisitor* p)
{
    return p->visitComponent(this);
}
std::vector<cp::Component *>* Account::getList()
{
    return &this->AccountList;
}
double Account::getCurrentValue()
{
    return sum;
}
void Account::setSum(double d)
{
    sum = d;
}