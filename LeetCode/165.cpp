/*******************************************************************************
	> File Name: 165.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Mar 11 01:03:56 2016
*******************************************************************************/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int main1 = std::stoi(version1);
        int main2 = std::stoi(version2);
        
        if (main1 > main2) return 1;
        if (main1 < main2) return -1;
        
        int p1 = version1.find('.');
        int p2 = version2.find('.');
        
        if (p1 == -1 && p2 == -1) {
            return 0;
        } else {
            string sub1 = p1 == -1 ? "0" : version1.substr(p1 + 1, version1.size() - p1);
            string sub2 = p2 == -1 ? "0" : version2.substr(p2 + 1, version2.size() - p2);
            return compareVersion(sub1, sub2);
        }
        
        return 0;
    }
};
