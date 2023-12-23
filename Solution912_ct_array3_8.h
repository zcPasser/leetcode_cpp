#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void buildMaxHeap(vector<int>& nums) {
        int nsSize = nums.size();
        // �����һ���� ��ʼ ��������
        // �Ե�����
        for (int i = (nsSize - 1) / 2; i >= 0; i--) {
            maxHeapify(nums, i, nsSize);
        }
        
    }
    void maxHeapify(vector<int>& nums, int i, int n) {
        // �ӵ�ǰ�ڵ� ���ѣ��Զ����¡�
        while (2 * i + 1 < n) {
            int lChild = 2 * i + 1;
            int rChild = 2 * i + 2;
            int large = i;
            if (lChild < n && nums[large] < nums[lChild])
                large = lChild;
            if (rChild < n && nums[large] < nums[rChild])
                large = rChild;
            // �����������������Ҫ �ݹ� ��󻯶� �� ����
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            }
            else
                break;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // ������
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // ���� ����
        buildMaxHeap(nums);
        // nums[0]Ϊ���ֵ
        // ÿ�ν� ��ǰ���ֵnums[0] �� ��ǰ���ѵ� ����һ��Ԫ�ؽ���
        // ��С���ѹ�ģ��������󻯶ѡ�
        for (int i = nsSize - 1; i >= 1; i--) {
            swap(nums[0], nums[i]);
            nsSize--;
            maxHeapify(nums, 0, nsSize);
        }

        return nums;
    }
};
