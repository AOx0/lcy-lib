cmake_minimum_required(VERSION 3.21)
project(test)

include(FetchContent)
# Agregamos corrosion para compilar rust por default
FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.2.1 # Optionally specify a commit hash, version tag or branch here
)

FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH Cargo.toml)

add_executable(test test.cpp)
target_link_libraries(test PUBLIC lcy_lib_c)