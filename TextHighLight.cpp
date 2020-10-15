#include <TextHighLight.h>


TextHighLight::TextHighLight(const int start, const int length) {
    this->position = start;
    this->length = length;
}
TextHighLight::int getPosition() const {
    return position;
}
TextHighLight::int getLength() const {
    return length;
}
TextHighLight::void setPosition(const int position) {
    this->position = position;
}
TextHighLight::void setLength(const int length) {
    this->length = length;
}