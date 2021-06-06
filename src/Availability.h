#ifndef AVAILABILITY_H
#define AVAILABILITY_H
#include <QObject>
class Availability: public QObject {
    Q_OBJECT
public:
    Availability(QObject * parent = nullptr);
    void setAvailabilityStatus(bool status);
    bool getAvailabilityStatus();

private:
    ~Availability();
    bool availabilityStatus;
};
#endif //AVAILABILITY_H
