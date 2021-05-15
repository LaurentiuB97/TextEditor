#ifndef FILESTATUS_H
#define FILESTATUS_H
#include <QObject>
#include <QFile>
class FileStatus : public QObject{
    Q_OBJECT
public:
    FileStatus();
    FileStatus(QFile *file);

    void setFile(QFile *file);
    QFile* getFile();
    void setChangeStatus(bool changed);
    bool hasChanges();
private:
    QFile* file;
    bool changed = false;
    ~FileStatus();
};

#endif // FILESTATUS_H
