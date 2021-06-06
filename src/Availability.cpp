#include "Availability.h"

Availability::Availability(QObject * parent){ this->setParent(parent);}
Availability::~Availability(){}
void Availability::setAvailabilityStatus(bool status){ availabilityStatus = status;}
bool Availability::getAvailabilityStatus(){return availabilityStatus;}
