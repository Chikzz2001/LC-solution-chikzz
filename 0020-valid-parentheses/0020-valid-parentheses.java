class Solution {
    public boolean isValid(String s) {
        ArrayDeque<Character> st=new ArrayDeque<>();
        
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==')')
            {
                if(st.size()==0||st.peek()!='(')
                    return false;
                st.pop();
            }
            else if(s.charAt(i)=='}')
            {
                if(st.size()==0||st.peek()!='{')
                    return false;
                st.pop();
            }
            else if(s.charAt(i)==']')
            {
                if(st.size()==0||st.peek()!='[')
                    return false;
                st.pop();
            }
            else
                st.push(s.charAt(i));
        }
        return st.isEmpty();
    }
}