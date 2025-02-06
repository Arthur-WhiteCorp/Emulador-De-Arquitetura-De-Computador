cmake_minimum_required(VERSION 3.28.3)
project(Emulador-De-Arquitetura-De-Computador)

message(STATUS "CMake source directory: ${CMAKE_SOURCE_DIR}")
message(STATUS "Project source directory: ${CMAKE_SOURCE_DIR}")

if(NOT UNIX)
  message(WARNING "Unsupported operating system")
endif()


include_directories(
  ${PROJECT_SOURCE_DIR}/headers
  ${PROJECT_SOURCE_DIR}/third-party/nlohmann-json/include/nlohmann
)

add_subdirectory(${PROJECT_SOURCE_DIR}/third-party/nlohmann-json)



set(project_SRC 
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/Machine.cpp
  ${PROJECT_SOURCE_DIR}/src/MachineDescriptionParser.cpp
  ${PROJECT_SOURCE_DIR}/src/MachineDescription.cpp
  ${PROJECT_SOURCE_DIR}/src/MachineDescriptionValidator.cpp
  ${PROJECT_SOURCE_DIR}/src/BinaryUtils.cpp
)

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

