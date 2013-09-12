//
//  Stock.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/2/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
#include "Stock.h"
stock::Stock::Stock(std::string name, double price, double maxshares): maxshares(maxshares)
{
    type = STOCK;
    setName(name);
    setValue(price);
    //std::cout << "Creating new stock: " << this->getName() << " with current price: $" << this->getValue() << std::endl;
    
}

stock::Stock::~Stock()
{
    std::cout << "Destroying stock: " << this->getName()<< std::endl;
}

void stock::Stock::addComponent(Component *p)
{
    std::cout << "Cannot add Components to Stock" << std::endl;
}
void stock::Stock::deleteComponent(Component *p)
{
    ;// do nothing
}
double stock::Stock::acceptVisitor(PricingVisitor *p)
{
    return p->visitComponent(this);
}
void stock::Stock::setPrice(double p)
{
    setValue(p);
}

double stock::Stock::getCurrentValue()
{
    return getValue();
}