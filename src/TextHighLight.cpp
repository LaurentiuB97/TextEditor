#include "TextHighLight.h"
TextHighLight::TextHighLight() {}
TextHighLight::TextHighLight(const int start, const int length) {
    this->position = start;
    this->length = length;
}

bool TextHighLight::equals( const TextHighLight &highlight) const {
    return (this->position == highlight.getPosition() &&
            (this->length == highlight.getLength()));
}

const std::string TextHighLight::print() {
    return "pos: " + std::to_string(position) + ", length: " + std::to_string(length);
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
