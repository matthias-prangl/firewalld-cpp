rebuild: clean configure  build
build:
    cmake --build build
configure:
    cmake . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=True -G Ninja
clean:
    rm -rf build
