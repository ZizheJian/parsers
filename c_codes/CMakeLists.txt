add_library(parsers INTERFACE)

target_include_directories(parsers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(parsers INTERFACE cxx_std_17)
