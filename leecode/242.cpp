#include <string>
#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() || t.empty() || s.size() != t.size())
            return false;
        int i, j;
        for (i = 0; i < s.size(); i++)
        {
            bool findBool = false;
	        for (j = 0; j < t.size(); j++)
	        {
		        if (s[i] == t[j])
		        {
                    t[j] = '#';
                    findBool = true;
                    break;
		        }
	        }
            if (!findBool)
                return false;
        }
        return true;
    }
};

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26, 0);
        if (s.empty() || t.empty() || s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            record[s[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
	        if (record[i] != 0)
                return false;
        }
        return true;
    }
};