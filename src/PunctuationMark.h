// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_PUNCTUATIONMARK_H_
#define SRC_PUNCTUATIONMARK_H_
#include <vector>
#include <QString>
#include <QChar>
class PunctuationMark {
 public:
      static std::vector<QChar> const marks;
      static bool isMark(const QChar &character);
      static std::vector<int> searchFor(const QChar &character,
                                        const QString &text);
      static std::vector<int> findAllMarks(const QString &text);
 private:
      PunctuationMark();
};
#endif  // SRC_PUNCTUATIONMARK_H_
