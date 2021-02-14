cmake_minimum_required(VERSION 3.10)

set(SOLID_EXEMPLE_HEADERS
    include/solid_exemple_lib/world.h
    include/solid_exemple_lib/save_manager.h

    # Item
    include/solid_exemple_lib/items/item.h
    
    # Character
    include/solid_exemple_lib/characters/entity_stats.h
    include/solid_exemple_lib/characters/character.h

    # NPCS
    include/solid_exemple_lib/characters/npcs/npc_abilities.h
    include/solid_exemple_lib/characters/npcs/npc_types.h

    # attributes
    include/solid_exemple_lib/attributes/attribute.h
    include/solid_exemple_lib/attributes/agility.h
    include/solid_exemple_lib/attributes/intelligence.h
    include/solid_exemple_lib/attributes/strenght.h
    "include/solid_exemple_lib/requirement.h"
     "include/solid_exemple_lib/factions/faction.h")

set(SOLID_EXEMPLE_SOURCES
    src/world.cpp
    src/save_manager.cpp
    # Character
    src/characters/entity_stats.cpp
    src/characters/character.cpp
    # attributes
    src/attributes/attribute.cpp
    "src/requirement.cpp"
     "src/items/item.cpp" "src/characters/npcs/npc_types.cpp")

add_library(solid_exemple_lib STATIC ${SOLID_EXEMPLE_HEADERS} ${SOLID_EXEMPLE_SOURCES} "src/items/item.cpp")

target_include_directories(solid_exemple_lib INTERFACE include)
target_include_directories(solid_exemple_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)