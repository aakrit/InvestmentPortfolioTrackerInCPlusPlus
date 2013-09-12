//
//  Portfolio.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Portfolio.h"

Portfolio::Portfolio(std::string name)
{
    type = PORTFOLIO;
    setName(name);
    std::cout << "Creating new Portfolio with name: " << name << std::endl;
}

void Portfolio::printList()
{
    if(PortfolioList.empty())
    {
        std::cout << "This Portfolio is currently Empty!" << std::endl;
    }
    else
    {
        std::cout << this->getName() << " has following Components: " << std::endl;
        for (auto& x : PortfolioList)
        {
            std::cout << x->getName(); std::cout << std::endl;
        }
    }

}

void Portfolio::addComponent(Component *p)
{
    std::cout << "Adding " << p->getName() << " to " << this->getName() << std::endl;
    PortfolioList.push_back(p);
    //std::cout << "Total items in " << this->getName() << ": " << PortfolioList.size(); std::cout << std::endl << std::endl;
}

void Portfolio::deleteComponent(Component *p)
{
    if(this->PortfolioList.empty())
    {
        std::cout << "This Portfolio is already empty!" << std::endl;
    }
    else
    {
        if(dynamic_cast<Portfolio*>(p))
        {
            if(std::find(PortfolioList.begin(), PortfolioList.end(), p) != PortfolioList.end())
            {
                std::vector<cp::Component*>::iterator it = std::find(PortfolioList.begin(), PortfolioList.end(), p);
                std::cout << "Removing Portfolio " << p->getName() << " from " << this->getName() << std::endl;
                this->PortfolioList.erase(it);
            }
            else
            {
                std::cout << "This Portfolio is not in " << this->getName() << std::endl;
            }
        }
        else if (dynamic_cast<Account*>(p))
        {
            if(std::find(PortfolioList.begin(), PortfolioList.end(), p) != PortfolioList.end())
            {
                std::vector<cp::Component*>::iterator it = std::find(PortfolioList.begin(), PortfolioList.end(), p);
                std::cout << "Removing Account " << p->getName() << " from " << this->getName() << std::endl;
                this->PortfolioList.erase(it);
            }
            else
            {
                std::cout << "This Account is not in " << this->getName() << std::endl;
            }
        }
        else
        {
            std::cout << "ERROR: can only Portfolios and Accounts" << std::endl;
        }
    }
}
double Portfolio::Portfolio::acceptVisitor(PricingVisitor *p)
{
    return p->visitComponent(this);
}
std::vector<cp::Component *>* Portfolio::getList()
{
    return &this->PortfolioList;
}

double Portfolio::getCurrentValue()
{
    if (sum == 0)
    {
        std::cout << "Please use the PricingVisitor and Pricing Iterator to determine the total value of your account" << std::endl;
    }
    //once the pricing visitor runs it will set the value of the profolio in the sum variable so we can return it with getCurrentValue rather than having to reiterate
    return sum;
}
void Portfolio::setSum(double d)
{
    sum = d;
}