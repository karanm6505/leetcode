class Solution {
    Map<Integer, List<Integer>> preMap = new HashMap<>();
    Set<Integer> v = new HashSet<>();
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        for(int i = 0; i < numCourses; i++){
            preMap.put(i, new ArrayList<>());
        }

        for(int []prereq : prerequisites){
            preMap.get(prereq[0]).add(prereq[1]);
        }

        for(int c = 0; c < numCourses; c++){
            if(!dfs(c)){
                return false;
            }
            
        }
        return true;
    }

    boolean dfs(int c){
        if(v.contains(c)){
            return false;
        }
        if(preMap.get(c).isEmpty()){
            return true;
        }

        v.add(c);
        for(int p: preMap.get(c)){
            if(!dfs(p))
            {
                return false;
            }
        }
        v.remove(c);
        preMap.put(c, new ArrayList<>());
        return true;
    }
}
