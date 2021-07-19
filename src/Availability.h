// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_AVAILABILITY_H_
#define SRC_AVAILABILITY_H_
#include <QObject>
class Availability: public QObject {
    Q_OBJECT
 public:
    explicit Availability(QObject * parent = nullptr);
    void setAvailabilityStatus(bool status);
    bool getAvailabilityStatus();

 private:
    ~Availability();
    bool availabilityStatus;
};
#endif  // SRC_AVAILABILITY_H_
