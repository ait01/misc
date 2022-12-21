#include <cstdlib>
#include <climits>
#include <cfloat>
#include <ctime>
#include <clocale>
#include <iostream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <bitset>

#define SIZE 100

void checkTypes(void)
{
    std::cout << "A 'char' takes " << sizeof(char) << " byte." << std::endl;
    std::printf("A 'char' takes %zu byte.\n", sizeof(char));
    std::cout << "The max 'char' is " << +std::numeric_limits<char>::max() << '.' << std::endl;
    std::printf("The max 'char' %i.\n", CHAR_MAX);
    std::cout << "The min 'char' is " << +std::numeric_limits<char>::min() << '.' << std::endl;
    std::printf("The min 'char' is %i.\n", CHAR_MIN);
    std::cout << "Is 'char' signed? " << (std::numeric_limits<char>::is_signed ? "Yes." : "No.") << std::endl;

    std::cout << "A 'short' takes " << sizeof(short) << " bytes." << std::endl;
    std::printf("A 'short' takes %zu bytes.\n", sizeof(short));
    std::cout << "The max 'short' is " << std::numeric_limits<short>::max() << '.' << std::endl;
    std::printf("The max 'short' is %i.\n", SHRT_MAX);
    std::cout << "The min 'short' is " << std::numeric_limits<short>::min() << '.' << std::endl;
    std::printf("The min 'short' is %i.\n", SHRT_MIN);

    std::cout << "An 'int' takes " << sizeof(int) << " bytes." << std::endl;
    std::printf("An 'int' takes %zu bytes.\n", sizeof(int));
    std::cout << "The max 'int' is " << std::numeric_limits<int>::max() << '.' << std::endl;
    std::printf("The max 'int' is %i.\n", INT_MAX);
    std::cout << "The min 'int' is " << std::numeric_limits<int>::min() << '.' << std::endl;
    std::printf("The min 'int' is %i.\n", INT_MIN);

    std::cout << "A 'long' takes " << sizeof(long) << " bytes." << std::endl;
    std::printf("A 'long' takes %zu bytes.\n", sizeof(long));
    std::cout << "The max 'long' is " << std::numeric_limits<long>::max() << '.' << std::endl;
    std::printf("The max 'long' is %li.\n", LONG_MAX);
    std::cout << "The min 'long' is " << std::numeric_limits<long>::min() << '.' << std::endl;
    std::printf("The min 'long' is %li.\n", LONG_MIN);

    std::cout << "A 'long long' takes " << sizeof(long long) << " bytes." << std::endl;
    std::printf("A 'long long' takes %zu bytes.\n", sizeof(long long));
    std::cout << "The max 'long long' is " << std::numeric_limits<long long>::max() << '.' << std::endl;
    std::printf("The max 'long long' is %lli.\n", LLONG_MAX);
    std::cout << "The min 'long long' is " << std::numeric_limits<long long>::min() << '.' << std::endl;
    std::printf("The min 'long long' is %lli.\n", LLONG_MIN);

    std::cout << "A 'float' takes " << sizeof(float) << " bytes." << std::endl;
    std::printf("A 'float' takes %zu bytes.\n", sizeof(float));
    std::cout << "The max 'float' is " << std::numeric_limits<float>::max() << '.' << std::endl;
    std::printf("The max 'float' is %g.\n", FLT_MAX);
    std::cout << "The min 'float' is " << std::numeric_limits<float>::min() << '.' << std::endl;
    std::printf("The min 'float' is %g.\n", FLT_MIN);

    std::cout << "A 'double' takes " << sizeof(double) << " bytes." << std::endl;
    std::printf("A 'double' takes %zu bytes.\n", sizeof(double));
    std::cout << "The max 'double' is " << std::numeric_limits<double>::max() << '.' << std::endl;
    std::printf("The max 'double' is %g.\n", DBL_MAX);
    std::cout << "The min 'double' is " << std::numeric_limits<double>::min() << '.' << std::endl;
    std::printf("The min 'double' is %g.\n", DBL_MIN);

    std::cout << "A 'long double' takes " << sizeof(long double) << " bytes." << std::endl;
    std::printf("A 'long double' takes %zu bytes.\n", sizeof(long double));
    std::cout << "The max 'long double' is " << std::numeric_limits<long double>::max() << '.' << std::endl;
    std::printf("The max 'long double' is %Lg.\n", LDBL_MAX);
    std::cout << "The min 'long double' is " << std::numeric_limits<long double>::min() << '.' << std::endl;
    std::printf("The min 'long double' is %Lg.\n", LDBL_MIN);

    std::cout << "A 'size_t' takes " << sizeof(std::size_t) << " bytes." << std::endl;
    std::printf("A 'size_t' takes %zu bytes.\n", sizeof(std::size_t));
    std::cout << "The max 'size_t' is " << std::numeric_limits<std::size_t>::max() << '.' << std::endl;
    std::printf("The max 'size_t' is %lu.\n", SIZE_MAX);
    std::cout << "The min 'size_t' is " << std::numeric_limits<std::size_t>::min() << '.' << std::endl;

    std::printf("A 'time_t' takes %zu bytes.\n", sizeof(std::time_t));
    std::printf("A 'void*' takes %zu bytes.\n", sizeof(void*));
    std::printf("'NULL', which is a 'void*', takes %zu bytes.\n", sizeof(NULL));
    std::printf("The value of 'NULL' is %p or %li.\n", (void*)NULL, (long)NULL);
    std::printf("The value of 'EXIT_SUCCESS' is %i.\n", EXIT_SUCCESS);
    std::printf("The value of 'EXIT_FAILURE' is %i.\n", EXIT_FAILURE);
    std::printf("The value of 'RAND_MAX' is %i.\n", RAND_MAX);
    std::printf("The value of 'EOF' is %i.\n", EOF);

    int A[SIZE] = { 0 };
    char B[SIZE] = { 0 };
    std::printf("Size of A: %zu.\n", sizeof(A));
    std::printf("Length of A: %zu.\n", sizeof(A)/sizeof(*A));
    std::printf("Size of B: %zu.\n", sizeof(B));
    std::printf("Length of B: %zu.\n", sizeof(B)/sizeof(*B));
}

void checkLocale(void)
{
    std::cout << "The locale is " << std::setlocale(LC_ALL, nullptr) << '.' << std::endl;
    std::cout << "The locale is " << std::setlocale(LC_ALL, "") << '.' << std::endl;
    std::cout << "System clock is monotonic: " << std::boolalpha << std::chrono::system_clock::is_steady << std::noboolalpha << std::endl;
    auto now = std::time(nullptr);
    std::cout << "It is " << std::ctime(&now);
    now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << "It is " << now << '.' << std::endl;
    std::cout << "It is " << std::ctime(&now);
    std::cout << "It is " << std::put_time(std::localtime(&now), "%F %T") << std::endl;
}

void checkIo(void)
{
    std::printf("%.*s\n", 3, "Hello");
    std::printf("%*s\n", 3, "Hello");
    std::printf("\n%lc\n\n", 0xFDFA);
    wchar_t c = 0xFDFA;
    std::scanf("%lc", &c);
    std::printf("%lc - %i\n", c, c);
    do {
        if ((c = std::getchar()) < 128) std::printf("%lc - %i\n", c, c);
        else std::printf("%lc - %i - %s\n", c, c, "Not ASCII");
    } while (c != EOF);
}

void checkRandom(void)
{
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<unsigned int> u(1);
    auto key = u(e);
    std::bitset<sizeof(unsigned int)*8> key_bin(key);

    char data[] = "A message to be encrypted by the random generated key.";

    std::cout << "The key in decimal is: " << key << '.' << std::endl;
    std::cout << "The key in hexadecimal is: " << std::hex << key << std::dec << '.' << std::endl;
    std::cout << "The key in binary is: ";
    for (std::streamsize i = key_bin.size() - 1; i >= 0 ; --i) std::cout << key_bin[i] << (i == 0 || i%8 ? "" : " ");
    std::cout << ".\n" << std::endl;

    std::cout << "The input data in plain text is: " << data << std::endl;
    std::cout << "The input data in binary is:\n";
    for (std::size_t i = 0; i < sizeof(data); ++i) std::cout << std::bitset<sizeof(char)*8>(data[i]) << ((i < sizeof(data) - 1 && (i + 1)%8) ? ' ' : '\n');
    std::cout << std::endl;

    for (std::size_t i = 0; i < sizeof(data) - 1; ++i) data[i] ^= key;
    std::cout << "The encrypted data in plain text is: " << data << std::endl;
    std::cout << "The encrypted data in binary is:\n";
    for (std::size_t i = 0; i < sizeof(data); ++i) std::cout << std::bitset<sizeof(char)*8>(data[i]) << ((i < sizeof(data) - 1 && (i + 1)%8) ? ' ' : '\n');
    std::cout << std::endl;

    for (std::size_t i = 0; i < sizeof(data) - 1; ++i) data[i] ^= key;
    std::cout << "The decrypted data in plain text is: " << data << std::endl;
    std::cout << "The decrypted data in binary is:\n";
    for (std::size_t i = 0; i < sizeof(data); ++i) std::cout << std::bitset<sizeof(char)*8>(data[i]) << ((i < sizeof(data) - 1 && (i + 1)%8) ? ' ' : '\n');
    std::cout << std::endl;
}
