class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc,
             int oldColor, int color) {

        int m = image.size();
        int n = image[0].size();
        if(sr < 0 || sc < 0 || sr >= m || sc >= n)
            return;
        if(image[sr][sc] != oldColor)
            return;
        image[sr][sc] = color;
        dfs(image, sr - 1, sc, oldColor, color); 
        dfs(image, sr + 1, sc, oldColor, color); 
        dfs(image, sr, sc - 1, oldColor, color); 
        dfs(image, sr, sc + 1, oldColor, color); 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color)
            return image;
        dfs(image, sr, sc, oldColor, color);
        return image;
    }
};