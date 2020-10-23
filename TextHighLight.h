#ifndef TEXTHIGHLIGHT_H
#define TEXTHIGHLIGHT_H

class TextHighLight {
 public:
    TextHighLight();
    TextHighLight(const int start, const int length);
    int getPosition() const;
    int getLength() const;
    void setPosition(const int position);
    void setLength(const int length);
 private:
    int position;
    int length;
};

#endif // TEXTHIGHLIGHT_H