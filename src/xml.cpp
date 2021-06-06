#include "../include/xml.h"


/*
 * Parse the XML file
 */
bool Xml::parse(const char* path){
    if(XML_SUCCESS != doc.LoadFile(path))
        return false;
    return true;
};

/*
 * Build HTML object which contains HTML table information, size, column name
 * and default HTML head and end structure
 */
void Xml::buildHtml(){
    std::cout<<"Start Build Html... "<<std::endl;
    XMLElement *root = doc.RootElement();
    root = root->FirstChildElement();
    
    int count = 0;
    while(root)
    {
        XMLElement *children = root->FirstChildElement();
        while(children)
        {
            if(children->GetText())
            {
                this->htmlDoc.set(children->Name(), children->GetText());
            }
            children = children->NextSiblingElement();
        }
        root = root->NextSiblingElement();
        count++;
    }
    this->htmlDoc.setSize(count);
    
}

/*
 * Save HTML table as file
 */
bool Xml::saveFile(const std::string& path, const std::string& fileName)
{
    std::string filePath = path + fileName;
    
    //check dirrectory
    struct stat info;
    if( stat(path.c_str(), &info) != 0) mkdir(path.c_str(), 0777);   //create directory if it doesn't exist
   
    std::ofstream myfile;
    myfile.open(filePath);
    if(!myfile) return false;
    
    //save html head
    myfile << this->htmlDoc.Head();
    //save body
    auto table = this->htmlDoc.toTable();
    for(auto row : table)
    {
        myfile << row;
    }
    //save rest
    myfile << this->htmlDoc.End();
    
    myfile.close();
    
    return true;
}



