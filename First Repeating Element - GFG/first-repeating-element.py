#User function Template for python3

class Solution:
    #Function to return the position of the first repeating element.
    def firstRepeated(self,arr, n):
        #given that the max element will be 10^6
        #I will make an array of size 10^6, to keep track of the element i have already visited
        #initialised an variable "ans" to keep track of the least index for such repeating
        #variables
        #if an element comes, which is already visited, ans = min(ans, visited[arr[i]]) 
        ans = -1
        visited = [-1] * 1000001;
        for i in range(n):
            if visited[arr[i]] != -1:
                #already visied
                if ans == -1:
                    ans = visited[arr[i]]
                else:
                    ans = min(ans, visited[arr[i]])
            else:
                visited[arr[i]] = i;
                
            
            
        if ans != -1:
            ans+=1
        return ans 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        
        arr=[int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.firstRepeated(arr, n))
# } Driver Code Ends