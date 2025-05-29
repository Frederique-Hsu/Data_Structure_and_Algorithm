# File name     : build.sh
# Description   : Build the C code and C++ code in different standard no.
#
#


gcc -std=c99 check_c_standard.c -o check_c_standard
./check_c_standard

gcc -std=c11 check_c_standard.c -o check_c_standard
./check_c_standard

gcc -std=c17 check_c_standard.c -o check_c_standard
./check_c_standard

gcc -std=c2x check_c_standard.c -o check_c_standard
./check_c_standard

gcc check_c_standard.c -o check_c_standard
./check_c_standard

rm -frv check_c_standard

g++ -std=c++98 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ -std=c++03 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ -std=c++11 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ -std=c++14 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ -std=c++17 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ -std=c++20 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ -std=c++23 check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

g++ check_cpp_standard.cpp -o check_cpp_standard
./check_cpp_standard

rm -frv check_cpp_standard