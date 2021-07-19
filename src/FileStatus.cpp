// Copyright 2021 Bobocea Laurentiu
#include "FileStatus.h"
#include <QDebug>
FileStatus::FileStatus() {}
FileStatus::FileStatus(QFile *file) { this->file = file;}
FileStatus::~FileStatus() {
    file->close();
}
void FileStatus::setFile(QFile *file) {this->file = file;}
QFile* FileStatus::getFile() {return file;}
void FileStatus::setChangeStatus(bool changed) { this->changed = changed;}
bool FileStatus::hasChanges() {return changed;}
