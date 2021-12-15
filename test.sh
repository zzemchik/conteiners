clang++ main.cpp test/test_vector.cpp
./a.out > ivan
clang++ main.cpp test/test_vector.cpp -D STD
./a.out > std
diff std ivan