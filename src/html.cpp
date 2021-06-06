#include "../include/html.h"

std::string Html::head;
std::string Html::bodyEnd;
Html::Html()
{
    createHead();
    createEnd();
}

/*
 * Get text for specific column and index
 */
std::string Html::get(const std::string& col_name, int index)
{
    return this->table[col_name][index];
};

/*
 * Set text to the HTML table
 */
void Html::set(const std::string& name, const std::string& text)
{
    if(this->table.find(name) == this->table.end())
    {
        this->col_name.push_back(name);
    }
    this->table[name].push_back(text);
};

/*
 * Get the table size
 */
int Html::getSize()
{
    return this->size;
}

/*
 * Set the table size
 */
void Html::setSize(int size)
{
    this->size = size;
}

/*
 * Get all column name
 */
std::vector<std::string> Html::getColName()
{
    return this->col_name;
}

/*
 * Save file if need to be
 */
void Html::saveFile(const std::string& filepath)
{
    std::ofstream output;
    output.open(filepath);
    //create head
    output << "<!DOCTYPE html>" << std::endl;
    output << "<html>" << std::endl;
    output << "<head>" << std::endl;
    output << "<meta charset=\"utf-8\">" << std::endl;
    output << "<title>xmltohtml</title>" << std::endl;
    output << "</head>" << std::endl;
    
    //create body
    output << "<body>" << std::endl;
    output << "<table border=\"1\">" << std::endl;
    
    //create table
    output << "<tr>" << std::endl;
    for(auto col : this->col_name)
    {
        output << "<th>" << col << "</th>" << std::endl;
    }
    output << "</tr>" << std::endl;
    
    for(int i=0;i<this->size;i++)
    {
        output << "<tr>" << std::endl;
        for(auto col : this->col_name)
        {
            output << "<td>" << this->table[col][i] << "</td>" << std::endl;
        }
        output << "</tr>" << std::endl;
    }
    
    //end body
    output << "</table>" << std::endl;
    output << "</body>" << std::endl;
    output << "</html>" << std::endl;
    
    output.close();
    
}

/*
 * Convert map content to HTML format table
 */
std::vector<std::string> Html::toTable()
{
    std::vector<std::string> table;
    
    //create table head
    std::string head;
    head += "<tr>\n";
    for(auto col : this->col_name)
    {
        head += "<th>" + col + "</th>\n";
    }
    head += "</tr>\n";
    table.push_back(head);
    
    //create table row
    for(int i=0;i<this->size;i++)
    {
        std::string row;
        row += "<tr>\n";
        for(auto col : this->col_name)
        {
            row += "<td>" + this->table[col][i] + "</td>\n";
        }
        row += "</tr>\n";
        table.push_back(row);
    }
    
    return table;
}

/*
 * Create default HTML head info
 */
void Html::createHead()
{
    //create head
    head += "<!DOCTYPE html>\n";
    head += "<html>\n";
    head += "<head>\n";
    head += "<meta charset=\"utf-8\">\n";
    head += "<title>xmltohtml</title>\n";
    head += "</head>\n";
    
    //create body
    head += "<body>\n";
    head += "<table border=\"1\">\n";
}

/*
 * Create default HTML end info
 */
void Html::createEnd()
{
    //end body
    bodyEnd += "</table>\n";
    bodyEnd += "</body>\n";
    bodyEnd += "</html>\n";
}

