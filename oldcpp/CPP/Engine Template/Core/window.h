#pragma once

#include <string>

class Window
{
public:
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string& title = "Engine",
                    unsigned int width = 400,
                    unsigned int height = 400) : Title(title),
                    Width(width), Height(height) {}
    };

    Window(const WindowProps& props);
    ~Window();

    void OnUpdate();
private:
    WindowProps m_props;
};
