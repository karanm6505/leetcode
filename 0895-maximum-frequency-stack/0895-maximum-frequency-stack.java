class FreqStack {
    public Stack<Integer> st;
    public Map<Integer, Integer> freqMap;
    public int maxFreq = 0;
    public Stack<Integer> poppingStack;

    public FreqStack() {
        st = new Stack<>();
        freqMap = new HashMap<>();
        poppingStack = new Stack<>();
    }
    
    public void push(int val) {
        
        st.push(val);

        if(freqMap.containsKey(val)){
            int freq = freqMap.get(val) + 1;
            freqMap.put(val, freq);

            if(freq > maxFreq){
                maxFreq = freq;
            }
        }
        else{
            freqMap.put(val, 1);

            if(maxFreq == 0){
                maxFreq = 1;
            }
        }
    }
    
    public int pop() {

        while(!st.isEmpty() && freqMap.get(st.peek()) < maxFreq){
            poppingStack.push(st.pop());
        }

        int x = st.pop();

        int newFreq = freqMap.get(x) - 1;
        freqMap.put(x, newFreq);

        while(!poppingStack.isEmpty()){
            st.push(poppingStack.pop());
        }

        boolean exists = false;

        for(int freq : freqMap.values()){
            if(freq == maxFreq){
                exists = true;
                break;
            }
        }

        if(!exists){
            maxFreq--;
        }

        return x;
    }
}