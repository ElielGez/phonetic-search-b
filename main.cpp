#include "PhoneticFinder.hpp"

int main()
{
    string text1 = "g";
    string ans = phonetic::find(text1, "n");

    // string found = phonetic::find("Dond vorri be haffy", "dontt");
    cout << ans;
    return 0;
}