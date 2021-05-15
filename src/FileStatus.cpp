#include "FileStatus.h"
#include <QDebug>
FileStatus::FileStatus(){}
FileStatus::FileStatus(QFile *file){this->file = file;}
FileStatus::~FileStatus(){
    file->close();
    qDebug() << "File deleted" << endl;
    qDebug() << "deleted" << endl;
}
void FileStatus::setFile(QFile *file){this->file = file;}
QFile* FileStatus::getFile(){return file;}
void FileStatus::setChangeStatus(bool changed){ this->changed = changed;}
bool FileStatus::hasChanges(){return changed;}
