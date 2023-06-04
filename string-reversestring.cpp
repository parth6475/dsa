class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for(int i=0;i<s.size()/2;++i)
        {
            int index=s.size()-i-1;
            temp=s[i];
            s[i]=s[index];
            s[index]=temp;
        }
    }
};
