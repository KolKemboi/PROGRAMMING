#include "ftxui/screen/color.hpp"
#include <cstdint>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <functional>
#include <string>
#include <vector>

using namespace ftxui;

Component Wrap(std::string name, Component component) {
  return Renderer(component, [name, component] {
    return hbox({
               text(name) | size(WIDTH, EQUAL, 8),
               separator(),
               component->Render() | xflex,
           }) |
           xflex;
  });
}

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  uint32_t left_size = 40;
  uint32_t top_size = 5;
  uint32_t top_line_size = 1;
  uint32_t line_size = 1;
  uint32_t bottom_size = 5;

  // int radiobox_selected = 0;
  // std::vector<std::string> radiobox_entries = {"Choice_A"};
  const std::vector<std::string> menu_entries = {
      "Song 1", "Song 2", "Song 3", "Song 4", "Song 5",
      "Song 6", "Song 7", "Song 8", "Song 9", "Song 10",
  };
  int menu_selected = 0;
  auto menu = Menu(&menu_entries, &menu_selected);
  menu = Wrap("ITZY", menu);
  // menu = FlexboxConfig::Wrap::Wrap("Menu", menu);

  int slider_value = 50;
  auto slider = Slider("Slider: ", &slider_value, 0, 100, 1);

  std::string text_input = "";
  auto input = Input(&text_input, "Song Search");

  auto middle_container = Container::Vertical({});
  auto left_container = Container::Vertical({
      input,
      menu,
  });
  auto line_container = Container::Vertical({slider});
  auto bottom_container = Container::Vertical({});
  auto top_container = Container::Vertical({});
  auto top_line_container = Container::Vertical({});

  auto middle_renderer = Renderer(middle_container, [&] {
    return vbox({
        text("Audio Visualizer") | bold | center,
    });
  });

  auto left_renderer = Renderer(left_container, [&] {
    return vbox({
        text("Queue") | bold | center,
        separator(),
        input->Render(),
        separator(),
        menu->Render(),
    });
  });

  auto line_renderer = Renderer(line_container, [&] {
    return dbox({// text("Line Container") | bold | center,
                 // separator(),
                 slider->Render(), 
			text("ON TOP") | center});
  });

  auto bottom_renderer = Renderer(bottom_container, [&] {
    return vbox({
        text("-77.82 X -78.29") | bold | center,
    });
  });

  auto top_renderer = Renderer(top_container, [&] {
    return vbox({
        text("KolPlayer") | bold | center,
    });
  });
  auto top_line_renderer = Renderer(top_line_container, [&] {
    return vbox({
        text("Current Track") | bold | center,
    });
  });

  // CHANGE 1: Create ONE container that has ALL interactive components
  auto interactive_container = Container::Vertical({
      left_container, // Has input (interactive)
      line_container, // Has slider (interactive)
  });

  // CHANGE 2: Use interactive_container to create the layout_renderer
  auto layout_renderer = Renderer(interactive_container, [&] {
    auto top_panel =
        top_renderer->Render() | size(HEIGHT, EQUAL, top_size) | frame;

    auto middle_panel = middle_renderer->Render() | frame | flex;

    auto left_panel =
        left_renderer->Render() | size(WIDTH, EQUAL, left_size) | frame;

    auto line_panel =
        line_renderer->Render() | size(HEIGHT, EQUAL, line_size) | frame;

    auto bottom_panel =
        bottom_renderer->Render() | size(HEIGHT, EQUAL, bottom_size) | frame;

    auto top_line_panel = top_line_renderer->Render() |
                          size(HEIGHT, EQUAL, top_line_size) | frame;

    return vbox({top_panel, separator(), top_line_panel, separator(),
                 hbox({left_panel, separator(), middle_panel | flex}) | flex,
                 separator(), line_panel, separator(), bottom_panel});
  });

  // CHANGE 3: Pass layout_renderer to screen.Loop
  screen.Loop(layout_renderer);
}
