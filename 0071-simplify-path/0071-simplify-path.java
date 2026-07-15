class Solution {
    public String simplifyPath(String path) {
        
        Stack<String> st = new Stack<String>();

        String[] sp = path.split("/");

        for(String x: sp)
        {
            if(x.equals(".."))
            {
                if(!st.isEmpty()) st.pop();
            }
            else if(!x.equals("") && !x.equals("."))
            {
                st.push(x);
            }
        }

        return "/" + String.join("/", st);
    }
}