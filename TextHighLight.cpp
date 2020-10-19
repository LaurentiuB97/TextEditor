#include <TextHighLight.h>

TextHighLight::TextHighLight() {}
TextHighLight::TextHighLight(const int start, const int length) {
    this->position = start;
    this->length = length;
}

bool operator== (TextHighLight highlight) {
    return (position == highlight.getPosition() && (length == highlight.getLength()));
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