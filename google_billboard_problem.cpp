// 1. precomputed string of 1000 digits of e
// 2. large unsigned integer: to store 10 digit integer
// 3. efficient isPrime function
// 4. iterate through e: checking 10 digit chunks
// 5. convert string slice to unsigned long long (stoull)
// 6. continue until prime is found
#include <iostream>
#include <string>
#include <cmath>


// Sieve of Eratosthenes
template <typename T>
inline auto isPrime(T n) -> decltype(n) {
  if (1 >= n)
    return false;
  if (3 >= n)
    return n;
  if (0 == n % 2 || 0 == n % 3)
    return false;
  
  // Already checked if evenly divisible by 2, 3, 4
  // Checks if evenly divisble by 5, 7, 13, 15, 21, 23, ... , n
  for (size_t i=5; i*i<=sqrt(n); i+=6)
      if (n%i == 0 || n%(i+2) == 0)
        return false;

  return n;
}

// Function overload for strings
inline auto isPrime(std::string n) -> unsigned long long {
  if ( std::string::npos != n.find('-') )
    return false; // Negative numbers aren't prime
  
  return isPrime(stoull(n));
}


auto main(void) -> int {
  // First 1,000 digits of e.
  const std::string e = 
    "27182818284590452353602874713526624977572470936999"
    "59574966967627724076630353547594571382178525166427"
    "42746639193200305992181741359662904357290033429526"
    "05956307381323286279434907632338298807531952510190"
    "11573834187930702154089149934884167509244761460668"
    "08226480016847741185374234544243710753907774499206"
    "95517027618386062613313845830007520449338265602976"
    "06737113200709328709127443747047230696977209310141"
    "69283681902551510865746377211125238978442505695369"
    "67707854499699679468644549059879316368892300987931"
    "27736178215424999229576351482208269895193668033182"
    "52886939849646510582093923982948879332036250944311"
    "73012381970684161403970198376793206832823764648042"
    "95311802328782509819455815301756717361332069811250"
    "99618188159304169035159888851934580727386673858942"
    "28792284998920868058257492796104841984443634632449"
    "68487560233624827041978623209002160990235304369941"
    "84914631409343173814364054625315209618369088870701"
    "67683964243781405927145635490613031072085103837505"
    "10115747704171898610687396965521267154688957035035";
  const int prime_length = 10;

  // Iterate through e while checking each substr of prime_length.
  for (size_t i=0; i<e.length()-prime_length; ++i) {
    if ( isPrime(stoull(e.substr(i, prime_length))) ) {
      std::cout << "Found first " << prime_length <<  " digit consecutive prime in e.\n"
                << stoull(e.substr(i, prime_length)) << ".com\n";
      break;
    }
  }

  return 0;
}
