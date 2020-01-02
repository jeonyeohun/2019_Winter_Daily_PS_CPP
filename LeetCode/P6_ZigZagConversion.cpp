class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char> > arr (numRows, vector<char>(s.size(), ' '));
        int row = 0;
        int col = 0;
        bool isDown = true;
        
        if (numRows==1) return s;
        
        for (int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            arr[row][col] = c;
            if (isDown == true) {
                row++;
                if (row == numRows-1) isDown = false;
            }
            else {
                row--;
                col++;
                if (row == 0) isDown = true;
            }
        }
        string result;
        for (vector<char> a : arr){
            for (char c : a){
                if (c != ' ') result.push_back(c);
            }
        }
        return result;
    }
};