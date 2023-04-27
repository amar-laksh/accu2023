set(HEADERS ./include/helpers.hpp ./include/ranges_demo.hpp ./include/monads_demo.hpp)
set(HEADERS ./main.cpp)

include_directories(include)
add_executable(main ${SOURCES} ${HEADERS})
