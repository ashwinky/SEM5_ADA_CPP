set windows-powershell := true


mode := "debug"
build_dir := "cmake-build-" + lowercase(mode)


# Remove build and cache files
[windows]
clean:
    -Remove-Item .\cmake-build-*, .\build, .\.idea, .\CMakeCache.txt -ErrorAction SilentlyContinue -Recurse -Force -Confirm:$false

# Remove build and cache files
[unix]
clean:
    -rm -rf ./cmake-build-* ./build ./CMakeCache.txt

[private]
alias rm := clean


# Configure and build project
config: clean && build
    cmake -DCMAKE_BUILD_TYPE={{capitalize(mode)}} -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_CXX_COMPILER=g++ -G Ninja -S . -B ./{{build_dir}}

[private]
alias setup := config


# Build target (default: all targets)
build target='all':
    cmake --build ./{{build_dir}} --config {{capitalize(mode)}} --target {{target}}

[private]
alias b := build


# Test target with CTest (default: all targets)
test target='all': (build target)
    ctest --output-on-failure -C {{capitalize(mode)}} --test-dir ./{{build_dir}} --target {{target}}

[private]
alias t := test


# Run target (default: main.cpp)
run target='main': (build target)
    ./{{build_dir}}/{{target}}

[private]
alias x := run
