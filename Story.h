#pragma once

#include <string>

using std::string;

enum StoryEvent {
    INTRODUCTION,
    LOCATION_ENTERED,
    CHARACTER_FOUND,
    OBJECT_EXAMINED,
    OBJECT_ALREADY_EXAMINED,
    OBJECT_CLOSED,
    OBJECT_LOCKED,
    ITEM_FOUND,
    NOTHING_FOUND,
    LEAVING_PLACE,
    DAMAGE_RECEIVED,
    ACTION_COMPLETED,
    ACTION_FAILED,
    ENDING
};

class Story {
public:
    void show(StoryEvent event, string detail = "");
};