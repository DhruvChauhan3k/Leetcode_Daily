class dsu
{
	int[] size,parent;
	dsu(int n)
	{
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
	}
	int findpar(int x)
	{
		if(x==parent[x])return x;
		return parent[x]=findpar(parent[x]);
	}
	void join(int a,int b)
	{
		int c=findpar(a);
		int d=findpar(b);
		if(c==d)return;
		if(size[c]<size[d])
		{
            parent[c]=d;
			size[d]+=size[c];
			
		}
		else
		{
			size[c]+=size[d];
			parent[d]=c;
		}
	}
};

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        HashMap<String,Integer>m=new HashMap<>();
        dsu ds=new dsu(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts.get(i).size();j++)
            {
               String temp=accounts.get(i).get(j);
               if(!m.containsKey(temp))
               {
                   m.put(temp,i);
               }
               else
               {
                   ds.join(m.get(temp),i);
               }
            }
        }


          List<List<String>> mergedEmails = new ArrayList<>(accounts.size());
        for (int i = 0; i < accounts.size(); i++) {
            mergedEmails.add(new ArrayList<>());
        }

        for (Map.Entry<String, Integer> entry : m.entrySet()) {
            String email = entry.getKey();
            int parent = ds.findpar(entry.getValue());
            mergedEmails.get(parent).add(email);
        }

        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < accounts.size(); i++) {
            if (!mergedEmails.get(i).isEmpty()) {
                List<String> account = new ArrayList<>();
                account.add(accounts.get(i).get(0)); // name
                Collections.sort(mergedEmails.get(i)); // sort emails
                account.addAll(mergedEmails.get(i));
                result.add(account);
            }
        }

        return result;
    }
}