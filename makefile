# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: UtPodDriver.o UtPod.o song.o
	g++ -otest  UtPodDriver.o UtPod.o song.o
UtPodDriver.o: UtPodDriver.cpp
	g++ UtPodDriver.cpp
UtPod.o: UtPod.cpp
	g++ UtPod.cpp
song.o: song.cpp
	g++ song.cpp
