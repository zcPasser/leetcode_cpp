#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        //����ǰ׺������ ���ټ���������ĺ�
        //������Ϊ���������������k�����������ڹ�ϣ���б������ǰ׺��Ϊx��һ�γ��ֵ��±�
        //Ȼ����������ÿ��Ԫ��Ϊ��β�ģ�� �͵���k�������鳤��

        //ֵΪx��ǰ׺��������ֵ��±�y  hash��x��=y
        unordered_map<int, int> hash;
        // �����ʼ������Ҫ��Ϊ�˿��ǵ� 0~i����k�����
        hash[0] = -1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.count(sum - k))  res = max(res, i - hash[sum - k]);
            if (!hash.count(sum)) hash[sum] = i; // ��ΪҪ���ǵ�һ�γ��ֵ�ֵ
        }

        return res;

    }
};

