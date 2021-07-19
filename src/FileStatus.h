// Copyright 2021 Bobocea Laurentiu
#ifndef SRC_FILESTATUS_H_
#define SRC_FILESTATUS_H_
#include <QObject>
#include <QFile>
class FileStatus : public QObject {
    Q_OBJECT
 public:
    FileStatus();
    explicit FileStatus(QFile *file);

    void setFile(QFile *file);
    QFile* getFile();
    void setChangeStatus(bool changed);
    bool hasChanges();
 private:
    QFile* file;
    bool changed = false;
    ~FileStatus();
};
#endif  // SRC_FILESTATUS_H_
