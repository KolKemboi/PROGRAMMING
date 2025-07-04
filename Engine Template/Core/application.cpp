#include "application.h"
#include <iostream>


Application::Application ()
{
    m_window = new Window(Window::WindowProps("Engine", 400, 400));
    std::cout << "Started" << std::endl;
}

Application::~Application()
{
    delete m_window;
    std::cout << "Application CLosed" << std::endl;
}

void Application::Run()
{
    while (m_running)
    {
        m_window->OnUpdate();

        m_running = false;
    }
}