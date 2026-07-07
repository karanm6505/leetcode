class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
        ArrayList<Integer> l = new ArrayList<>();
        HashMap<Integer, Integer> h = new HashMap<>();
        int len = nums.length;
        if (len == 1)
        {
            l.add(nums[0]);
            return l;
        }
        for(int n: nums)
        {
            if(h.containsKey(n))
            {
                int v = h.get(n);
                h.replace(n, ++v);
            }
            else
            {
                h.put(n, 1);
            }
        }
        System.out.println(len/3);
        for(int x: h.keySet())
        {
            if(h.get(x) > len/3)
            {
                l.add(x);
            }
        }

        return l;
    }
}