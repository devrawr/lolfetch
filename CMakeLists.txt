project(lolfetch)

add_executable(lolfetch main.cpp config.cpp)

find_package(unofficial-curlpp CONFIG REQUIRED)
target_link_libraries(lolfetch PRIVATE unofficial::curlpp::curlpp)
