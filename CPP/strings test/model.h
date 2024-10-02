#pragma once

#include "mesh.h"

class Model
{
public:
    Model(std::string shadername)
    {
        
    }
private:
    std::shared_ptr<std::string> m_shaderName;

    
    Mesh sendShaderName()
    {
        return Mesh(m_shaderName);
    }
};