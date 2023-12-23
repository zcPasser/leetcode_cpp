#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // ��������
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // ͳ�� ��Χ����Сֵ�����ֵ
        int minVal = nums[0], maxVal = nums[0];
        for (int i = 0; i < nsSize; i++) {
            if (nums[i] < minVal)
                minVal = nums[i];
            if (nums[i] > maxVal)
                maxVal = nums[i];
        }
        // �� ��СֵΪ��׼������ ��������
        vector<int> cnts(maxVal - minVal + 1, 0);
        for (int i = 0; i < nsSize; i++)
            ++cnts[nums[i] - minVal];
        int idx = 0;
        // ���� �����������������ͬʱ ����׼ minVal ��ԭ��
        for (int i = 0; i < cnts.size(); i++) {
            while (cnts[i]) {
                nums[idx++] = i + minVal;
                cnts[i]--;
            }
        }

        return nums;
    }
};
