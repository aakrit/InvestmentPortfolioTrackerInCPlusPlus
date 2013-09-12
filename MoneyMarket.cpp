//
//  MoneyMarket.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "MoneyMarket.h"

mm::MoneyMarket::MoneyMarket(std::string name, double deposit): interestRate(0.02)
{
    type = MM;
    setName(name);
    setValue(deposit);
   // std::cout << "Creating new MoneyMarket with name: " << this->getName() << " with current price: $" << this->getValue() << std::endl;
}
mm::MoneyMarket::~MoneyMarket()
{
    std::cout << "Destroying MoneyMarket Account: " << this->getName() << std::endl;
}
void mm::MoneyMarket::addComponent(Component *p)
{
    std::cout << "Cannot add Components to MoneyMarket" << std::endl;
}
void mm::MoneyMarket::deleteComponent(Component *p)
{
    ; //Do Nothing
}
double mm::MoneyMarket::acceptVisitor(PricingVisitor *p)
{
    return p->visitComponent(this);
}
void mm::MoneyMarket::setBalance(double p)
{
    setValue(p);
}


double mm::MoneyMarket::getCurrentValue()
{
//    years = (time(0) - years);
    int n = 0;
    std::cout << "How many years have you been banking with us? " << std::endl;
    std::cin >> n;
    years = n;
    updateBalane();
    std::cout << "The balance in your account is: $" << getValue() << std::endl;
    return getValue();
}
void mm::MoneyMarket::updateBalane()
{
    double balance = getValue();
    balance = (balance*(pow(1+interestRate, years)));
    setValue(balance);
}
