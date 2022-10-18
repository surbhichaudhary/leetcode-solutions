class Solution {
public:
    string say( string in, int i, int n ){
        if( i==n ){
            return in;
        }
        string op1;
        for( int j=0; j < in.length(); j++ ){
            int k = j+1, c=1;
            while( c < in.length() && in[k] == in[j] ){
                k++;
                c++;
            }
            char ch = c+48;
            op1.push_back(ch);
            op1.push_back(in[j]);
            j = k-1;
        }
        return say( op1, i+1, n );
    }
    string countAndSay(int n) {
        string ans = "1";
        if( n==1 ){
            return ans;
        }
        return say( ans, 1, n );
    }
};