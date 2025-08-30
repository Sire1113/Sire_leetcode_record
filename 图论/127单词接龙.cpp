class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, int> used;
        if (!words.contains(endWord))
            return 0;
        int distance{};
        queue<string> q;
        q.push(beginWord);
        used[beginWord] = 1;
        while (!q.empty()){
            string word = q.front();
            string new_word = word;
            q.pop();
            if (new_word == endWord)
                return used[word];
            for (int idx=0; idx<beginWord.size(); idx++){
                for (int alpha=0; alpha<26; alpha++){
                    new_word[idx] = alpha+'a';
                    if (words.contains(new_word) && new_word != word && !used.contains(new_word)){
                        q.push(new_word);
                        used[new_word] = used[word]+1;
                    }
                }
                new_word[idx] = word[idx];
            }
        }
        return 0;
    }
};