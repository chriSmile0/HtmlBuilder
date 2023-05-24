cmake_minimum_required(VERSION 3.25)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(HtmlBuilder LANGUAGES CXX)

add_executable(htmlbuilder src/projet.cpp)
target_sources(htmlbuilder PRIVATE src/projet.cpp
					
			
							)


IF (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
ENDIF()

