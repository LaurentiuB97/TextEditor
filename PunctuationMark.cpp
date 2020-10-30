#include "PunctuationMark.h"
std::vector<char> const PunctuationMark::marks{'.',',','!','?','(',')','[',']','{','}',':'};
bool PunctuationMark::isMark(const char character) {
   for(auto mark : marks ) {
      if(character == mark) {
         return true;
      }
   }
   return false;
}

std::vector<int> PunctuationMark::findAllMarks(const std::string &text) {
   std::vector<int> results;
   for(int i = 0; i < text.length(); ++i) {
      if(isMark(text[i])) {
         results.push_back(i);
      }
   }
   return results;
}

std::vector<int> PunctuationMark::searchFor(const char mark, const std::string &text) {
   std::vector<int> results;
   for(int i = 0; i < text.length(); ++i) {
      if(mark == text[i]) {
         results.push_back(i);
      }
   }
   return results;
}