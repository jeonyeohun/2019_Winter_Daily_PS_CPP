class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        
        for (int i = 0 ; i < ops.size() ; i++){
            if (ops[i].compare("C") == 0){
                cout << score.size() << endl;
                score.pop_back();
            }
            else if (ops[i].compare("D") == 0){
                int s = score.size()-1;
                score.push_back(score[s]*2);
            }
            else if (ops[i].compare("+") == 0){
                int s = score.size()-1;
                score.push_back(score[s]+score[s-1]);
            }
            else{
                score.push_back(stoi(ops[i]));
            }
        }
        
        int sum = 0;
        for (int i : score){
            sum+=i;
        }
            
        return sum;
    }
};