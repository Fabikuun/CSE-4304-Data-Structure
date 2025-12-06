#include<iostream>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<int> st;
        int sum=0;
        for(char c:s){
            if(c>='0' && c<='9'){
                st.push(c-'0');
            }
            else if(c=='+' || c=='-' || c=='*' || c=='/'){
                int prev1=st.top();
                st.pop();
                int prev2=st.top();
                st.pop();
                if(c=='+'){
                    st.push(prev2+prev1);
                }
                else if(c=='-'){
                    st.push(prev2-prev1);
                }
                else if(c=='*'){
                    st.push(prev2*prev1);
                }
                else if(c=='/'){
                    st.push(prev2/prev1);
                }
            }
        }
        cout<<st.top()<<endl;
    }
    return 0;
}
