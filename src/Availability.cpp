// Copyright 2021 Bobocea Laurentiu
#include "Availability.h"
/// constructorul clasei
Availability::Availability(QObject * parent) {this->setParent(parent);}
/// destructorul clasei
Availability::~Availability() {}
/// seteaza statusul de disponibil/indisponibil pentru celelalte plugin-uri
void Availability::setAvailabilityStatus(bool status) {
    availabilityStatus = status;
}
/// returneaza valoarea statusului de disponibil/indisponibil
bool Availability::getAvailabilityStatus() {return availabilityStatus;}
