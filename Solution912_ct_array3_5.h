#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // ϣ������
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // ���Ϊd��Ϊһ�飬���� �Ӵ�С
        //
        for (int d = nsSize / 2; d >= 1; d /= 2) {
            // һ�� ϣ������
            // ��dΪ��������ĵ�ǰ�� ����һ��Ŀ�ͷԪ�� [0, d)
            // ��ǰd ���� d�����У�ÿ�����п�ͷ�ֱ��Ӧ[0, d)
            for (int x = 0; x < d; x++) {
                // �Ե�ǰ�� ��ʼ ��������
                // Ĭ�� ��ǰ�� ��һ��Ԫ�� ���� ���������
                for (int i = x + d; i < nsSize; i += d) {
                    int tmp = nums[i];
                    int j = 0;
                    // ��ǰ�� �� ÿһ��Ԫ�� ����֮ǰ ����������С�
                    // ����λ�ã��Ӻ���ǰ���ҵ���һ�� <= ��ǰԪ��tmp��λ�õ���һ����������ִ�� ���ǡ�
                    for (j = i - d; j >= 0 && nums[j] > tmp; j -= d) {
                        nums[j + d] = nums[j];
                    }
                    // ����λ��
                    nums[j + d] = tmp;
                }
            }
        }

        return nums;
    }
};
