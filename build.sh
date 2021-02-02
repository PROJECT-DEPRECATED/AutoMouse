project_name=automouse
version=3.0v

if [ "build" == "$1" ]; then
    echo clear directory....
    rm -rf build/

    echo compiling...
    gcc src/$project_name.c -o src/$project_name-$version.exe

    mkdir build/
    mv src/$project_name-$version.exe build/
else
    echo "Invalid argument! $1"
fi