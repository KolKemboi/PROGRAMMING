#include <functional>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  // Fixed sizes
  const int left_size = 40;
  const int top_size = 5;
  const int bottom_size = 5;
  
  // State variables
  int slider_value = 50;
  std::string text_input = "Type here";
  bool checkbox_value = false;
  int dropdown_selected = 0;
  std::vector<std::string> dropdown_entries = {"Option 1", "Option 2", "Option 3"};
  int radiobox_selected = 0;
  std::vector<std::string> radiobox_entries = {"Choice A", "Choice B", "Choice C"};

  // Create components
  auto slider = Slider("Slider:", &slider_value, 0, 100, 1);
  auto input = Input(&text_input, "placeholder");
  auto checkbox = Checkbox("Check me", &checkbox_value);
  auto dropdown = Dropdown(&dropdown_entries, &dropdown_selected);
  auto radiobox = Radiobox(&radiobox_entries, &radiobox_selected);
  
  auto button1 = Button("Button 1", []{});
  auto button2 = Button("Button 2", []{});
  auto button3 = Button("Button 3", []{});

  // Create containers for different sections
  auto middle_container = Container::Vertical({
    slider,
    input,
    checkbox,
    dropdown,
    radiobox,
    Container::Horizontal({ button1, button2, button3 })
  });

  auto left_container = Container::Vertical({});
  auto top_container = Container::Vertical({});
  auto bottom_container = Container::Vertical({});

  // Create renderers for each section
  auto middle_renderer = Renderer(middle_container, [&] {
    return vbox({
        text("Middle Container") | bold | center,
        separator(),
        hbox(text("Slider: "), text(std::to_string(slider_value))),
        slider->Render(),
        separator(),
        hbox(text("Input: "), input->Render()),
        separator(),
        checkbox->Render(),
        separator(),
        hbox(text("Dropdown: "), dropdown->Render()),
        separator(),
        radiobox->Render(),
        separator(),
        hbox({
          button1->Render(),
          button2->Render(),
          button3->Render()
        }) | center
    }) | border;
  });

  auto left_renderer = Renderer(left_container, [&] {
    return vbox({
        text("Left Panel") | bold | center | color(Color::Blue),
        separator(),
        paragraph("Fixed left panel"),
        separator(),
        vbox({
            text("Item 1"),
            text("Item 2"),
            text("Item 3"),
            text("Item 4")
        }),
        filler(),
        text("Static width: " + std::to_string(left_size)) | dim
    }) | border | bgcolor(Color::Black);
  });

  auto top_renderer = Renderer(top_container, [&] {
    return vbox({
        text("Top Panel") | bold | center | color(Color::Green),
        separator(),
        text("Fixed top panel") | center
    }) | border;
  });

  auto bottom_renderer = Renderer(bottom_container, [&] {
    return vbox({
        text("Bottom Panel") | bold | center | color(Color::Red),
        separator(),
        text("Fixed bottom panel") | center
    }) | border;
  });

  // Create the main layout container
  auto layout_container = Container::Vertical({});
  
  // Wrap each section with fixed size decorators
  auto layout_renderer = Renderer(layout_container, [&] {
    // Apply fixed sizes to each panel
    auto top_panel = top_renderer->Render() 
      | size(HEIGHT, EQUAL, top_size) 
      | frame;
    
    auto left_panel = left_renderer->Render() 
      | size(WIDTH, EQUAL, left_size) 
      | frame;
    
    auto middle_panel = middle_renderer->Render() 
      | flex 
      | frame;
    
    auto bottom_panel = bottom_renderer->Render() 
      | size(HEIGHT, EQUAL, bottom_size) 
      | frame;
    
    // Create the layout
    return vbox({
      top_panel,
      hbox({
        left_panel,
        middle_panel | flex
      }) | flex,
      bottom_panel
    }) | border;
  });

  // Create a container that holds all interactive components
  auto main_container = Container::Vertical({
    middle_container,  // This contains all interactive widgets
    layout_container   // This is just for rendering
  });

  // Focus on the interactive part
  auto focused_container = Container::Tab({
    middle_container,
    layout_container
  }, &radiobox_selected);  // Using radiobox_selected as focus index

  // Final renderer
  auto final_renderer = Renderer(focused_container, [&] {
    return layout_renderer->Render();
  });

  screen.Loop(final_renderer);
}
