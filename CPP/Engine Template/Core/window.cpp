#include <iostream>
#include "window.h"

Window::Window(const WindowProps& props) : m_props(props)
{
    std::cout << "Window Created" << props.Title << std::endl;
}

Window::~Window()
{
    std::cout << "Window Destroyed" << std::endl;
}

void Window::OnUpdate()
{
    std::cout << "Window Updates" << std::endl;
}