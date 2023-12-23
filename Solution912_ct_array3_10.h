#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    void radixSort(vector<int>& nums) {
        int maxVal = nums[0];
        // ��֤ �������ҵ����ֵ��
        for (int& num : nums) {
            num += 50000;
            if (maxVal < num)
                maxVal = num;
        }
        int d = 1;
        int p = 10;
        // ͨ�� �������õ� ���ֵ��λ����Ҳ��ѭ��������
        while (maxVal >= p) {
            maxVal /= 10;
            ++d;
        }
        vector<int> cnt(10, 0);        
        int i, j, k;
        int radix = 1;
        int nsSize = nums.size();
        vector<int> tmp(nsSize, 0);
        for (i = 0; i < d; i++) {
            // �������� ���㡣
            std::fill(cnt.begin(), cnt.end(), 0);
            // ��ǰλ ����
            for (j = 0; j < nsSize; j++) {
                k = (nums[j] / radix) % 10;
                cnt[k]++;
            }
            // ��ǰλ ���ݼ������������ ��ǰ������� ÿ���������
            for (j = 1; j < 10; j++) {
                cnt[j] += cnt[j - 1];
            }
            // ���� ����������
            for (j = nsSize - 1; j >= 0; j--) {
                k = (nums[j] / radix) % 10;
                tmp[cnt[k] - 1] = nums[j];
                cnt[k]--;
            }
            // ������ ����ԭ����
            copy(tmp.begin(), tmp.end(), nums.begin());
            // λ������
            radix *= 10;
        }
        for (int& num : nums)
            num -= 50000;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // ��������
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;

        radixSort(nums);

        return nums;
    }
};
