 #!bin/bash

if [ -f $1 ]; then
    g++ $1 -L./freeglut/lib64 -L./ -lglut -lGLU -lGL -lglpng -lm
    ./a.out
    rm a.out
else
    echo "file not found"
fi
