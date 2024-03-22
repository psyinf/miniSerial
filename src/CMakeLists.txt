project(serialToolKR VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE HEADER_FILES 	CONFIGURE_DEPENDS "*.h*")
file(GLOB_RECURSE CPP_FILES 	CONFIGURE_DEPENDS "*.cpp")

find_package(serial REQUIRED)

add_executable(${PROJECT_NAME}
   ${CPP_FILES}
   ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    serial::serial
    fmt::fmt
)

install(TARGETS ${PROJECT_NAME})