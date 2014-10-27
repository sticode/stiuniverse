cmake_minimum_required(VERSION 2.8)
project(StiUniverse)
set(SOURCE_FILES main.cpp
			AssetGenerator.cpp
			BatVessel.cpp
			BigOrangeMissile.cpp
			GameActionFactory.cpp
			GameOverlay.cpp
			GreenMissile.cpp
			MainMenuState.cpp
			MainState.cpp
			MissileFactory.cpp
			MissileThrower.cpp
			OptionMenuState.cpp
			RedMissile.cpp
			SpaceHud.cpp
			SpaceMapFile.cpp
			SpaceObject.cpp
			SpaceVessel.cpp
			UDefinition.cpp
			UnitMovementAction.cpp
			UObject.cpp
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} mingw32 ${SDL2main} ${SDL2} ${SDL2_image} ${SDL2_ttf} ${SDL2_net} ${SDL2_gfx} ${StiGame})
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} ${SDL2main} ${SDL2} ${SDL2_image} ${SDL2_ttf} ${SDL2_net} ${SDL2_gfx} ${StiGame})
endif(WIN32)

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
