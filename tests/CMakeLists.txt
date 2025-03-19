include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    tests
    tests_min_dist.cpp
    ${PROJECT_SOURCE_DIR}/src/min_dist.cpp
)

target_include_directories(tests PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(
    tests
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(tests)