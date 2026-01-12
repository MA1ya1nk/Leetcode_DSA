class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0; 

        while (i < n) {
            int j = i;
            int lineLength = 0, totalChars = 0;

            
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length(); 
                totalChars += words[j].length();
                j++;
            }

            int spaces = maxWidth - totalChars; 
            int gaps = j - i - 1; 
            string line = "";

            if (j == n || gaps == 0) { 
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " "; 
                }
                
                while (line.size() < maxWidth) line += " ";
            } else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps; 

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int toAdd = spaceEach + (extra > 0 ? 1 : 0);
                        line += string(toAdd, ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};