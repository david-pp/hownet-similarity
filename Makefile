src=main.cpp sentiment.cpp similarity.cpp
app=main

all: sim

cygwin: $(src)
	g++ $(src) -g -lpthread -L./lib -lNLPIR -I./include -DOS_LINUX  -o ./app/$(app)

sim : similarity.cpp
	g++ similarity.cpp -D_TEST_SIMILARITY -o ./similarity

test : sim
	sh test/sim_test_1.sh; \
	sh test/sim_test_2.sh