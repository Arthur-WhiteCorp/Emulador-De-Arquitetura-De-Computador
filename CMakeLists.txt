cmake_minimum_required(VERSION 3.28.3)
project(Emulador-De-Arquitetura-De-Computador)

message(STATUS "CMake source directory: ${CMAKE_SOURCE_DIR}")
message(STATUS "Project source directory: ${CMAKE_SOURCE_DIR}")


set(ANTLR_JAR_PATH "${CMAKE_SOURCE_DIR}/third-party/antlr-tool/antlr.jar")
set(GRAMMAR_DIR "${CMAKE_SOURCE_DIR}/grammar")
set(GENERATED_DIR "${CMAKE_SOURCE_DIR}/src/antlr-src")




if(NOT UNIX)
  message(WARNING "Unsupported operating system")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ANTLR_BUILD_STATIC TRUE)  

find_package(Java REQUIRED)
if (NOT Java_FOUND)
    message(FATAL_ERROR "Java not found! Please install it using:\n sudo apt install openjdk-21-jdk")
endif()

find_package(glfw3 REQUIRED)
if (NOT glfw3_FOUND)
    message(FATAL_ERROR "GLFW not found! Please install it using:\n  sudo apt install libglfw3-dev")
endif()

find_package(OpenGL REQUIRED)
if (NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found! Please install it using:\n  sudo apt install libgl1-mesa-dev")
endif()

# Collect all generated .cpp files
file(GLOB GENERATED_CPP_FILES "${GENERATED_DIR}/*.cpp")

# Add the generated files to a library
add_library(antlr_generated ${GENERATED_CPP_FILES})



include_directories(
  ${PROJECT_SOURCE_DIR}/headers
  ${PROJECT_SOURCE_DIR}/third-party/nlohmann-json/include/nlohmann
  ${PROJECT_SOURCE_DIR}/third-party/imgui/headers
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/src
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/src/misc
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/src/atn
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/src/dfa
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/src/tree
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/src/support
  ${PROJECT_SOURCE_DIR}/third-party/antlr-runtime/demo/generated
)

add_subdirectory(${PROJECT_SOURCE_DIR}/third-party/nlohmann-json)
add_subdirectory(${PROJECT_SOURCE_DIR}/third-party/antlr-runtime)

file(GLOB project_SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
# Collect .cpp files from the second folder and append them to project_SRC
file(GLOB another_folder_SRC "${PROJECT_SOURCE_DIR}/third-party/imgui/src/*.cpp")
list(APPEND project_SRC ${another_folder_SRC})


if(NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()



foreach(src_file ${project_SRC})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach(src_file ${project_SRC})


add_executable(project
  ${project_SRC}
)


target_link_libraries(project PRIVATE nlohmann_json::nlohmann_json)
# Link GLFW and OpenGL libraries
target_link_libraries(project PRIVATE glfw ${OPENGL_LIBRARIES})
target_link_libraries(project PRIVATE OpenGL::GL)

# Link antlr-runtime
target_link_libraries(project PRIVATE antlr4_static)


