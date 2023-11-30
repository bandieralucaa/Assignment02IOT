PORT="COM4"

rm -r bin

#if (($1 == 1)); then
javac -d bin -cp "bin;lib/jssc-2.9.5.jar" src/comm/*.java
javac -d bin -cp "bin;lib/jssc-2.9.5.jar" src/main/*.java
javac -d bin -cp "bin;lib/jssc-2.9.5.jar" src/*.java
#fi;

java -cp "bin;lib/jssc-2.9.5.jar" Launcher ${PORT}

