#ifndef MYHEADER_H
#define MYHEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class StringEditor
{
    private:
        std::string str;
        std::vector<std::string> longest_repeats;

    public:
        StringEditor() {};
        void edit();
        friend std::ifstream& operator>>(std::ifstream &file_in, StringEditor &my_ed);
        friend std::ofstream& operator<<(std::ofstream &file_out, const StringEditor &my_ed);
};

void StringEditor::edit()
{
    std::string new_str = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str[i + 1])
        {
            new_str += str[i];
        }
        else
        {
            int repeat_len = 1;
            for (int j = i + 1; j < str.size(); j++)
            {
                if (str[j] == str[i])
                {
                    repeat_len++;
                }
            }
            if (repeat_len > longest_repeats.size())
            {
                longest_repeats.clear();
                longest_repeats.push_back(str.substr(i, repeat_len));
            }
            else if (repeat_len == longest_repeats.size())
            {
                longest_repeats.push_back(str.substr(i, repeat_len));
            }
            i += repeat_len - 1;
        }
    }
    str = new_str;
}

std::ifstream& operator>>(std::ifstream &file_in, StringEditor &my_ed)
{
    std::getline(file_in, my_ed.str);
    return file_in;
}

std::ofstream& operator<<(std::ofstream &file_out, const StringEditor &my_ed)
{
    file_out << my_ed.str << std::endl;
    if (my_ed.longest_repeats.empty())
    {
        file_out << "Longest Repeating Sequences: NA" << std::endl;
    }
    else
    {
        file_out << "Longest Repeating Sequences: ";
        for (const auto &repeat : my_ed.longest_repeats)
        {
            file_out << repeat << " ";
        }
        file_out << std::endl;
    }
    return file_out;
}

#endif 