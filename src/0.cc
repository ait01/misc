#include <cstdlib>
#include <climits>
#include <cfloat>
#include <ctime>
#include <clocale>
#include <iostream>
#include <limits>
#include <chrono>
#include <iomanip>
#include <random>
#include <bitset>

#define SIZE 100

int main()
{
    std::cout << std::boolalpha << std::chrono::system_clock::is_steady << std::noboolalpha << std::endl;
    auto begin = std::chrono::steady_clock::now();

    std::printf("An 'int' takes %zu bytes.\n", sizeof(int));
    std::printf("The max 'int' is %i.\n", INT_MAX);
    std::printf("The min 'int' is %i.\n", INT_MIN);
    std::printf("A 'char' takes %zu byte.\n", sizeof(char));
    std::printf("The max 'char' %i.\n", CHAR_MAX);
    std::printf("The min 'char' is %i.\n", CHAR_MIN);
    std::printf("A 'short' takes %zu bytes.\n", sizeof(short));
    std::printf("The max 'short' is %i.\n", SHRT_MAX);
    std::printf("The min 'short' is %i.\n", SHRT_MIN);
    std::printf("A 'long' takes %zu bytes.\n", sizeof(long));
    std::printf("The max 'long' is %li.\n", LONG_MAX);
    std::printf("The min 'long' is %li.\n", LONG_MIN);
    std::printf("A 'long long' takes %zu bytes.\n", sizeof(long long));
    std::printf("The max 'long long' is %lli.\n", LLONG_MAX);
    std::printf("The min 'long long' is %lli.\n", LLONG_MIN);
    std::printf("A 'float' takes %zu bytes.\n", sizeof(float));
    std::printf("The max 'float' is %g.\n", FLT_MAX);
    std::printf("The min 'float' is %g.\n", FLT_MIN);
    std::printf("A 'double' takes %zu bytes.\n", sizeof(double));
    std::printf("The max 'double' is %g.\n", DBL_MAX);
    std::printf("The min 'double' is %g.\n", DBL_MIN);
    std::printf("A 'long double' takes %zu bytes.\n", sizeof(long double));
    std::printf("The max 'long double' is %Lg.\n", LDBL_MAX);
    std::printf("The min 'long double' is %Lg.\n", LDBL_MIN);
    std::printf("A 'size_t' takes %zu bytes.\n", sizeof(std::size_t));
    std::printf("The max 'size_t' is %lu.\n", SIZE_MAX);
    std::printf("A 'time_t' takes %zu bytes.\n", sizeof(std::time_t));
    std::printf("The value of 'NULL' is %p or %li.\n", (void*)NULL, (long)NULL);
    std::printf("'NULL', which is a 'void*', takes %zu bytes.\n", sizeof(NULL));
    std::printf("A 'void*' pointer takes %zu bytes.\n", sizeof(void*));
    std::printf("The value of 'EXIT_SUCCESS' is %i\n", EXIT_SUCCESS);
    std::printf("The value of 'EXIT_FAILURE' is %i\n", EXIT_FAILURE);
    std::printf("The value of 'RAND_MAX' is %i\n", RAND_MAX);
    std::printf("The value of 'EOF' is %i.\n", EOF);
    std::printf("The value of 'getchar() == EOF' is %i.\n", (std::getchar() == EOF));

    std::cout << "The C++ version is " << __cplusplus << '.' << std::endl;
    std::cout << "A 'long' takes " << sizeof(long) << " bytes." << std::endl;
    std::cout << "The max 'long' is " << std::numeric_limits<long>::max() << '.' << std::endl;
    std::cout << "The min 'long' is " << std::numeric_limits<long>::min() << '.' << std::endl;
    std::cout << "A 'long long' takes " << sizeof(long long) << " bytes." << std::endl;
    std::cout << "A 'float' takes " << sizeof(float) << " bytes." << std::endl;
    std::cout << "The max 'float' is " << std::numeric_limits<float>::max() << '.' << std::endl;
    std::cout << "The min 'float' is " << std::numeric_limits<float>::min() << '.' << std::endl;
    std::cout << "Is 'char' signed? " << (std::numeric_limits<char>::is_signed ? "Yes." : "No.") << std::endl;
    std::cout << "A 'size_t' takes " << sizeof(std::size_t) << " bytes." << std::endl;
    std::cout << "The max 'size_t' is " << std::numeric_limits<std::size_t>::max() << '.' << std::endl;
    std::cout << "The min 'size_t' is " << std::numeric_limits<std::size_t>::min() << '.' << std::endl;

    wchar_t c = 0;
    int i = 3;
    int A[SIZE] = {0};
    char B[SIZE] = {0};
    std::time_t now = std::time(nullptr);

    std::cout << "The locale is " << std::setlocale(LC_ALL, nullptr) << '.' << std::endl;
    std::cout << "The locale is " << std::setlocale(LC_ALL, "") << '.' << std::endl;
    std::cout << "It is " << std::ctime(&now);
    now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << "It is " << now << '.' << std::endl;
    std::cout << "It is " << std::ctime(&now);
    std::cout << "It is " << std::put_time(std::localtime(&now), "%F %T") << std::endl;
    std::printf("%.*s\n", i, "Hello");
    std::printf("%*s\n", i, "Hello");
    std::printf("Size of A: %zu\n", sizeof(A));
    std::printf("Length of A: %zu\n", sizeof(A)/sizeof(*A));
    std::printf("Size of B: %zu\n", sizeof(B));
    std::printf("Length of B: %zu\n", sizeof(B)/sizeof(*B));
    std::printf("\n%lc\n\n", 0xFDFA);
    std::scanf("%lc", &c);
    std::printf("%lc - %i\n", c, c);
    do {
        if ((c = std::getchar()) < 128) std::printf("%lc - %i\n", c, c);
        else std::printf("%lc - %i - %s\n", c, c, "Not ASCII");
    } while (c != EOF);

    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<unsigned> u(1);
    unsigned int key = u(e);
    std::bitset<sizeof(unsigned int)*8> key_bin(key);

    char data[] = "A message to be encrypted by the random generated key.";

    std::cout << "The key in decimal is: " << key << '.' << std::endl;
    std::cout << "The key in hexadecimal is: " << std::hex << key << std::dec << '.' << std::endl;
    std::cout << "The key in binary is: ";
    for (std::streamsize i = key_bin.size()-1; i >= 0 ; --i) std::cout << key_bin[i] << (i == 0 || i%8 ? "" : " ");
    std::cout << ".\n" << std::endl;

    std::cout << "The input data in plain text is: " << data << std::endl;
    std::cout << "The input data in binary is:\n";
    for (std::size_t i = 0; i < sizeof(data); ++i) std::cout << std::bitset<sizeof(char)*8>(data[i]) << ((i < sizeof(data)-1 && (i+1)%8) ? ' ' : '\n');
    std::cout << std::endl;

    for (std::size_t i = 0; i < sizeof(data)-1; ++i) data[i] ^= key;
    std::cout << "The encrypted data in plain text is: " << data << std::endl;
    std::cout << "The encrypted data in binary is:\n";
    for (std::size_t i = 0; i < sizeof(data); ++i) std::cout << std::bitset<sizeof(char)*8>(data[i]) << ((i < sizeof(data)-1 && (i+1)%8) ? ' ' : '\n');
    std::cout << std::endl;

    for (std::size_t i = 0; i < sizeof(data)-1; ++i) data[i] ^= key;
    std::cout << "The decrypted data in plain text is: " << data << std::endl;
    std::cout << "The decrypted data in binary is:\n";
    for (std::size_t i = 0; i < sizeof(data); ++i) std::cout << std::bitset<sizeof(char)*8>(data[i]) << ((i < sizeof(data)-1 && (i+1)%8) ? ' ' : '\n');
    std::cout << std::endl;

    auto end = std::chrono::steady_clock::now();
    std::cout << "The program took " << (end-begin).count() << std::endl;
    std::cout << "The program took " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanoseconds." << std::endl;
    std::cout << "The program took " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " microseconds." << std::endl;
    std::cout << "The program took " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds." << std::endl;

    return 0;
}
