#include <iostream> 
#include <string> 
using namespace std;
#include "StringEditor.h"

int main() { 
    StringEditor my_ed;
    std::ifstream file_in("input.txt"); 
    std::ofstream file_out("output.txt");

    if (file_in.is_open() && file_out.is_open())
    {
        while (file_in)
        {
            file_in >> my_ed;
		my_ed.edit (); 
		file_out << my_ed;
        }
    }
return 0;
}
