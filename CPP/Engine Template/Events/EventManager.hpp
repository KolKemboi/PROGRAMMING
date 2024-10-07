#pragma once
#include <vector>
#include "events.hpp"

class EventManager
{
    void Dispatch(Event& event);
    void AddListenet(Event* listener)
private:
    s}