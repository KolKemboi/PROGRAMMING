#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void alg();
void callback(const std::function<void()>& callback);

int main()
{
    int factor = 10;

    auto mul = [&factor](int a)
    {
        return factor * a;
    };

    int var = mul(10);
    std::cout << var << std::endl;

    alg();

    callback([]() {
        std::cout << "callBacked" << std::endl;
    });

}

void callback(const std::function<void()>& callback)
{
    callback();
}


void alg()
{
    std::vector<int> numbers = {3, 2, 3, 4, 5, 1, 0};

    std::sort(numbers.begin(), numbers.end(), [](int a, int b)
    {
        return a < b;
    });

    for (int num: numbers)
    {
        std::cout << num << " ";
    }
}