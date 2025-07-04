#pragma once
#include "shad.h"

class Mesh
{
public:
    
    Mesh(std::shared_ptr<std::string> shaderName)
    {
         this->m_mesh_string = shaderName;

         this->shader = std::make_shared<Shader>(this->m_mesh_string);

         this->shader->outStringName();
    }

private:
    std::shared_ptr<std::string> m_mesh_string;
    std::shared_ptr<Shader> shader;
};