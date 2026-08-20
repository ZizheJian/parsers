add_library(libparsers INTERFACE)
add_library(parsers::parsers ALIAS libparsers)

target_include_directories(libparsers INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/parsers>)

install(TARGETS libparsers)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include/parsers
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.tpp"
)
