#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 1000000; // maximum length of the text editor

int arr[MAXN]; // array to store the hash values of the text editor
int pow_num[MAXN]; // array to store the powers of num
const int num = 2; // value of num
const int mod = 1000000007; // a large prime number for hashing
const int k = 3; // length of the pattern string

int hash_string(string s) {
    int hash_val = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        hash_val = (hash_val * num + s[i]) % mod;
    }
    return hash_val;
}

int main() {
    string text;
    getline(cin, text); // read the text editor string
    int n = text.size();
    pow_num[k-1] = 1;
    for (int i = k-2; i >= 0; i--) {
        pow_num[i] = (pow_num[i+1] * num) % mod;
    }
    int pattern_hash = hash_string("CAC"); // calculate the hash value of the pattern string
    for (int i = 0; i < n - k + 1; i++) {
        string substring = text.substr(i, k);
        arr[i] = hash_string(substring);
        if (i == n - k) {
            break;
        }
        arr[i+1] = (arr[i] - text[i] * pow_num[k-1] % mod + mod) * num % mod + text[i+k];
    }
    bool found = false;
    for (int i = 0; i < n - k + 1; i++) {
        if (arr[i] == pattern_hash) {
            if (text.substr(i, k) == "CAC") { // check if the actual substring matches the pattern string
                found = true;
                break;
            }
        }
    }
    if (found) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}