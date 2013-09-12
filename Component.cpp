//
//  Component.cpp
//  OODesign_Lab1Deliverable
//
//  Created by Aakrit Prasad on 5/3/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Component.h"

std::string cp::Component::getName()
{
    return name;
}

void cp::Component::setName(std::string n)
{
    name = n;
}
void cp::Component::printList()
{
    ;//do Nothing
}
double cp::Component::getValue()
{
    return value;
}

void cp::Component::setValue(double n)
{
    value = n;
}
double cp::Component::acceptVisitor(PricingVisitor* )
{
    return this->getCurrentValue();
}
std::vector<cp::Component *>* cp::Component::getList()
{
    return &cvec;
}
