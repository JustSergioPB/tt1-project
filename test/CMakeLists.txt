cmake_minimum_required(VERSION 3.10)

set(this test)

set(Sources
    linearAlgebraFunctionsTest.c
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    C_project
)

add_test(
    NAME ${This}
    COMMAND ${This}
)