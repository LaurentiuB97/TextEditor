#include "PunctuationMark.h"
std::vector<QChar> const PunctuationMark::marks{'.',',','!','?','(',')','[',']','{','}',':'};


bool PunctuationMark::isMark(const QChar &character) {
   for(auto mark : marks ) {
      if(character == mark) {
         return true;
      }
   }
   return false;
}
std::vector<int> PunctuationMark::findAllMarks(const QString &text) {
   std::vector<int> results;
   for(int i = 0; i < text.count(); ++i) {
      if(isMark(text[i])) {
         results.push_back(i);
      }
   }
   return results;
}

std::vector<int> PunctuationMark::searchFor(const QChar &mark, const QString &text) {
   std::vector<int> results;
   for(int i = 0; i < text.count(); ++i) {
      if(mark == text[i]) {
         results.push_back(i);
      }
   }
   return results;
}
