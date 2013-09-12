//
//  Bond.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Bond.h"
#include "PricingVisitor.h"


bond::Bond::Bond(std::string name, double deposit): interestRate(0.02)
{
    type = BOND;
    setName(name);
    setValue(deposit);
   // std::cout << "Creating new Bond with name: " << this->getName() << " with current price: $" << this->getValue() << std::endl;
}
bond::Bond::~Bond()
{
    std::cout << "Destroying MoneyMarket Account: " << this->getName() << std::endl;
}
void bond::Bond::addComponent(Component *p)
{
    std::cout << "Cannot add Components to Bond" << std::endl;
}
void bond::Bond::deleteComponent(Component *p)
{
    ; //Do Nothing
}
double bond::Bond::acceptVisitor(PricingVisitor *p)
{
    return p->visitComponent(this);
}

void bond::Bond::setBalance(double p)
{
    setValue(p);
}

double bond::Bond::getCurrentValue()
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
void bond::Bond::updateBalane()
{
    double balance = getValue();
    balance = (balance*(pow(1+interestRate, years)));
    setValue(balance);
}
