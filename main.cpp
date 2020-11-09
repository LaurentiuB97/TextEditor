#include "WindowForm.h"
// #include "StringManipulator.h"
// #include "TextHighLight.h"
// #include "PunctuationMark.h"
// #include "Utils.h"
#include <QApplication>
// #include <iostream>
// #include <string>


int main(int argc, char *argv[]){
    QApplication app(argc, argv);  
    WindowForm window;
    window.setFixedSize(1900,980);
    window.setWindowTitle("TextEditor");
    window.show();
  return app.exec();
}