// 1. precomputed string of 1000 digits of e
// 2. large unsigned integer: to store 10 digit integer
// 3. efficient isPrime function
// 4. iterate through e: checking 10 digit chunks
// 5. convert string slice to unsigned long long (stoull)
// 6. continue until prime is found
#include <iostream>
#include <string>

// Sieve of Eratosthenes
inline bool isPrime(unsigned long long n) {
  if (1 >= n)
    return false;
  if (3 >= n)
    return true;
  if (0 == n % 2 || 0 == n % 3)
    return false;
  
  // Already checked if evenly divisible by 2, 3, 4
  // Checks if evenly divisble by 5, 7, 9, ... , n
  for (size_t i=5; i*i<=n; i+=6)
      if (n%i == 0 || n%(i+2) == 0)
        return false;

  return true;
}


// Expansion for signed integers; unused in this example
inline bool isPrime(long long n) {
  if (1 >= n)
    return false;

  return isPrime( static_cast<unsigned long long>(n) );
}

inline bool isPrime(std::string n) {
  if ( std::string::npos != n.find('-') )
    return isPrime(stoll(n));
  
  return isPrime(stoull(n));
}


int main(void) {
  const std::string e = "27182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449920695517027618386062613313845830007520449338265602976067371132007093287091274437470472306969772093101416928368190255151086574637721112523897844250569536967707854499699679468644549059879316368892300987931277361782154249992295763514822082698951936680331825288693984964651058209392398294887933203625094431173012381970684161403970198376793206832823764648042953118023287825098194558153017567173613320698112509961818815930416903515988885193458072738667385894228792284998920868058257492796104841984443634632449684875602336248270419786232090021609902353043699418491463140934317381436405462531520961836908887070167683964243781405927145635490613031072085103837505101157477041718986106873969655212671546889570350354";
  const int prime_length = 10;

  // Iterate through e constant 10 character strings at a time.
  std::string solution;
  for (size_t i=0; i<e.length()-prime_length; ++i) {
    solution = e.substr(i, prime_length);
    if ( isPrime( stoull(solution) ) )
      break;
  }

  std::cout << "Found first " << prime_length <<  " digit consecutive prime in e.\n"
  << solution << ".com\n";
}
