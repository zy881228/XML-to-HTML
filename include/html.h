#ifndef _HTML_TABLE_
#define _HTML_TABLE_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <map>
#include <errno.h>
#include <fstream>


class Html
{
private:
    std::map<std::string, std::vector<std::string>> table;
    std::vector<std::string> col_name;
    int size;
    
    //Since for every instance we need the same head and bodyend
    static std::string head;
    static std::string bodyEnd;
    
public:
    Html();
    
    std::string get(const std::string& col_name, int index);
    void set(const std::string& name, const std::string& text);
    int getSize();
    void setSize(int size);
    std::vector<std::string> getColName();
    
    void saveFile(const std::string& filepath);
    std::vector<std::string> toTable();
    
    static void createHead();
    static void createEnd();

    std::string Head(){return head;};
    std::string End(){return bodyEnd;};
};

#endif

