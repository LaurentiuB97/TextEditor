#ifndef TEXTHIGHLIGHT_H
#define TEXTHIGHLIGHT_H
#include <string>
#include <iostream>
class TextHighLight {
 public:
    TextHighLight();
    TextHighLight(const int start, const int length);
    int getPosition() const;
    int getLength() const;
    void setPosition(const int position);
    void setLength(const int length);
    const std::string print();
    //bool operator==(const TextHighLight &highlight1,const TextHighLight &highlight2);
    bool equals(const TextHighLight &highlight) const;
 private:
    int position;
    int length;
};

#endif // TEXTHIGHLIGHT_H
