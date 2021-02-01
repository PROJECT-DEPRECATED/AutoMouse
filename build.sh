project_name=automouse
version=2.0v

function build() {
    echo compiling...
    gcc src/$project_name.c -o src/$project_name-$version.exe

    mkdir build/
    mv src/$project_name-$version.exe build/
}

function clean() {
    echo clear directory....
    rm -rf build/
}

if [ "build" == "$1" ]; then
    build()

elif [ "clean" == "$1" ]; then
    clean()

    if [ "build" == "$2" ]; then
        build()
    fi

else
    echo "Invalid argument! $1 $2"
fi
