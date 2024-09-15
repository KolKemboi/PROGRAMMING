#include <iostream>
#include <vector>

//we have a file somewhere
unsigned int pos[] = {1, 2, 3, 4, 5, 6, 7};
//end of file somewhere

struct vertices
{
    std::vector<unsigned int> data;
};


class Mesh
{
private:
    std::vector<unsigned int> vertices;
public:
    Mesh(std::vector<unsigned int>& indices)
    {
        this->vertices = indices;
    }
    ~Mesh()
    {
        std::cout << this->vertices.data() << std::endl;
        std::cout << this->vertices.size() * sizeof(unsigned int) << std::endl;
    }
};

//This is the Assimp importer part
Mesh filldata(unsigned int poses[])
{
    std::vector<unsigned int> outData;

    for (unsigned int i = 0; i < 7; i++)
    {
        outData.push_back(poses[i]);
    }
    return Mesh(outData);
}


int main(int argc, const char** argv) {

    filldata(pos);
    return 0;
}