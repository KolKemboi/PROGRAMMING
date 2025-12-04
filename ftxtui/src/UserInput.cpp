#include "ftxui/component/event.hpp"
#include <cstdint>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <functional>
#include <string>
#include <vector>

using namespace ftxui;

int main() {
  auto layout = Container::Vertical({});

  auto screen = ScreenInteractive::Fullscreen();

  auto component = CatchEvent(layout, [&](Event event) {
    if (event == Event::Escape) {
      screen.Exit();
    }

    return false;
  });

  screen.Loop(component);
}
