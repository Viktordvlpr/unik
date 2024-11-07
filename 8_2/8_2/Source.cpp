#include <iostream>
#include <string>
#include <limits>

using namespace std;

size_t MinLength(const string& s)
{
    size_t k = 0;
    size_t len = 0;
    size_t minLen = numeric_limits<size_t>::max();
    size_t start = 0;
    size_t finish;

    while (start < s.length())
    {
        while (start < s.length() && (isspace(s[start]) || ispunct(s[start]))) {
            start++;
        }

        finish = start;

        while (finish < s.length() && !isspace(s[finish]) && !ispunct(s[finish])) {
            finish++;
        }

        len = finish - start;

        if (len > 0 && (k == 0 || len < minLen))
            minLen = len;

        start = finish + 1;
        k++;
    }

    return minLen == numeric_limits<size_t>::max() ? 0 : minLen;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "Length of min word: " << MinLength(str) << endl;

    return 0;
}
