#ifndef PUNCTUATIONMARK_H
#define PUNCTUATIONMARK_H
#include <vector>
#include <string>
class PunctuationMark {
 public:
      static std::vector<char> const marks;
      static bool isMark(const char character);
      static std::vector<int> searchFor(const char character, const std::string &text);
      static std::vector<int> findAllMarks(const std::string &text);
 private:
      PunctuationMark();
};
#endif // PUNCTUATIONMARK_H