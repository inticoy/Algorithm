class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int newFlowers = 0;

        for (int i = 0; i < flowerbed.size(); i++)
        {   
            if (flowerbed[i] == 1)
                continue;
        
            bool canPlaceFlower = true;
            
            if (i != 0 && flowerbed[i - 1] == 1)
                canPlaceFlower = false;
            if (i != flowerbed.size() - 1 && flowerbed[i + 1] == 1)
                canPlaceFlower = false;

            if (canPlaceFlower)
            {
                flowerbed[i] = 1;
                ++newFlowers;
            }
        }
        
        return newFlowers >= n;
    }
};