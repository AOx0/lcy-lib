default:
  just --list

init:
  cmake -S. -B cmake_build

build: init
  cmake --build cmake_build

build_release: init
  cmake --build cmake_build --config Release

run: build
  ./cmake_build/test

run_release: build_release
  ./cmake_build/test

clean:
  rm -rf cmake_build