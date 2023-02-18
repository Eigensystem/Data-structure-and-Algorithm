#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int pos = -1, last_pos = -1;
        string result;
        while(1)
        {
            last_pos = pos;
            pos = s.find(' ', last_pos + 1);
            if (pos == string::npos)
            {
                result.append(s, last_pos + 1, s.length() - last_pos - 1);
                return result;
            }
            result.append(s, last_pos + 1, pos - last_pos - 1);
            result.append("%20");
        }
    }
};