#include "TextHighLight.h"

TextHighLight::TextHighLight() {}
TextHighLight::TextHighLight(const int start, const int length) {
    this->position = start;
    this->length = length;
}

bool operator== (TextHighLight highlight1, TextHighLight highlight2) {
    return (highlight1.getPosition() == highlight2.getPosition() &&
            (highlight1.getLength() == highlight2.getLength()));
}
int TextHighLight::getPosition() const {
    return position;
}
int TextHighLight::getLength() const {
    return length;
}
void TextHighLight::setPosition(const int position) {
    this->position = position;
}
void TextHighLight::setLength(const int length) {
    this->length = length;
}