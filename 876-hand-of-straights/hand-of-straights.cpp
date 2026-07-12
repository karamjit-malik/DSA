class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
        return false;
        unordered_map<int, int> freq;
        for (int x : hand)
        freq[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for (auto &p : freq)
        heap.push(p);
        while (!heap.empty())
        {
            if (heap.size() < groupSize)
            return false;
            vector<pair<int,int>> temp;
            auto [start, cnt] = heap.top();
            heap.pop();
            cnt--;
            if (cnt > 0)
            temp.push_back({start, cnt});
            int prev = start;
            for (int i = 1; i < groupSize; i++)
            {
                if (heap.empty())
                return false;
                auto [num, count] = heap.top();
                heap.pop();
                if (num != prev + 1)
                return false;
                count--;
                if (count > 0)
                temp.push_back({num, count});
                prev = num;
            }
            for (auto &p : temp)
            heap.push(p);
        }
        return true;
    }
};