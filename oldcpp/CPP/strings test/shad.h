#pragma once
#include <string>
#include <memory>
#include <iostream>

class Shader
{
public:
    Shader(std::shared_ptr<std::string> stringName)
    {
        std::cout << "STRING CREATED" << std::endl;
        this->m_stringName = stringName;
    }
    void outStringName()
    {
        std::cout << this->m_stringName << std::endl;
    }
private:
    std::shared_ptr<std::string> m_stringName;
};