#pragma once

#include "window.h"

class Application
{
public:
    Application();
    ~Application();

    void Run();
    
private:
    bool m_running = true;
    Window* m_window;
};