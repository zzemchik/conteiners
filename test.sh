g++ --std=c++98 main.cpp test/test_vector.cpp test/map_test.cpp test/set_test.cpp test/stack_test.cpp
./a.out > ivan
g++ --std=c++98 main.cpp test/test_vector.cpp test/map_test.cpp test/set_test.cpp test/stack_test.cpp -D STD
./a.out > std
diff std ivan