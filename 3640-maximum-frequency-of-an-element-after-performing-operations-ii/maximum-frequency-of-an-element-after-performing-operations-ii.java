class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
       HashMap<Integer,Integer>mp=new HashMap<>();
       HashMap<Integer,Integer>hash=new HashMap<>();

       TreeSet<Integer> points = new TreeSet<>();
       for(int it:nums){
            hash.put(it, hash.getOrDefault(it, 0) + 1);
            mp.put(it - k, mp.getOrDefault(it - k, 0) + 1);
            mp.put(it + k + 1, mp.getOrDefault(it + k + 1, 0) - 1);
            points.add(it);
            points.add(it - k);
            points.add(it + k + 1);
       }

        int ans = 1;
        int sum = 0;

        for (int it : points) {
            sum += mp.getOrDefault(it, 0);
            int freq = hash.getOrDefault(it, 0);
            ans = Math.max(ans, freq + Math.min(sum - freq, numOperations));
        }

        return ans;
    }
}