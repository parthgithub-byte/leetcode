class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if (n==0) return 0;

        stack<int>st;
        long long currentnumber = 0;
        char operation = '+';   // default first operation

        for (int i=0; i<n; i++){
            char currentChar = s[i];

            if (isdigit(currentChar)){
                currentnumber = currentnumber*10 + (currentChar - '0');
            }

            if ((!isdigit(currentChar) && currentChar != ' ') or i == n-1){
                if (operation == '+'){
                    st.push(currentnumber);
                }
                else if (operation == '-'){
                    st.push(-currentnumber);
                }
                else if (operation == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top*currentnumber);
                }
                else if (operation == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/currentnumber);
                }

                operation = currentChar;
                currentnumber = 0;
            }
        }

        int result = 0;
        while (!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};

/*
Eg:
13 + 5*14/2 -7
- the currentnumber gets filled till 13
- now the currentChar is ' ', just gets read.
- now the currentChar is +. Every operation is a chance to think on the stored currentnumber. Since default operation was '+', 13 is pushed to stack. Reset currentnumber to 0. Now the operation is set to '+'.
- now the currentChar is ' ', just gets read.
- the currentnumber gets filled till 5
- now the currentChar is '*'. Ok, but operation is still stored as '+'. Push 5 in stack. Clear currentnumber, operation set to '*'
- the currentnumber gets filled to 14.
- now the currentChar is '/'. But operation is stored as '*'. Take out the top of stack and multiply it with currentnumber. Push 5*14 (=70) to stack. Now the operation becomes '/'.
- now the currentnumber becomes 2.
- Space as currentChar is read and ignored.
- now the currentChar is -. The operation stored was '/'. Thus taking out the top of stack and dividing it with currentnumber. Pushing 70/2 (=35) into the stack. Operation is set to '-'.
- now the currentnumber becomes 7. 
- iterator reached till n-1 position. Operation was '-'. Push -currentnumber (=-7) in the stack.
- stack items: 13, 35, -7
- lastly add them to get the answer
*/