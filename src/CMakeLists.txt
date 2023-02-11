set(COMPONENTS_SRC components/transform.cpp)

# add_library(components ${COMPONENTS_SRC}) target_compile_options(components
# PRIVATE -Wall -Werror -std=c++17)

set(EXE_SRC main.cpp)

add_executable(enttTest ${EXE_SRC} ${COMPONENTS_SRC})

target_compile_options(enttTest PRIVATE -Wall -Werror -std=c++17)
target_link_libraries(enttTest EnTT::EnTT)
