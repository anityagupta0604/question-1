#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findUniqueNumbers(const vector<int>& arr) {
    int xor_all = 0;
    for (int num : arr) {
        xor_all ^= num;
    }
    int set_bit = xor_all & -xor_all;
    int num1 = 0, num2 = 0;
    for (int num : arr) {
        if (num & set_bit)  num1 ^= num; 
         else num2 ^= num;
    }
    vector<int> result = {num1, num2};
    sort(result.begin(), result.end());
    return result;
}
int main() {
    vector<int> arr = {1, 2, 1, 3, 2, 5};
    vector<int> result = findUniqueNumbers(arr);
    cout << "The two unique numbers are: " << result[0] << " and " << result[1] << endl;
    return 0;
}
