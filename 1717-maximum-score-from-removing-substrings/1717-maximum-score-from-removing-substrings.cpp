class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        if (y > x) {
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty()) {
                    char c = st.top();
                    if (c == 'b' && s[i] == 'a') {
                        ans += y;
                        st.pop();
                    } else {
                        st.push(s[i]);
                    }
                } else {
                    st.push(s[i]);
                }
            }
            string t;
            while (!st.empty()) {
                t += st.top();
                st.pop();
            }
            reverse(t.begin(), t.end());
            for (int i = 0; i < t.size(); i++) {
                if (!st.empty()) {
                    char c = st.top();
                    if (c == 'a' && t[i] == 'b') {
                        ans += x;
                        st.pop();
                    } else {
                        st.push(t[i]);
                    }
                } else {
                    st.push(t[i]);
                }
            }
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty()) {
                    char c = st.top();
                    if (c == 'a' && s[i] == 'b') {
                        ans += x;
                        st.pop();
                    } else {
                        st.push(s[i]);
                    }
                } else {
                    st.push(s[i]);
                }
            }
            string t;
            while (!st.empty()) {
                t += st.top();
                st.pop();
            }
            reverse(t.begin(), t.end());
            for (int i = 0; i < t.size(); i++) {
                if (!st.empty()) {
                    char c = st.top();
                    if (c == 'b' && t[i] == 'a') {
                        ans += y;
                        st.pop();
                    } else {
                        st.push(t[i]);
                    }
                } else {
                    st.push(t[i]);
                }
            }
        }
        return ans;
    }
};