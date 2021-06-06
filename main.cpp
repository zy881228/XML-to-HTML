/*
Copyright by Yang Zhou
Date: 2021/06/06
Usage: Convert XML file to HTML file as HTML table format.
3rd library: Tinyxml2   https://github.com/leethomason/tinyxml2
Version: Test
*/

#include <iostream>
#include <exception>
#include <fstream>
#include <stdio.h>

#include "include/xml.h"

#define CATALOG_PATH "test/cd_catalog.xml"
#define DEFAULT_OUTPUT "output/"


int main(int argc, char *argv[])
{
    std::cout<<"Xml Converter Start "<<std::endl;
    std::string workDirectory(argv[0]);
    workDirectory = workDirectory.substr(0, workDirectory.length()-15);

    
    // choose option
    while(1)
    {
        std::cout << "\n**********************************"<< std::endl
                  << "* 1. Convert cd_catalog.xml      *" << std::endl
                  << "* 2. Convert customized file     *" << std::endl
                  << "* 3. Quit                        *" << std::endl
                  << "**********************************\n" << std::endl;
        std::cout << "Enter your option: " << std::endl;
        std::string input;
        getline(std::cin, input);

        try{
            switch(stoi(input))
            {
                case 1:
                    {
                        Xml xml;
                        std::string filepath = workDirectory + CATALOG_PATH;
                        if(xml.parse(filepath.c_str()))
                            std::cout<<"Parse sucessful!"<<std::endl;
                        else
                        {
                            std::cout<<"Parse error for file path "<< "\"" << filepath << "\"" << "\nPlease check your input file!"<<std::endl;
                            continue;
                        }
                        
                        xml.buildHtml();
                        std::string output_filepath = workDirectory + DEFAULT_OUTPUT;
                        if(xml.saveFile(output_filepath, "cd_catalog.html"))
                            std::cout<<"Save file sucessfully to " << "\"" << output_filepath << "cd_catalog.html\"" <<std::endl;
                        else
                            std::cout<<"Save file failed!"<<std::endl;
                        
                        break;
                    }
                case 2:
                    {
                        std::cout << "Please enter your file path:" << std::endl;
                        std::string path;
                        getline(std::cin, path);
                        
                        Xml xml;
                        if(xml.parse(path.c_str()))
                            std::cout<<"Parse sucessful!"<<std::endl;
                        else
                        {
                            std::cout<<"Parse error for file path " << "\"" << path << "\"" << "\nPlease check your input file!"<<std::endl;
                            continue;
                        }
                        
                        xml.buildHtml();
                        std::string output_filepath = workDirectory + DEFAULT_OUTPUT;
                        if(xml.saveFile(output_filepath, "output.html"))
                            std::cout<<"Save file sucessfully to " << "\"" << output_filepath << "output.html\"" <<std::endl;
                        else
                            std::cout<<"Save file failed!"<<std::endl;
                        
                        break;
                    }
                case 3:
                    exit(0);
                    break;
                default:
                    {
                        std::cout << "Wrong input, please enter again!" << std::endl;
                        break;
                    }
            }
        } catch (std::exception& e) {
            std::cout << "Exception: "<< e.what() << std::endl;
        }
    
    }
    
    return 0;
}

