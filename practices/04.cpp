#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int mid;
        int start = 0, end = matrix.size() - 1;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        while(start <= end)
        {
            mid = start + ((end - start) >> 1);
            if(matrix[mid][0] < target)
            {
                start = mid + 1;
            }
            else if(matrix[mid][0] > target)
            {
                end = mid - 1;
            }
            else
            {
                end = mid;
                break;
            }
        }
        int line = end;
        for (int i = 0; i <= line; ++i)
        {
            start = 0;
            end = matrix[0].size();
            while(start <= end)
            {
                mid = start + ((end - start) >> 1);
                if(matrix[i][mid] < target)
                {
                    start = mid + 1;
                }
                else if(matrix[i][mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};