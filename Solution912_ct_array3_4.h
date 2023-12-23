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
        // ��һ��Ԫ�ر���Ϊ�Ѿ�������
        for (int i = 1; i < nsSize; i++) {
            // ��Ԫ�ص���������ֱ�Ӳ���
            if (nums[i] >= nums[i - 1])
                continue;
            // ���ֲ��ң�ʱ�临�Ӷ�logn
            int l = 0, r = i - 1;
            while (l <= r) {
                int mid = (r - l) / 2 + l;
                // r�Ҳ�Ԫ�ؾ����� nums[i]���� r �������Ԫ�ؾ�С�ڵ���nums[i]
                if (nums[i] < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // �ȶ�������������
            int idx = r + 1;
            int tmp = nums[i];
            // ����ǰ i Ԫ�ز����� index λ�ã�index ~ i - 1 Ԫ�����κ��ƣ�ʱ�临�Ӷ�n
            for (int k = i; k >= idx + 1; --k) {
                nums[k] = nums[k - 1];
            }
            nums[idx] = tmp;
        }

        return nums;
    }
};
