#ifndef STRINGEDITOR_H
#define STRINGEDITOR_H

#include <string>

class StingEditor {
    private:
        std::string name;
        int age;

    public: StringEditor();
        StringEditor(std::string n, int a);
        void setName(std::string n);
        void setAge(int a);
        std::string getName();
        int getAge();
    public: edit(){
        file_in;
        file_out;
    }
    
};

#endif