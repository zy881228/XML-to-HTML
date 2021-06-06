#ifndef _XML_CONVERTER_
#define _XML_CONVERTER_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <errno.h>
#include <fstream>
#include <sys/stat.h>

#include "../library/tinyxml2.h"
#include "html.h"

using namespace tinyxml2;
class Xml
{
private:
    std::string file_path;
    XMLDocument doc;
    Html htmlDoc;
public:
    Xml() = default;
    Xml(const char* path): file_path(path){};
    
    bool parse(const char* path);
    void buildHtml();
    bool saveFile(const std::string& path, const std::string& fileName);
};

#endif

