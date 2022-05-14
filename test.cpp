#include <iostream>
#include <vector>

using namespace std;

struct DynArray {
    uint8_t* array;
    size_t length;
};

extern "C" DynArray cypher_bytes(uint8_t* numbers, uint32_t length);

extern "C" DynArray decipher_bytes(uint8_t* numbers, uint32_t length);

extern "C" void rust_free(DynArray);

int main() {
  string ok;

  cin >> ok;

  std::vector<uint8_t> numbers;
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);

  for (const auto& r : numbers)
    std::cout << +r << std::endl;

  cin >> ok;
  
  uint32_t length = numbers.size();
  DynArray result = cypher_bytes(&(numbers[0]), length);

  cin >> ok;

  for (int i=0; i<(result.length); i++)
    std::cout << +result.array[i] << std::endl;

  cin >> ok;

  DynArray result2 = decipher_bytes(&(result.array[0]), result.length);

  for (int i=0; i<(result2.length); i++)
    std::cout << +result2.array[i] << std::endl;

  cin >> ok;

  rust_free(result);
  rust_free(result2);

}